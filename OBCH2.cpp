//
// Created by oslon on 19.05.2023.
//
#include <iostream> //Поток ввода и вывода, чтобы язык мог вводить и выводить
#include <cstdlib>
using namespace std;

int PrintBin(unsigned int a){
    string out="";
    for (int i =0;i <16; i++){
        out=to_string(a&1)+out;
        a = a>>1;
    }
    cout<<out<<endl;
    return 0;
}

int main(){
    unsigned int a;
    int count;
    cout<<"Vvedite chislo a>0"<<endl;
    cin>>a;
    PrintBin(a);
    for (int i = 0;i<16; i++){
        if (a&1){
            count+=1;
            a=a>>1;
        } else a=a>>1;

    }
    cout<<count<<endl;

    return 0;
}