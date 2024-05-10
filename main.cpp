#include <iostream>
#include <vector>
#include <limits>
#include "CustomerData.h"

void displayCustomer(const Customer& customer) {
    std::cout << "Customer ID: " << customer.id << std::endl;
    std::cout << "Name: " << customer.name << std::endl;
    std::cout << "Plan: " << customer.plan << std::endl;
}

void addCustomer(CustomerDatabase& db) {
    Customer tempCustomer;
    std::cout << "Enter Customer ID: ";
    std::cin >> tempCustomer.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Improved newline character consumption
    std::cout << "Enter Name: ";
    std::getline(std::cin, tempCustomer.name);
    std::cout << "Enter Plan: ";
    std::getline(std::cin, tempCustomer.plan);

    try {
        db.addCustomer(tempCustomer);
        std::cout << "Customer added successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Failed to add customer: " << e.what() << std::endl;
    }
}

void deleteCustomer(CustomerDatabase& db) {
    int id;
    std::cout << "Enter Customer ID to delete: ";
    std::cin >> id;

    try {
        db.deleteCustomer(id);
        std::cout << "Customer deleted successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Failed to delete customer: " << e.what() << std::endl;
    }
}

void modifyCustomer(CustomerDatabase& db) {
    Customer tempCustomer;
    std::cout << "Enter Customer ID to modify: ";
    std::cin >> tempCustomer.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Improved newline character consumption
    std::cout << "Enter new Name: ";
    std::getline(std::cin, tempCustomer.name);
    std::cout << "Enter new Plan: ";
    std::getline(std::cin, tempCustomer.plan);

    try {
        db.modifyCustomer(tempCustomer);
        std::cout << "Customer modified successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Failed to modify customer: " << e.what() << std::endl;
    }
}

void searchCustomerByName(CustomerDatabase& db) {
    std::string name;
    std::cout << "Enter Name to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Improved newline character consumption
    std::getline(std::cin, name);

    try {
        std::vector<Customer> results = db.searchCustomerByName(name);
        if (results.empty()) {
            std::cout << "No customers found.\n";
        } else {
            std::cout << "Found customers:\n";
            for (const auto& cust : results) {
                displayCustomer(cust);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Failed to search customers: " << e.what() << std::endl;
    }
}

int main() {
    try {
        CustomerDatabase db;  // Initialize the database connection
        int choice;

        while (true) {
            std::cout << "\nEZTechMovieDB Management System" << std::endl;
            std::cout << "1. Add Customer" << std::endl;
            std::cout << "2. Delete Customer" << std::endl;
            std::cout << "3. Modify Customer" << std::endl;
            std::cout << "4. Search Customer by Name" << std::endl;
            std::cout << "5. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();  // Clears the error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discards "bad" characters
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    addCustomer(db);
                    break;
                case 2:
                    deleteCustomer(db);
                    break;
                case 3:
                    modifyCustomer(db);
                    break;
                case 4:
                    searchCustomerByName(db);
                    break;
                case 5:
                    std::cout << "Exiting program.\n";
                    return 0;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
