#ifndef MODIFYCUSTOMERWIDGET_H
#define MODIFYCUSTOMERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QPushButton>
#include <QMessageBox> // Ensure QMessageBox is included

class ModifyCustomerWidget : public QWidget {
Q_OBJECT

public:
    explicit ModifyCustomerWidget(QWidget *parent = nullptr);
    void searchCustomers(const QString& searchTerm, const QString& searchCriteria);
    void modifySelectedCustomer();

signals:
    void cancelModifyCustomer();

private:
    QLineEdit *searchLineEdit;
    QComboBox *searchCriteriaComboBox;
    QTableWidget *resultsTableWidget;
    QPushButton *modifyButton;
    QPushButton *cancelButton;

    void setupUi();
};

#endif // MODIFYCUSTOMERWIDGET_H