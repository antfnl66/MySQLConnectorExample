#ifndef SEARCHVIEWCUSTOMERWIDGET_H
#define SEARCHVIEWCUSTOMERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QFormLayout>

class SearchViewCustomerWidget : public QWidget {
Q_OBJECT

public:
    explicit SearchViewCustomerWidget(QWidget *parent = nullptr);

signals:
    void cancelSearch();

private:
    QVBoxLayout* mainLayout;
    QLineEdit* searchLineEdit;
    QComboBox* searchCriteriaComboBox;
    QLabel* resultsLabel;
    QPushButton* searchButton;
    QPushButton* cancelButton;

    void setupUi();
    void performSearch();
};

#endif // SEARCHVIEWCUSTOMERWIDGET_H