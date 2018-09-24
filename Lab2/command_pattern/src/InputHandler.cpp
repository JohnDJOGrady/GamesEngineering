#include "InputHandler.h"

void InputHandler::handleInput()
{
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_A) > 0) { m_buttonA_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_B) > 0) { m_buttonB_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_X) > 0) { m_buttonX_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_Y) > 0) { m_buttonY_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_LEFTSTICK) > 0) { m_leftClick_->execute(); };
}

void InputHandler::bindCommands()
{
	m_buttonX_ = new FireCommand();
	m_buttonA_ = new JumpCommand();
	m_buttonB_ = new MeleeCommand();
	m_buttonY_ = new ShieldCommand();
	m_leftClick_ = new CrouchCommand();
}
