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
Q_OBJECT

public:
    explicit MainWindow(CustomerDatabase& db, QWidget *parent = nullptr);

private slots:
    void showAddCustomerForm();
    void showHomeWidget();
    void showModifyCustomerForm();
    void showSearchViewCustomerForm();
    void handleCustomerAdded(const QString& firstName, const QString& lastName,
                             const QString& email, const QString& phoneNumber,
                             const QString& accountNumber, const QString& address,
                             const QString& plan);

private:
    CustomerDatabase& db;
    QPushButton* addButton;
    QPushButton* searchViewButton;
    QPushButton* modifyButton;
    QPushButton* exitButton;
    QVBoxLayout* layout;
    QStackedWidget* stackedWidget;
    AddCustomerWidget *addCustomerWidget;
    SearchViewCustomerWidget *searchViewCustomerWidget;
    ModifyCustomerWidget *modifyCustomerWidget;

    void setupUi();
    void connectSignals();
};

#endif // MAINWINDOW_H