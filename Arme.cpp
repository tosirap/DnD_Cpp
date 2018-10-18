#include "Arme.hpp"
#include "Obj.hpp"
#include <iostream>
#include <cstdio>


Arme::Arme(string nom):Obj(nom){
	srand (time(NULL));
  int degats = rand()%10;
}

Arme::Arme(string nom, int _degats):Obj(nom){
  int degats = _degats;
}
int Arme::getDegats(){
	return this->degats;
}