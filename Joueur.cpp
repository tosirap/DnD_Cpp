#include "Creature.hpp"
#include "Joueur.hpp"
#include "Obj.hpp"
#include <iostream>
#include <vector>
using namespace std;

Joueur::Joueur(string nom, int vie, int deg, int res,int x,int y,Carte *c):Creature('J'+nom,vie,deg,res,x,y,c),visionPortee(5),regard('d'){
  tailleSac =10;
  tailleEquipement=5;
}
Joueur::Joueur(int vie, int deg, int res, int x, int y,Carte *c):Creature("Jean",vie,deg,res,x,y,c),visionPortee(5),regard('d'){
  tailleSac =10;
  tailleEquipement=5;
};

char Joueur::getRegard(){
  return this->regard;
}
void Joueur::setRegard(char c){
  this->regard = c;
}

Obj* Joueur::getSac(int i){
  return this->sac[i];
}
void Joueur::afficheContenuSac(){
  for(int i(0);i<this->sac.size();++i){
    std::cout<<this->sac[i]->getNom()<<" ";
  }
}
void Joueur::addSac(Obj* obj){
  if(this->sac.size()<this->tailleSac){
    this->sac.push_back(obj);
    std::cout<<"Nouvel objet ajoute"<<std::endl;
  }
  else{
    std::cout<<"Sac plein"<<std::endl;
  }
}
void Joueur::removeSac(int i){
  this->sac.erase(sac.begin() + i);
}

Obj* Joueur::getEquipement(int i){
  return this->equipement[i];
}
void Joueur::addEquipement(Obj* obj){  //pour ajouter un elmnt dans equipement, il faut qu'il soit present dans le sac, et le retirer du sac
  if(this->equipement.size()<this->tailleEquipement){
    this->equipement.push_back(obj);
    std::cout<<"Nouvel objet ajoute"<<std::endl;
  }
  else{
    std::cout<<"Equipement plein"<<std::endl;
  }
}

void Joueur::removeEquipement(int i){  
  this->equipement.erase(sac.begin() + i);
}
void Joueur::afficheEquipement(){
  for(int i(0);i<this->equipement.size();++i){
    std::cout<<this->equipement[i]->getNom()<<" ";
  }
}
int Joueur::getVisionPortee(){
  return this->visionPortee;
}
void Joueur::setVisionPortee(int i){
  this->visionPortee=i;
}
//owerwrite
/*void Joueur::deplacementJoueur(){
  cout<<"Choississez une case ou aller b h g d"<<endl;
  string direction;
  bool ok = false;

  while(!ok){
    cout<<"Choississez une case ou aller b h g d"<<endl;
    cin>>direction;
    if(direction=="b"){
      if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())!=NULL){
        if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='.'||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='E'||this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getCreature()!=NULL){//combat
            this->combat(this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->getCreature(),this->getPosX()-1,this->getPosY());
            ok=true;
            break;
          }else{//pas de combat, deplacement ok
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX()-1,this->getPosY())->setCreature(this);
            this->setPosX(this->getPosX()-1);
            ok=true;
            break;
          }

        }
        else{
          cout<<"type de case inccorecte"<<endl;
        }

      }
      else{
        cout<<"case inexistante"<<endl;
      }
    }
    else if(direction =="h"){
      if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())!=NULL){
        if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='.'||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='E'||this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->getCreature()!=NULL){//combat
              
              ok=true;
              break;
          }else{//pas de combat, deplacement ok
            
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX()+1,this->getPosY())->setCreature(this);
            this->setPosX(this->getPosX()+1);
            ok=true;
            break;
          }

        }
        else{
          cout<<"type de case inccorecte"<<endl;
        }

      }
      else{
        cout<<"case inexistante"<<endl;
      }
      
    }else if(direction == "g"){
      if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)!=NULL){
        if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='.'||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='#'
          ||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='E'||this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getType()=='%'){
          if(this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->getCreature()!=NULL){//combat

          }else{//pas de combat, deplacement ok
            
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX(),this->getPosY()-1)->setCreature(this);
            this->setPosY(this->getPosY()-1);
            ok=true;
            break;
          }

        }
        else{
          cout<<"type de case inccorecte"<<endl;
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

          }else{//pas de combat, deplacement ok
            
            this->getCarte()->getCase(this->getPosX(),this->getPosY())->setCreature(NULL);
            this->getCarte()->getCase(this->getPosX(),this->getPosY()+1)->setCreature(this);
            this->setPosY(this->getPosY()+1);
            ok=true;
            break;
          }

        }
        else{
          cout<<"type de case inccorecte"<<endl;
        }

      }
      else{
        cout<<"case inexistante"<<endl;
      }
    
    }
    else{
      cout<<"direction inccorecte"<<endl;
    }
  }
}*/

Joueur::~Joueur(){std::cout<<"Destruction du joueur"<<endl;}

