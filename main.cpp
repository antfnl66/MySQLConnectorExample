#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include "CustomerData.h"

void displayCustomer(const Customer& customer) {
    QMessageBox msgBox;
    msgBox.setText("Customer ID: " + QString::number(customer.id) +
                   "\nName: " + QString::fromStdString(customer.name) +
                   "\nPlan: " + QString::fromStdString(customer.plan));
    msgBox.exec();
}

void addCustomerGUI(CustomerDatabase& db, QWidget* parent) {
    // This function would eventually open a form dialog to add a customer
    QMessageBox::information(parent, "Add Customer", "This will open a customer add form.");
}

void deleteCustomerGUI(CustomerDatabase& db, QWidget* parent) {
    // This function would eventually open a form dialog to delete a customer
    QMessageBox::information(parent, "Delete Customer", "This will open a customer delete form.");
}

void modifyCustomerGUI(CustomerDatabase& db, QWidget* parent) {
    // This function would eventually open a form dialog to modify a customer
    QMessageBox::information(parent, "Modify Customer", "This will open a customer modify form.");
}

void searchCustomerGUI(CustomerDatabase& db, QWidget* parent) {
    // This function would eventually open a form dialog to search a customer
    QMessageBox::information(parent, "Search Customer", "This will open a customer search form.");
}

class MainWindow : public QWidget {
public:
    MainWindow(CustomerDatabase& db) {
        auto* layout = new QVBoxLayout(this);
        QPushButton* addButton = new QPushButton("Add Customer", this);
        QPushButton* deleteButton = new QPushButton("Delete Customer", this);
        QPushButton* modifyButton = new QPushButton("Modify Customer", this);
        QPushButton* searchButton = new QPushButton("Search Customer by Name", this);
        QPushButton* exitButton = new QPushButton("Exit", this);

        layout->addWidget(addButton);
        layout->addWidget(deleteButton);
        layout->addWidget(modifyButton);
        layout->addWidget(searchButton);
        layout->addWidget(exitButton);

        connect(addButton, &QPushButton::clicked, [this, &db] { addCustomerGUI(db, this); });
        connect(deleteButton, &QPushButton::clicked, [this, &db] { deleteCustomerGUI(db, this); });
        connect(modifyButton, &QPushButton::clicked, [this, &db] { modifyCustomerGUI(db, this); });
        connect(searchButton, &QPushButton::clicked, [this, &db] { searchCustomerGUI(db, this); });
        connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CustomerDatabase db;  // Initialize the database connection
    MainWindow window(db);
    window.setWindowTitle("EZTechMovieDB Management System");
    window.show();
    return app.exec();
}
