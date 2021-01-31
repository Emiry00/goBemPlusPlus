// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GOBEM_goBEMCharacter_generated_h
#error "goBEMCharacter.generated.h already included, missing '#pragma once' in goBEMCharacter.h"
#endif
#define GOBEM_goBEMCharacter_generated_h

#define goBEM_Source_goBEM_goBEMCharacter_h_22_SPARSE_DATA
#define goBEM_Source_goBEM_goBEMCharacter_h_22_RPC_WRAPPERS
#define goBEM_Source_goBEM_goBEMCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define goBEM_Source_goBEM_goBEMCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAgoBEMCharacter(); \
	friend struct Z_Construct_UClass_AgoBEMCharacter_Statics; \
public: \
	DECLARE_CLASS(AgoBEMCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/goBEM"), NO_API) \
	DECLARE_SERIALIZER(AgoBEMCharacter)


#define goBEM_Source_goBEM_goBEMCharacter_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAgoBEMCharacter(); \
	friend struct Z_Construct_UClass_AgoBEMCharacter_Statics; \
public: \
	DECLARE_CLASS(AgoBEMCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/goBEM"), NO_API) \
	DECLARE_SERIALIZER(AgoBEMCharacter)


#define goBEM_Source_goBEM_goBEMCharacter_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AgoBEMCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AgoBEMCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AgoBEMCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AgoBEMCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AgoBEMCharacter(AgoBEMCharacter&&); \
	NO_API AgoBEMCharacter(const AgoBEMCharacter&); \
public:


#define goBEM_Source_goBEM_goBEMCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AgoBEMCharacter(AgoBEMCharacter&&); \
	NO_API AgoBEMCharacter(const AgoBEMCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AgoBEMCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AgoBEMCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AgoBEMCharacter)


#define goBEM_Source_goBEM_goBEMCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(AgoBEMCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AgoBEMCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__RunningAnimation() { return STRUCT_OFFSET(AgoBEMCharacter, RunningAnimation); } \
	FORCEINLINE static uint32 __PPO__IdleAnimation() { return STRUCT_OFFSET(AgoBEMCharacter, IdleAnimation); }


#define goBEM_Source_goBEM_goBEMCharacter_h_19_PROLOG
#define goBEM_Source_goBEM_goBEMCharacter_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	goBEM_Source_goBEM_goBEMCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	goBEM_Source_goBEM_goBEMCharacter_h_22_SPARSE_DATA \
	goBEM_Source_goBEM_goBEMCharacter_h_22_RPC_WRAPPERS \
	goBEM_Source_goBEM_goBEMCharacter_h_22_INCLASS \
	goBEM_Source_goBEM_goBEMCharacter_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define goBEM_Source_goBEM_goBEMCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	goBEM_Source_goBEM_goBEMCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	goBEM_Source_goBEM_goBEMCharacter_h_22_SPARSE_DATA \
	goBEM_Source_goBEM_goBEMCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	goBEM_Source_goBEM_goBEMCharacter_h_22_INCLASS_NO_PURE_DECLS \
	goBEM_Source_goBEM_goBEMCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GOBEM_API UClass* StaticClass<class AgoBEMCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID goBEM_Source_goBEM_goBEMCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
