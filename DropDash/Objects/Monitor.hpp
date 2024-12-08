#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"
#include "Player.hpp"

namespace GameLogic
{

struct Monitor : RSDK::GameObject::Entity {

    // ==============================
    // ENUMS
    // ==============================

    enum MonitorTypes {
        MONITOR_BLANK,
        MONITOR_RINGS,
        MONITOR_BLUESHIELD,
        MONITOR_INVINCIBILITY,
        MONITOR_SPEEDSHOES,
        MONITOR_EXTRALIFE,
        MONITOR_ROBOTNIK,
    };

    // ==============================
    // STRUCTS
    // ==============================

    // ==============================
    // STATIC VARS
    // ==============================

    struct Static : RSDK::GameObject::Static {
        RSDK::SpriteAnimation aniFrames;
        RSDK::Hitbox hitbox;
        RSDK::SoundFX sfxDestroy;
        RSDK::SoundFX sfxBlueShield;
    };

    struct ModStatic : RSDK::GameObject::Static {
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    MonitorTypes type;
    RSDK::StateMachine<Monitor> state;
    RSDK::Vector2 iconPos;
    RSDK::Animator animator;
    RSDK::Animator iconAnim;
    bool32 falling;
    int32 timer;
    int32 pSpeed;
    Player *target;

    // ==============================
    // EVENTS
    // ==============================

    void Update();

    // ==============================
    // FUNCTIONS
    // ==============================

    // ==============================
    // DECLARATION
    // ==============================

    MOD_DECLARE(Monitor);
};
} // namespace GameLogic
