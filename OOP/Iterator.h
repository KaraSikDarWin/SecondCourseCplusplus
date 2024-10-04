#pragma once
#include <iostream>
#include <set>
template <typename Con>

class ConIterator
{
public:

    using ValType = typename Con::ValType;
    using PointerType = ValType*;
    using ReferenceType = ValType&;

    using NodeType = typename Con::NodeType;
    using NodePointer = NodeType*;
    using NodeReference = NodeType&;

public:
    ConIterator(NodePointer ptr) : the_elem(ptr) {};

    bool IsNext() {
        return the_elem->next;
    }

    void next() {
        the_elem = the_elem->next;
    }

    ConIterator& operator++(int ) {
        if (the_elem!=nullptr)
            the_elem->data;
                next();
        return *this;
    }

    ConIterator& operator++() {
        int cn = 0;
        if ((the_elem != 0) && (the_elem->next != 0)) {
            std::set<char> t;
            std::string data = std::to_string(int(the_elem->data));
            for (int i = 0; i < data.length(); i++) {
                if (!(t.contains(data[i]))) {
                    t.insert(data[i]);
                    cn++;
                }
            }
        }
        the_elem->data-=cn;
        the_elem= the_elem->next;
        return *this;
    }

    ReferenceType operator*() {
            return (the_elem->data);
    }

    bool operator==(const ConIterator& other) const {
        return (the_elem == other.the_elem);
    }
    bool operator!=(const ConIterator& other) const {
        return the_elem != other.the_elem;
    }

private:
    NodePointer the_elem;
};


template <class It1, class It2>
bool equals(It1 begin1, It1 end1, It2 begin2) {
    for (; begin1 != end1; begin1++, begin2++) {
        if (*begin1 != *begin2) return false;
    }

    return true;
}

