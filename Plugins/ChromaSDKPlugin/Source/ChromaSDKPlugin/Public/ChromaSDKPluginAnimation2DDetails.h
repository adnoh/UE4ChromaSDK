﻿// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IDetailCustomization.h"
#include "ChromaSDKPluginTypes.h"
#include "ChromaSDKPluginButton2D.h"
#include "Widgets/Layout/SGridPanel.h"

class FChromaSDKPluginAnimation2DDetails : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	void CreateKeyboard();
	void RefreshKeyboard();

	void OnClickColor(int row, int column);

	TSharedRef<SWidget> GenerateChromaSDKKeyboardKeys(TSharedPtr<FString> InItem);
	void OnChangeChromaSDKKeyboardKeys(TSharedPtr<FString> Item, ESelectInfo::Type SelectInfo);

	void OnColorCommitted(FLinearColor color);

	FReply OnClickSetButton();

	FReply OnClickClearButton();

	FReply OnClickRandomButton();

	FReply OnClickApplyButton();

private:

	TSharedPtr<FChromaSDKPluginAnimation2DDetails> _mDetails;

	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;

	TSharedPtr<SGridPanel> _mGrid;

	TArray<TSharedRef<IChromaSDKPluginButton2D>> ColorButtons;

	TArray<TSharedPtr<FString>> ChromaSDKKeyboardKeys;

	EChromaSDKKeyboardKey _mSelectedKey;
	FLinearColor _mColor;
};