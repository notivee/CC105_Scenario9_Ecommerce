#ifndef STACK_ENGINE_H
#define STACK_ENGINE_H

#include <string>
#include <iostream>

struct StackNode {
    std::string itemName;
    double itemPrice;
    StackNode* next;

    StackNode(std::string name, double price)
        : itemName(name), itemPrice(price), next(nullptr) {}
};

class CartStack {
private:
    StackNode* top;
public:
    CartStack();
    ~CartStack();
    void push(std::string name, double price);
    bool pop();
    void peek() const;
    void displayStack() const;
};
#endif
