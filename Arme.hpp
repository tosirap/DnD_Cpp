#ifndef Arme_h
#define Arme_h
#include "Obj.hpp"

using namespace std;

class Arme : public Obj{
  private:
    int degats;
  public:
    Arme(string);
    Arme(string, int);
    int getDegats();
    ~Arme();
};

#endif
