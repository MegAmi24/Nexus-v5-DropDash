#pragma once

#include "GameAPI/Game.hpp"
#include "../SonicNexus.hpp"
#include "Player.hpp"

namespace GameLogic
{

struct Invincibility : RSDK::GameObject::Entity {

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
        RSDK::Animator animator;
    };

    struct ModStatic : RSDK::GameObject::Static {
    };

    // ==============================
    // INSTANCE VARS
    // ==============================
    Player *parent;
    RSDK::StateMachine<Invincibility> state;
    int32 timer;

    // ==============================
    // EVENTS
    // ==============================

    void Create(void *data);

    // ==============================
    // FUNCTIONS
    // ==============================

    static RSDK::Action<void> State_Spawner;

    // ==============================
    // DECLARATION
    // ==============================

    MOD_DECLARE(Invincibility);
};

bool32 Invincibility_State_Spawner_Pre(bool32 skipped);
bool32 Invincibility_State_Spawner_Hook(bool32 skipped);

} // namespace GameLogic
