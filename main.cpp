#include <QApplication>
#include "CustomerData.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Placeholder for database connection
    // Since we are focusing on UI, no real database connection is established.
    // Assuming a default constructor is present in CustomerDatabase that does not connect to the database.
    CustomerDatabase db;

    MainWindow window(db);
    window.setWindowTitle("EZTechMovieDB Management System");
    window.show();

    // Run the application
    return app.exec();
}