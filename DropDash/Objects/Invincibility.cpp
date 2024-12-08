#include "Invincibility.hpp"

using namespace RSDK;

namespace GameLogic
{
MOD_REGISTER_OBJECT(Invincibility);

Action<void> Invincibility::State_Spawner;

void Invincibility::Create(void *data)
{
    sVars->Super(SUPER_CREATE, data);

    if (this->state.Matches(Invincibility::State_Spawner.action)) {
        if (this->parent->animator.animationID == Player::ANI_DROPDASH)
            this->position.y += 327680;
    }
}

bool32 Invincibility_State_Spawner_Pre(bool32 skipped)
{
    RSDK_THIS(Invincibility);

    if (self->parent->animator.animationID == Player::ANI_DROPDASH)
        self->parent->position.y += 327680;

    return false;
}

bool32 Invincibility_State_Spawner_Hook(bool32 skipped)
{
    RSDK_THIS(Invincibility);

    if (self->parent->animator.animationID == Player::ANI_DROPDASH)
        self->parent->position.y -= 327680;

    return false;
}

} // namespace GameLogic
