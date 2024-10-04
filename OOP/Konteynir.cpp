#include <iostream>
#include "Dormetery.h"



int main() {
   Dormetery Doom;
   Doom.AddRoom(52, {"Kirill","Danil"});
   Doom.AddRoom(25, {"Kirill","Vadim"});
   Doom.AddRoom(92, {});
  Doom.AddInFreeRoom("Miha");


   Doom.Print();

    cout<<Doom.FindFreeRoom();
    return 0;
}