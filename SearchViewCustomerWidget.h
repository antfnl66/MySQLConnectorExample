#ifndef SEARCHVIEWCUSTOMERWIDGET_H
#define SEARCHVIEWCUSTOMERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QTextEdit>

class SearchViewCustomerWidget : public QWidget {
Q_OBJECT

public:
    explicit SearchViewCustomerWidget(QWidget *parent = nullptr);

private slots:
    void cancelSearch();
    void performSearch();

private:
    void setupUi();
    void displayResults(const QString& results);

    QVBoxLayout *mainLayout;
    QLineEdit *searchLineEdit;
    QComboBox *searchCriteriaComboBox;
    QPushButton *searchButton;
    QPushButton *cancelButton;
    QLabel *resultsLabel;
    QTextEdit *resultsBox;
};

#endif // SEARCHVIEWCUSTOMERWIDGET_H