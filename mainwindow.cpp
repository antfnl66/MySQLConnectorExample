#include "MainWindow.h"
#include <QMessageBox>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

class AddCustomerWidget : public QWidget {
public:
    AddCustomerWidget(QWidget *parent = nullptr) {
        // Setup layout and inputs here
    }
};

MainWindow::MainWindow(CustomerDatabase& db, QWidget *parent)
    : QWidget(parent), db(db) {
    setupUi();
}

void MainWindow::setupUi() {
    auto *stackedWidget = new QStackedWidget(this);
    auto *homeWidget = new QWidget(this);
    layout = new QVBoxLayout(homeWidget);

    addButton = new QPushButton("Add Customer", this);
    deleteButton = new QPushButton("Delete Customer", this);
    modifyButton = new QPushButton("Modify Customer", this);
    searchButton = new QPushButton("Search Customer by Name", this);
    exitButton = new QPushButton("Exit", this);

    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    layout->addWidget(modifyButton);
    layout->addWidget(searchButton);
    layout->addWidget(exitButton);

    // Setup AddCustomerWidget and add to stacked widget
    auto *addCustomerWidget = new AddCustomerWidget();
    stackedWidget->addWidget(homeWidget);  // index 0
    stackedWidget->addWidget(addCustomerWidget);  // index 1

    connect(addButton, &QPushButton::clicked, [this, stackedWidget] {
        stackedWidget->setCurrentIndex(1);  // Switch to Add Customer screen
    });
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);

    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
}
