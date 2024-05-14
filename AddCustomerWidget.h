#ifndef ADDCUSTOMERWIDGET_H
#define ADDCUSTOMERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QFormLayout>
#include "CustomerData.h"

class AddCustomerWidget : public QWidget {
Q_OBJECT

public:
    explicit AddCustomerWidget(QWidget *parent = nullptr, CustomerDatabase *db = nullptr);

signals:
    void cancelAddCustomer();  // Add this signal

private slots:
    void addCustomerToDatabase();

private:
    void setupUi();

    CustomerDatabase *m_db;
    QLineEdit *firstNameLineEdit;
    QLabel *firstNameLabel;  // Add this declaration
    QLineEdit *lastNameLineEdit;
    QLabel *lastNameLabel;   // Add this declaration
    QLineEdit *emailLineEdit;
    QLabel *emailLabel;      // Add this declaration
    QLineEdit *phoneNumberLineEdit;
    QLabel *phoneNumberLabel;
    QLineEdit *accountNumberLineEdit;
    QLabel *accountNumberLabel;
    QLineEdit *addressLineEdit;
    QLabel *addressLabel;
    QComboBox *planComboBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;
};

#endif // ADDCUSTOMERWIDGET_H