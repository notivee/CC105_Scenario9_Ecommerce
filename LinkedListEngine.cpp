#include "LinkedListEngine.h"
#include <iostream>

CustomerOrdersLedger::CustomerOrdersLedger() : head(nullptr), tail(nullptr) {}

CustomerOrdersLedger::~CustomerOrdersLedger() {
    Order* current = head;
    while (current != nullptr) {
        Order* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}

void CustomerOrdersLedger::insertOrder(int id, std::string name, double val, std::string status, std::string ship) {
    Order* newOrder = new Order(id, name, val, status, ship);
    if (!head) {
        head = tail = newOrder;
    } else {
        tail->next = newOrder;
        newOrder->prev = tail;
        tail = newOrder;
    }
}

bool CustomerOrdersLedger::deleteOrder(int id) {
    Order* current = head;
    while (current != nullptr) {
        if (current->orderID == id) {
            if (current->prev) current->prev->next = current->next;
            else head = current->next;

            if (current->next) current->next->prev = current->prev;
            else tail = current->prev;

            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

Order* CustomerOrdersLedger::searchOrder(int id) {
    Order* current = head;
    while (current != nullptr) {
        if (current->orderID == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void CustomerOrdersLedger::displayLedger() const {
    Order* current = head;
    std::cout << "\n--- CUSTOMER ORDERS LEDGER ---\n";
    while (current != nullptr) {
        std::cout << "ID: " << current->orderID
                  << " | Name: " << current->customerName
                  << " | Total: $" << current->totalValue
                  << " | Shipping: " << current->shippingClass << "\n";
        current = current->next;
    }
}
    bool CustomerOrdersLedger::updateOrder(int id, std::string newStatus, std::string newShip) {
    Order* target = searchOrder(id); // Reuses your search function!
    if (target != nullptr) {
        target->paymentStatus = newStatus;
        target->shippingClass = newShip;
        return true; // Successfully updated
    }
    return false; // Order ID not found
}
