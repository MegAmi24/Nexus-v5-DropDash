#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"

namespace GameLogic
{

struct Player : RSDK::GameObject::Entity {

    // ==============================
    // ENUMS
    // ==============================

    enum PlayerModes {
        PLAYERMODE_NORMAL,
        PLAYERMODE_PARACHUTE,
        PLAYERMODE_DEBUG,
    };

    enum PlayerControlModes {
        CONTROLMODE_NONE     = -1,
        CONTROLMODE_NORMAL   = 0,
        CONTROLMODE_SIDEKICK = 1,
    };

    enum PlayerAni {
        ANI_STOPPED,
        ANI_WAITING,
        ANI_BORED,
        ANI_LOOKINGUP,
        ANI_LOOKINGDOWN,
        ANI_WALKING,
        ANI_RUNNING,
        ANI_SKIDDING,
        ANI_PEELOUT,
        ANI_SPINDASH,
        ANI_JUMPING,
        ANI_BOUNCING,
        ANI_HURT,
        ANI_DYING,
        ANI_DROWNING,
        ANI_LIFEICON,
        ANI_FANROTATE,
        ANI_BREATHING,
        ANI_PUSHING,
        ANI_FLAILINGLEFT,
        ANI_FLAILINGRIGHT,
        ANI_SLIDING,
        ANI_FINISHPOSE = 23,
        ANI_CORKSCREW  = 34,
        ANI_DROPDASH   = 36,
        ANI_HANGING    = 43,
    };

    enum Shields {
        SHIELD_NONE,
        SHIELD_BLUE,
    };

    enum HurtTypes {
        HURT_NONE,
        HURT_HASSHIELD,
        HURT_RINGLOSS,
        HURT_DIE,
    };

    // ==============================
    // STRUCTS
    // ==============================

    struct PlayerMovementStats {
        int32 topSpeed;
        int32 acceleration;
        int32 deceleration;
        int32 airAcceleration;
        int32 airDeceleration;
        int32 gravityStrength;
        int32 jumpStrength;
        int32 rollingAcceleration;
        int32 rollingDeceleration;
    };

    // ==============================
    // STATIC VARS
    // ==============================

    struct Static : RSDK::GameObject::Static {
        uint16 delayUp;
        uint16 delayDown;
        uint16 delayLeft;
        uint16 delayRight;
        uint16 delayJumpPress;
        uint16 delayJumpHold;
        RSDK::SpriteAnimation sonicFrames;
        RSDK::SoundFX sfxJump;
        RSDK::SoundFX sfxLoseRings;
        RSDK::SoundFX sfxHurt;
        RSDK::SoundFX sfxSpin;
        RSDK::SoundFX sfxCharge;
        RSDK::SoundFX sfxRelease;
        RSDK::SoundFX sfxSkidding;
        RSDK::SoundFX sfxDestroy;
        RSDK::SoundFX sfxBossHit;
        RSDK::SoundFX sfxYes;
        bool32 pauseEnabled;
        bool32 frameAdvance;
    };

    struct ModStatic : RSDK::GameObject::Static {
        RSDK::SoundFX sfxDropdash;
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    uint8 mode;
    void *camera;
    RSDK::Vector2 screenPos;
    int32 timer;
    RSDK::StateMachine<Player> state;
    RSDK::Animator animator;
    RSDK::SpriteAnimation aniFrames;
    RSDK::Hitbox *outerbox;
    RSDK::Hitbox *innerbox;
    uint8 skidding;
    uint8 pushing;
    int8 controlMode;
    uint8 frictionLoss;
    int32 lookPos;
    PlayerMovementStats stats;
    uint8 left;
    uint8 right;
    uint8 up;
    uint8 down;
    uint8 jumpPress;
    uint8 jumpHold;
    uint8 followPlayer1;
    uint8 trackScroll;
    uint8 gravity;
    uint8 water;
    uint8 flailing[3];
    int16 runningSpeed;
    int16 walkingSpeed;
    int16 jumpingSpeed;
    int32 rings;
    int32 spinDash;
    int32 aniJumpSpeed;
    int32 speedShoes;
    int32 invincibility;
    int32 flashing;
    int32 minRollSpeed;
    int32 ringExtraLife;
    RSDK::Hitbox *normalbox;
    RSDK::Hitbox *jumpbox;
    int32 animCheck;
    int16 jumpAnimSpeed;
    uint8 shield;

    // ==============================
    // EVENTS
    // ==============================

    void LateUpdate();
    static void StageLoad();

    // ==============================
    // FUNCTIONS
    // ==============================

    static RSDK::Action<void> State_Air_Movement;
    static RSDK::Action<void> State_Rolling;
    static RSDK::Action<void> State_Rolling_Jump;
    static RSDK::Action<void> State_Spindash;
    static RSDK::Action<void> State_Peelout;

    void State_Dropdash(void);

    // ==============================
    // DECLARATION
    // ==============================

    MOD_DECLARE(Player);
};

extern void (*Player_ProcessDefaultAirMovement)(Player *player);
extern void (*Player_ProcessDefaultGravityTrue)(Player *player);

bool32 Player_State_Air_Movement_Hook(bool32 skipped);
bool32 Player_State_Rolling_Jump_Hook(bool32 skipped);

} // namespace GameLogic
