#include "AddCustomerWidget.h"

AddCustomerWidget::AddCustomerWidget(QWidget *parent, CustomerDatabase* db)
        : QWidget(parent), m_db(db) {
    setupUi();
}

void AddCustomerWidget::setupUi() {
    firstNameLineEdit = new QLineEdit(this);
    lastNameLineEdit = new QLineEdit(this);
    emailLineEdit = new QLineEdit(this);
    phoneNumberLineEdit = new QLineEdit(this);
    accountNumberLineEdit = new QLineEdit(this);
    addressLineEdit = new QLineEdit(this);
    firstNameLabel = new QLabel("First Name:", this);
    lastNameLabel = new QLabel("Last Name:", this);
    emailLabel = new QLabel("Email:", this);
    phoneNumberLabel = new QLabel("Phone Number:", this);
    accountNumberLabel = new QLabel("Account Number:", this);
    addressLabel = new QLabel("Address:", this);
    planComboBox = new QComboBox(this);
    planComboBox->addItems({"Plan 1", "Plan 2", "Plan 3"});

    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(firstNameLabel, firstNameLineEdit);
    layout->addRow(lastNameLabel, lastNameLineEdit);
    layout->addRow(emailLabel, emailLineEdit);
    layout->addRow(phoneNumberLabel, phoneNumberLineEdit);
    layout->addRow(accountNumberLabel, accountNumberLineEdit);
    layout->addRow(addressLabel, addressLineEdit);
    layout->addRow("Plan:", planComboBox);
    layout->addRow(saveButton, cancelButton);

    connect(saveButton, &QPushButton::clicked, this, &AddCustomerWidget::addCustomerToDatabase);
    connect(cancelButton, &QPushButton::clicked, this, &AddCustomerWidget::cancelAddCustomer);
}

void AddCustomerWidget::addCustomerToDatabase() {
    if (m_db) {
        bool success = m_db->addCustomer(firstNameLineEdit->text(), lastNameLineEdit->text(), emailLineEdit->text(),
                                         phoneNumberLineEdit->text(), accountNumberLineEdit->text(), addressLineEdit->text(),
                                         planComboBox->currentText());
        if (success) {
            qDebug() << "Customer added successfully";
        } else {
            qDebug() << "Failed to add customer";
        }
    }
}