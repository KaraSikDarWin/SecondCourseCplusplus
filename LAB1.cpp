#include <iostream>
#include <cmath>


double F(double x, int n){
    double y = 0.5  *x;

    for (int k =1;k<=n;k++){
        y+=(pow(x,2*k-2)/(2*k-1));
    }
    return y;
}

int main(){
    double x;
    int n;
    bool flag =1;

    std::cout<<"Vvedite x"<<std::endl;
    std::cin>>x;
    if (!std::cin)
    {
        flag=0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    std::cout<<"Veedite n>=1 "<<std::endl;
    std::cin>>n;
    if (!std::cin)
    {
        flag=0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    if ((flag) and (n>=1)){
        std::cout<<F(x,n);
    }else std::cout<<"OSHIBKA"<<std::endl;

    return 0;
}

//void Del(Elem* &head, Elem* &beg){
//    if (head!= nullptr) {
//        Elem *run;
//        if (head->next == head) {
//            delete head;
//            head = nullptr;
//        } else {
//            beg->next = nullptr;
//            while (head->next != nullptr) {
//                run = head->next;
//                delete head;
//                head = run;
//            }
//            delete head;
//            head = nullptr;
//            beg = nullptr;
//
//        }
//    } else cout<<"List doesn't exist!"<<endl;