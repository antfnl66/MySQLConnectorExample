#include "AddCustomerWidget.h"
#include <QMessageBox>
#include <QFormLayout>

AddCustomerWidget::AddCustomerWidget(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void AddCustomerWidget::setupUi() {
    // Initialize input fields and labels
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

    // Initialize the plan selection combo box
    planComboBox = new QComboBox(this);
    planComboBox->addItems({"Plan 1", "Plan 2", "Plan 3"});

    // Initialize buttons
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);

    // Layout setup using QFormLayout for organized input fields
    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(firstNameLabel, firstNameLineEdit);
    layout->addRow(lastNameLabel, lastNameLineEdit);
    layout->addRow(emailLabel, emailLineEdit);
    layout->addRow(phoneNumberLabel, phoneNumberLineEdit);
    layout->addRow(accountNumberLabel, accountNumberLineEdit);
    layout->addRow(addressLabel, addressLineEdit);
    layout->addRow("Plan:", planComboBox);
    layout->addRow(saveButton, cancelButton);

    // Connect the Save button to emit customerAdded when clicked
    connect(saveButton, &QPushButton::clicked, this, [this]() {
        emit customerAdded(firstNameLineEdit->text(), lastNameLineEdit->text(), emailLineEdit->text(),
                           phoneNumberLineEdit->text(), accountNumberLineEdit->text(), addressLineEdit->text(),
                           planComboBox->currentText());
    });

    // Connect the Cancel button to emit cancelAddCustomer when clicked
    connect(cancelButton, &QPushButton::clicked, this, [this]() {
        emit cancelAddCustomer();
    });
}
