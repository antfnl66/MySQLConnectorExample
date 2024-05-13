#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "CustomerData.h"
#include "AddCustomerWidget.h"
#include "SearchViewCustomerWidget.h"
#include "ModifyCustomerWidget.h"

class MainWindow : public QWidget {
    Q_OBJECT // Required macro for any class that implements signals, slots

public:
    explicit MainWindow(CustomerDatabase& db, QWidget *parent = nullptr);

private slots:  // Slot functions within Qt's signals and slots mechanism
            void showAddCustomerForm(); // Shows the form to add a new customer
    void showHomeWidget(); // Returns to the main/home view
    void showModifyCustomerForm(); // Shows the form to modify an existing customer
    void showSearchViewCustomerForm(); // Shows the form to search and view customers
    void handleCustomerAdded(const QString& firstName, const QString& lastName,
                             const QString& email, const QString& phoneNumber,
                             const QString& accountNumber, const QString& address,
                             const QString& plan); // Handles logic after a new customer is added

private:
    CustomerDatabase& db; // Reference to the CustomerDatabase, used for data operations

    QPushButton* addButton; // Button to open the add customer form
    QPushButton* searchViewButton; // Button to open the search/view customer form
    QPushButton* modifyButton; // Button to open the modify customer form
    QPushButton* exitButton; // Button to exit the application
    QVBoxLayout* layout; // Layout for the main window
    QStackedWidget* stackedWidget; // Widget stack to switch between different forms/views
    AddCustomerWidget *addCustomerWidget; // Widget for adding a new customer
    SearchViewCustomerWidget *searchViewCustomerWidget; // Widget for searching and viewing customers
    ModifyCustomerWidget *modifyCustomerWidget; // Widget for modifying existing customers

    void setupUi(); // Setup the UI components and layout
};

#endif // MAINWINDOW_H