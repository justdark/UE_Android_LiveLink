// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Input/Reply.h"
#include "Types/SlateEnums.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class SEditableTextBox;

class SJSONLiveLinkSourceFactory : public SCompoundWidget
{
public:
	DECLARE_DELEGATE_OneParam(FOnOkClicked, FIPv4Endpoint);

	SLATE_BEGIN_ARGS(SJSONLiveLinkSourceFactory){}
		SLATE_EVENT(FOnOkClicked, OnOkClicked)
	SLATE_END_ARGS()

	void Construct(const FArguments& Args);

private:

	void OnEndpointChanged(const FText& NewValue, ETextCommit::Type);

	FReply OnOkClicked();

	TWeakPtr<SEditableTextBox> EditabledText;
	FOnOkClicked OkClicked;
};