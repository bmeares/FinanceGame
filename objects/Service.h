#ifndef SERVICE_H
#define SERVICE_H 1

#include <iostream>
#include <string>
//#include "Good.h"

// #include "../includes.h"


using namespace std;

class Service{
  private:
    string name;
    int cost;
    double gain;

  public:

    void setName(string name){this->name = name;}
    void setCost(int cost){this->cost = cost;}

    friend ostream& operator<<(ostream&, const Service&);

    Service();
    Service(int, string);
    ~Service();
};
#endif
