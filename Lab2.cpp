#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits>
using namespace std;




//Больше вправо, меньше влево


bool F1( int* itr, int* ma){ //VPRAVO
    bool flag=1;
    if (itr==ma){
        return 1;
    }

    int *run = itr-1;
    if ((run==ma)and (*run>=*itr)) flag=0;
    while((run!=ma) and (flag==1)){
        if(*run >= *itr){
            flag=0;
        }else run-=1;
    }
    if (*run>=*itr){
        return 0;
    }
    return flag;
}

bool F2(int* itr, int* ma){ //VLEVO
    bool flag=1;
    if(itr==ma){
        return 1;
    }
    int *run= itr+1;
    if ((run==ma)and(*run<=*itr) ) flag=0;
    while((run!=ma) and (flag==1)){
        if(*run <= *itr){
            flag=0;
        }else run+=1;
    }
    if (*run<=*itr){
        return 0;
    }
    return flag;

}


int main(){
    int N;
    int M;
    bool flag=1;
    cout<<"Vvedite N"<<endl;
    cin>>N;
    if (!cin)
    {
        flag=0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    }
    cout<<"Vvedite M"<<endl;
    cin>>M;
    if (!cin)
    {
        flag=0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    }

    if ((flag)and (N>=1) and (M>=1)) {


        srand(time(NULL));
        int beg = 1;
        int count = 0;
        int **matrix = new int *[N];
        for (int i = 0; i < N; i++)
            matrix[i] = new int[M];

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < M; j++) {

                matrix[i][j] = rand();
                beg++;
            }
        }

//        matrix[0][ 0 ]=21145;
//    matrix[0][ 1 ]=10509;
//    matrix[0][ 2 ]=21144;
//    matrix[0][ 3 ]=29808;
//
//    matrix[1][ 0 ]=1005;
//    matrix[1][ 1 ]=17691;
//    matrix[1][ 2 ]=1684;
//    matrix[1][ 3 ]=1684;
//
//        matrix[2][ 0 ]=31007;
//        matrix[2][ 1 ]=23908;
//        matrix[2][ 2 ]=608;
//        matrix[2][ 3 ]=12602;
//
//        matrix[3][ 0 ]=20910;
//        matrix[3][ 1 ]=5625;
//        matrix[3][ 2 ]=4629;
//        matrix[3][ 3 ]=21750;


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (F1(matrix[i] + j, matrix[i]) and F2(matrix[i] + j, matrix[i] + (M - 1))) {
                    cout << i << " " << j << endl;
                    count++;
//
                }
            }
        }
        cout << count;
        for (int i = 0; i < N; i++)
            delete[] matrix[i];
        delete[] matrix;

        return 0;
    }else cout<<"Dannie ne te"<<endl;

}
