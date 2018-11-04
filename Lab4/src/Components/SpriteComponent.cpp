#include <Components/SpriteComponent.h>

SpriteComponent::SpriteComponent(SDL_Texture * texture, int src_x, int src_y, int width, int height)
{
	m_id = 3;
	m_w = width;
	m_h = height;
	m_srcX = src_x;
	m_srcY = src_y;
	m_texture = texture;

	m_src.x = src_x;
	m_src.y = src_y;
	m_src.h = m_h;
	m_src.w = m_w;

	m_dest.x = 400;
	m_dest.y = 0;
	m_dest.h = m_h;
	m_dest.w = m_w;
}
