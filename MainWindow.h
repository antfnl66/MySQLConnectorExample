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
Q_OBJECT  // This macro is essential for signal-slot mechanism

public:
    explicit MainWindow(CustomerDatabase& db, QWidget *parent = nullptr); // Constructor accepting a database reference

private slots:
    void showAddCustomerForm();
    void showHomeWidget(); // Ensure this is declared
    void showModifyCustomerForm();
    void showSearchViewCustomerForm();
    void handleCustomerAdded(const QString& firstName, const QString& lastName,
                             const QString& email, const QString& phoneNumber,
                             const QString& accountNumber, const QString& address,
                             const QString& plan);

private:
    CustomerDatabase& db;  // Reference to CustomerDatabase
    QPushButton* addButton;
    QPushButton* searchViewButton;
    QPushButton* modifyButton;
    QPushButton* exitButton;
    QVBoxLayout* layout;
    QStackedWidget* stackedWidget;
    AddCustomerWidget *addCustomerWidget;
    SearchViewCustomerWidget *searchViewCustomerWidget;
    ModifyCustomerWidget *modifyCustomerWidget;

    void setupUi();  // Setup the UI components and layout
    void connectSignals();
};

#endif // MAINWINDOW_H