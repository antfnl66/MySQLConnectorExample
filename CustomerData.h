#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <string>
#include <vector>
#include <mysqlx/xdevapi.h>

struct Customer {
    int id;
    std::string name;
    std::string plan;
};

class CustomerDatabase {
public:
    CustomerDatabase();  // Constructor to initialize the database connection
    ~CustomerDatabase(); // Destructor to close the database connection

    void addCustomer(const Customer& newCustomer);
    void deleteCustomer(int id);
    void modifyCustomer(const Customer& modifiedCustomer);
    std::vector<Customer> searchCustomerByName(const std::string& name);

private:
    mysqlx::Session session;
    mysqlx::Schema schema;
    mysqlx::Table table;
};

#endif // CUSTOMERDATA_H
