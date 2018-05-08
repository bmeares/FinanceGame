#include "auction.h"

using namespace std;

Good Auction::phone, Auction::car, Auction::bike, Auction::game,
  Auction::food, Auction::clothing;
vector<Good> Auction::GOODS = {phone, car, bike, game, food, clothing};

void Auction::auction(){
  bool runagain = true;
  int choice = -1;

  Canvas::clearScreen();
  Canvas::stats();
  cout << "\n   AUCTION:\n\n";

  if(Player::getBalance() > 0)
    runagain = true;
  else{
    cout << "You need money to buy something." << endl;
    cout << "Press any key to return." << endl;
    cin.clear();
    cin.ignore();
    cin.ignore();
    runagain = false;
  }

  while(runagain){

    runagain = false;


    if(Player::getInventory().size() < 6){
      printOptions();

      cout << "  Choice: ";
      cin >> choice;
      cout << "\n";

      if(choice != 0){
        if(!(choice > 0 && choice < 7)){
          cout << "Error: please choose a valid item." << endl;
          cout << "Press any key to run again." << endl;
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

  //uint64_t maxPrice = Player::getBalance();

  cout << "   Choose an item from below to purchase, or press n to return\n"
    << endl;
  for(int i = 0; i < 6; i++){
    seed = rand() % randMax;
    //cout << "TEST: unround: " << (123456789) << endl;
    //cout << "TEST: round: $" << Canvas::FormatWithCommas(roundPrice()) << endl;
    GOODS.at(i).setValue(roundPrice());
    GOODS.at(i).setName(itemName(seed));
    cout << " " << i + 1 << ".\n" << GOODS.at(i) << endl;
  }
}

uint64_t Auction::roundPrice(){
  int numDigits = Player::numDigits();

  uint64_t balance = Player::getBalance();
  uint64_t randPrice = Canvas::randomLL(1, balance);
  //int firstThreeBalance = Canvas::randomLL(1, 9);

  if(numDigits > 3){
    randPrice = Canvas::randomLL(1, Player::firstThreeBalance());
    for(uint i = 0; i < Canvas::randomLL(1, numDigits - 3); i++){
      randPrice *= 10;
    }
  }

  // cap randPrice to maxVal
  uint64_t maxVal = 1000000000000000;
  if(randPrice > maxVal)
    randPrice = maxVal;

  return randPrice;
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
