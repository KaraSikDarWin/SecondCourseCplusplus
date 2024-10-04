#include <iostream>
#include <typeinfo>
#include <limits>
using namespace std;

int main(){
    double a;
    double b;
    double sum;
    char c;
    bool flag=1;
    bool flagbad=0;
    bool run = 1;

    while (run) {
        a = 0;
        b = 0;
        c = 0;
        flag=1;
        flagbad=0;

        cout<<"Vvedite 1 operand"<<endl;
        cin >> a;
        if (std::cin.fail()) //
        {
            std::cin.clear(); //
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            flagbad = 1;
        }
        cout<<"Vvedite 2 operand"<<endl;
        cin >> b;
        if (std::cin.fail()) //
        {
            std::cin.clear(); //
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            flagbad = 1;
        }
        cout<<"Vvedite opearciu (+,-,*,/) ili & chto bi viytyti"<<endl;

        cin >> c;
        if (std::cin.fail()) //
        {
            std::cin.clear(); //
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            flagbad = 1;
        }

        if (flagbad) {
            flag = 0;
        }

        if (flag) {
            while (flag) {
                switch (c) {
                    case '+': {
                        sum = a + b;
                        flag = 0;
                        cout << sum << endl;
                        break;
                    }
                    case '-': {
                        sum = a - b;
                        cout << sum << endl;
                        flag = 0;
                        break;
                    }
                    case '*': {
                        sum = a * b;
                        cout << sum << endl;
                        flag = 0;
                        break;
                    }
                    case '/': {
                        if (b == 0) {
                            cout << "NA NOL` DELIT NELZYA!!!" << endl;
                            flag = 0;
                            break;
                        } else {
                            sum = a / b;
                            cout << sum << endl;
                            flag = 0;
                            break;
                        }

                    }
                    case '$': {
                        cout << "Thank you =)";
                        run =0;
                        flag=0;
                        break;
                    }
                    default:
                        cout << "Такой операции нет";
                }

            }
        } else { cout << "Chto poshlo ne tak; gde to oshibka" << endl; }
    }
}

