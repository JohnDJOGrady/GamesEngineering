#include "InputHandler.h"

void InputHandler::handleInput()
{

	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_A) == SDL_PRESSED) { m_buttonA_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_B) == SDL_PRESSED) { m_buttonB_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_X) == SDL_PRESSED) { m_buttonX_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_Y) == SDL_PRESSED) { m_buttonY_->execute(); };
	if (SDL_GameControllerGetButton(m_controller, SDL_CONTROLLER_BUTTON_LEFTSTICK) == SDL_PRESSED) { m_leftClick_->execute(); };
}

void InputHandler::bindCommands()
{
	m_buttonX_ = new FireCommand();
	m_buttonA_ = new JumpCommand();
	m_buttonB_ = new MeleeCommand();
	m_buttonY_ = new ShieldCommand();
	m_leftClick_ = new CrouchCommand();
}
