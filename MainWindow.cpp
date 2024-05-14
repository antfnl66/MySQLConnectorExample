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

    addCustomerWidget = new AddCustomerWidget(this);
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
}

void MainWindow::showAddCustomerForm() {
    stackedWidget->setCurrentWidget(addCustomerWidget);
}

void MainWindow::showHomeWidget() { // Ensure this is defined
    stackedWidget->setCurrentWidget(addCustomerWidget);
}

void MainWindow::showSearchViewCustomerForm() {
    stackedWidget->setCurrentWidget(searchViewCustomerWidget);
}

void MainWindow::showModifyCustomerForm() {
    stackedWidget->setCurrentWidget(modifyCustomerWidget);
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

// Include the MOC file at the very end of the source file
#include "MainWindow.moc"