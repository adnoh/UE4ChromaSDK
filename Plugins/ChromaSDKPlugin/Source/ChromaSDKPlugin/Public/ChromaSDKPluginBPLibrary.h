// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "ChromaSDKPluginBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UENUM(BlueprintType)
enum class EChromaSDKDeviceEnum : uint8
{
	DE_ChromaLink	UMETA(DisplayName = "ChromaLink"),
	DE_Headset		UMETA(DisplayName = "Headset"),
	DE_Keyboard		UMETA(DisplayName = "Keyboard"),
	DE_Keypad		UMETA(DisplayName = "Keypad"),
	DE_Mouse		UMETA(DisplayName = "Mouse"),
	DE_Mousepad	UMETA(DisplayName = "Mousepad")
};

USTRUCT(BlueprintType)
struct FChromaSDKGuid
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int Data1;

	UPROPERTY(BlueprintReadOnly)
	int Data2;

	UPROPERTY(BlueprintReadOnly)
	int Data3;

	UPROPERTY(BlueprintReadOnly)
	TArray<int> Data4;

	//Constructor
	FChromaSDKGuid()
	{
		Data1 = 0;
		Data2 = 0;
		Data3 = 0;
		for (int i = 0; i < 8; ++i)
		{
			Data4.Add(0);
		}
	}
};

USTRUCT(BlueprintType)
struct FChromaSDKEffectResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int Result;

	UPROPERTY(BlueprintReadOnly)
	FChromaSDKGuid EffectId;

	//Constructor
	FChromaSDKEffectResult()
	{
		Result = 0;
	}
};

UCLASS()
class UChromaSDKPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsPlatformWindows", Keywords = "Returns true on the Windows Platform"), Category = "ChromaSDK")
	static bool IsPlatformWindows();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Init", Keywords = "Initialize the ChromaSDK"), Category = "ChromaSDK")
	static int ChromaSDKInit();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnInit", Keywords = "Uninitialize the ChromaSDK"), Category = "ChromaSDK")
	static int ChromaSDKUnInit();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectStatic", Keywords = "Create a static color effect"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectStatic(const EChromaSDKDeviceEnum& device, const FLinearColor& color);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PrintEffectId", Keywords = "Print Effect GUID"), Category = "ChromaSDK")
	static void ChromaSDKPrintEffectId(const FChromaSDKGuid& effectId);
};
