#ifndef Joueur_h
#define Joueur_h
#include <string>
#include "Creature.hpp"
#include "Obj.hpp"
#include <vector>
using namespace std;
class Case;
class Joueur : public Creature{
private:
  int visionPortee;
  char regard; //b bas, h haut, g gauche, d droite  
  //créer une classe Obj "generique"
  vector<Obj*> equipement; //objet en cours d'utilisation, epee, armure, potion, etc
  vector<Obj*> sac ; //objet dans l'inventeur, qui ne sont pas utilisés
  int tailleSac;
  int tailleEquipement;
public:
  Joueur(string,int,int,int,int,int,Carte*);
  Joueur(int,int,int,int,int,Carte*);//on def nous meme le nom
  char getRegard();
  void setRegard(char);
  //Obj[] getAllSac(); //tt les items du sac
  Obj* getSac(int); //l'item en pos i
  void afficheContenuSac();
  void addSac(Obj*);
  void removeSac(int);
  //Obj[] getAllEquipent();//tt les items equipes
  Obj* getEquipement(int); //l'item en pos i
  void addEquipement(Obj*);
  void removeEquipement(int);
  void afficheEquipement();
  int getVisionPortee();
  void setVisionPortee(int);
  //void deplacementJoueur();
  //void deplacementBis(int);
  
  ~Joueur();
};

#endif
