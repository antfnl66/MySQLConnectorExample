#include "CustomerData.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

CustomerDatabase::CustomerDatabase() {
    if (!initializeDatabase()) {
        qDebug() << "Database initialization failed.";
    }
}

bool CustomerDatabase::initializeDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("YourDatabaseName");
    db.setUserName("YourUsername");
    db.setPassword("YourPassword");

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return false;
    }
    return true;
}

bool CustomerDatabase::addCustomer(const QString& firstName, const QString& lastName,
                                   const QString& email, const QString& phoneNumber,
                                   const QString& accountNumber, const QString& address,
                                   const QString& plan) {
    QSqlQuery query;
    query.prepare("INSERT INTO customers (firstName, lastName, email, phoneNumber, accountNumber, address, plan) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(email);
    query.addBindValue(phoneNumber);
    query.addBindValue(accountNumber);
    query.addBindValue(address);
    query.addBindValue(plan);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
    return true;
}

// Implement other methods if necessary