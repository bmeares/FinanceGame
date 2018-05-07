#include "auction.h"

using namespace std;

Good Auction::phone, Auction::car, Auction::bike, Auction::game,
  Auction::food, Auction::clothing;
vector<Good> Auction::GOODS = {phone, car, bike, game, food, clothing};

void Auction::auction(){
  bool runagain = true;
  int choice = -1;

  while(runagain){

    runagain = false;
    Canvas::clearScreen();
    Canvas::stats();
    cout << "\n   AUCTION:\n\n";

    if(Player::getInventory().size() < 6){
      printOptions();

      cout << "  Choice: ";
      cin >> choice;
      cout << "\n";

      if(choice != 0){
        if(!(choice > 0 && choice < 7)){
          cout << "Error: please choose a valid item." << endl;
          cout << "Press any key to choose return." << endl;
          runagain = true;
          // Not sure why, but I need two ignores for this to work
          cin.ignore();
          cin.ignore();
        }
        else{
          GOODS.at(choice - 1).buy();
        }
      }
    }
    else {
      cout << "   Your inventory is full.\n" << endl;
      cout << "   Press any key to return." << endl;
      cin.ignore();
    }
    cin.clear();

  }
}

void Auction::printOptions(){
  srand(time(NULL));
  int randMax = 6;
  int seed;

  int maxPrice = Player::getBalance();

  cout << "   Choose an item from below to purchase, or press n to return\n"
    << endl;
  for(int i = 0; i < 6; i++){
    seed = rand() % randMax;
    GOODS.at(i).setValue(rand() % maxPrice);
    GOODS.at(i).setName(itemName(seed));
    cout << " " << i + 1 << ".\n" << GOODS.at(i) << endl;
  }
}

string Auction::itemName(int num){
  string first, second, last;
  int randMax = 19;
  vector<string> firsts, seconds, lasts;
  stringstream fullName;


    firsts =  {"LG", "Apple", "Google", "Samsung", "Sony", "Nokia", "Motorola",
              "2018", "2009", "1996", "1965", "1999", "2015", "2001",
              "Speedy", "Lightning", "Super Duper", "Ultra", "Mega",
              "All-natural"};
    seconds = {"G5", "iPhone", "Pixel", "Galaxy", "Xperia", "3310", "Droid",
              "BMW", "Ford", "Toyota", "Chevrolet", "GMC", "Tesla", "Nissan",
              "Turbo", "Nintendo", "Lightsaber", "Time machine", "Toothpaste",
              "Hershey's"};
    lasts =   {"Pro", "Compact", "S9", "XL", "C", "X", "mini",
              "X5", "F150", "Tacoma", "C10", "Sonoma", "Model S", "Altima",
              "For Elders", "For Women", "For Men", "For Children",
              "Uncensored Edition", "Xtreme Editiion"};


  first = firsts.at(rand() % randMax);
  second = seconds.at(rand() % randMax);
  last = lasts.at(rand() % randMax);

   fullName << first << " " << second << " " << last;
   return fullName.str();
}
