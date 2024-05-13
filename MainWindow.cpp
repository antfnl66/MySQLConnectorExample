#include "MainWindow.h"

MainWindow::MainWindow(CustomerDatabase& db, QWidget *parent) : QWidget(parent), db(db) {
    setupUi();
    // Connect the customerAdded signal from AddCustomerWidget to the handleCustomerAdded slot
    connect(addCustomerWidget, &AddCustomerWidget::customerAdded, this, &MainWindow::handleCustomerAdded);
}


void MainWindow::setupUi() {
    layout = new QVBoxLayout(this);

    addButton = new QPushButton("Add Customer", this);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::showAddCustomerForm);

    searchViewButton = new QPushButton("Search/View Customer", this);
    connect(searchViewButton, &QPushButton::clicked, this, &MainWindow::showSearchViewCustomerForm);

    modifyButton = new QPushButton("Modify Customer", this);
    connect(modifyButton, &QPushButton::clicked, this, &MainWindow::showModifyCustomerForm);

    exitButton = new QPushButton("Exit", this);
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);

    layout->addWidget(addButton);
    layout->addWidget(searchViewButton);
    layout->addWidget(modifyButton);
    layout->addWidget(exitButton);

    stackedWidget = new QStackedWidget(this);
    layout->addWidget(stackedWidget);

    addCustomerWidget = new AddCustomerWidget(this);
    searchViewCustomerWidget = new SearchViewCustomerWidget(this);
    modifyCustomerWidget = new ModifyCustomerWidget(this);

    stackedWidget->addWidget(addCustomerWidget);
    stackedWidget->addWidget(searchViewCustomerWidget);
    stackedWidget->addWidget(modifyCustomerWidget);

    setLayout(layout);
}

void MainWindow::showAddCustomerForm() {
    stackedWidget->setCurrentWidget(addCustomerWidget);
}

void MainWindow::showHomeWidget() {
    stackedWidget->setCurrentWidget(addCustomerWidget); // Assuming this is the home widget
}

void MainWindow::showModifyCustomerForm() {
    stackedWidget->setCurrentWidget(modifyCustomerWidget);
}

void MainWindow::showSearchViewCustomerForm() {
    stackedWidget->setCurrentWidget(searchViewCustomerWidget);
}

void MainWindow::handleCustomerAdded(const QString& firstName, const QString& lastName,
                                      const QString& email, const QString& phoneNumber,
                                      const QString& accountNumber, const QString& address,
                                      const QString& plan) {
    if (!db.addCustomer(firstName, lastName, email, phoneNumber, accountNumber, address, plan)) {
        qDebug() << "Failed to add customer";
        // Optionally, provide user feedback about the failure
    } else {
        qDebug() << "Customer added successfully";
        // Optionally, clear the input fields or update the UI
    }
}


// Include the MOC file at the very end of the source file
#include "MainWindow.moc"
