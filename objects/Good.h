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
    int value;
    string name;
    vector<Service> services;

  public:

    virtual void buy();
    virtual void sell(int);

    friend ostream& operator<<(ostream&, const Good&);

    void setValue(int val){value = val;}
    int getValue(){return value;}
    void setName(string name){this->name = name;}
    string getName(){return name;}

    Good();
    Good(int, string);
    ~Good();
};
#endif
