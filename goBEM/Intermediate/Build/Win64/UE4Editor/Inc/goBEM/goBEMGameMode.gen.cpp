// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "goBEM/goBEMGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodegoBEMGameMode() {}
// Cross Module References
	GOBEM_API UClass* Z_Construct_UClass_AgoBEMGameMode_NoRegister();
	GOBEM_API UClass* Z_Construct_UClass_AgoBEMGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_goBEM();
// End Cross Module References
	void AgoBEMGameMode::StaticRegisterNativesAgoBEMGameMode()
	{
	}
	UClass* Z_Construct_UClass_AgoBEMGameMode_NoRegister()
	{
		return AgoBEMGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AgoBEMGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AgoBEMGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_goBEM,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AgoBEMGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The GameMode defines the game being played. It governs the game rules, scoring, what actors\n * are allowed to exist in this game type, and who may enter the game.\n *\n * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of goBEMCharacter\n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "goBEMGameMode.h" },
		{ "ModuleRelativePath", "goBEMGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "The GameMode defines the game being played. It governs the game rules, scoring, what actors\nare allowed to exist in this game type, and who may enter the game.\n\nThis game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of goBEMCharacter" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AgoBEMGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AgoBEMGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AgoBEMGameMode_Statics::ClassParams = {
		&AgoBEMGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AgoBEMGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AgoBEMGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AgoBEMGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AgoBEMGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AgoBEMGameMode, 958226313);
	template<> GOBEM_API UClass* StaticClass<AgoBEMGameMode>()
	{
		return AgoBEMGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AgoBEMGameMode(Z_Construct_UClass_AgoBEMGameMode, &AgoBEMGameMode::StaticClass, TEXT("/Script/goBEM"), TEXT("AgoBEMGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AgoBEMGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
