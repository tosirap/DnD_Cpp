#ifndef Potion_h
#define Potion_h
#include "Obj.hpp"
#include <string>
#include <stdlib.h>  

class Potion : public Obj{
private:
	int vie;
	int resistance;
	int degats;

public:
	Potion(string, int, int, int);
	Potion(string);
	int getVie();
	int getResistance();
	int getDegats();
	~Potion();
};




#endif