#ifndef SERVICE_H
#define SERVICE_H 1

#include <iostream>
#include <string>
#include "Good.h"

// #include "../includes.h"


using namespace std;

class Service : public Good{
  private:

  public:

    friend ostream& operator<<(ostream&, const Service&);

    Service();
    Service(int, string);
    ~Service();
};
#endif
