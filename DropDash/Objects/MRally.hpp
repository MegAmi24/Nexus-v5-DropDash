#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"

namespace GameLogic
{

struct MRally : RSDK::GameObject::Entity {

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
    };

    struct ModStatic : RSDK::GameObject::Static {
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    RSDK::StateMachine<MRally> state;
    RSDK::Animator animator;
    int32 timer;

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

    MOD_DECLARE(MRally);
};
} // namespace GameLogic
