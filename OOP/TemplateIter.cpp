#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    struct Node{
        T data;
        Node *next;
        Node():data(0), next(nullptr){};
        Node(T dat_ ):data(dat_), next(nullptr){};
    };

    int sp;
public:
    friend class StackIter;

};


class StackIter
{
    const Stack &stk;
    int index;
public:

};

bool operator == (const Stack &l, const Stack &r)
{

}
