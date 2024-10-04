#include <iostream>
using namespace std;
int ConvertStringToInt(string str){
    int ln = str.length();
    int sum =0;
    for (int i =0; i<ln; i++){
        sum+=str[i];
    }
    return sum;
}
int main(){
 string lox;
 cin >>lox;
 cout<<ConvertStringToInt(lox);
}
