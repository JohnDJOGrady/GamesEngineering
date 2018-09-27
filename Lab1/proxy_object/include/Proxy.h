#ifndef GRAPHIC_PROXY_H
#define GRAPHIC_PROXY_H

/// <summary>
/// Proxy Definition
/// </summary>
#include "Graphic.h"

class GraphicProxy : public IGraphic
{
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw();

private:
	Graphic* graphic;
	Graphic* getInstance();
};

#endif // !GRAPHIC_PROXY_H
