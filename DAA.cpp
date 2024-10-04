//
// Created by oslon on 12.05.2023.
//
#include <iostream>
using namespace std;

string PrintBin(unsigned int a){
    string out="";
    for (int i =0;i <16; i++){
        out=to_string(a&1)+out;
        a = a>>1;
    }

    return out;
}


int main(){
unsigned int a;
int k;
int n;
int selector;
string abin="";

cout<<"VVedite chislo a>0"<<endl;
cin>>a;
cout<<PrintBin(a)<<endl;


while (true)
{
    cout<<"Viberite funciu"<<endl;
    cout<<"1 - Sdvinut' na k shagov vlevo k>0"<<endl;
    cout<<"2 - Sdvinut' na n shagov vlevo n>0"<<endl;
    cin>>selector;
    cout<<endl;
            if (selector==1){
                cout<<"Vvedite k"<<endl;
                cin>>k;
                a=a<<k;
                cout<<a<<endl;
                abin=PrintBin(a);
                cout<<abin<<endl;
            }else if(selector==2){
                cout<<"Vvedite n"<<endl;
                cin>>n;
                a=a>>n;
                cout<<a<<endl;
                abin=PrintBin(a);
                cout<<abin<<endl;
            }else break;
cout<<endl;

}
return 0;
}