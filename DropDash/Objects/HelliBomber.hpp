#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"
#include "Player.hpp"

namespace GameLogic
{

struct HelliBomber : RSDK::GameObject::Entity {

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
        RSDK::Hitbox aggroHitbox;
        RSDK::Hitbox bulletHitbox;
    };

    struct ModStatic : RSDK::GameObject::Static {
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    bool32 isBullet;
    RSDK::StateMachine<HelliBomber> state;
    RSDK::Animator animator;
    RSDK::Animator bladesAnim;
    int32 destX;
    int32 timer;
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

    MOD_DECLARE(HelliBomber);
};
} // namespace GameLogic
