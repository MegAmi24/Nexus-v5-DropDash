#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"
#include "Player.hpp"

namespace GameLogic
{

struct Parachute : RSDK::GameObject::Entity {

    // ==============================
    // ENUMS
    // ==============================

    // ==============================
    // STRUCTS
    // ==============================

    // ==============================
    // STATIC VARS
    // ==============================

    struct Static : RSDK::GameObject::Static {
        RSDK::SpriteAnimation aniFrames;
        RSDK::Hitbox hitbox;
        RSDK::SoundFX sfxCatch;
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    RSDK::StateMachine<Parachute> state;
    RSDK::Animator animator;
    Player *target;
    RSDK::Vector2 startPos;

    // ==============================
    // EVENTS
    // ==============================

    // ==============================
    // FUNCTIONS
    // ==============================

    static RSDK::Action<void> State_Glide;

    // ==============================
    // DECLARATION
    // ==============================

    RSDK_DECLARE(Parachute);
};

bool32 Parachute_State_Glide_Hook(bool32 skipped);

} // namespace GameLogic
