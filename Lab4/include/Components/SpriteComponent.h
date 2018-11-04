#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <Components/Component.h>
#include <SDL_image.h>

class SpriteComponent : public Component
{
public:
	SpriteComponent(SDL_Texture *texture, int src_x, int src_y, int width, int height);
	SDL_Rect getSource() { return m_src; };
	SDL_Rect getDestination() { return m_dest; };
	SDL_Texture * getTexture() { return m_texture; };

private:
	SDL_Texture * m_texture;
	SDL_Rect m_src, m_dest;
	int m_w, m_h;
	int m_srcX, m_srcY;
};

#endif // !SPRITECOMPONENT_H
