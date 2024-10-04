#include <iostream>
#include <experimental/random>
#include <intrin.h>
using namespace std;

uint64_t rdtsc(){
    return __rdtsc();
}

int main(){
    int M1[4][4];
    int M2[4][4];
    int M3[4][4];
    int delta =6;

    auto start = rdtsc();
    for (int i =0; i<4; i++){
        for(int j = 0; j<4; j++){
            M1[i][j]= experimental::randint(0,10);
        }
    }

    for (int i =0; i<4; i++){
        for(int j = 0; j<4; j++){
            M2[i][j]= experimental::randint(0,10);
        }
    }


    for (int i =0; i<4; i++){
        for(int j = 0; j<4; j++){
            M1[i][j]+= delta;
        }
    }


    for (int i =0; i<4; i++){
        for (int j = 0; j<4;j++){
            M3[i][j]=0;
            for (int k =0;k<4;k++){
                M3[i][j]+=M1[i][k]*M2[k][j];
            }
        }
    }

    for(int j =0; j<4; j++){
        M3[0][j]+=M3[3][j];
    }

    auto stop = rdtsc();
    auto diff = stop-start;
    float dff =  diff/3200;
    cout<<dff;
//    for (int i =0; i<4; i++){
//        for(int j = 0; j<4; j++){
//            cout<<M1[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    for (int i =0; i<4; i++){
//        for(int j = 0; j<4; j++){
//            cout<<M2[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//
//    cout<<endl;
//
//    for (int i =0; i<4; i++){
//        for(int j = 0; j<4; j++){
//            cout<<M3[i][j]<<" ";
//        }
//        cout<<endl;
//    }


}