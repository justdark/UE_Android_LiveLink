// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LiveLinkSourceFactory.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "JSONLiveLinkSourceFactory.generated.h"

class SJSONLiveLinkSourceEditor;

UCLASS()
class UJSONLiveLinkSourceFactory : public ULiveLinkSourceFactory
{
public:

	GENERATED_BODY()

	virtual FText GetSourceDisplayName() const override;
	virtual FText GetSourceTooltip() const override;

	virtual EMenuType GetMenuType() const override { return EMenuType::SubPanel; }
	virtual TSharedPtr<SWidget> BuildCreationPanel(FOnLiveLinkSourceCreated OnLiveLinkSourceCreated) const override;
	TSharedPtr<ILiveLinkSource> CreateSource(const FString& ConnectionString) const override;
private:
	void OnOkClicked(FIPv4Endpoint Endpoint, FOnLiveLinkSourceCreated OnLiveLinkSourceCreated) const;
};