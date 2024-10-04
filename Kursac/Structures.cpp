#include <iostream>
using namespace std;

struct Number{
    char FB;
    int number;
    string SB;
};

struct PhoneNumber{
    int CodeOfCountry;
    int CodeOfRegion;
    string Numbers;
};

struct BrandName{
    string Brand;
    string Model;
};

struct Date{
    string Day;
    string Month;
    string Year;
};

struct Elem{
    Number number;
    PhoneNumber phoneNumber;
    BrandName brandName;
    Date date;
    int NumberOfString;
};

struct HashNode{
    Elem* LinkNode;
    bool status;
    HashNode(int =0):LinkNode(nullptr),status(0){};
};