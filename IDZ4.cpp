//11****11 - чтобы был гибридом mask= 11000011
//0*0**1*0 - чтобы был джип mask = 10100101
#include <iostream>
using namespace std;

int BinToDec(string s){
    int count = 1;
    int sum =0;
    for (int i=8; i>0;i--,count*=2){
        if(s[i-1]=='1'){
            sum+=count;
        }
    }
    return sum;
}

string PrintBin(unsigned int a,int index, int limit, int check){
    string out="";
    for (int i =index;i <limit; i++){
        out=to_string(a&check)+out;
        a = a>>1;
    }

    return out;
}

string Slice(string s, int point1 , int point2){
    string out="";
    for (int i = point1; i<point2;i++){
        out+=s[i];

    }
    return out;
}

int main(){
    int inp;
    string a, mn , dlc;
    cout<<"Vvedite desyaticnoe chislo"<<endl;
    cin>>inp;
    cout<<endl;
    a = PrintBin(inp,0,16,1);
    mn = Slice(a, 8, 16);
    dlc = Slice(a, 0,8);
    cout<<"Number in bin: "<<PrintBin(inp,0,16,1)<<endl;
    cout<<"First part: "<<dlc<<endl;
    cout<<"Second part: "<<mn<<endl;

    //cout<<BinToDec(mn)<<endl;

    cout<<endl;
    cout<<"Nomer Proizvod i modeli"<<endl;
    cout<<"DEC:"<<BinToDec(dlc)<<endl;
    cout<<"Bin:"<<dlc<<endl;

    inp = BinToDec(mn);
    cout<<endl;
    cout<<"Specifications"<<endl;
    cout<<"DEC:"<<BinToDec(mn)<<endl;
    cout<<"BIN:"<<mn<<endl;
    cout<<endl;
    if ((inp&3 | inp&64 | inp&128)==195){
        cout<<"It is gybrid"<<endl;
    }else if ((inp&4 | (inp&1) | (inp&32) | (inp&128))==4){
        cout<<"It's jeep"<<endl;
    }else cout<<"Kakaya to drugaya tachka"<<endl;

//    if ((inp&4 | (inp&1) | (inp&32) | (inp&128))==4){
//        cout<<"It's jeep"<<endl;
//    }else cout<<"It isn't jeep"<<endl;




}