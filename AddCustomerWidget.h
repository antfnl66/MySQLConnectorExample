#ifndef ADDCUSTOMERWIDGET_H
#define ADDCUSTOMERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>

class AddCustomerWidget : public QWidget {
Q_OBJECT

public:
    explicit AddCustomerWidget(QWidget *parent = nullptr);

signals:
    void customerAdded(const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber, const QString &accountNumber, const QString &address, const QString &plan);
    void cancelAddCustomer();

private:
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *accountNumberLineEdit;
    QLineEdit *addressLineEdit;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *emailLabel;
    QLabel *phoneNumberLabel;
    QLabel *accountNumberLabel;
    QLabel *addressLabel;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QComboBox *planComboBox;

    void setupUi();
};

#endif // ADDCUSTOMERWIDGET_H