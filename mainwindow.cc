#include "mainwindow.h"

MainWindow::MainWindow() {
    QPushButton *cppTestButton = new QPushButton("C/C++ test");
    QPushButton *pythonTestButton = new QPushButton("Python test");
    QPushButton *nodejsTestButton = new QPushButton("Node.js test");
    QPushButton *javaTestButton = new QPushButton("Java test");

    QVBoxLayout *qvbLayout = new QVBoxLayout();

    connect(cppTestButton, &QPushButton::clicked, this, &MainWindow::cppTest);

    qvbLayout->addWidget(cppTestButton);
    qvbLayout->addWidget(pythonTestButton);
    qvbLayout->addWidget(nodejsTestButton);
    qvbLayout->addWidget(javaTestButton);

    setLayout(qvbLayout);
}

void MainWindow::cppTest() {
    // code here
}
