#include "Potion.hpp"
#include "Obj.hpp"
#include <iostream>
#include <stdlib.h>     
#include <time.h>
//using namespace std;
Potion::Potion(string nom,int life, int res,int deg):Obj(nom),vie(life),resistance(res),degats(deg){}
Potion::Potion(string nom):Obj(nom){
	srand (time(NULL));
	if(nom=="PotPvPlus"){
		this->vie=15;
	}
	else if(nom=="PotPvMyst"){
		this->vie= (rand() % 30)-15;  //ajoute-retire jusqu'a 15 pv
	}
	else if(nom=="PotDegPlus"){
		this->degats=7;
	}
	else if(nom=="PotDegMyst"){
		this->degats= (rand() % 14)-7;  //ajoute-retire jusqu'a 15 pts de degats
	}
	else if(nom=="MasterPot"){
		this->vie=15;
		this->degats=10;
		this->resistance=5;
	}


	else{
		this->vie= (rand() % 15)-5;
		this->degats= (rand() % 15)-7; 
		this->resistance=(rand() % 7)-3;
	}
}

int Potion::getVie(){
	return this->vie;
}
int Potion::getResistance(){
	return this->resistance;
}
int Potion::getDegats(){
	return this->degats;
}

Potion::~Potion(){std::cout<<"Destruction de la potion"<<std::endl;}

