#include "Trees.h"
#include "Access.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(){
    Elem* root= nullptr;
    bool h =0;
    Read(root,h);
    Search("A225BC",1,root,h);
    Search("A220BC",1,root,h);
    Search("A233BC",1,root,h);
    Search("A246BC",1,root,h);
    Search("A254BC",1,root,h);
    deletel("A233BC",1,root,h);
    Print(root,20);
    //PreOrder(root);

    return 0;
}