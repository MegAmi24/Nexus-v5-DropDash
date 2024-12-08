#include "GameAPI/Game.hpp"
#include "SonicNexus.hpp"

#include "Objects/Player.hpp"
#include "Objects/Invincibility.hpp"
#include "Objects/Parachute.hpp"

GlobalVariables *globals = nullptr;

using namespace RSDK;
using namespace GameLogic;

void InitModAPI(void)
{
    // --------------------
    // Get Public Functions
    // --------------------

    PubFuncAssign(Player_ProcessDefaultAirMovement, NULL, "Player::ProcessDefaultAirMovement");
    PubFuncAssign(Player_ProcessDefaultGravityTrue, NULL, "Player::ProcessDefaultGravityTrue");

    // --------------------
    // Set Public Functions
    // --------------------

    ADD_PUBLIC_FUNC(Player::State_Dropdash);

    // -----------------
    // Get Object States
    // -----------------

    auto Func1 = Mod::PubFunc("Player::State_Air_Movement");
    auto Func2 = Mod::PubFunc("Player::State_Rolling");
    auto Func3 = Mod::PubFunc("Player::State_Rolling_Jump");
    auto Func4 = Mod::PubFunc("Player::State_Spindash");
    auto Func5 = Mod::PubFunc("Player::State_Peelout");
    auto Func6 = Mod::PubFunc("Invincibility::State_Spawner");
    auto Func7 = Mod::PubFunc("Parachute::State_Glide");

    Player::State_Air_Movement.Set(Func1);
    Player::State_Rolling.Set(Func2);
    Player::State_Rolling_Jump.Set(Func3);
    Player::State_Spindash.Set(Func4);
    Player::State_Peelout.Set(Func5);
    Invincibility::State_Spawner.Set(Func6);
    Parachute::State_Glide.Set(Func7);

    // --------------------
    // Register State Hooks
    // --------------------

    Mod::StateHook<void, Player>(Player::State_Air_Movement, Player_State_Air_Movement_Hook, false);
    Mod::StateHook<void, Player>(Player::State_Rolling_Jump, Player_State_Rolling_Jump_Hook, true);

    Mod::StateHook<void, Invincibility>(Invincibility::State_Spawner, Invincibility_State_Spawner_Pre, true);
    Mod::StateHook<void, Invincibility>(Invincibility::State_Spawner, Invincibility_State_Spawner_Hook, false);

    Mod::StateHook<void, Parachute>(Parachute::State_Glide, Parachute_State_Glide_Hook, false);
}

void InitModAPI(void);

#if RETRO_USE_MOD_LOADER
bool32 LinkModLogic(RSDK::EngineInfo *info, const char *modID)
{
#if RETRO_REV02
    LinkGameLogicDLL(info);
#else
    LinkGameLogicDLL(*info);
#endif

    globals = (GlobalVariables *)Mod::GetGlobals();

    RSDK::Mod::modID = modID;

    InitModAPI();

    return true;
}
#endif
