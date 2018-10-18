#include "Obj.hpp"
#include <iostream>
using namespace std;

Obj::Obj(string name):nom(name),equiper(false){}

string Obj::getNom(){
	return this->nom;
}
char Obj::affichageObj(){
	return this->nom[0];
}
bool Obj::estEquiper(){
		return this->equiper;
}
void Obj::setEquiper(bool b){
	this->equiper=b;
}

Obj::~Obj(){std::cout<<"Destruction de "<<this->getNom()<<endl;}