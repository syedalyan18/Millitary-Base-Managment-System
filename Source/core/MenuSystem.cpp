#include "core/MenuSystem.h"
#include "personnel/Officer.h"
#include "personnel/Contractor.h"
#include "logistics/Weapon.h"
#include "logistics/Supplies.h"
#include "operations/Operation.h"
#include "core/AuditLog.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Global data storage
vector<Officer*> officers;
vector<Contractor*> contractors;
vector<Weapon*> weapons;
vector<Supplies*> supplies;
vector<Operation*> operations;
AuditLog* auditLog = nullptr;

// Constructor
MenuSystem::MenuSystem() : isRunning(true) {
    if (auditLog == nullptr) {
        auditLog = new AuditLog("military_audit.log");
    }
}

// Destructor
MenuSystem::~MenuSystem() {
    // Cleanup all dynamic objects
    for (auto officer : officers) delete officer;
    for (auto contractor : contractors) delete contractor;
    for (auto weapon : weapons) delete weapon;
    for (auto supply : supplies) delete supply;
    for (auto op : operations) delete op;
    
    if (auditLog != nullptr) {
        delete auditLog;
        auditLog = nullptr;
    }
}

// Main menu loop
void MenuSystem::run() {
    while (isRunning) {
        displayMainMenu();
        int choice = getMainMenuChoice();
        handleMainMenu(choice);
    }
}

// Display main menu
void MenuSystem::displayMainMenu() {
    Utils::clearScreen();
    Utils::printHeader("MILITARY BASE MANAGEMENT SYSTEM");
    cout << "\n1. Personnel Management" << endl;
    cout << "2. Logistics Management" << endl;
    cout << "3. Operations Management" << endl;
    cout << "4. Reports & Analytics" << endl;
    cout << "5. Audit Log" << endl;
    cout << "6. Save & Exit" << endl;
    cout << "\nEnter your choice: ";
}

// Get main menu choice
int MenuSystem::getMainMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

// Handle main menu
void MenuSystem::handleMainMenu(int choice) {
    switch (choice) {
        case 1:
            while (true) {
                displayPersonnelMenu();
                int pChoice = getPersonnelMenuChoice();
                if (pChoice == 0) break;
                handlePersonnelMenu(pChoice);
            }
            break;
        case 2:
            while (true) {
                displayLogisticsMenu();
                int lChoice = getLogisticsMenuChoice();
                if (lChoice == 0) break;
                handleLogisticsMenu(lChoice);
            }
            break;
        case 3:
            while (true) {
                displayOperationsMenu();
                int oChoice = getOperationsMenuChoice();
                if (oChoice == 0) break;
                handleOperationsMenu(oChoice);
            }
            break;
        case 4:
            while (true) {
                displayReportsMenu();
                int rChoice = getReportsMenuChoice();
                if (rChoice == 0) break;
                handleReportsMenu(rChoice);
            }
            break;
        case 5:
            while (true) {
                displayAuditMenu();
                int aChoice = getAuditMenuChoice();
                if (aChoice == 0) break;
                handleAuditMenu(aChoice);
            }
            break;
        case 6:
            saveAllData();
            isRunning = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

// Personnel Menu
void MenuSystem::displayPersonnelMenu() {
    Utils::clearScreen();
    Utils::printHeader("PERSONNEL MANAGEMENT");
    cout << "\n1. Add Officer" << endl;
    cout << "2. Add Contractor" << endl;
    cout << "3. Delete Personnel" << endl;
    cout << "4. Display All Personnel" << endl;
    cout << "5. Promote Officer" << endl;
    cout << "6. Search Personnel by ID" << endl;
    cout << "7. Search Personnel by Name" << endl;
    cout << "8. Update Personnel Details" << endl;
    cout << "9. Assign Weapon to Personnel" << endl;
    cout << "10. Unassign Weapon from Personnel" << endl;
    cout << "11. View Personnel Weapons" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getPersonnelMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handlePersonnelMenu(int choice) {
    switch (choice) {
        case 1:
            addOfficer();
            break;
        case 2:
            addContractor();
            break;
        case 3:
            deletePersonnel();
            break;
        case 4:
            displayAllPersonnel();
            break;
        case 5:
            promoteOfficer();
            break;
        case 6:
            searchPersonnelByID();
            break;
        case 7:
            searchPersonnelByName();
            break;
        case 8:
            updatePersonnelDetails();
            break;
        case 9:
            assignWeaponToPersonnel();
            break;
        case 10:
            unassignWeaponFromPersonnel();
            break;
        case 11:
            viewPersonnelWeapons();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Logistics Menu
void MenuSystem::displayLogisticsMenu() {
    Utils::clearScreen();
    Utils::printHeader("LOGISTICS MANAGEMENT");
    cout << "\n1. Add Weapon" << endl;
    cout << "2. Add Supplies" << endl;
    cout << "3. Delete Equipment" << endl;
    cout << "4. Display All Equipment" << endl;
    cout << "5. Check Inventory" << endl;
    cout << "6. Update Weapon Ammunition" << endl;
    cout << "7. Perform Weapon Maintenance" << endl;
    cout << "8. Issue Ammunition to Personnel" << endl;
    cout << "9. Check Expired Supplies" << endl;
    cout << "10. Refillup Supplies" << endl;
    cout << "11. Consume Supplies" << endl;
    cout << "12. Search Equipment by ID" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getLogisticsMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleLogisticsMenu(int choice) {
    switch (choice) {
        case 1:
            addWeapon();
            break;
        case 2:
            addSupplies();
            break;
        case 3:
            deleteEquipment();
            break;
        case 4:
            displayAllEquipment();
            break;
        case 5:
            checkInventory();
            break;
        case 6:
            updateWeaponAmmunition();
            break;
        case 7:
            performWeaponMaintenance();
            break;
        case 8:
            issueAmmunition();
            break;
        case 9:
            checkExpiredSupplies();
            break;
        case 10:
            replenishSupplies();
            break;
        case 11:
            consumeSupplies();
            break;
        case 12:
            searchEquipmentByID();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Operations Menu
void MenuSystem::displayOperationsMenu() {
    Utils::clearScreen();
    Utils::printHeader("OPERATIONS MANAGEMENT");
    cout << "\n1. Create Operation" << endl;
    cout << "2. Delete Operation" << endl;
    cout << "3. Display All Operations" << endl;
    cout << "4. Assign Personnel to Operation" << endl;
    cout << "5. Assign Equipment to Operation" << endl;
    cout << "6. Update Operation Status" << endl;
    cout << "7. Search Operation" << endl;
    cout << "8. Generate Operation Report" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getOperationsMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleOperationsMenu(int choice) {
    switch (choice) {
        case 1:
            createOperation();
            break;
        case 2:
            deleteOperation();
            break;
        case 3:
            displayAllOperations();
            break;
        case 4:
            assignPersonnelToOperation();
            break;
        case 5:
            assignEquipmentToOperation();
            break;
        case 6:
            updateOperationStatus();
            break;
        case 7:
            searchOperation();
            break;
        case 8:
            generateOperationReport();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Reports Menu
void MenuSystem::displayReportsMenu() {
    Utils::clearScreen();
    Utils::printHeader("REPORTS & ANALYTICS");
    cout << "\n1. Personnel Report" << endl;
    cout << "2. Equipment Report" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getReportsMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleReportsMenu(int choice) {
    switch (choice) {
        case 1:
            generatePersonnelReport();
            break;
        case 2:
            generateEquipmentReport();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Personnel Management Implementations
void MenuSystem::addOfficer() {
    cout << "\n=== ADD NEW OFFICER ===" << endl;
    cout << "Enter name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter service number (SN-XXXXX): ";
    string sNumber;
    getline(cin, sNumber);
    
    cout << "Enter rank (Private, Sergeant, Lieutenant, Captain, Major, Colonel, General): ";
    string rank;
    getline(cin, rank);
    
    cout << "Enter salary: ";
    string salStr;
    getline(cin, salStr);
    double salary = stod(salStr);
    
    cout << "Enter specialization: ";
    string spec;
    getline(cin, spec);
    
    cout << "Enter command center: ";
    string cmdCenter;
    getline(cin, cmdCenter);
    
    cout << "Enter years of service: ";
    string yearsStr;
    getline(cin, yearsStr);
    int years = stoi(yearsStr);
    
    try {
        Officer* officer = new Officer(name, sNumber, rank, salary, spec, cmdCenter, years);
        officers.push_back(officer);
        auditLog->addEntry("ADD", "Officer", officer->getID(), "Officer " + name + " added");
        cout << "\nOfficer added successfully. ID: " << officer->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::addContractor() {
    cout << "\n=== ADD NEW CONTRACTOR ===" << endl;
    cout << "Enter name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter service number (SN-XXXXX): ";
    string sNumber;
    getline(cin, sNumber);
    
    cout << "Enter salary: ";
    string salStr;
    getline(cin, salStr);
    double salary = stod(salStr);
    
    cout << "Enter company name: ";
    string company;
    getline(cin, company);
    
    cout << "Enter security clearance (Confidential, Secret, Top Secret, TS/SCI): ";
    string clearance;
    getline(cin, clearance);
    
    cout << "Enter contract end date (YYYY-MM-DD): ";
    string endDate;
    getline(cin, endDate);
    
    cout << "Enter contract value: ";
    string valueStr;
    getline(cin, valueStr);
    double value = stod(valueStr);
    
    try {
        Contractor* contractor = new Contractor(name, sNumber, salary, company, clearance, endDate, value);
        contractors.push_back(contractor);
        auditLog->addEntry("ADD", "Contractor", contractor->getID(), "Contractor " + name + " added");
        cout << "\nContractor added successfully. ID: " << contractor->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::displayAllPersonnel() {
    cout << "\n=== ALL PERSONNEL ===" << endl;
    
    if (!officers.empty()) {
        cout << "\n--- Officers ---" << endl;
        for (const auto& officer : officers) {
            officer->display();
        }
    }
    
    
    if (!contractors.empty()) {
        cout << "\n--- Contractors ---" << endl;
        for (const auto& contractor : contractors) {
            contractor->display();
        }
    }
    
    if (officers.empty() && contractors.empty()) {
        cout << "No personnel found." << endl;
    }
}

void MenuSystem::deletePersonnel() {
    cout << "\n=== DELETE PERSONNEL ===" << endl;
    cout << "Enter personnel ID to delete: ";
    int id;
    cin >> id;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    for (auto it = officers.begin(); it != officers.end(); ++it) {
        if ((*it)->getID() == id) {
            cout << "Deleting Officer: " << (*it)->getName() << endl;
            delete *it;
            officers.erase(it);
            cout << "Officer deleted." << endl;
            return;
        }
    }
    
    for (auto it = contractors.begin(); it != contractors.end(); ++it) {
        if ((*it)->getID() == id) {
            cout << "Deleting Contractor: " << (*it)->getName() << endl;
            delete *it;
            contractors.erase(it);
            cout << "Contractor deleted." << endl;
            return;
        }
    }
    
    cout << "Personnel not found." << endl;
}

void MenuSystem::promoteOfficer() {
    cout << "\n=== PROMOTE OFFICER ===" << endl;
    cout << "Enter officer ID: ";
    int id;
    cin >> id;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    cout << "Enter new rank: ";
    string newRank;
    getline(cin, newRank);
    
    for (auto& officer : officers) {
        if (officer->getID() == id) {
            try {
                officer->promote(newRank);
                auditLog->addEntry("UPDATE", "Officer", id, "Officer promoted to " + newRank);
                cout << "\nOfficer promoted successfully." << endl;
                return;
            }
            catch (const exception& e) {
                cout << "\nError: " << e.what() << endl;
                return;
            }
        }
    }
    cout << "\nOfficer not found." << endl;
}

// Logistics Management Implementations
void MenuSystem::addWeapon() {
    cout << "\n=== ADD NEW WEAPON ===" << endl;
    cout << "Enter weapon name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter equipment code: ";
    string code;
    getline(cin, code);
    
    cout << "Enter weapon type (Rifle, Pistol, Sniper, etc.): ";
    string type;
    getline(cin, type);
    
    cout << "Enter quantity: ";
    string qtyStr;
    getline(cin, qtyStr);
    int qty = stoi(qtyStr);
    
    cout << "Enter unit cost: ";
    string costStr;
    getline(cin, costStr);
    double cost = stod(costStr);
    
    cout << "Enter storage location: ";
    string loc;
    getline(cin, loc);
    
    cout << "Enter initial ammunition: ";
    string ammoStr;
    getline(cin, ammoStr);
    int ammo = stoi(ammoStr);
    
    cout << "Enter magazine capacity: ";
    string magStr;
    getline(cin, magStr);
    int magCap = stoi(magStr);
    
    cout << "Enter caliber: ";
    string caliber;
    getline(cin, caliber);
    
    try {
        Weapon* weapon = new Weapon(name, code, type, qty, cost, loc, ammo, magCap, caliber);
        weapons.push_back(weapon);
        auditLog->addEntry("ADD", "Weapon", weapon->getID(), "Weapon " + name + " added");
        cout << "\nWeapon added successfully. ID: " << weapon->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::addSupplies() {
    cout << "\n=== ADD NEW SUPPLIES ===" << endl;
    cout << "Enter supply name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter equipment code: ";
    string code;
    getline(cin, code);
    
    cout << "Enter supply type (Food, Medical, Clothing, Fuel, etc.): ";
    string type;
    getline(cin, type);
    
    cout << "Enter quantity: ";
    string qtyStr;
    getline(cin, qtyStr);
    int qty = stoi(qtyStr);
    
    cout << "Enter unit cost: ";
    string costStr;
    getline(cin, costStr);
    double cost = stod(costStr);
    
    cout << "Enter storage location: ";
    string loc;
    getline(cin, loc);
    
    cout << "Enter expiration date (YYYY-MM-DD): ";
    string expDate;
    getline(cin, expDate);
    
    cout << "Enter minimum stock level: ";
    string minStockStr;
    getline(cin, minStockStr);
    int minStock = stoi(minStockStr);
    
    cout << "Enter supplier name: ";
    string supplier;
    getline(cin, supplier);
    
    try {
        Supplies* sup = new Supplies(name, code, type, qty, cost, loc, expDate, minStock, supplier);
        supplies.push_back(sup);
        auditLog->addEntry("ADD", "Supplies", sup->getID(), "Supplies " + name + " added");
        cout << "\nSupplies added successfully. ID: " << sup->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::displayAllEquipment() {
    cout << "\n=== ALL EQUIPMENT ===" << endl;
    
    if (!weapons.empty()) {
        cout << "\n--- Weapons ---" << endl;
        for (const auto& weapon : weapons) {
            weapon->display();
        }
    }
    
    if (!supplies.empty()) {
        cout << "\n--- Supplies ---" << endl;
        for (const auto& supply : supplies) {
            supply->display();
        }
    }
    
    if (weapons.empty() && supplies.empty()) {
        cout << "No equipment found." << endl;
    }
}

void MenuSystem::deleteEquipment() {
    cout << "\n=== DELETE EQUIPMENT ===" << endl;
    cout << "Enter equipment ID to delete: ";
    int id;
    cin >> id;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    for (auto it = weapons.begin(); it != weapons.end(); ++it) {
        if ((*it)->getID() == id) {
            cout << "Deleting Weapon: " << (*it)->getName() << endl;
            auditLog->addEntry("DELETE", "Weapon", id, "Weapon deleted");
            delete *it;
            weapons.erase(it);
            cout << "Weapon deleted successfully." << endl;
            return;
        }
    }
    
    for (auto it = supplies.begin(); it != supplies.end(); ++it) {
        if ((*it)->getID() == id) {
            cout << "Deleting Supplies: " << (*it)->getName() << endl;
            auditLog->addEntry("DELETE", "Supplies", id, "Supplies deleted");
            delete *it;
            supplies.erase(it);
            cout << "Supplies deleted successfully." << endl;
            return;
        }
    }
    
    cout << "\nEquipment not found." << endl;
}

void MenuSystem::displayAllOperations() {
    cout << "\n=== ALL OPERATIONS ===" << endl;
    
    if (operations.empty()) {
        cout << "No operations found." << endl;
    } else {
        for (const auto& op : operations) {
            op->display();
            cout << endl;
        }
    }
}

// Operations Management Implementations
void MenuSystem::createOperation() {
    cout << "\n=== CREATE NEW OPERATION ===" << endl;
    cout << "Enter operation code: ";
    string code;
    getline(cin, code);
    
    cout << "Enter operation type (Training, Patrol, Combat, etc.): ";
    string opType;
    getline(cin, opType);
    
    cout << "Enter commander name: ";
    string commander;
    getline(cin, commander);
    
    cout << "Enter location: ";
    string location;
    getline(cin, location);
    
    cout << "Enter description: ";
    string desc;
    getline(cin, desc);
    
    try {
        Operation* op = new Operation(code, opType, commander, location, desc);
        operations.push_back(op);
        auditLog->addEntry("ADD", "Operation", op->getID(), "Operation " + code + " created");
        cout << "\nOperation created successfully. ID: " << op->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::deleteOperation() {
    cout << "\n=== DELETE OPERATION ===" << endl;
    cout << "Enter operation ID: ";
    int id;
    cin >> id;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    for (auto it = operations.begin(); it != operations.end(); ++it) {
        if ((*it)->getID() == id) {
            cout << "Deleting Operation: " << (*it)->getOperationCode() << endl;
            auditLog->addEntry("DELETE", "Operation", id, "Operation deleted");
            delete *it;
            operations.erase(it);
            cout << "Operation deleted successfully." << endl;
            return;
        }
    }
    
    cout << "\nOperation not found." << endl;
}

void MenuSystem::generateEquipmentReport() {
    cout << "\n=== EQUIPMENT REPORT ===" << endl;
    cout << "Total Weapons: " << weapons.size() << endl;
    cout << "Total Supplies: " << supplies.size() << endl;
    cout << "Total Equipment: " << (weapons.size() + supplies.size()) << endl;
    
    // Save to txt file
    ofstream reportFile("equipment_report.txt");
    if (reportFile.is_open()) {
        reportFile << "======== EQUIPMENT REPORT ========\n";
        reportFile << "Generated: " << Utils::getCurrentDateTime() << "\n\n";
        reportFile << "Total Weapons: " << weapons.size() << "\n";
        reportFile << "Total Supplies: " << supplies.size() << "\n";
        reportFile << "Total Equipment: " << (weapons.size() + supplies.size()) << "\n";
        
        double totalWeaponValue = 0;
        for (const auto& weapon : weapons) {
            totalWeaponValue += weapon->getTotalValue();
        }
        reportFile << "\nTotal Weapon Value: Rs" << fixed << setprecision(2) << totalWeaponValue << "\n";
        
        double totalSupplyValue = 0;
        for (const auto& supply : supplies) {
            totalSupplyValue += supply->getTotalValue();
        }
        reportFile << "Total Supply Value: Rs" << fixed << setprecision(2) << totalSupplyValue << "\n";
        reportFile << "Total Equipment Value: Rs" << fixed << setprecision(2) << (totalWeaponValue + totalSupplyValue) << "\n";
        reportFile.close();
        cout << "\nReport saved to equipment_report.txt" << endl;
    } else {
        cout << "\nError: Could not create equipment_report.txt" << endl;
    }
}

void MenuSystem::generatePersonnelReport() {
    cout << "\n=== PERSONNEL REPORT ===" << endl;
    cout << "Total Officers: " << officers.size() << endl;
    cout << "Total Contractors: " << contractors.size() << endl;
    cout << "Total Personnel: " << (officers.size() + contractors.size()) << endl;
    
    // Calculate total salaries
    double totalSalary = 0;
    for (const auto& officer : officers) {
        totalSalary += officer->getSalary();
    }
    for (const auto& contractor : contractors) {
        totalSalary += contractor->getSalary();
    }
    cout << "Total Salary Expense: Rs" << fixed << setprecision(2) << totalSalary << endl;
    
    // Save to txt file
    ofstream reportFile("personnel_report.txt");
    if (reportFile.is_open()) {
        reportFile << "======== PERSONNEL REPORT ========\n";
        reportFile << "Generated: " << Utils::getCurrentDateTime() << "\n\n";
        reportFile << "Total Officers: " << officers.size() << "\n";
        reportFile << "Total Contractors: " << contractors.size() << "\n";
        reportFile << "Total Personnel: " << (officers.size() + contractors.size()) << "\n";
        reportFile << "Total Salary Expense: Rs" << fixed << setprecision(2) << totalSalary << "\n";
        
        reportFile << "\n--- OFFICERS ---\n";
        for (const auto& officer : officers) {
            reportFile << "ID: " << officer->getID() << " | Name: " << officer->getName() 
                      << " | Rank: " << officer->getRank() << " | Salary: Rs" << officer->getSalary() << "\n";
        }
        
        reportFile << "\n--- CONTRACTORS ---\n";
        for (const auto& contractor : contractors) {
            reportFile << "ID: " << contractor->getID() << " | Name: " << contractor->getName() 
                      << " | Salary: Rs" << contractor->getSalary() << "\n";
        }
        reportFile.close();
        cout << "\nReport saved to personnel_report.txt" << endl;
    } else {
        cout << "\nError: Could not create personnel_report.txt" << endl;
    }
}

// Audit Log Management
void MenuSystem::displayAuditMenu() {
    Utils::clearScreen();
    Utils::printHeader("AUDIT LOG MANAGEMENT");
    cout << "\n1. View All Audit Entries" << endl;
    cout << "2. Search by Entity Type" << endl;
    cout << "3. Search by Operation Type" << endl;
    cout << "4. Search by Entity ID" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getAuditMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleAuditMenu(int choice) {
    switch (choice) {
        case 1:
            viewAllAuditEntries();
            break;
        case 2:
            searchAuditByEntityType();
            break;
        case 3:
            searchAuditByOperationType();
            break;
        case 4:
            searchAuditByEntityID();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

void MenuSystem::viewAllAuditEntries() {
    if (auditLog != nullptr) {
        cout << "\n";
        Utils::printHeader("ALL AUDIT ENTRIES");
        auditLog->displayAllEntries();
    } else {
        cout << "\nError: Audit log not available." << endl;
    }
}

void MenuSystem::searchAuditByEntityType() {
    string entityType;
    cout << "\nEnter entity type to search (e.g., Officer, Contractor, Weapon, Supplies, Operation): ";
    getline(cin, entityType);
    
    if (auditLog != nullptr) {
        cout << "\n";
        Utils::printHeader("AUDIT ENTRIES FOR ENTITY TYPE: " + entityType);
        auditLog->searchByEntityType(entityType);
    } else {
        cout << "\nError: Audit log not available." << endl;
    }
}

void MenuSystem::searchAuditByOperationType() {
    string operationType;
    cout << "\nEnter operation type to search (e.g., ADD, UPDATE, DELETE, PROMOTE): ";
    getline(cin, operationType);
    
    if (auditLog != nullptr) {
        cout << "\n";
        Utils::printHeader("AUDIT ENTRIES FOR OPERATION TYPE: " + operationType);
        auditLog->searchByOperationType(operationType);
    } else {
        cout << "\nError: Audit log not available." << endl;
    }
}

void MenuSystem::searchAuditByEntityID() {
    int entityID;
    cout << "\nEnter entity ID to search: ";
    cin >> entityID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    if (auditLog != nullptr) {
        cout << "\n";
        Utils::printHeader("AUDIT ENTRIES FOR ENTITY ID: " + to_string(entityID));
        auditLog->searchByEntityID(entityID);
    } else {
        cout << "\nError: Audit log not available." << endl;
    }
}

// Save and Load
void MenuSystem::saveAllData() {
    cout << "\nSaving all data..." << endl;
    if (auditLog != nullptr) {
        auditLog->saveToFile();
    }
    cout << "Data saved successfully." << endl;
}

void MenuSystem::loadAllData() {
    cout << "\nLoading all data..." << endl;
    if (auditLog != nullptr) {
        auditLog->loadFromFile();
    }
    cout << "Data loaded successfully." << endl;
}

// Helper methods to find personnel and weapons by ID
Person* MenuSystem::findPersonnelByID(int id) {
    for (auto& officer : officers) {
        if (officer->getID() == id) {
            return officer;
        }
    }
    for (auto& contractor : contractors) {
        if (contractor->getID() == id) {
            return contractor;
        }
    }
    return nullptr;
}

Weapon* MenuSystem::findWeaponByID(int id) {
    for (auto& weapon : weapons) {
        if (weapon->getID() == id) {
            return weapon;
        }
    }
    return nullptr;
}

// Weapon Assignment Functions
void MenuSystem::assignWeaponToPersonnel() {
    cout << "\n=== ASSIGN WEAPON TO PERSONNEL ===" << endl;
    
    if (officers.empty() && contractors.empty()) {
        cout << "No personnel available." << endl;
        return;
    }
    
    if (weapons.empty()) {
        cout << "No weapons available." << endl;
        return;
    }
    
    // Display all personnel
    cout << "\n--- Available Personnel ---" << endl;
    for (const auto& officer : officers) {
        cout << "ID: " << officer->getID() << " | Name: " << officer->getName() 
             << " | Rank: " << officer->getRank() << endl;
    }
    for (const auto& contractor : contractors) {
        cout << "ID: " << contractor->getID() << " | Name: " << contractor->getName() << endl;
    }
    
    cout << "\nEnter personnel ID: ";
    int personID;
    cin >> personID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Person* person = findPersonnelByID(personID);
    if (!person) {
        cout << "\nPersonnel not found." << endl;
        return;
    }
    
    // Display all weapons
    cout << "\n--- Available Weapons ---" << endl;
    for (const auto& weapon : weapons) {
        cout << "ID: " << weapon->getID() << " | Name: " << weapon->getName() 
             << " | Type: " << weapon->getWeaponType() << " | Qty: " << weapon->getQuantity() << endl;
    }
    
    cout << "\nEnter weapon ID to assign: ";
    int weaponID;
    cin >> weaponID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Weapon* weapon = findWeaponByID(weaponID);
    if (!weapon) {
        cout << "\nWeapon not found." << endl;
        return;
    }
    
    // Assign weapon
    if (person->hasWeapon(to_string(weaponID))) {
        cout << "\nThis weapon is already assigned to " << person->getName() << endl;
        return;
    }
    
    person->addAssignedWeapon(to_string(weaponID));
    auditLog->addEntry("ASSIGN", "Weapon", weaponID, 
                       "Weapon " + weapon->getName() + " assigned to " + person->getName());
    
    cout << "\nWeapon assigned successfully!" << endl;
    cout << "Weapon: " << weapon->getName() << " assigned to: " << person->getName() << endl;
}

void MenuSystem::unassignWeaponFromPersonnel() {
    cout << "\n=== UNASSIGN WEAPON FROM PERSONNEL ===" << endl;
    
    if (officers.empty() && contractors.empty()) {
        cout << "No personnel available." << endl;
        return;
    }
    
    // Display all personnel
    cout << "\n--- Available Personnel ---" << endl;
    for (const auto& officer : officers) {
        cout << "ID: " << officer->getID() << " | Name: " << officer->getName() 
             << " | Rank: " << officer->getRank() << endl;
    }
    for (const auto& contractor : contractors) {
        cout << "ID: " << contractor->getID() << " | Name: " << contractor->getName() << endl;
    }
    
    cout << "\nEnter personnel ID: ";
    int personID;
    cin >> personID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Person* person = findPersonnelByID(personID);
    if (!person) {
        cout << "\nPersonnel not found." << endl;
        return;
    }
    
    auto assignedWeapons = person->getAssigneedWeapons();
    if (assignedWeapons.empty()) {
        cout << "\n" << person->getName() << " has no weapons assigned." << endl;
        return;
    }
    
    // Display assigned weapons
    cout << "\n--- Weapons Assigned to " << person->getName() << " ---" << endl;
    for (const auto& weaponIDStr : assignedWeapons) {
        int wID = stoi(weaponIDStr);
        Weapon* w = findWeaponByID(wID);
        if (w) {
            cout << "ID: " << w->getID() << " | Name: " << w->getName() 
                 << " | Type: " << w->getWeaponType() << endl;
        }
    }
    
    cout << "\nEnter weapon ID to unassign: ";
    int weaponID;
    cin >> weaponID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Weapon* weapon = findWeaponByID(weaponID);
    if (!weapon) {
        cout << "\nWeapon not found." << endl;
        return;
    }
    
    if (!person->hasWeapon(to_string(weaponID))) {
        cout << "\nThis weapon is not assigned to " << person->getName() << endl;
        return;
    }
    
    person->removeAssignedWeapon(to_string(weaponID));
    auditLog->addEntry("UNASSIGN", "Weapon", weaponID, 
                       "Weapon " + weapon->getName() + " unassigned from " + person->getName());
    
    cout << "\nWeapon unassigned successfully!" << endl;
    cout << "Weapon: " << weapon->getName() << " unassigned from: " << person->getName() << endl;
}

void MenuSystem::viewPersonnelWeapons() {
    cout << "\n=== VIEW PERSONNEL WEAPONS ===" << endl;
    
    if (officers.empty() && contractors.empty()) {
        cout << "No personnel available." << endl;
        return;
    }
    
    // Display all personnel
    cout << "\n--- Available Personnel ---" << endl;
    for (const auto& officer : officers) {
        cout << "ID: " << officer->getID() << " | Name: " << officer->getName() 
             << " | Rank: " << officer->getRank() << endl;
    }
    for (const auto& contractor : contractors) {
        cout << "ID: " << contractor->getID() << " | Name: " << contractor->getName() << endl;
    }
    
    cout << "\nEnter personnel ID: ";
    int personID;
    cin >> personID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Person* person = findPersonnelByID(personID);
    if (!person) {
        cout << "\nPersonnel not found." << endl;
        return;
    }
    
    auto assignedWeapons = person->getAssigneedWeapons();
    
    cout << "\n" << Utils::createString(60, '=') << endl;
    cout << "WEAPONS ASSIGNED TO: " << person->getName() << endl;
    cout << Utils::createString(60, '=') << endl;
    
    if (assignedWeapons.empty()) {
        cout << "\nNo weapons assigned to " << person->getName() << endl;
    } else {
        for (const auto& weaponIDStr : assignedWeapons) {
            int wID = stoi(weaponIDStr);
            Weapon* w = findWeaponByID(wID);
            if (w) {
                cout << "\nWeapon ID: " << w->getID() << endl;
                cout << "Name: " << w->getName() << endl;
                cout << "Type: " << w->getWeaponType() << endl;
                cout << "Caliber: " << w->getCaliber() << endl;
                cout << "Ammunition: " << w->getCurrentAmmunition() << endl;
                cout << "Magazine Capacity: " << w->getMaxAmmunitionCapacity() << endl;
                cout << "Status: " << (w->isWeaponLocked() ? "LOCKED" : "UNLOCKED") << endl;
                cout << Utils::createString(60, '-') << endl;
            }
        }
    }
}

// NEW PERSONNEL FUNCTIONS

void MenuSystem::searchPersonnelByID() {
    cout << "\n=== SEARCH PERSONNEL BY ID ===" << endl;
    cout << "Enter personnel ID: ";
    int id;
    cin >> id;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Person* person = findPersonnelByID(id);
    if (person) {
        cout << "\n" << Utils::createString(60, '=') << endl;
        person->display();
        cout << Utils::createString(60, '=') << endl;
    } else {
        cout << "\nPersonnel not found." << endl;
    }
}

void MenuSystem::searchPersonnelByName() {
    cout << "\n=== SEARCH PERSONNEL BY NAME ===" << endl;
    cout << "Enter personnel name (full or partial): ";
    string searchName;
    getline(cin, searchName);
    
    vector<Person*> results;
    
    for (auto& officer : officers) {
        if (officer->getName().find(searchName) != string::npos) {
            results.push_back(officer);
        }
    }
    
    for (auto& contractor : contractors) {
        if (contractor->getName().find(searchName) != string::npos) {
            results.push_back(contractor);
        }
    }
    
    if (results.empty()) {
        cout << "\nNo personnel found with name containing: " << searchName << endl;
    } else {
        cout << "\n" << Utils::createString(60, '=') << endl;
        cout << "SEARCH RESULTS: Found " << results.size() << " personnel" << endl;
        cout << Utils::createString(60, '=') << endl;
        for (auto& person : results) {
            person->display();
            cout << endl;
        }
    }
}

void MenuSystem::updatePersonnelDetails() {
    cout << "\n=== UPDATE PERSONNEL DETAILS ===" << endl;
    cout << "Enter personnel ID: ";
    int id;
    cin >> id;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Person* person = findPersonnelByID(id);
    if (!person) {
        cout << "\nPersonnel not found." << endl;
        return;
    }
    
    cout << "\nUpdating: " << person->getName() << endl;
    cout << "\nWhat would you like to update?" << endl;
    cout << "1. Salary" << endl;
    cout << "2. Rank" << endl;
    cout << "3. Current Position" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    
    // Handle invalid input for choice
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid choice." << endl;
        return;
    }
    
    cin.ignore();
    
    try {
        if (choice == 1) {
            cout << "Current Salary: " << person->getSalary() << endl;
            cout << "Enter new salary: ";
            double newSalary;
            cin >> newSalary;
            
            // Handle invalid input for salary
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nInvalid input. Please enter a valid salary amount." << endl;
                return;
            }
            
            cin.ignore();
            person->setSalary(newSalary);
            auditLog->addEntry("UPDATE", "Personnel", id, "Salary updated to " + to_string(newSalary));
            cout << "\nSalary updated successfully." << endl;
        } else if (choice == 2) {
            cout << "Current Rank: " << person->getRank() << endl;
            cout << "Enter new rank: ";
            string newRank;
            getline(cin, newRank);
            person->setRank(newRank);
            auditLog->addEntry("UPDATE", "Personnel", id, "Rank updated to " + newRank);
            cout << "\nRank updated successfully." << endl;
        } else if (choice == 3) {
            cout << "Current Position: " << person->getCurrentPosition() << endl;
            cout << "Enter new position: ";
            string newPos;
            getline(cin, newPos);
            person->setCurrentPosition(newPos);
            auditLog->addEntry("UPDATE", "Personnel", id, "Position updated to " + newPos);
            cout << "\nPosition updated successfully." << endl;
        } else {
            cout << "\nInvalid choice." << endl;
        }
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

// NEW LOGISTICS FUNCTIONS

void MenuSystem::checkInventory() {
    cout << "\n=== INVENTORY CHECK ===" << endl;
    cout << Utils::createString(60, '=') << endl;
    
    double totalWeaponValue = 0;
    double totalSupplyValue = 0;
    
    cout << "\n--- WEAPONS INVENTORY ---" << endl;
    if (weapons.empty()) {
        cout << "No weapons in inventory." << endl;
    } else {
        for (const auto& weapon : weapons) {
            double value = weapon->getQuantity() * weapon->getUnitCost();
            totalWeaponValue += value;
            cout << "\nID: " << weapon->getID() << " | Name: " << weapon->getName()
                 << " | Qty: " << weapon->getQuantity() << " | Cost: Rs" << fixed << setprecision(2) 
                 << value << endl;
        }
    }
    
    cout << "\n--- SUPPLIES INVENTORY ---" << endl;
    if (supplies.empty()) {
        cout << "No supplies in inventory." << endl;
    } else {
        for (const auto& supply : supplies) {
            double value = supply->getQuantity() * supply->getUnitCost();
            totalSupplyValue += value;
            cout << "\nID: " << supply->getID() << " | Name: " << supply->getName()
                 << " | Qty: " << supply->getQuantity() << " | Cost: Rs" << fixed << setprecision(2) 
                 << value << endl;
        }
    }
    
    cout << "\n" << Utils::createString(60, '=') << endl;
    cout << "TOTAL WEAPONS VALUE: Rs" << fixed << setprecision(2) << totalWeaponValue << endl;
    cout << "TOTAL SUPPLIES VALUE: Rs" << fixed << setprecision(2) << totalSupplyValue << endl;
    cout << "TOTAL INVENTORY VALUE: Rs" << fixed << setprecision(2) << (totalWeaponValue + totalSupplyValue) << endl;
    cout << Utils::createString(60, '=') << endl;
}

void MenuSystem::updateWeaponAmmunition() {
    cout << "\n=== UPDATE WEAPON AMMUNITION ===" << endl;
    
    if (weapons.empty()) {
        cout << "No weapons available." << endl;
        return;
    }
    
    cout << "\n--- Available Weapons ---" << endl;
    for (const auto& weapon : weapons) {
        cout << "ID: " << weapon->getID() << " | Name: " << weapon->getName() 
             << " | Current Ammo: " << weapon->getCurrentAmmunition() << endl;
    }
    
    cout << "\nEnter weapon ID: ";
    int weaponID;
    cin >> weaponID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Weapon* weapon = findWeaponByID(weaponID);
    if (!weapon) {
        cout << "\nWeapon not found." << endl;
        return;
    }
    
    cout << "\nCurrent Ammunition: " << weapon->getCurrentAmmunition() << endl;
    cout << "1. Add Ammunition" << endl;
    cout << "2. Remove Ammunition" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid choice." << endl;
        return;
    }
    
    cin.ignore();
    
    cout << "Enter amount: ";
    int amount;
    cin >> amount;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer amount." << endl;
        return;
    }
    
    cin.ignore();
    
    try {
        if (choice == 1) {
            weapon->addAmmunition(amount);
            auditLog->addEntry("UPDATE", "Weapon", weaponID, "Ammunition added: " + to_string(amount) + " rounds");
            cout << "\nAmmunition added successfully." << endl;
        } else if (choice == 2) {
            weapon->removeAmmunition(amount);
            auditLog->addEntry("UPDATE", "Weapon", weaponID, "Ammunition removed: " + to_string(amount) + " rounds");
            cout << "\nAmmunition removed successfully." << endl;
        } else {
            cout << "\nInvalid choice." << endl;
        }
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::performWeaponMaintenance() {
    cout << "\n=== PERFORM WEAPON MAINTENANCE ===" << endl;
    
    if (weapons.empty()) {
        cout << "No weapons available." << endl;
        return;
    }
    
    cout << "\n--- Available Weapons ---" << endl;
    for (const auto& weapon : weapons) {
        cout << "ID: " << weapon->getID() << " | Name: " << weapon->getName() << endl;
    }
    
    cout << "\nEnter weapon ID: ";
    int weaponID;
    cin >> weaponID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Weapon* weapon = findWeaponByID(weaponID);
    if (!weapon) {
        cout << "\nWeapon not found." << endl;
        return;
    }
    
    try {
        weapon->performMaintenance();
        auditLog->addEntry("UPDATE", "Weapon", weaponID, "Maintenance performed on " + weapon->getName());
        cout << "\nMaintenance completed successfully." << endl;
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::issueAmmunition() {
    cout << "\n=== ISSUE AMMUNITION ===" << endl;
    
    if (weapons.empty()) {
        cout << "No weapons available." << endl;
        return;
    }
    
    cout << "\n--- Available Weapons ---" << endl;
    for (const auto& weapon : weapons) {
        cout << "ID: " << weapon->getID() << " | Name: " << weapon->getName() 
             << " | Available: " << weapon->getCurrentAmmunition() << " rounds" << endl;
    }
    
    cout << "\nEnter weapon ID: ";
    int weaponID;
    cin >> weaponID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Weapon* weapon = findWeaponByID(weaponID);
    if (!weapon) {
        cout << "\nWeapon not found." << endl;
        return;
    }
    
    cout << "\nEnter quantity to issue: ";
    int quantity;
    cin >> quantity;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer quantity." << endl;
        return;
    }
    
    cin.ignore();
    
    if (quantity > weapon->getCurrentAmmunition()) {
        cout << "\nInsufficient ammunition. Available: " << weapon->getCurrentAmmunition() << endl;
        return;
    }
    
    try {
        weapon->removeAmmunition(quantity);
        auditLog->addEntry("ISSUE", "Weapon", weaponID, "Ammunition issued: " + to_string(quantity) + " rounds");
        cout << "\nAmmunition issued successfully." << endl;
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::checkExpiredSupplies() {
    cout << "\n=== CHECK EXPIRED SUPPLIES ===" << endl;
    
    if (supplies.empty()) {
        cout << "No supplies in inventory." << endl;
        return;
    }
    
    vector<Supplies*> expiredItems;
    
    for (auto& supply : supplies) {
        if (supply->getExpirationDate() < "2026-04-24") {
            expiredItems.push_back(supply);
        }
    }
    
    cout << "\n" << Utils::createString(60, '=') << endl;
    
    if (expiredItems.empty()) {
        cout << "No expired supplies found." << endl;
    } else {
        cout << "EXPIRED SUPPLIES: " << expiredItems.size() << " items" << endl;
        cout << Utils::createString(60, '=') << endl;
        for (auto& supply : expiredItems) {
            cout << "\nID: " << supply->getID() << endl;
            cout << "Name: " << supply->getName() << endl;
            cout << "Type: " << supply->getSupplyType() << endl;
            cout << "Expiration Date: " << supply->getExpirationDate() << endl;
            cout << "Quantity: " << supply->getQuantity() << endl;
        }
    }
    cout << "\n" << Utils::createString(60, '=') << endl;
}

void MenuSystem::replenishSupplies() {
    cout << "\n=== REPLENISH SUPPLIES ===" << endl;
    
    if (supplies.empty()) {
        cout << "No supplies available." << endl;
        return;
    }
    
    cout << "\n--- Available Supplies ---" << endl;
    for (const auto& supply : supplies) {
        cout << "ID: " << supply->getID() << " | Name: " << supply->getName() 
             << " | Current Qty: " << supply->getQuantity() << endl;
    }
    
    cout << "\nEnter supplies ID: ";
    int supplyID;
    cin >> supplyID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Supplies* supply = nullptr;
    for (auto& s : supplies) {
        if (s->getID() == supplyID) {
            supply = s;
            break;
        }
    }
    
    if (!supply) {
        cout << "\nSupplies not found." << endl;
        return;
    }
    
    cout << "Enter quantity to add: ";
    int quantity;
    cin >> quantity;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer quantity." << endl;
        return;
    }
    
    cin.ignore();
    
    try {
        supply->replenishSupply(quantity);
        auditLog->addEntry("UPDATE", "Supplies", supplyID, "Supplies replenished: " + to_string(quantity) + " units");
        cout << "\nSupplies replenished successfully." << endl;
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::consumeSupplies() {
    cout << "\n=== CONSUME SUPPLIES ===" << endl;
    
    if (supplies.empty()) {
        cout << "No supplies available." << endl;
        return;
    }
    
    cout << "\n--- Available Supplies ---" << endl;
    for (const auto& supply : supplies) {
        cout << "ID: " << supply->getID() << " | Name: " << supply->getName() 
             << " | Current Qty: " << supply->getQuantity() << endl;
    }
    
    cout << "\nEnter supplies ID: ";
    int supplyID;
    cin >> supplyID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Supplies* supply = nullptr;
    for (auto& s : supplies) {
        if (s->getID() == supplyID) {
            supply = s;
            break;
        }
    }
    
    if (!supply) {
        cout << "\nSupplies not found." << endl;
        return;
    }
    
    cout << "Enter quantity to consume: ";
    int quantity;
    cin >> quantity;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer quantity." << endl;
        return;
    }
    
    cin.ignore();
    
    if (quantity > supply->getQuantity()) {
        cout << "\nInsufficient quantity. Available: " << supply->getQuantity() << endl;
        return;
    }
    
    try {
        supply->consumeSupply(quantity);
        auditLog->addEntry("UPDATE", "Supplies", supplyID, "Supplies consumed: " + to_string(quantity) + " units");
        cout << "\nSupplies consumed successfully." << endl;
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::searchEquipmentByID() {
    cout << "\n=== SEARCH EQUIPMENT BY ID ===" << endl;
    cout << "Enter equipment ID: ";
    int id;
    cin >> id;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    for (auto& weapon : weapons) {
        if (weapon->getID() == id) {
            cout << "\n" << Utils::createString(60, '=') << endl;
            weapon->display();
            cout << Utils::createString(60, '=') << endl;
            return;
        }
    }
    
    for (auto& supply : supplies) {
        if (supply->getID() == id) {
            cout << "\n" << Utils::createString(60, '=') << endl;
            supply->display();
            cout << Utils::createString(60, '=') << endl;
            return;
        }
    }
    
    cout << "\nEquipment not found." << endl;
}

// NEW OPERATIONS FUNCTIONS

void MenuSystem::assignPersonnelToOperation() {
    cout << "\n=== ASSIGN PERSONNEL TO OPERATION ===" << endl;
    
    if (operations.empty()) {
        cout << "No operations available." << endl;
        return;
    }
    
    if (officers.empty() && contractors.empty()) {
        cout << "No personnel available." << endl;
        return;
    }
    
    cout << "\n--- Available Operations ---" << endl;
    for (const auto& op : operations) {
        cout << "ID: " << op->getID() << " | Code: " << op->getOperationCode() << endl;
    }
    
    cout << "\nEnter operation ID: ";
    int opID;
    cin >> opID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Operation* operation = nullptr;
    for (auto& op : operations) {
        if (op->getID() == opID) {
            operation = op;
            break;
        }
    }
    
    if (!operation) {
        cout << "\nOperation not found." << endl;
        return;
    }
    
    cout << "\n--- Available Personnel ---" << endl;
    for (const auto& officer : officers) {
        cout << "ID: " << officer->getID() << " | Name: " << officer->getName() << endl;
    }
    for (const auto& contractor : contractors) {
        cout << "ID: " << contractor->getID() << " | Name: " << contractor->getName() << endl;
    }
    
    cout << "\nEnter personnel ID: ";
    int personID;
    cin >> personID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Person* person = findPersonnelByID(personID);
    if (!person) {
        cout << "\nPersonnel not found." << endl;
        return;
    }
    
    operation->assignPersonnel(personID);
    auditLog->addEntry("ASSIGN", "Operation", opID, "Personnel " + person->getName() + " assigned");
    cout << "\nPersonnel assigned successfully to operation." << endl;
}

void MenuSystem::assignEquipmentToOperation() {
    cout << "\n=== ASSIGN EQUIPMENT TO OPERATION ===" << endl;
    
    if (operations.empty()) {
        cout << "No operations available." << endl;
        return;
    }
    
    if (weapons.empty() && supplies.empty()) {
        cout << "No equipment available." << endl;
        return;
    }
    
    cout << "\n--- Available Operations ---" << endl;
    for (const auto& op : operations) {
        cout << "ID: " << op->getID() << " | Code: " << op->getOperationCode() << endl;
    }
    
    cout << "\nEnter operation ID: ";
    int opID;
    cin >> opID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Operation* operation = nullptr;
    for (auto& op : operations) {
        if (op->getID() == opID) {
            operation = op;
            break;
        }
    }
    
    if (!operation) {
        cout << "\nOperation not found." << endl;
        return;
    }
    
    cout << "\n--- Available Equipment ---" << endl;
    for (const auto& weapon : weapons) {
        cout << "ID: " << weapon->getID() << " | Name: " << weapon->getName() << endl;
    }
    for (const auto& supply : supplies) {
        cout << "ID: " << supply->getID() << " | Name: " << supply->getName() << endl;
    }
    
    cout << "\nEnter equipment ID: ";
    int equipID;
    cin >> equipID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    operation->requireEquipment(equipID);
    auditLog->addEntry("ASSIGN", "Operation", opID, "Equipment ID " + to_string(equipID) + " assigned");
    cout << "\nEquipment assigned successfully to operation." << endl;
}

void MenuSystem::updateOperationStatus() {
    cout << "\n=== UPDATE OPERATION STATUS ===" << endl;
    
    if (operations.empty()) {
        cout << "No operations available." << endl;
        return;
    }
    
    cout << "\n--- Available Operations ---" << endl;
    for (const auto& op : operations) {
        cout << "ID: " << op->getID() << " | Code: " << op->getOperationCode() 
             << " | Status: " << op->getStatus() << endl;
    }
    
    cout << "\nEnter operation ID: ";
    int opID;
    cin >> opID;
    
    // Handle invalid input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a valid integer ID." << endl;
        return;
    }
    
    cin.ignore();
    
    Operation* operation = nullptr;
    for (auto& op : operations) {
        if (op->getID() == opID) {
            operation = op;
            break;
        }
    }
    
    if (!operation) {
        cout << "\nOperation not found." << endl;
        return;
    }
    
    cout << "\nCurrent Status: " << operation->getStatus() << endl;
    cout << "Enter new status (Planned, Active, Completed, Cancelled): ";
    string newStatus;
    getline(cin, newStatus);
    
    operation->setStatus(newStatus);
    auditLog->addEntry("UPDATE", "Operation", opID, "Status updated to " + newStatus);
    cout << "\nOperation status updated successfully." << endl;
}

void MenuSystem::searchOperation() {
    cout << "\n=== SEARCH OPERATION ===" << endl;
    cout << "\nSearch by:" << endl;
    cout << "1. Operation ID" << endl;
    cout << "2. Operation Code" << endl;
    cout << "3. Operation Type" << endl;
    cout << "4. Operation Status" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    
    vector<Operation*> results;
    
    if (choice == 1) {
        cout << "Enter operation ID: ";
        int id;
        cin >> id;
        
        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter a valid integer ID." << endl;
            return;
        }
        
        cin.ignore();
        for (auto& op : operations) {
            if (op->getID() == id) {
                results.push_back(op);
            }
        }
    } else if (choice == 2) {
        cout << "Enter operation code: ";
        string code;
        getline(cin, code);
        for (auto& op : operations) {
            if (op->getOperationCode() == code) {
                results.push_back(op);
            }
        }
    } else if (choice == 3) {
        cout << "Enter operation type: ";
        string type;
        getline(cin, type);
        for (auto& op : operations) {
            if (op->getOperationType() == type) {
                results.push_back(op);
            }
        }
    } else if (choice == 4) {
        cout << "Enter operation status: ";
        string status;
        getline(cin, status);
        for (auto& op : operations) {
            if (op->getStatus() == status) {
                results.push_back(op);
            }
        }
    } else {
        cout << "\nInvalid choice." << endl;
        return;
    }
    
    if (results.empty()) {
        cout << "\nNo operations found." << endl;
    } else {
        cout << "\n" << Utils::createString(60, '=') << endl;
        cout << "SEARCH RESULTS: Found " << results.size() << " operation(s)" << endl;
        cout << Utils::createString(60, '=') << endl;
        for (auto& op : results) {
            op->display();
            cout << endl;
        }
    }
}

void MenuSystem::generateOperationReport() {
    cout << "\n=== OPERATION REPORT ===" << endl;
    cout << "Total Operations: " << operations.size() << endl;
    
    int planned = 0, active = 0, completed = 0, cancelled = 0;
    
    for (const auto& op : operations) {
        string status = op->getStatus();
        if (status == "Planned") planned++;
        else if (status == "Active") active++;
        else if (status == "Completed") completed++;
        else if (status == "Cancelled") cancelled++;
    }
    
    cout << "\nStatus Breakdown:" << endl;
    cout << "  Planned: " << planned << endl;
    cout << "  Active: " << active << endl;
    cout << "  Completed: " << completed << endl;
    cout << "  Cancelled: " << cancelled << endl;
    
    cout << "\n--- ALL OPERATIONS ---" << endl;
    for (const auto& op : operations) {
        cout << "\nID: " << op->getID() << endl;
        cout << "Code: " << op->getOperationCode() << endl;
        cout << "Type: " << op->getOperationType() << endl;
        cout << "Status: " << op->getStatus() << endl;
        cout << "Location: " << op->getLocation() << endl;
        cout << Utils::createString(60, '-') << endl;
    }
}
