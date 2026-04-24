# Military Base Management System
**Course:** Object-Oriented Programming (CS2001) Lab Semester Project

##  Group Members
* **Muhammad Anas** (ID: 25K-0899)
* **Abdullah Moin**(ID: 25K-0991)
* **Syed Alyan Hussain** (ID: 25K-0648)

---

##  Project Description
The Military Base Management System is a comprehensive C++ application designed to manage the core logistical and personnel operations of a military installation. Built using advanced Object-Oriented Programming principles, the system provides a centralized platform for tracking personnel (Officers and Contractors), managing high-security inventory (Weapons and Supplies), and coordinating complex military operations.

The system emphasizes data integrity through a robust **Audit Log** that records every administrative action, and ensures system stability through custom **Exception Handling** and strict **Input Validation**.

---

##  Key Use Cases
1.  **Personnel Deployment:** Register and manage detailed records for Officers (including rank and years of service) and Civilian Contractors.
2.  **Inventory Control:** Track weapon status, caliber, and ammunition levels, alongside consumable supplies with automated expiration and stock alerts.
3.  **Operation Coordination:** Create and monitor missions by assigning specific personnel and equipment while tracking real-time status updates (Planned to Completed).
4.  **Strategic Reporting:** Generate real-time analytics on total base valuation, personnel distribution, and inventory health.
5.  **Security Auditing:** Review a persistent chronological log of all system changes to ensure accountability and track entity modifications.
6.  **Data Persistence:** Save and load the entire base state to external files, ensuring information is preserved across different sessions.

---

##  Core OOP Concepts Applied
* **Encapsulation:** All data members (e.g., `salary`, `quantity`) are protected/private, accessible only through controlled getter and setter methods[cite: 41].
* **Inheritance:** Utilizes a multi-level hierarchy where `Officer` and `Contractor` inherit from `Person`, and `Weapon` and `Supplies` inherit from `Equipment`—all deriving from a central `BaseEntity`[cite: 41].
* **Polymorphism:** Implements function overriding and virtual functions for `display()` and `getEntityType()` to handle diverse objects through base pointers[cite: 41].
* **Abstraction:** Employs abstract classes (e.g., `BaseEntity`, `Person`) and interfaces (`ILoggable`) to define essential behaviors without exposing implementation details[cite: 41].

---

##  Instructions to Run (Dev-C++)
To run this project in Dev-C++, follow these steps to ensure the modular files are linked correctly:

1.  **Create a Project:** Go to `File > New > Project...`
2.  **Select Console Application:** Choose `C++ Project`, name it `MilitaryManagement`, and click OK.
3.  **Add Files:** Right-click the project folder in the left sidebar, select **"Add to Project"**, and select all `.cpp` and `.h` files from the `include` and `Source` directories.
4.  **Configure Compiler:** Go to `Tools > Compiler Options`. Check the box "Add the following commands when calling the compiler" and enter `-std=c++11` (or higher).
5.  **Build and Run:** Press `F11` to compile and run the system.

---

##  Instructions to Run (VS Code)
1.  **Prerequisite:** Ensure the `C/C++` and `C++ Runner` extensions are installed.
2.  **Open Folder:** Open the project root directory in VS Code.
3.  **Compilation:** Since this project uses a modular structure, compile using the following command in the terminal:
    ```bash
    g++ -I include Source/core/*.cpp Source/Logistics/*.cpp Source/personnel/*.cpp Source/operations/*.cpp Source/utilities/*.cpp Source/main/main.cpp -o MilitarySystem
    ```
4.  **Execution:** Run the generated file:
    ```bash
    ./MilitarySystem
    ```

---

## Assumptions & Limitations
* **Date Format:** The system expects dates in the `YYYY-MM-DD` format for validation[cite: 66].
* **Persistence:** Data is saved to `.txt` or `.log` files in the execution directory; ensure the program has write permissions[cite: 66].
* **Memory:** The system uses dynamic memory; ensure "Save & Exit" is used to trigger proper destructor cleanup[cite: 66].