#include "CustomerData.h"
#include <iostream>
#include <stdexcept>

CustomerDatabase::CustomerDatabase()
        : session("localhost", 33060, "root", "Embiid76"),
          schema(session.getSchema("EZTechMovieDB")),
          table(schema.getTable("customers"))
{
    try {
        // Test the connection with a simple query to ensure it's active
        session.sql("SELECT 1").execute();
        std::cout << "Connected to database successfully!" << std::endl;
    } catch (const mysqlx::Error& e) {
        std::cerr << "Connection error: " << e.what() << std::endl;
        throw std::runtime_error("Database connection failed");
    } catch (std::exception& e) {
        std::cerr << "Error during database initialization: " << e.what() << std::endl;
        throw;
    }
}

CustomerDatabase::~CustomerDatabase() {
    try {
        // Safely attempt to close the session
        session.close();
        std::cout << "Database session closed." << std::endl;
    } catch (const mysqlx::Error& e) {
        std::cerr << "Error closing the database session: " << e.what() << std::endl;
    }
}

void CustomerDatabase::addCustomer(const Customer& newCustomer) {
    try {
        table.insert("id", "name", "plan").values(newCustomer.id, newCustomer.name, newCustomer.plan).execute();
        std::cout << "Customer added successfully.\n";
    } catch (const mysqlx::Error& e) {
        std::cerr << "Failed to add customer: " << e.what() << std::endl;
    }
}

void CustomerDatabase::deleteCustomer(int id) {
    try {
        table.remove().where("id = :id").bind("id", id).execute();
        std::cout << "Customer deleted successfully.\n";
    } catch (const mysqlx::Error& e) {
        std::cerr << "Failed to delete customer: " << e.what() << std::endl;
    }
}

void CustomerDatabase::modifyCustomer(const Customer& modifiedCustomer) {
    try {
        table.update().set("name", modifiedCustomer.name).set("plan", modifiedCustomer.plan).where("id = :id").bind("id", modifiedCustomer.id).execute();
        std::cout << "Customer modified successfully.\n";
    } catch (const mysqlx::Error& e) {
        std::cerr << "Failed to modify customer: " << e.what() << std::endl;
    }
}

std::vector<Customer> CustomerDatabase::searchCustomerByName(const std::string& name) {
    std::vector<Customer> results;
    try {
        mysqlx::RowResult dbResults = table.select("id", "name", "plan")
                .where("name like :name")
                .bind("name", name + "%")
                .execute();
        for (mysqlx::Row row : dbResults) {
            results.push_back(Customer{row[0].get<int>(), row[1].get<std::string>(), row[2].get<std::string>()});
        }
        std::cout << "Search completed successfully.\n";
    } catch (const mysqlx::Error& e) {
        std::cerr << "Search error: " << e.what() << std::endl;
    }
    return results;
}
