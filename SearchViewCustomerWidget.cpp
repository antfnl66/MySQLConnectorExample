#include "SearchViewCustomerWidget.h"
#include <QDebug>

SearchViewCustomerWidget::SearchViewCustomerWidget(QWidget *parent)
        : QWidget(parent) {
    setupUi();
}

void SearchViewCustomerWidget::setupUi() {
    mainLayout = new QVBoxLayout(this);

    searchLineEdit = new QLineEdit(this);
    searchCriteriaComboBox = new QComboBox(this);
    searchCriteriaComboBox->addItems({"First Name", "Last Name", "Email", "Phone Number", "Account Number", "Plan"});

    searchButton = new QPushButton("Search", this);
    cancelButton = new QPushButton("Cancel", this);

    connect(cancelButton, &QPushButton::clicked, this, &SearchViewCustomerWidget::cancelSearch);
    connect(searchButton, &QPushButton::clicked, this, &SearchViewCustomerWidget::performSearch);

    QFormLayout *searchLayout = new QFormLayout();
    searchLayout->addRow("Search:", searchLineEdit);
    searchLayout->addRow("Criteria:", searchCriteriaComboBox);

    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(searchButton);
    resultsLabel = new QLabel("Search results will appear here", this);
    resultsBox = new QTextEdit(this);
    resultsBox->setReadOnly(true);

    mainLayout->addWidget(resultsLabel);
    mainLayout->addWidget(resultsBox);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);
}

void SearchViewCustomerWidget::cancelSearch() {
    qDebug() << "Search canceled";
    searchLineEdit->clear();
    resultsBox->clear();
    // Additional logic to handle canceling the search if needed
}

void SearchViewCustomerWidget::performSearch() {
    qDebug() << "Performing search";
    QString searchTerm = searchLineEdit->text();
    QString searchCriteria = searchCriteriaComboBox->currentText();

    // Example hardcoded customer
    QString customerData = "Name: Anthony Rivera\n"
                           "Address: 123 Philly St, Philadelphia\n"
                           "Email: anthony@example.com\n"
                           "Phone Number: 123-456-7890\n"
                           "Account Number: 001234\n"
                           "Plan: Basic\n";

    // Check if search term matches the hardcoded customer data
    if (searchTerm == "Anthony" && searchCriteria == "First Name") {
        displayResults(customerData);
    } else {
        displayResults("No results found.");
    }
}

void SearchViewCustomerWidget::displayResults(const QString& results) {
    resultsBox->setText(results);
}