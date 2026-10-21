#include "StackEngine.h"

CartStack::CartStack() : top(nullptr) {}

CartStack::~CartStack() {
    StackNode* current = top;
    while (current != nullptr) {
        StackNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    top = nullptr;
}

void CartStack::push(std::string name, double price) {
    StackNode* newNode = new StackNode(name, price);
    newNode->next = top;
    top = newNode;
    std::cout << "\nAdded '" << name << "' ($" << price << ") to Cart Stack.\n";
}

bool CartStack::pop() {
    if (top == nullptr) {
        std::cout << "\nCart Stack is empty! Nothing to undo/remove.\n";
        return false;
    }

    StackNode* temp = top;
    top = top->next;

    std::cout << "\nRemoved/Undid '" << temp->itemName << "' ($" << temp->itemPrice << ") from Cart Stack.\n";

    delete temp;
    return true;
}

void CartStack::peek() const {
    if (top == nullptr) {
        std::cout << "\nCart Stack is empty!\n";
        return;
    }

    std::cout << "\n--- TOP OF CART STACK ---\n"
              << "Item/Coupon: " << top->itemName
              << " | Value: $" << top->itemPrice << "\n";
}

void CartStack::displayStack() const {
    if (top == nullptr) {
        std::cout << "\nCart Stack is empty!\n";
        return;
    }

    StackNode* temp = top;
    std::cout << "\n--- CHECKOUT CART & COUPON STACK (Newest to Oldest) ---\n";
    int index = 1;
    while (temp != nullptr) {
        std::cout << index++ << ". " << temp->itemName
                  << " ($" << temp->itemPrice << ")\n";
        temp = temp->next;
    }
}
