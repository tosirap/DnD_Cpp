#ifndef Obj_h
#define Obj_h
#include <string>
#include <time.h>
#include <stdlib.h>  

using namespace std;
class Obj{
private:
  bool equiper;
  const string nom;
  
  //bool utilise; //0 non, 1 dans le sac sinon detruit apres utilisation

 public:
  Obj(string);
  string getNom();
  char affichageObj();
  bool estEquiper();
  void setEquiper(bool);
  //bool getUtilise();
  //void setUtilise(bool);
  ~Obj();
};


#endif
