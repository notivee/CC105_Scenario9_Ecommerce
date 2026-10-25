# 🛒 E-Commerce Order Fulfillment & Audit Engine
> **CC105: Data Structures & Algorithms — Terminal Assessment 2 (Scenario 9)**  
> **National Teachers College — Department of Computer Studies**

An enterprise-grade C++ console application designed to manage online retail orders using dynamic memory management, raw C++ pointers, and linear dynamic data structures without relying on C++ STL container wrappers.

---

## 🏛️ Core Data Structures Implemented

* **Master Orders Ledger (`Doubly Linked List`):** Bidirectional tracking of customer order records supporting $O(1)$ head insertion and $O(1)$ node deletion given a pointer reference.
* **Order Dispatch Queue (`Priority Queue`):** Dynamically prioritizes high-urgency `Express` shipments ahead of `Standard` and `Eco` orders to meet service level agreements (SLAs).
* **Checkout Cart & Coupon Engine (`Dynamic Stack`):** Enforces strict Last-In, First-Out (LIFO) order tracking, allowing real-time rollback/undo capabilities for recently added items or discounts.
* **Empirical Benchmarking Suite:** Automated performance profiling engine measuring wall-clock execution time (`<chrono>`), comparison counts, and swap metrics across Bubble Sort, Selection Sort, and Insertion Sort for dataset scales up to $N=50,000$.

---

## 🛠️ System Requirements & Build Instructions

### Prerequisites
* **Compiler:** Modern C++ Compiler (`g++`, `clang++`, or MSVC supporting C++11 standard or higher).
* **IDE:** Code::Blocks, VS Code, Visual Studio, or CLion.

### Compilation Steps
1. Clone the repository:
   ```bash
   git clone [https://github.com/notivee/CC105_Scenario9_Ecommerce.git](https://github.com/notivee/CC105_Scenario9_Ecommerce.git)
