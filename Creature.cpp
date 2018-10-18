#include <iostream>
#include <map>
#include "Creature.hpp"
using namespace std;
Creature::Creature(string nom, int hp,int dmg, int res,int x, int y, Carte *carte):nom(nom),vie(hp),degats(dmg),resistance(res),posX(x),posY(y),carteCourante(carte){}

string Creature::getNom(){
  return this->nom;
}
char Creature::getAffNom(){//recupere le 1er char du nom de la creature pour l'affichage, ex:Gobelin -> G
	if(this->nom.empty()/*|| this->nom[0]==""*/){
		return '?';
	}
	else{
		return this->nom[0];
	} 	
}
int Creature::getVie(){
  return this->vie;
}
void Creature::setVie(int hp){
  this->vie=hp;
}
int Creature::getDegats(){
  return this->degats;
}
void Creature::setDegats(int deg){
  this->degats=deg;
}
int Creature::getResistance(){
  return this->resistance;
}
void Creature::setResistance(int res){
  this->resistance=res;
}

Carte* Creature::getCarte(){
	return this->carteCourante;
}
void Creature::setCarte(Carte *c){
	this->carteCourante=c;
}
int Creature::getPosX(){
	return this->posX;
}
int Creature::getPosY(){
	return this->posY;
}
void Creature::setPosX(int x){
	this->posX=x;
}
void Creature::setPosY(int y){
	this->posY=y;
}
void Creature::affiche(){ //creature inconnue
  std::cout<<" ? ";
}
void Creature::afficheNom(){ //creature inconnue
  std::cout<<" "<<this->getAffNom()<<" ";
}

void Creature::deplacement(){
	if(this->getAffNom()=='G'||this->getAffNom()=='T'/*||this->getAffNom()=='D'*/){
		//le demon ne bouge pas, boss de fin
    //aleatoire
    vector <char> choix(0);
    if(this->getPosX()<1 ||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())!=NULL){//h
       if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='.'||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='E'||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getCreature()==NULL){
              choix.push_back('h');
          }
      } 
    }

    if(this->getPosX()>=this->getCarte()->getHauteur()-1 ||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())!=NULL){//b
      if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='.'||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='E'||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='%'){
        if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getCreature()==NULL){
              choix.push_back('b');
        }
      } 
    }
    if(this->getPosY()<1 ||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)!=NULL){//g
       if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='.'||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='E'||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getCreature()==NULL){
              choix.push_back('g');
          }
      } 
    }
     if(this->getPosY()>=this->getCarte()->getLargeur()-1 ||this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)!=NULL){//d
       if(this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='.'||this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='E'||this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getCreature()==NULL){
              choix.push_back('d');
          }
      } 
    }
    srand (time(NULL));
    int taille = choix.size();
    char c;
    if(taille>0){
      int indice =(rand() % taille);
      c= choix[indice];
      if(c=='h'){
        this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
        this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->setCreature(this);
        this->setPosX(this->getPosX()-1);
      }
      else if(c=='b'){
        this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
        this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->setCreature(this);
        this->setPosX(this->getPosX()+1);
      }
      else if(c=='g'){
        this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
        this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->setCreature(this);
        this->setPosY(this->getPosY()-1);
      }
      else if(c=='d'){
        this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
        this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->setCreature(this);
        this->setPosY(this->getPosY()+1);
      }
  	}
  }
	else if(this->getAffNom()=='J'){
		this->deplacementJoueur();
	}
}



void Creature::deplacementJoueur(){
  string direction;
  bool ok = false;
  //int test =0;

  while(!ok){
    //cout<<"ok:"<<ok<<endl;
    cout<<"Choississez une case ou aller b, h, g, d, ou info"<<endl;
    cin>>direction;
    if(direction=="info"){//info
      cout<<"vie: "<<this->getVie()<<", degats: "<<this->getDegats()<<", resistance: "<<this->getResistance()<<endl;
    }
    /*if(direction=="ramasser"){//ramasser
      if(this->getCarte()->getCase(this->getPosX(),this->getPosY())->getObj()!=NULL){

      }
      else{
        cout<<"il n'y a rien a ramasser!"<<endl;
      }
    }*/
  //deplacement
    if(direction=="h"){
      if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())!=NULL){
        if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='.'||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='E'||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getCreature()!=NULL){//combat
            this->combat(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getCreature(),this->getPosX()-1,this->getPosY());
            ok=true;
            
          }else{//pas de combat, deplacement ok
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->setCreature(this);
            this->setPosX(this->getPosX()-1);
            ok=true;
          
          }

        }
        else{
          cout<<"type de case incorecte"<<endl;
        }

      }
      else{
        cout<<"case inexistante"<<endl;
      }
    }
    else if(direction =="b"){
      if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())!=NULL){
        if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='.'||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='E'||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getCreature()!=NULL){//combat
            this->combat(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getCreature(),this->getPosX()+1,this->getPosY());
            ok=true;
            
          }else{//pas de combat, deplacement ok
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->setCreature(this);
            this->setPosX(this->getPosX()+1);
            //cout<<"yess"<<endl;
            ok=true;
            /*test=1;
           cout<<"nooooo"<<endl;*/
          }

        }
        else{
          cout<<"type de case incorecte"<<endl;
        }

      }
      else{
        cout<<"case inexistante"<<endl;
      }
    }  
    else if(direction == "g"){
      if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)!=NULL){
        if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='.'||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='E'||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getCreature()!=NULL){//combat
            this->combat(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getCreature(),this->getPosX(),this->getPosY()-1);
            ok=true;
          }else{//pas de combat, deplacement ok
            
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->setCreature(this);
            this->setPosY(this->getPosY()-1);
            ok=true;
         
          }
        }
        else{
          cout<<"type de case incorecte"<<endl;
        }
      }
      else{
        cout<<"case inexistante"<<endl;
      } 
    }else if(direction=="d"){
       if(this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)!=NULL){
        if(this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='.'||this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='E'||this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getCreature()!=NULL){//combat
            this->combat(this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->getCreature(),this->getPosX(),this->getPosY()+1);
            ok=true;
          }else{//pas de combat, deplacement ok
            
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->setCreature(this);
            this->setPosY(this->getPosY()+1);
            ok=true;
            
          }
        }
        else{
          cout<<"type de case incorecte"<<endl;
        }
      }
      else{
        cout<<"case inexistante"<<endl;
      }
    }
    if(direction!="b"&&direction!="h"&&direction!="g"&&direction!="d"&&direction!="info"){
      cout<<"direction incorecte"<<endl;;
    }
  }
   /*cout<<"oooook:"<<ok<<endl;
   ok=true;
    cout<<"okkkkk:"<<ok<<endl;*/
ok=true;
}


void Creature::combat(Creature *ennemi, int x, int y){
	if(ennemi==NULL){//pas de combat, simple deplacement

        this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
        this->getCarte()->getCase(x,y)->setCreature(this);
        this->setPosX(x);
		this->setPosY(y);
	}
	else{//vrai combat
		ennemi->setVie(ennemi->getVie()-this->getDegats());
		this->setVie(this->getVie()-ennemi->getResistance());
		if(ennemi->getVie()<=0){
      if(ennemi->getAffNom()=='J'){
        ennemi->getCarte()->setFini(true);
      }
			cout<<"Mort au combat: "<<ennemi->getNom()<<endl;
      ennemi->getCarte()->getCase(ennemi->getPosX(),ennemi->getPosY())->setCreature(NULL);
      ennemi->~Creature();//delete

		}
		if(this->getVie()<=0){
       if(ennemi->getAffNom()=='J'){
        ennemi->getCarte()->setFini(true);
      }
			cout<<"Mort au combat: "<<this->getNom()<<endl;
      this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
      this->~Creature();
		}

		

	}
	//TO DO
}
Creature::~Creature(){std::cout<<"Destruction de la creature"<<endl;}