#ifndef SEARCHVIEWCUSTOMERWIDGET_H
#define SEARCHVIEWCUSTOMERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QPushButton>
#include <QMessageBox> // Ensure QMessageBox is included

class SearchViewCustomerWidget : public QWidget {
Q_OBJECT

public:
    explicit SearchViewCustomerWidget(QWidget *parent = nullptr);
    void performSearch(const QString& searchTerm, const QString& searchCriteria);
    void viewCustomerDetails();

signals:
    void cancelSearchViewCustomer();

private:
    QLineEdit *searchLineEdit;
    QComboBox *searchCriteriaComboBox;
    QTableWidget *resultsTableWidget;
    QPushButton *viewDetailsButton;
    QPushButton *cancelButton;

    void setupUi();
};

#endif // SEARCHVIEWCUSTOMERWIDGET_H