#ifndef Carte_h
#define Carte_h
#include "Case.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Case;
class Carte{
private:
	bool fin;
	string nom;
	int hauteur;
	int largeur;
	//Case **tabCase;
	vector<vector<Case*> > tab; 
public:
	Carte(int,int);
	Carte(string);
	string getNom();
	bool getFini();
	void setFini(bool);
	int getHauteur();
	int getLargeur();
	Case* getCase(int , int );
	void afficheGeneral();
	void deplacerAll();
	void netoyageAll();
	~Carte();
};

#endif