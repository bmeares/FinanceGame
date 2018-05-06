#include "Service.h"
#include "Player.h"

std::ostream& operator << (ostream& out, const Service& service) {
 return out << "   Service:     " << service.name << "\n   "
            << "Value:    $" << service.value << endl;
}

Service::Service(){}
Service::Service(int val, string name){
  this->value = val;
  this->name = name;
}
Service::~Service(){}
