#include "Case.hpp"
#include "Obj.hpp"
#include "Creature.hpp"
using namespace std;
Case::Case(int x, int y):coordX(x),coordY(y),creature(NULL){//null->nullptr ???
	this->type='.';
}
Case::Case(int x, int y, char c):coordX(x),coordY(y),type(c),creature(NULL){}
Case::Case():coordX(0),coordY(0),type('.'),creature(NULL){}
int Case::getCoordX(){
	return this->coordX;
}
void Case::setCoordX(int i){
	this->coordX=i;
}

int Case::getCoordY(){
	return this->coordY;
}
void Case::setCoordY(int i){
	this->coordY=i;
}
char Case::getType(){
	return this->type;
}
void Case::setType(char c){
	this->type=c;
}
Creature* Case::getCreature(){
	return this->creature;
}
void Case::setCreature(Creature *crea){
	this->creature=crea;
}
Obj* Case::getObj(){
	return this->obj;
}
void Case::setObj(Obj *objet){
	this->obj=objet;
}
bool Case::isOccupe(){
	if(this->creature==NULL && this->obj==NULL){
		return false;
	}
	else return true;
}
void Case::affichageCase(){ //priorite: creature/obj/type
	if(this->getCreature()!=NULL){
		cout<<this->getCreature()->getAffNom();
	}
	else if(this->getObj()!=NULL){
		cout <<this->getObj()->affichageObj();
	}
	else{
		cout<<this->type;
	}
}

Case::~Case(){std::cout<<"Destruction de la case"<<endl;}



