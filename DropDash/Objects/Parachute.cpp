#include "Parachute.hpp"

using namespace RSDK;

namespace GameLogic
{
RSDK_REGISTER_OBJECT(Parachute);

RSDK::Action<void> Parachute::State_Glide;

bool32 Parachute_State_Glide_Hook(bool32 skipped)
{
    RSDK_THIS(Parachute);

    Player *player = self->target;

    if (player->jumpPress)
        player->spinDash = 1;

    return false;
}

} // namespace GameLogic
