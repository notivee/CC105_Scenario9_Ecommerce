#ifndef QUEUE_ENGINE_H
#define QUEUE_ENGINE_H

#include "OrderModel.h"
#include <iostream>

// Node representing an order inside the queue
struct QueueNode {
    int orderID;
    std::string customerName;
    double totalValue;
    std::string paymentStatus;
    std::string shippingClass;
    QueueNode* next;

    QueueNode(int id, std::string name, double val, std::string status, std::string ship)
        : orderID(id), customerName(name), totalValue(val),
          paymentStatus(status), shippingClass(ship), next(nullptr) {}
};

class OrderDispatchQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    OrderDispatchQueue();
    ~OrderDispatchQueue(); // Destructor to prevent memory leaks

    void enqueue(int id, std::string name, double val, std::string status, std::string ship);
    bool dequeue();
    void peek() const;
    void displayQueue() const;
};

#endif
