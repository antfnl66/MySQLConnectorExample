#ifndef ADDCUSTOMERWIDGET_H
#define ADDCUSTOMERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QComboBox> // For the plan selection dropdown

class AddCustomerWidget : public QWidget {
    Q_OBJECT  // Qt macro to handle signals and slots

public:
    explicit AddCustomerWidget(QWidget *parent = nullptr);

    signals:
            void cancelAddCustomer();
    void customerAdded(const QString &firstName,
                       const QString &lastName,
                       const QString &email,
                       const QString &phoneNumber,
                       const QString &accountNumber,
                       const QString &address,
                       const QString &plan);

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
    QComboBox *planComboBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(); // Function to set up the UI components
};

#endif // ADDCUSTOMERWIDGET_H