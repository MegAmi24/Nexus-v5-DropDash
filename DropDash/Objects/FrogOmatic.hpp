#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"

namespace GameLogic
{

struct FrogOmatic : RSDK::GameObject::Entity {

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
    RSDK::Animator animator;
    int32 bounce;

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

    MOD_DECLARE(FrogOmatic);
};
} // namespace GameLogic
