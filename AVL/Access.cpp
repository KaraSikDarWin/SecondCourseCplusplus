//
// Created by oslon on 03.11.2023.
//
#include <iostream>
#include <fstream>
#include "Trees.h"
using namespace std;
bool Check(string s){
    if ((s.length()==6) and (100<=stoi(s.substr(1,3)) and 999>stoi(s.substr(1,3))  ) and ((s[0]>=65) and (s[0]<=90)) and ((s[4]>=65) and (s[4]<=90)) and ((s[5]>=65) and (s[5]<=90)) ) return 1;
    return 0;
}//

void Read(Elem* &root,bool &h){ //Считывание данных из файла
    string b;
    int i=0;
    ifstream fin("lol.txt");
    while(!fin.eof()){
        i++;
        fin>>b;
        if (Check(b)) Search(b,i,root,h); else cout<<"Incorrect string number "<<i<<" in the file"<<endl;
    }
}//
