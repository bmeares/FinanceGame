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
    uint64_t value;
    string name;
    Service service;
    //bool invested;

  public:

    void buy();
    void sell(int);
    void improve(double e);

    friend ostream& operator<<(ostream&, Good&);

    void setValue(uint64_t val){value = val;}
    uint64_t getValue(){return value;}
    void setName(string name){this->name = name;}
    string getName(){return name;}
    void setService(Service srv){service = srv;}
    Service& getService(){return service;}

    static bool hasImprovement(int);

    Good();
    Good(uint64_t, string);
    ~Good();
};
#endif
