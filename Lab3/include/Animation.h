#ifndef ANIMATION_H
#define ANIMATION_H

class Animation
{
private:
	class State* m_current; // Order: m_current prior to setCurrent
	class State* m_previous;
public:
	Animation();
	~Animation();
	void setCurrent(State* s);
	void setPrevious(State* s);
	State* getCurrent();
	State* getPrevious();

	void idle();
	void jumping();
	void climbing();
};

#endif // !ANIMATION_H
