#ifndef ADDCUSTOMERWIDGET_H
#define ADDCUSTOMERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include "CustomerData.h"

class AddCustomerWidget : public QWidget {
Q_OBJECT

public:
    explicit AddCustomerWidget(QWidget *parent = nullptr, CustomerDatabase* db = nullptr);

signals:
    void cancelAddCustomer();  // Ensure this signal is declared

private slots:
    void addCustomerToDatabase();  // Ensure this slot is declared

private:
    QLineEdit* firstNameLineEdit;
    QLineEdit* lastNameLineEdit;
    QLineEdit* emailLineEdit;
    QLineEdit* phoneNumberLineEdit;
    QLineEdit* accountNumberLineEdit;
    QLineEdit* addressLineEdit;
    QLabel* firstNameLabel;
    QLabel* lastNameLabel;
    QLabel* emailLabel;
    QLabel* phoneNumberLabel;
    QLabel* accountNumberLabel;
    QLabel* addressLabel;
    QComboBox* planComboBox;  // Ensure this is declared
    QPushButton* saveButton;
    QPushButton* cancelButton;
    CustomerDatabase* m_db;

    void setupUi();
};

#endif // ADDCUSTOMERWIDGET_H