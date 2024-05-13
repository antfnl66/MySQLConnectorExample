#include "MainWindow.h"
#include "AddCustomerWidget.h"
#include "ModifyCustomerWidget.h"
#include "SearchViewCustomerWidget.h"
#include <QVBoxLayout>
#include <QMessageBox>  // For displaying messages to the user

MainWindow::MainWindow(CustomerDatabase& db, QWidget *parent)
        : QWidget(parent), db(db) {
    setupUi();

    // Connect the cancel signals to showHomeWidget slot
    connect(addCustomerWidget, &AddCustomerWidget::cancelAddCustomer, this, &MainWindow::showHomeWidget);
    connect(modifyCustomerWidget, &ModifyCustomerWidget::cancelModifyCustomer, this, &MainWindow::showHomeWidget);
    connect(searchViewCustomerWidget, &SearchViewCustomerWidget::cancelSearchViewCustomer, this, &MainWindow::showHomeWidget);

    // Connect the customerAdded signal to handleCustomerAdded slot
    connect(addCustomerWidget, &AddCustomerWidget::customerAdded, this, &MainWindow::handleCustomerAdded);
}

void MainWindow::setupUi() {
    stackedWidget = new QStackedWidget(this);

    // Home Widget setup
    auto *homeWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(homeWidget);
    addButton = new QPushButton("Add Customer", this);
    searchViewButton = new QPushButton("Search and View Customer Info", this);
    modifyButton = new QPushButton("Modify Customer", this);
    exitButton = new QPushButton("Exit", this);

    layout->addWidget(addButton);
    layout->addWidget(searchViewButton);
    layout->addWidget(modifyButton);
    layout->addWidget(exitButton);
    homeWidget->setLayout(layout);
    stackedWidget->addWidget(homeWidget);

    // Add Customer Widget setup
    addCustomerWidget = new AddCustomerWidget(this);
    stackedWidget->addWidget(addCustomerWidget);

    // Search & View Customer Widget setup (Index 2)
    searchViewCustomerWidget = new SearchViewCustomerWidget(this);
    stackedWidget->addWidget(searchViewCustomerWidget);

    // Modify Customer Widget setup (Index 3)
    modifyCustomerWidget = new ModifyCustomerWidget(this);
    stackedWidget->addWidget(modifyCustomerWidget);

    // Main layout setup
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    this->setLayout(mainLayout);

    // Connections
    connect(addButton, &QPushButton::clicked, this, &MainWindow::showAddCustomerForm);
    connect(searchViewButton, &QPushButton::clicked, this, &MainWindow::showSearchViewCustomerForm);
    connect(modifyButton, &QPushButton::clicked, this, &MainWindow::showModifyCustomerForm);
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
}

void MainWindow::showAddCustomerForm() {
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::showSearchViewCustomerForm() {
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::showModifyCustomerForm() {
    stackedWidget->setCurrentIndex(3);
}

void MainWindow::showHomeWidget() {
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::handleCustomerAdded(const QString &firstName,
                                     const QString &lastName,
                                     const QString &email,
                                     const QString &phoneNumber,
                                     const QString &accountNumber,
                                     const QString &address,
                                     const QString &plan) {
    // Simulated feedback for adding a customer (no actual database interaction)
    QMessageBox::information(this, "Success", "Customer added successfully (simulated)!");

    // Return to the home widget after adding the customer (simulated successful or not)
    showHomeWidget();
}