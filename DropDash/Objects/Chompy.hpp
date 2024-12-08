#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"

namespace GameLogic
{

struct Chompy : RSDK::GameObject::Entity {

    // ==============================
    // ENUMS
    // ==============================

    enum ChompyJumpDirs {
        JUMPDIR_LEFT,
        JUMPDIR_RIGHT,
        JUMPDIR_RIGHT2, // not sure if or how this is different from JUMPDIR_RIGHT
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
    };

    struct ModStatic : RSDK::GameObject::Static {
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    ChompyJumpDirs jumpDir;
    RSDK::StateMachine<Chompy> state;
    RSDK::Animator animator;
    RSDK::Vector2 oldPos;
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

    MOD_DECLARE(Chompy);
};
} // namespace GameLogic
