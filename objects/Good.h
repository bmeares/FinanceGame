#ifndef GOOD_H
#define GOOD_H 1

#include <iostream>
#include <string>
#include <vector>
#include "Service.h"

// #include "../includes.h"


using namespace std;

class Good{
  protected:
    unsigned long long value;
    string name;
    Service service;

  public:

    void buy();
    void sell(int);
    void improve(double e);

    friend ostream& operator<<(ostream&, Good&);

    void setValue(unsigned long long val){value = val;}
    unsigned long long getValue(){return value;}
    void setName(string name){this->name = name;}
    string getName(){return name;}
    void setService(Service srv){service = srv;}
    Service& getService(){return service;}

    Good();
    Good(int, string);
    ~Good();
};
#endif
