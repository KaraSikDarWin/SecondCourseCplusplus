#include <iostream>
using namespace std;

int PrintBin(unsigned int a, unsigned int n){
    string out="";
    for (int i =0;i <n; i++){
        out=to_string(a&1)+out;
        a = a>>1;
    }
    cout<<out<<endl;
    return 0;
}


int main(){

    unsigned short int x;
    unsigned short int n;
    unsigned short int mask;
    unsigned short int out;



    n = sizeof(x)*8;
    cout<<"Enter x"<<endl;
    cin>>x;
    cout<<"X in bin: ";
    PrintBin(x,n);
    for ( int i=1, c = 1; i<=n; i+=2, c*=4){
        mask+=c;

    }

    cout<<endl;

    cout<<"Res in dec: "<<mask<<endl;
    cout<<"Res in bin: ";
    PrintBin(mask,n);

    cout<<endl;

    out=x&mask;
    cout<<"Output in dec: "<<out<<endl;
    cout<<"Output in bin: ";
    PrintBin(out,n);

    return 0;
}

