// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "goBEM/goBEMCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodegoBEMCharacter() {}
// Cross Module References
	GOBEM_API UClass* Z_Construct_UClass_AgoBEMCharacter_NoRegister();
	GOBEM_API UClass* Z_Construct_UClass_AgoBEMCharacter();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	UPackage* Z_Construct_UPackage__Script_goBEM();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
// End Cross Module References
	void AgoBEMCharacter::StaticRegisterNativesAgoBEMCharacter()
	{
	}
	UClass* Z_Construct_UClass_AgoBEMCharacter_NoRegister()
	{
		return AgoBEMCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AgoBEMCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SideViewCameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SideViewCameraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RunningAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RunningAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IdleAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IdleAnimation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AgoBEMCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_goBEM,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AgoBEMCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * This class is the default character for goBEM, and it is responsible for all\n * physical interaction between the player and the world.\n *\n * The capsule component (inherited from ACharacter) handles collision with the world\n * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule\n * The Sprite component (inherited from APaperCharacter) handles the visuals\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "goBEMCharacter.h" },
		{ "ModuleRelativePath", "goBEMCharacter.h" },
		{ "ToolTip", "This class is the default character for goBEM, and it is responsible for all\nphysical interaction between the player and the world.\n\nThe capsule component (inherited from ACharacter) handles collision with the world\nThe CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule\nThe Sprite component (inherited from APaperCharacter) handles the visuals" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_SideViewCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Side view camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "goBEMCharacter.h" },
		{ "ToolTip", "Side view camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_SideViewCameraComponent = { "SideViewCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AgoBEMCharacter, SideViewCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_SideViewCameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_SideViewCameraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera beside the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "goBEMCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera beside the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AgoBEMCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_RunningAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while running around\n" },
		{ "ModuleRelativePath", "goBEMCharacter.h" },
		{ "ToolTip", "The animation to play while running around" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_RunningAnimation = { "RunningAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AgoBEMCharacter, RunningAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_RunningAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_RunningAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_IdleAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while idle (standing still)\n" },
		{ "ModuleRelativePath", "goBEMCharacter.h" },
		{ "ToolTip", "The animation to play while idle (standing still)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_IdleAnimation = { "IdleAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AgoBEMCharacter, IdleAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_IdleAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_IdleAnimation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AgoBEMCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_SideViewCameraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_RunningAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AgoBEMCharacter_Statics::NewProp_IdleAnimation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AgoBEMCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AgoBEMCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AgoBEMCharacter_Statics::ClassParams = {
		&AgoBEMCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AgoBEMCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AgoBEMCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AgoBEMCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AgoBEMCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AgoBEMCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AgoBEMCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AgoBEMCharacter, 3176634781);
	template<> GOBEM_API UClass* StaticClass<AgoBEMCharacter>()
	{
		return AgoBEMCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AgoBEMCharacter(Z_Construct_UClass_AgoBEMCharacter, &AgoBEMCharacter::StaticClass, TEXT("/Script/goBEM"), TEXT("AgoBEMCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AgoBEMCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
