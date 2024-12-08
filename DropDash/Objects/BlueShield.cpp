#include "BlueShield.hpp"

using namespace RSDK;

namespace GameLogic
{
MOD_REGISTER_OBJECT(BlueShield);

void BlueShield::Draw(void)
{
    if (this->parent->animator.animationID == Player::ANI_DROPDASH) {
        this->parent->position.y += 327680;
        sVars->Super(SUPER_DRAW, nullptr);
        this->parent->position.y -= 327680;
    }
    else
        sVars->Super(SUPER_DRAW, nullptr);
}

} // namespace GameLogic
