#include "Creature.hpp"
#include "Joueur.hpp"
#include "Carte.hpp"
#include "Obj.hpp"

int main(){
	bool fin=false;
	Carte carte("etage1bis.txt");
	carte.afficheGeneral();
	while(!fin){
		carte.deplacerAll();
		carte.afficheGeneral();
		/*if(carte.getFini()==true){
			fin=true;
		}*/
	}
	//carte.netoyageAll();
  return 0;
}
