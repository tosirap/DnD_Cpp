#include "Carte.hpp"
#include "Case.hpp"
#include "Joueur.hpp"
#include "Creature.hpp"
#include "Obj.hpp"
#include "Arme.hpp"
#include "Armure.hpp"
#include "Potion.hpp"
#include <iostream>
#include <fstream>
using namespace std;

string Carte::getNom(){
		return this->nom;
}
bool Carte::getFini(){
	return this->fin;
}
void Carte::setFini(bool b){
	this->fin=b;
}
int Carte::getHauteur(){
		return this->hauteur;
}
int Carte::getLargeur(){
		return this->largeur;
}
Case* Carte::getCase(int x, int y){
		if(x>=this->largeur || y >= this->hauteur){
			return NULL;
	}
	else{
		return this->tab[x][y];
	}
}

Carte::Carte(int h, int l):hauteur(h),largeur(l){
	
}
Carte::Carte(string s){
	//try{
		ifstream fichier(s.c_str(), ios::in); //s:chemin absolu, ios::in: mode d'ouverture,c_str() pour transformer en *char	
		if(fichier){  // si l'ouverture a réussi
            // instructions
        	//lire les caractere du fichier et en déduire la map
        	bool fin=false;
        	string ligne; //chaque ligne
        	char tmp;	//chaque caractere
        	getline(fichier,ligne);
        	string haut= ligne.substr(0, ligne.find(" ")); //recupere les infos de la 1ere ligne hauteur _ largeur
        	
        	string larg= ligne.substr(ligne.find(" "));
        	this->hauteur=atoi(haut.c_str());
        	this->largeur=atoi(larg.c_str());
        	cout<<"largeur:"<<this->largeur<<"hauteur: "<<this->hauteur<<endl;
        	this->tab.resize(this->hauteur);
        	for(int i=0;i<this->hauteur;i++){
        		this->tab.at(i).resize(this->largeur);

        	}
			for(int i=0;i<(this->hauteur);i++){//chaque ligne
				getline(fichier,ligne);
				for (int j = 0; j < (this->largeur); ++j){//chaque caractere
					tmp=ligne[j];
					if(tmp==' '){
						this->tab[i][j]=NULL;
						break;
					}

					Case *myCase= new Case(i,j);
					this->tab[i][j]=(myCase);
					//si tmp = objet alors creer l'objet et type forcement case vide '.', sinon type = tmp
					if(tmp=='-'||tmp=='|'||tmp=='#'||tmp=='.'||tmp=='E'||tmp=='%'){
						this->tab.at(i).at(j)->setType(tmp);
					}
					else if(tmp=='J'||tmp=='C'||tmp=='P'||tmp=='o'||tmp=='A'||tmp=='a'||tmp=='T'||tmp=='G'||tmp=='D'||tmp=='p'){
						this->tab.at(i).at(j)->setType('.');
						switch(tmp){
							case 'J':{ Joueur *joueur = new Joueur(25,10,5,i,j,this);
									//this->tabCase[i][j].setCreature(joueur);
									this->tab.at(i).at(j)->setCreature(joueur);
									break;
								}
							case 'T': { Creature *creature = new Creature("Troll",10,7,3,i,j,this);
									//this->tabCase[i][j].setCreature(creature);
									this->tab.at(i).at(j)->setCreature(creature);
									break;
								}
							case 'G': { Creature *creature = new Creature("Gobelin",5,3,1,i,j,this);
									//this->tabCase[i][j].setCreature(creature);
									this->tab.at(i).at(j)->setCreature(creature);
									break;
								}
							case 'D': { Creature *creature = new Creature("Demon Gorgoth de Morgoth",20,10,5,i,j,this);
									//this->tabCase[i][j].setCreature(creature);
									this->tab.at(i).at(j)->setCreature(creature);
									break;
								}
							//case 'P':  //dispo dans le prochain DLC
							case 'a': { Armure *armure = new Armure("armure");
									//this->tabCase[i][j].setObj(armure);
									this->tab.at(i).at(j)->setObj(armure);
									break;
								}
							case 'A' :{	Arme *arme = new Arme ("arme");
									//this->tabCase[i][j].setObj(arme);
									this->tab.at(i).at(j)->setObj(arme);
									break;
							}
							case 'p' :{	Potion *potion = new Potion ("potionAlea");
									//this->tabCase[i][j].setObj(potion);
									this->tab.at(i).at(j)->setObj(potion);
									break;
							}
						}
					}
					else{
						//this->tabCase[i][j].setType('?');
						this->tab.at(i).at(j)->setType('?');
					}
					//cout << tmp;
				}
				//cout << endl;
			}
            fichier.close();  // on ferme le fichier
        }
        else{
        	cerr << "Impossible d'ouvrir le fichier !" << endl;
     	}
	/*}
	catch(const std::exception& e){
		std::cout<<"exception, pb ouverture fichier"<<e<<std::endl;
	}*/

}
void Carte::afficheGeneral(){//affiche la carte entiere, si creature sur case, affiche creature, sinon affiche le type de la
	for(int i=0;i<this->tab.size();i++){
		//cout<<endl;
		for(int j=0;j<this->tab[i].size();j++){
			if(this->tab[i][j]!=NULL){
				this->tab[i][j]->affichageCase();
			}
		}
		cout<<endl;
	}
}

void Carte::deplacerAll(){
	for(int i=0;i<this->hauteur;i++){
		for(int j=0;j<this->largeur;j++){
			if(this->tab[i][j]!=NULL&&this->tab[i][j]->getCreature()!=NULL){
				this->tab[i][j]->getCreature()->deplacement();
			}
		}
	}
}

void Carte::netoyageAll(){
	for(int i=0;i<this->hauteur;i++){
		for(int j=0;j<this->largeur;j++){
			if(this->getCase(i,j)->getObj()!=NULL){
				this->getCase(i,j)->getObj()->~Obj();
			}
			if(this->getCase(i,j)->getCreature()!=NULL){
				this->getCase(i,j)->getCreature()->~Creature();
			}
			this->getCase(i,j)->~Case();
		}
	}
	this->~Carte();
}

Carte::~Carte(){std::cout<<"Destruction de la carte"<<endl;}