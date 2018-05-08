#include "Menu.h"

bool Menu::startGame(){
  Canvas::clearScreen();
  cout << "Welcome to Money Game. Press any key to begin" << endl;
  cin.ignore();
  return true;
}

void Menu::printTable(){

  cout << "\n Choose what you'd like to do from the options below.\n\n";

  for(int i = 0; i < 55; i++){
    cout << "_";
  }
  cout << "\n|" << setw(18) << "|" << setw(18) << "|" << setw(18) << "|" << endl;
  cout << "|" << centered("Inventory (i)", 17) << "|";
  cout << centered("Auction (a)", 17) << "|";
  cout << centered("Sell  (s)", 17) << "|";
  cout << "\n|" << setw(18) << "|" << setw(18) << "|" << setw(18) << "|" << endl;

  for(int i = 0; i < 55; i++){
    cout << "\u2014";
  }

  cout << "\n|" << setw(18) << "|" << setw(18) << "|" << setw(18) << "|" << endl;
  cout << "|" << centered("Improve (m)", 17) << "|";
  cout << centered("Invest  (n)", 17) << "|";
  cout << centered("Quit  (q)", 17) << "|";
  cout << "\n|" << setw(18) << "|" << setw(18) << "|" << setw(18) << "|" << endl;

  for(int i = 0; i < 55; i++){
    cout << "\u0305";
  }
  cout << "\n Choice: ";
}

string Menu::centered(string original, int targetSize){
    assert( targetSize >= 0 );
    int padding = targetSize - static_cast<int>( original.size() );
    return padding > 0
        ? string( padding / 2, ' ' )
            + original
            + string(padding / 2, ' ' )
        : original;
}


Menu::Menu(){}
Menu::~Menu(){}
