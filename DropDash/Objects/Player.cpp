#include "Player.hpp"

using namespace RSDK;

namespace GameLogic
{
MOD_REGISTER_OBJECT(Player);

Action<void> Player::State_Air_Movement;
Action<void> Player::State_Rolling;
Action<void> Player::State_Rolling_Jump;
Action<void> Player::State_Spindash;
Action<void> Player::State_Peelout;

void (*Player_ProcessDefaultAirMovement)(Player *player);
void (*Player_ProcessDefaultGravityTrue)(Player *player);

void Player::LateUpdate(void)
{
    sVars->Super(SUPER_LATEUPDATE, nullptr);

    if (this->state.Matches(Player::State_Rolling_Jump.action))
        this->state.Set(Player::State_Air_Movement.action);

    // Check if you jumped
    if (!this->frictionLoss && !this->onGround && this->trackScroll && !this->angle && this->collisionMode == CMODE_FLOOR && this->timer == 1
        && this->state.Matches(Player::State_Air_Movement.action))
        this->spinDash = 1;
    else if (this->onGround && !this->state.Matches(Player::State_Spindash.action) && !this->state.Matches(Player::State_Peelout.action))
        this->spinDash = 0;
}

void Player::StageLoad(void)
{
    sVars->Super(SUPER_STAGELOAD, nullptr);
    modSVars->sfxDropdash.Get("NexusGlobal/DropDash.wav");
}

bool32 Player_State_Air_Movement_Hook(bool32 skipped)
{
    RSDK_THIS(Player);

    if (!self->state.Matches(Player::State_Air_Movement.action))
        return false;

    if (!self->onGround && self->animator.animationID == Player::ANI_JUMPING) {
        if (self->jumpPress && self->spinDash == 1)
            self->spinDash = 2;

        if (self->spinDash >= 2 && self->jumpHold) {
            if (++self->spinDash >= 22) {
                self->state.Set(&Player::State_Dropdash);
                self->animator.SetAnimation(self->aniFrames, Player::ANI_DROPDASH, false, 0);
                Player::modSVars->sfxDropdash.Play();
            }
        }
    }
    return false;
}

void Player::State_Dropdash(void)
{
    SET_CURRENT_STATE();

    if (this->onGround) {
        this->spinDash = 0;

        if (this->right)
            this->direction = FLIP_NONE;
        if (this->left)
            this->direction = FLIP_X;

        int32 vel = 0x80000;
        int32 cap = 0xC0000;

        if (this->direction) {
            if (this->velocity.x <= 0) {
                this->groundVel = (this->groundVel >> 2) - vel;

                if (this->groundVel < -cap)
                    this->groundVel = -cap;
            }
            else if (this->angle) {
                this->groundVel = (this->groundVel >> 1) - vel;
            }
            else {
                this->groundVel = -vel;
            }
        }
        else {
            if (this->velocity.x >= 0) {
                this->groundVel = vel + (this->groundVel >> 2);

                if (this->groundVel > cap)
                    this->groundVel = cap;
            }
            else if (this->angle) {
                this->groundVel = vel + (this->groundVel >> 1);
            }
            else {
                this->groundVel = vel;
            }
        }

        modSVars->sfxDropdash.Stop();
        sVars->sfxRelease.Play(false, 255);

        this->animator.SetAnimation(this->aniFrames, Player::ANI_JUMPING, false, 0);
        this->skidding = 0;
        this->state.Set(Player::State_Rolling.action);
    }
    else if (this->jumpHold) {
        Player_ProcessDefaultAirMovement(this);
        Player_ProcessDefaultGravityTrue(this);
    }
    else {
        this->spinDash = 0;
        this->state.Set(Player::State_Air_Movement.action);
        this->animator.SetAnimation(this->aniFrames, Player::ANI_JUMPING, false, 0);
    }
}

bool32 Player_State_Rolling_Jump_Hook(bool32 skipped)
{
    RSDK_THIS(Player);
    self->state.SetAndRun(Player::State_Air_Movement.action, self);
    return true;
}

} // namespace GameLogic
