# CC105_Scenario9_Ecommerce

E-Commerce Order Fulfillment & Audit Engine (CC105 - Terminal Assessment 2)
Scenario 9 Overview
An enterprise-grade C++ console application designed to manage online retail orders using dynamic memory management, raw pointers, and linear dynamic data structures without relying on C++ STL container wrappers.

Core Data Structures Implemented
Master Orders Ledger: Custom Doubly Linked List for bidirectional order tracking ($O(n)$ search, $O(1)$ deletion given node pointer).
Dispatch Queue: Priority Queue placing "Express" orders ahead of "Standard" and "Eco" orders.
Cart & Coupon Engine: Dynamic LIFO Stack for managing cart modifications and discount rollbacks.
Benchmarking Suite: Empirical profiling engine tracking wall-clock execution time (<chrono>), comparison counts, and swap counts for Bubble, Selection, and Insertion Sort across dataset scales up to N=50,000.

## Compilation & Run Instructions
1. Open `CC105_Scenario9_Ecommerce.cbp` in Code::Blocks (or any modern C++ compiler).
2. Press `F9` (Build and Run).
3. Navigate the CLI menu using numeric selections (0–7).
