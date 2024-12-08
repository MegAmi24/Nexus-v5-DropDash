#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"
#include "Player.hpp"

namespace GameLogic
{

struct BlueShield : RSDK::GameObject::Entity {

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
    };

    struct ModStatic : RSDK::GameObject::Static {
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    RSDK::Animator animator;
    Player *parent;
    uint8 shieldValue;

    // ==============================
    // EVENTS
    // ==============================

    void Draw();

    // ==============================
    // FUNCTIONS
    // ==============================

    // ==============================
    // DECLARATION
    // ==============================

    MOD_DECLARE(BlueShield);
};
} // namespace GameLogic
