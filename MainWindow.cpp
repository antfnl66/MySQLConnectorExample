#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(CustomerDatabase& db, QWidget *parent)
        : QWidget(parent), db(db) {
    setupUi();
    connectSignals();
}

void MainWindow::setupUi() {
    layout = new QVBoxLayout(this);
    addButton = new QPushButton("Add Customer", this);
    searchViewButton = new QPushButton("Search/View Customer", this);
    modifyButton = new QPushButton("Modify Customer", this);
    exitButton = new QPushButton("Exit", this);
    stackedWidget = new QStackedWidget(this);

    addCustomerWidget = new AddCustomerWidget(this, &db);
    searchViewCustomerWidget = new SearchViewCustomerWidget(this);
    modifyCustomerWidget = new ModifyCustomerWidget(this);

    stackedWidget->addWidget(addCustomerWidget);
    stackedWidget->addWidget(searchViewCustomerWidget);
    stackedWidget->addWidget(modifyCustomerWidget);

    layout->addWidget(addButton);
    layout->addWidget(searchViewButton);
    layout->addWidget(modifyButton);
    layout->addWidget(exitButton);
    layout->addWidget(stackedWidget);

    setLayout(layout);
}

void MainWindow::connectSignals() {
    connect(addButton, &QPushButton::clicked, this, &MainWindow::showAddCustomerForm);
    connect(searchViewButton, &QPushButton::clicked, this, &MainWindow::showSearchViewCustomerForm);
    connect(modifyButton, &QPushButton::clicked, this, &MainWindow::showModifyCustomerForm);
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
    connect(addCustomerWidget, &AddCustomerWidget::cancelAddCustomer, this, &MainWindow::showHomeWidget);
}

void MainWindow::showAddCustomerForm() {
    stackedWidget->setCurrentWidget(addCustomerWidget);
}

void MainWindow::showSearchViewCustomerForm() {
    stackedWidget->setCurrentWidget(searchViewCustomerWidget);
}

void MainWindow::showModifyCustomerForm() {
    stackedWidget->setCurrentWidget(modifyCustomerWidget);
}

void MainWindow::showHomeWidget() {
    stackedWidget->setCurrentWidget(addCustomerWidget); // Assuming this is the home widget
}

void MainWindow::handleCustomerAdded(const QString& firstName, const QString& lastName,
                                     const QString& email, const QString& phoneNumber,
                                     const QString& accountNumber, const QString& address,
                                     const QString& plan) {
    if (!db.addCustomer(firstName, lastName, email, phoneNumber, accountNumber, address, plan)) {
        qDebug() << "Failed to add customer";
    } else {
        qDebug() << "Customer added successfully";
    }
}