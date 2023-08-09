#ifndef STACK_HPP
#define STACK_HPP


#include "Node.hpp"
using namespace std;

struct Stack {
public:
    Node *topOfStack;
    Stack();
    bool isEmpty();
    void clear();
    void push(const int&);
    const int& top();
    void pop();
    ~Stack();

};
#endif