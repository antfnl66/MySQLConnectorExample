#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <vector>
#include <QString>

struct Customer {
    QString firstName;
    QString lastName;
    QString email;
    QString phoneNumber;
    QString accountNumber;
    QString address;
    QString plan;
};

class CustomerDatabase {
public:
    CustomerDatabase() = default;
    ~CustomerDatabase() = default;

    void addCustomer(const QString& firstName,
                     const QString& lastName,
                     const QString& email,
                     const QString& phoneNumber,
                     const QString& accountNumber,
                     const QString& address,
                     const QString& plan);

    void deleteCustomer(const QString& accountNumber);
    void modifyCustomer(const Customer& modifiedCustomer);
    std::vector<Customer> searchCustomers(const QString& searchTerm, const QString& searchCriteria);
};

#endif // CUSTOMERDATA_H