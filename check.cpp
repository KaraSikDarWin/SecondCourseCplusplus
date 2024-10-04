#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

struct Date{
    char FB;
    string number;
    string SB;
    Date(char x, string y, string z):FB(x),number(y),SB(z){};
};

struct Elem{
    Date* data;
};

bool Check(string s){
    set <int> number {'0','1','2','3','4','5','6','7','8','9'};
    if ((s.length()==6) and number.count(s[1]) and number.count(s[2]) and number.count(s[3]) and ((s[0]>=65) and (s[0]<=90)) and ((s[4]>=65) and (s[4]<=90)) and ((s[5]>=65) and (s[5]<=90)) ) return 1;
    return 0;
}

bool DataLowX(Elem* est, string vst){//Нод-дата меньше x
    if(est->data->FB>vst[0]) return true;
    else if(est->data->number>vst) return true;
    else if(est->data->SB[0]>vst[4]) return true;
    else if(est->data->SB[1]>vst[5]) return true;
    return 0;
}


bool DataBigX(Elem* est, string vst){//Нод-дата больше x
    if(est->data->FB<vst[0]) return true;
    else if(est->data->number<vst) return true;
    else if(est->data->SB[0]<vst[4]) return true;
    else if(est->data->SB[1]<vst[5]) return true;
    return 0;
}

bool EXVELENT(Elem* est, string vst){//Нод-дата равно x
    if((est->data->FB==vst[0])and(est->data->number ==int (vst[1]+vst[2]+vst[3])) and (est->data->SB[0]==vst[4]) and (est->data->SB[1]==vst[5])) return true;
    return 0;
}

void rd(){ //Считывание данных из файла
    string b;
    int i=0;
    ifstream fin("text.txt");
    while(!fin.eof()){
        i++;
        fin>>b;
        if(Check(b))cout<<b<<endl ; else cout<<"v stroke problema"<<endl;

    }
}

int main(){
    rd();
    Elem* run = new Elem;


    return 0;
}
