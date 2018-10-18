#include "Armure.hpp"
#include "Obj.hpp"
#include <iostream>
#include <cstdio>

Armure::Armure(string nom):Obj(nom){
	srand (time(NULL));
  	int resistance = (rand()%10)+1;
}

Armure::Armure(string nom,int _resistance):Obj(nom){
  int resistance = _resistance;
}
int Armure::getResistance(){
	return this->resistance;
}

Armure::~Armure(){std::cout<<"Destruction de l'Armure"<<this->getNom()<<endl;}