#ifndef Armure_h
#define Armure_h
#include "Obj.hpp"

using namespace std;

class Armure: public Obj{
  private:
    int resistance;
    //bool equiper;
  public:
    Armure(string);
    Armure(string, int );
    int getResistance();
    //bool estEquiper();
    ~Armure();
};

#endif
      