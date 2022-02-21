package co.facemoji.mocap4face

import android.content.Context
import co.facemoji.async.Future
import co.facemoji.io.ApplicationContext
import co.facemoji.io.ResourceFileSystem
import co.facemoji.logging.logError
import co.facemoji.tracker.CameraWrapper
import co.facemoji.tracker.FaceTracker
import co.facemoji.tracker.FaceTrackerResult
import co.facemoji.tracker.OpenGLTexture
import co.facemoji.math.Quaternion
import co.facemoji.math.Vec3
import org.json.JSONArray
import 	java.net.DatagramSocket
import java.net.DatagramPacket
import java.net.InetAddress
import org.json.JSONObject



/**
 * Wraps a camera source and a face tracker into one object.
 */
class CameraTracker(context: Context,ip: String,port: Int) {
    private val cameraWrapper: CameraWrapper = CameraWrapper(context)
    private val faceTracker: Future<FaceTracker?>
    private var socket:  DatagramSocket = DatagramSocket()
    var trackerDelegate: (OpenGLTexture, FaceTrackerResult?) -> Unit = { _, _ -> }
    var frontFacing = true
    public var ip:  String = ip
    public var port:  Int = port
    init {
        cameraWrapper.start(frontFacing = frontFacing).logError("Error initializing camera")
        cameraWrapper.addOnFrameListener(this::onCameraImage)
        faceTracker = FaceTracker.createVideoTracker(ResourceFileSystem(ApplicationContext(context)), cameraWrapper.openglContext)
                .logError("Error initializing face tracker")
    }

    /**
     * Converts head rotation to blendshape-like coefficients to send as params
     */
    private fun faceRotationParams(rotation: Quaternion): Map<String, Float> {
        val euler = rotation.toEuler()
        val halfPi = Math.PI.toFloat() * 0.5f
        return mapOf(
            "headYaw" to euler.y / -halfPi,
            "headPitch" to euler.x / -halfPi,
            "headRoll" to euler.z / -halfPi,
        )
    }

    /**
     * Called whenever a new camera frame becomes available
     */
    private fun onCameraImage(cameraTexture: OpenGLTexture) {
        val result = faceTracker.currentValue?.track(cameraTexture)
        try {
            val rotation = result?.rotationQuaternion
            if (result != null) {
                val blendShapes =
                    result?.blendshapes + faceRotationParams(result?.rotationQuaternion);
                val paramArray = JSONArray()
                val boneArray = JSONArray()
                val jsonResult = JSONObject()
                val jsonFinal = JSONObject()
                for ((key,value) in blendShapes.orEmpty()){
                    val obj = JSONObject()
                    obj?.put("Name",key.replace("_L","Left").replace("_R","Right"))
                    obj?.put("Value",value)
                    paramArray.put(obj)
                }
                val headBone = JSONObject()
                val euler = rotation?.toEuler()

                val real_rotation = euler?.withX(-euler.x)?.withZ(-euler.z)?.withY(-euler.y)?.let { Quaternion.fromEuler(it) }
                headBone.put("Name","Head")
                headBone.put("Parent",-1)
                headBone.put("Location",JSONArray(listOf(0,0,0)))
                headBone.put("Rotation",JSONArray(listOf(real_rotation?.xyzw?.x,real_rotation?.xyzw?.y!!,real_rotation?.xyzw?.z!!,real_rotation?.xyzw?.w)))
                headBone.put("Scale",JSONArray(listOf(0,0,0)))
                boneArray.put(headBone)
                jsonResult.put("Bone",boneArray)

                jsonResult.put("Parameter",paramArray)

                jsonFinal.put("android",jsonResult)
                val s = jsonFinal.toString()
                val buf = s.toByteArray()
                val packet = DatagramPacket(buf, buf.size, InetAddress.getByName(ip), port)
                socket.send(packet)
            }
        } catch (e: Exception) {
        }

        trackerDelegate(cameraTexture, result)
    }

    /**
     * Stops the tracking and releases the camera
     */
    fun stop() {
        cameraWrapper.stop()
    }

    /**
     * (Re)-starts the camera (useful after the app gets suspended)
     */
    fun restart() {
        cameraWrapper.start(frontFacing)
    }

    /**
     * Switches between front and back cameras
     */
    fun switchCamera() {
        frontFacing = !frontFacing
        cameraWrapper.start(frontFacing)
    }

    /**
     * Reference to the OpenGL context used to create the camera surface texture
     */
    val openGLContext = cameraWrapper.openglContext

    /**
     * List of blendshape names used for the list of blendshape sliders
     */
    val blendshapeNames: Future<List<String>> get() = faceTracker.map { it?.blendshapeNames ?: emptyList() }
}
