// CustomerData.h
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <vector>

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

    bool addCustomer(const QString& firstName, const QString& lastName,
                     const QString& email, const QString& phoneNumber,
                     const QString& accountNumber, const QString& address,
                     const QString& plan);
    // Other methods...
};

#endif // CUSTOMERDATA_H
