#ifndef Case_h
#define Case_h
#include "Obj.hpp"
//#include "Creature.hpp"
class Creature;
class Case{

private:
	int coordX; //ligne
	int coordY; //colone
	char type; //cf Nomenclature.txt
	Creature *creature; //creature qui pourrait se trouver sur la case
	Obj *obj; //objet qui pourrait se trouver sur la case

public:
	Case();
	Case(int,int); //case vide .
	Case(int,int,char);
	int getCoordX();
	void setCoordX(int);
	int getCoordY();
	void setCoordY(int);
	char getType();
	void setType(char);
	Creature* getCreature();
	void setCreature(Creature*);
	Obj* getObj();
	void setObj(Obj*);
	bool isOccupe(); //true si obj ou crea dessus, false sinon
	void affichageCase();

	~Case();
};



#endif