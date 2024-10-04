
#include <iostream>
using namespace std;

int main(){

    float epsilon;
    float y;
    float x;
    float s;
    float k;


    cout<<"Enter x"<<endl;
    cin>>x;
    cout<<"Enter 0< epsilon<=1"<<endl;
    cin>>epsilon;
    y=x;
    s=x;
    k=1;
    if ((epsilon>0) and (epsilon<=1)) {
        while (abs(y * (((-1) * (x * x)) / ((k+1) * (k+2))) - y) >= epsilon) {
            y = y * (((-1) * (x * x) / ((k+1) * (k+2))));
            s += y;
            k += 2;
        }
        cout << "Sum:" << s;
    } else cout<<"Epsilon is wrong"<<endl;
    return 0;
}