#include <iostream> //Поток ввода и вывода, чтобы язык мог вводить и выводить
using namespace std;

long long int Fact(short lim){
    long long int s=1;
    for (int i =1; i<=lim; i++){
        s*=i;

    }
    return s;
}

long long int FactWhile(short lim){
    long long int s=1;
    int i =1;
    while (i <=lim){
      s*=i;
      i++;
    }
    return s;
}

long long int FactUntile(short lim){
    long long int s=1;
    int i =1;
    do{
        s*=i;
        i++;
    }while (i<=lim);
    return s;
}
long long int FactRec(short lim){

    if (lim ==1) return 1;
    if (lim !=1){
        return lim* FactRec((lim-1));
    }

}

int main() {
    int x;

    cin>>x;
    cout<< Fact(x) <<endl;
    cout<< FactWhile(x) <<endl;
    cout<< FactUntile(x) <<endl;
    cout<< FactRec(x) <<endl;

    return 0;
}
//вычислить факториал всеми 3 циклами и рекурсия