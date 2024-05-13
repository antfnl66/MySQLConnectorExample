#include "AddCustomerWidget.h"
#include <QFormLayout>

AddCustomerWidget::AddCustomerWidget(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void AddCustomerWidget::setupUi() {
    // Create input fields and labels
    firstNameLineEdit = new QLineEdit(this);
    firstNameLabel = new QLabel("First Name:", this);
    lastNameLineEdit = new QLineEdit(this);
    lastNameLabel = new QLabel("Last Name:", this);
    emailLineEdit = new QLineEdit(this);
    emailLabel = new QLabel("Email:", this);
    phoneNumberLineEdit = new QLineEdit(this);
    phoneNumberLabel = new QLabel("Phone Number:", this);
    accountNumberLineEdit = new QLineEdit(this);
    accountNumberLabel = new QLabel("Account Number:", this);
    addressLineEdit = new QLineEdit(this);
    addressLabel = new QLabel("Address:", this);

    // Plan selection combo box
    planComboBox = new QComboBox(this);
    planComboBox->addItems({"Plan 1", "Plan 2", "Plan 3"}); // Placeholder plans

    // Create buttons
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);

    // Layout
    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(firstNameLabel, firstNameLineEdit);
    layout->addRow(lastNameLabel, lastNameLineEdit);
    layout->addRow(emailLabel, emailLineEdit);
    layout->addRow(phoneNumberLabel, phoneNumberLineEdit);
    layout->addRow(accountNumberLabel, accountNumberLineEdit);
    layout->addRow(addressLabel, addressLineEdit);
    layout->addRow("Plan:", planComboBox);
    layout->addRow(saveButton, cancelButton);

    // Button connections
    connect(saveButton, &QPushButton::clicked, this, [this](){
        // Get data from input fields
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString email = emailLineEdit->text();
        QString phoneNumber = phoneNumberLineEdit->text();
        QString accountNumber = accountNumberLineEdit->text();
        QString address = addressLineEdit->text();
        QString plan = planComboBox->currentText();

        emit customerAdded(firstName, lastName, email, phoneNumber, accountNumber, address, plan);
    });

    connect(cancelButton, &QPushButton::clicked, this, [this](){
        emit cancelAddCustomer();
    });
}