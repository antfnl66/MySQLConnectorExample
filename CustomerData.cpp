#include "CustomerData.h"
#include <iostream>
#include <vector>

void CustomerDatabase::addCustomer(const QString& firstName,
                                   const QString& lastName,
                                   const QString& email,
                                   const QString& phoneNumber,
                                   const QString& accountNumber,
                                   const QString& address,
                                   const QString& plan) {
    std::cout << "Pretend to add customer: " << firstName.toStdString() << std::endl;
    // No actual database operations are performed.
}

void CustomerDatabase::deleteCustomer(const QString& accountNumber) {
    std::cout << "Pretend to delete customer with account number: " << accountNumber.toStdString() << std::endl;
    // No actual database operations are performed.
}

void CustomerDatabase::modifyCustomer(const Customer& modifiedCustomer) {
    std::cout << "Pretend to modify customer: " << modifiedCustomer.firstName.toStdString() << std::endl;
    // No actual database operations are performed.
}

std::vector<Customer> CustomerDatabase::searchCustomers(const QString& searchTerm, const QString& searchCriteria) {
    std::cout << "Pretend to search customers by: " << searchCriteria.toStdString() << " for " << searchTerm.toStdString() << std::endl;
    return {}; // Return an empty vector as placeholder.
}