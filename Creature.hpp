#ifndef Creature_h
#define Creature_h
#include "Carte.hpp"
#include <string>
#include <iostream>
using namespace std;
class Case;
class Joueur;
class Creature{
  
private:
  const string nom;
  Carte *carteCourante;
  int vie;
  int degats;
  int resistance;
  int posX;
  int posY;

public:
  Creature(string,int,int,int,int,int,Carte*);
  //attr
  string getNom();
  char getAffNom();
  int getVie();
  void setVie(int);
  int getDegats();
  void setDegats(int);
  int getResistance();
  void setResistance(int);
  //pos
  Carte* getCarte();
  void setCarte(Carte*);
  int getPosX();
  int getPosY();
  void setPosX(int);
  void setPosY(int);
  //action
  void affiche();
  void afficheNom();
  void deplacement();
  void deplacementJoueur();
  void combat(Creature*,int x,int y); //appelée si mouvement d'une creature sur le joueur et vice versa
  ~Creature(); 


};

#endif 
