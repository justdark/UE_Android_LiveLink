// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JSONLiveLink/Private/JSONLiveLinkSourceFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJSONLiveLinkSourceFactory() {}
// Cross Module References
	JSONLIVELINK_API UClass* Z_Construct_UClass_UJSONLiveLinkSourceFactory_NoRegister();
	JSONLIVELINK_API UClass* Z_Construct_UClass_UJSONLiveLinkSourceFactory();
	LIVELINKINTERFACE_API UClass* Z_Construct_UClass_ULiveLinkSourceFactory();
	UPackage* Z_Construct_UPackage__Script_JSONLiveLink();
// End Cross Module References
	void UJSONLiveLinkSourceFactory::StaticRegisterNativesUJSONLiveLinkSourceFactory()
	{
	}
	UClass* Z_Construct_UClass_UJSONLiveLinkSourceFactory_NoRegister()
	{
		return UJSONLiveLinkSourceFactory::StaticClass();
	}
	struct Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULiveLinkSourceFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_JSONLiveLink,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "JSONLiveLinkSourceFactory.h" },
		{ "ModuleRelativePath", "Private/JSONLiveLinkSourceFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJSONLiveLinkSourceFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics::ClassParams = {
		&UJSONLiveLinkSourceFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UJSONLiveLinkSourceFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UJSONLiveLinkSourceFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UJSONLiveLinkSourceFactory, 1148127641);
	template<> JSONLIVELINK_API UClass* StaticClass<UJSONLiveLinkSourceFactory>()
	{
		return UJSONLiveLinkSourceFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UJSONLiveLinkSourceFactory(Z_Construct_UClass_UJSONLiveLinkSourceFactory, &UJSONLiveLinkSourceFactory::StaticClass, TEXT("/Script/JSONLiveLink"), TEXT("UJSONLiveLinkSourceFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UJSONLiveLinkSourceFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
