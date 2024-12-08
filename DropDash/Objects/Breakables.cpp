#include "Monitor.hpp"
#include "Chompy.hpp"
#include "FrogOmatic.hpp"
#include "HelliBomber.hpp"
#include "MRally.hpp"

using namespace RSDK;

namespace GameLogic
{
MOD_REGISTER_OBJECT(Monitor);
MOD_REGISTER_OBJECT(Chompy);
MOD_REGISTER_OBJECT(FrogOmatic);
MOD_REGISTER_OBJECT(HelliBomber);
MOD_REGISTER_OBJECT(MRally);

void Monitor::Update(void)
{
    foreach_active(Player, player)
    {
        if (player->animator.animationID == Player::ANI_DROPDASH)
            player->animator.animationID = Player::ANI_JUMPING;
    }

    sVars->Super(SUPER_UPDATE, nullptr);

    foreach_active(Player, player)
    {
        if (player->state.Matches(&Player::State_Dropdash))
            player->animator.animationID = Player::ANI_DROPDASH;
    }
}

void Chompy::Update(void)
{
    foreach_active(Player, player)
    {
        if (player->animator.animationID == Player::ANI_DROPDASH)
            player->animator.animationID = Player::ANI_JUMPING;
    }

    sVars->Super(SUPER_UPDATE, nullptr);

    foreach_active(Player, player)
    {
        if (player->state.Matches(&Player::State_Dropdash))
            player->animator.animationID = Player::ANI_DROPDASH;
    }
}

void FrogOmatic::Update(void)
{
    foreach_active(Player, player)
    {
        if (player->animator.animationID == Player::ANI_DROPDASH)
            player->animator.animationID = Player::ANI_JUMPING;
    }

    sVars->Super(SUPER_UPDATE, nullptr);

    foreach_active(Player, player)
    {
        if (player->state.Matches(&Player::State_Dropdash))
            player->animator.animationID = Player::ANI_DROPDASH;
    }
}

void HelliBomber::Update(void)
{
    foreach_active(Player, player)
    {
        if (player->animator.animationID == Player::ANI_DROPDASH)
            player->animator.animationID = Player::ANI_JUMPING;
    }

    sVars->Super(SUPER_UPDATE, nullptr);

    foreach_active(Player, player)
    {
        if (player->state.Matches(&Player::State_Dropdash))
            player->animator.animationID = Player::ANI_DROPDASH;
    }
}

void MRally::Update(void)
{
    foreach_active(Player, player)
    {
        if (player->animator.animationID == Player::ANI_DROPDASH)
            player->animator.animationID = Player::ANI_JUMPING;
    }

    sVars->Super(SUPER_UPDATE, nullptr);

    foreach_active(Player, player)
    {
        if (player->state.Matches(&Player::State_Dropdash))
            player->animator.animationID = Player::ANI_DROPDASH;
    }
}

} // namespace GameLogic
