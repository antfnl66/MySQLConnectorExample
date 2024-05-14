#include "SearchViewCustomerWidget.h"

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

    QFormLayout* searchLayout = new QFormLayout;
    searchLayout->addRow("Search:", searchLineEdit);
    searchLayout->addRow("Criteria:", searchCriteriaComboBox);

    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(searchButton);
    mainLayout->addWidget(cancelButton);

    resultsLabel = new QLabel("Search results will appear here", this);
    mainLayout->addWidget(resultsLabel);

    connect(searchButton, &QPushButton::clicked, this, &SearchViewCustomerWidget::performSearch);
    connect(cancelButton, &QPushButton::clicked, this, &SearchViewCustomerWidget::cancelSearch);
}

void SearchViewCustomerWidget::performSearch() {
    // Implementation for search functionality
    // Example:
    // QString searchTerm = searchLineEdit->text();
    // QString searchCriteria = searchCriteriaComboBox->currentText();
    // Implement your search logic here
}