#ifndef ORDER_MODEL_H
#define ORDER_MODEL_H

#include <string>
struct Order {
    int orderID;
    std::string customerName;
    double totalValue;
    std::string paymentStatus;
    std::string shippingClass;
    Order* next;
    Order* prev;

    Order(int id, std::string name, double val, std::string status, std::string ship)
        : orderID(id), customerName(name), totalValue(val),
          paymentStatus(status), shippingClass(ship),
          next(nullptr), prev(nullptr) {}
};

#endif
