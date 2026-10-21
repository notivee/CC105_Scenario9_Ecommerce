#ifndef LINKED_LIST_ENGINE_H
#define LINKED_LIST_ENGINE_H

#include "OrderModel.h"

class CustomerOrdersLedger {
private:
    Order* head;
    Order* tail;

public:
    CustomerOrdersLedger();
    ~CustomerOrdersLedger(); //destructor lang to hayaan niyo yan

    void insertOrder(int id, std::string name, double val, std::string status, std::string ship);
    bool deleteOrder(int id);
    Order* searchOrder(int id);
    bool updateOrder(int id, std::string newStatus, std::string newShip);
    void displayLedger() const;
};

#endif
