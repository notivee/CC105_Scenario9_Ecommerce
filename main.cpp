#include <iostream>
#include <string>
#include <limits>
#include "LinkedListEngine.h"
#include "QueueEngine.h"
#include "StackEngine.h"
#include "SearchSortBench.h"

using namespace std;

// Input validation function to prevent terminal crashes on bad input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    CustomerOrdersLedger ledger;
    OrderDispatchQueue dispatchQueue;
    CartStack cartStack;

    int choice;
    do {
        cout << "\n=======================================================\n";
        cout << "  E-COMMERCE FULFILLMENT ENGINE (SCENARIO 9)  \n";
        cout << "=======================================================\n";
        cout << "1. Add New Order (Saves to Ledger & Dispatch Queue)\n";
        cout << "2. View Customer Orders Ledger (Linked List)\n";
        cout << "3. View Dispatch Queue (Priority Queue)\n";
        cout << "4. Process Next Dispatch Order\n";
        cout << "5. Add Item/Coupon to Cart (Stack)\n";
        cout << "6. Undo Last Cart Action (Stack)\n";
        cout << "7. Run Benchmarking Suite (Sorting & Big-O)\n";
        cout << "0. Exit System\n";
        cout << "-------------------------------------------------------\n";
        cout << "Enter menu choice: ";

        if (!(cin >> choice)) {
            cout << "\n[ERROR] Invalid input! Please enter a number.\n";
            clearInput();
            continue;
        }

        switch(choice) {
            case 1: {
                int id; double val; string name, status, ship;
                cout << "\n--- ADD NEW ORDER ---\n";
                cout << "Enter Order ID: ";
                while (!(cin >> id)) {
                    cout << "[ERROR] Numbers only. Try again: ";
                    clearInput();
                }
                clearInput();

                cout << "Enter Customer Name: ";
                getline(cin, name);

                cout << "Enter Total Value ($): ";
                while (!(cin >> val)) {
                    cout << "[ERROR] Numbers only. Try again: ";
                    clearInput();
                }
                clearInput();

                cout << "Enter Payment Status (Paid/Pending): ";
                getline(cin, status);

                cout << "Enter Shipping Class (Express/Standard/Eco): ";
                getline(cin, ship);

                ledger.insertOrder(id, name, val, status, ship);
                dispatchQueue.enqueue(id, name, val, status, ship);
                cout << "\n[SUCCESS] Order saved to Ledger and queued for Dispatch!\n";
                break;
            }
            case 2:
                ledger.displayLedger();
                break;
            case 3:
                dispatchQueue.displayQueue();
                break;
            case 4:
                dispatchQueue.dequeue();
                break;
            case 5: {
                string item; double price;
                clearInput();
                cout << "\n--- ADD TO CART ---\n";
                cout << "Enter Item or Coupon Name: ";
                getline(cin, item);
                cout << "Enter Value/Price: $";
                while (!(cin >> price)) {
                    cout << "[ERROR] Numbers only. Try again: ";
                    clearInput();
                }
                cartStack.push(item, price);
                break;
            }
            case 6:
                cartStack.pop();
                break;
            case 7:
                BenchmarkingSuite::runBenchmarkingSuite();
                break;
            case 0:
                cout << "\nExiting system. Destructors cleaning dynamic memory...\n";
                break;
            default:
                cout << "\n[ERROR] Invalid menu choice. Try 0 to 7.\n";
        }
    } while (choice != 0);

    return 0;
}
