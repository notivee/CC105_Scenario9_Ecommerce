#include "QueueEngine.h"

OrderDispatchQueue::OrderDispatchQueue() : front(nullptr), rear(nullptr) {}

OrderDispatchQueue::~OrderDispatchQueue() {
    QueueNode* current = front;
    while (current != nullptr) {
        QueueNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    front = rear = nullptr;
}

void OrderDispatchQueue::enqueue(int id, std::string name, double val, std::string status, std::string ship) {
    QueueNode* newNode = new QueueNode(id, name, val, status, ship);


    if (front == nullptr) {
        front = rear = newNode;
        return;
    }

    if (ship == "Express") {
        if (front->shippingClass != "Express") {
            newNode->next = front;
            front = newNode;
        } else {
            QueueNode* temp = front;
            while (temp->next != nullptr && temp->next->shippingClass == "Express") {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == nullptr) {
                rear = newNode;
            }
        }
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

bool OrderDispatchQueue::dequeue() {
    if (front == nullptr) {
        std::cout << "\nDispatch Queue is empty! Nothing to process.\n";
        return false;
    }

    QueueNode* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }

    std::cout << "\nSuccessfully Dispatched Order ID #" << temp->orderID
              << " (" << temp->customerName << " - " << temp->shippingClass << ")\n";

    delete temp;
    return true;
}

void OrderDispatchQueue::peek() const {
    if (front == nullptr) {
        std::cout << "\nDispatch Queue is empty!\n";
        return;
    }

    std::cout << "\n--- NEXT ORDER IN LINE FOR DISPATCH ---\n"
              << "ID: " << front->orderID
              << " | Name: " << front->customerName
              << " | Total: $" << front->totalValue
              << " | Shipping: " << front->shippingClass << "\n";
}

void OrderDispatchQueue::displayQueue() const {
    if (front == nullptr) {
        std::cout << "\nDispatch Queue is empty!\n";
        return;
    }

    QueueNode* temp = front;
    std::cout << "\n--- ORDER DISPATCH QUEUE (Priority: Express First) ---\n";
    int pos = 1;
    while (temp != nullptr) {
        std::cout << pos++ << ". ID: " << temp->orderID
                  << " | Name: " << temp->customerName
                  << " | Total: $" << temp->totalValue
                  << " | Shipping: " << temp->shippingClass << "\n";
        temp = temp->next;
    }
}
