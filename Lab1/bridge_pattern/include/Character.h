#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
	Character() {};
	void Print() { std::cout << "Print Character" << std::endl; };

};

#endif // !CHARACTER_H

#ifndef HANDLETOCHARACTER_H
#define HANDLETOCHARACTER_H

class HandleToCharacter 
{
public:
	HandleToCharacter() : character(new Character()) {};
	Character* operator->() { return character; } // overloaded "->" operator
private:
	Character * character;
};

#endif // !HANDLETOCHARACTER_H
