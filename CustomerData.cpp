// CustomerData.cpp
#include "CustomerData.h"
#include <QDebug>
#include <QSqlQuery>

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
        qDebug() << "Error adding customer to database:" << query.lastError().text();
        return false;
    }
    return true;
}
