//****11 - женщина спортсмен
//1110*1 - мужчина, живущий на кампусе <20, холостой, дети 57 - 59
//max(32)
#include <iostream>
using namespace std;


int PrintBin(unsigned int a){
    string out="";
    for (int i =0;i <6; i++){
        out=to_string(a&1)+out;
        a = a>>1;
    }
    cout<<out<<endl;
    return 0;
}

int Func1(int s){
    int a = s&2 | (s&1);
    if (a==2) {
        cout<<"YES, She is sport woman"<<endl;
    }

}

int Func2(int s){
    int a = (s&56 | s&1 |2);
    if (a==59){
        cout<<"YES, He's man with child"<<endl;

    } else cout<<"Its nobody"<<endl;
}

int main(){
    cout<<"Vvedite desyatichnoe chislo <64"<<endl;
    int s;
    cin>>s;
    PrintBin(s);
    Func1(s);
    Func2(s);



}
