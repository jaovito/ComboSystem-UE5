// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "SoulsLikeCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	None UMETA(DisplayName = "None"),
	Attacking UMETA(DisplayName = "Attacking"),
	Dodge UMETA(DisplayName = "Dodge"),
	Dead UMETA(DisplayName = "Dead")
};

UCLASS(config=Game)
class ASoulsLikeCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	ASoulsLikeCharacter();

	UFUNCTION(BlueprintCallable)
	void PerformLightAttack(int AttackIndex);

	UFUNCTION(BlueprintCallable)
	void SaveLightAttack();

	UFUNCTION(BlueprintCallable)
	void ResetLightAttack();

	UFUNCTION(BlueprintPure)
	bool CanAttack();

	UFUNCTION(BlueprintPure)
	bool IsCurrentStateIncluding(TArray<EPlayerState> States);
	
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void Jump(const FInputActionValue& Value);

	/** Variable to player state */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Stats")
	EPlayerState CurrentPlayerState = EPlayerState::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	bool bSaveLightAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	bool bSaveHeavyAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int LightAttackIndex = 0;

	/** Set the anim montage array for light attacks */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<UAnimMontage*> LightAttackMontages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int HeavyAttackIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<UAnimMontage*> HeavyAttackMontages;


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

