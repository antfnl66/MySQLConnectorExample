#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "CustomerData.h"  // Ensure this includes your CustomerDatabase definition

class MainWindow : public QWidget {
    Q_OBJECT  // This macro must be included to handle Qt's signals and slots mechanism

public:
    explicit MainWindow(CustomerDatabase& db, QWidget *parent = nullptr);

private:
    CustomerDatabase& db;  // Reference to your database interface

    // GUI components
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* modifyButton;
    QPushButton* searchButton;
    QPushButton* exitButton;
    QVBoxLayout* layout;

    void setupUi();  // Setup function for the UI
};

#endif // MAINWINDOW_H
