#ifndef SERVICE_H
#define SERVICE_H 1

#include <iostream>
#include <string>
//#include "Good.h"

// #include "../includes.h"


using namespace std;

class Service{
  private:
    int cost;
    string name;
    double effect;

  public:

    void buy();

    void setName(string name){this->name = name;}
    void setCost(int cost){this->cost = cost;}
    string getName(){return name;}
    void setEffect(double e){this->effect = e;}
    double getEffect(){return effect;}

    friend ostream& operator<<(ostream&, const Service&);
    Service& operator=(const Service& rhs);

    Service();
    Service(int, string, double);
    ~Service();
};
#endif
