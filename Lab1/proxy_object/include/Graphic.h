#ifndef IGRAPHIC_H
#define IGRAPHIC_H

// common interface (subject) definition
class IGraphic
{
public:
	virtual void Draw() = 0; // pure virtual
};

#endif // !IGRAPHIC_H


#ifndef GRAPHIC_H
#define GRAPHIC_H

// real subject definition

class Graphic : public IGraphic
{
public:
	Graphic() {};
	~Graphic() {};
	void Draw();
};

#endif // !GRAPHIC_H

