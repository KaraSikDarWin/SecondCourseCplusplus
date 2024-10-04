//
// Created by oslon on 12.05.2023.
//
#include <iostream> //Поток ввода и вывода, чтобы язык мог вводить и выводить
#include <cstdlib>
using namespace std;


int main(){
    srand(time(0));
    int l;
    int n;
    int m;

    cout<<"Vvedite kol vo strok 1 matrici"<<endl;
    cin>>l;
    cout<<"Vvedite kol vo stolbcov 1 matrici i kol vo strok 2"<<endl;
    cin>>n;
    cout<<"Vvedite kol vo strok 2 matrici"<<endl;
    cin>>m;

    float a[l][n];
    float b[n][m];
    float c[l][m];

    for(int i=0;i<l; i++ ){
        for (int j=0; j<n;j++){
            a[i][j]=rand()%10;
        }
    }

    for(int i=0;i<l; i++ ){
        for (int j=0; j<n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0;i<n; i++ ){
        for (int j=0; j<m;j++){
            b[i][j]=rand()%10;
        }
    }

    for(int i=0;i<n; i++ ){
        for (int j=0; j<m;j++){
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }

    for(int i=0;i<l; i++ ){
        float s =0;
        for (int j=0; j<m;j++){
            float s =0;
           for (int k=0; k<n; k++){
               s+=a[i][k]*b[k][j];
           }
           c[i][j]=s;
        }
    }

    cout<<endl;
    for(int i=0;i<l; i++ ){
        for (int j=0; j<m;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}