#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H
#include <Components/Component.h>

class SpriteComponent : Component
{
public:
	SpriteComponent();
	~SpriteComponent();
	void setTexture(SDL_Texture * tex);

private:
	SDL_Texture * m_texture;
	SDL_Rect * m_destRect;
};
#endif // !SPRITECOMPONENT_H
