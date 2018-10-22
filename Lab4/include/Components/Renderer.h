#ifndef RENDERER_H
#define RENDERER_H
#include <Components/Component.h>
#include <SDL.h>
#include <SDL_image.h>

class Renderer : public Component
{
public:
	void setTexture(std::string &path);
	SDL_Texture * getTexture();
private:
	SDL_Texture * m_texture = nullptr;
};

#endif // !RENDERER_H
