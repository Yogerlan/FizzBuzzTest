#include "mainwindow.h"

MainWindow::MainWindow() {
    setWindowTitle("FizzBuzz test");

    // Display FizzBuzz.png image in a QLabel
    QPixmap *fbPixmap = new QPixmap("FizzBuzz.png");
    QLabel *fbLabel = new QLabel();
    fbLabel->setPixmap(fbPixmap->scaled(fbPixmap->width() / 2, fbPixmap->height() / 2));

    // Display parameters controls in a QGroupBox with QGridLayout
    QGroupBox *parametersGroupBox = new QGroupBox("Parameters");

    QGridLayout *qgLayout = new QGridLayout();

    // Fizz parameter
    QLabel *fizzLabel = new QLabel("Fizz");
    fizzSpinBox = new QSpinBox();
    fizzSpinBox->setRange(-1000, 1000);
    fizzSpinBox->setValue(3);

    // Buzz parameter
    QLabel *buzzLabel = new QLabel("Buzz");
    buzzSpinBox = new QSpinBox();
    buzzSpinBox->setRange(-1000, 1000);
    buzzSpinBox->setValue(5);

    // Start parameter
    QLabel *startLabel = new QLabel("Start");
    startSpinBox = new QSpinBox();
    startSpinBox->setRange(-1000, 1000);
    startSpinBox->setValue(1);

    // End parameter
    QLabel *endLabel = new QLabel("End");
    endSpinBox = new QSpinBox();
    endSpinBox->setRange(-1000, 1000);
    endSpinBox->setValue(100);

    qgLayout->addWidget(fizzLabel, 0, 0);
    qgLayout->addWidget(fizzSpinBox, 0, 1);
    qgLayout->addWidget(buzzLabel, 0, 2);
    qgLayout->addWidget(buzzSpinBox, 0, 3);
    qgLayout->addWidget(startLabel, 1, 0);
    qgLayout->addWidget(startSpinBox, 1, 1);
    qgLayout->addWidget(endLabel, 1, 2);
    qgLayout->addWidget(endSpinBox, 1, 3);

    parametersGroupBox->setLayout(qgLayout);

    // Display action controls in the MainWindow with QVBoxLayout
    QPushButton *buildCppTestButton = new QPushButton("Build C/C++ test");
    QPushButton *runCppTestButton = new QPushButton("Run C/C++ test");
    QPushButton *runPythonTestButton = new QPushButton("Run Python test");
    QPushButton *buildNodejsTestButton = new QPushButton("Build Node.js test");
    QPushButton *runNodejsTestButton = new QPushButton("Run Node.js test");
    QPushButton *runJavaTestButton = new QPushButton("Run Java test");

    QHBoxLayout *cppQHBoxLayout = new QHBoxLayout();
    QHBoxLayout *nodejsQHBoxLayout = new QHBoxLayout();
    QVBoxLayout *qvbLayout = new QVBoxLayout();

    connect(buildCppTestButton, &QPushButton::clicked, this, &MainWindow::buildCppTest);
    connect(runCppTestButton, &QPushButton::clicked, this, &MainWindow::runCppTest);
    connect(runPythonTestButton, &QPushButton::clicked, this, &MainWindow::runPythonTest);
    connect(buildNodejsTestButton, &QPushButton::clicked, this, &MainWindow::buildNodejsTest);
    connect(runNodejsTestButton, &QPushButton::clicked, this, &MainWindow::runNodejsTest);
    connect(runJavaTestButton, &QPushButton::clicked, this, &MainWindow::runJavaTest);

    cppQHBoxLayout->addWidget(buildCppTestButton);
    cppQHBoxLayout->addWidget(runCppTestButton);
    nodejsQHBoxLayout->addWidget(buildNodejsTestButton);
    nodejsQHBoxLayout->addWidget(runNodejsTestButton);

    qvbLayout->addWidget(fbLabel);
    qvbLayout->addWidget(parametersGroupBox);
    qvbLayout->addLayout(cppQHBoxLayout);
    qvbLayout->addWidget(runPythonTestButton);
    qvbLayout->addLayout(nodejsQHBoxLayout);
    qvbLayout->addWidget(runJavaTestButton);

    setLayout(qvbLayout);
}

void MainWindow::buildCppTest() {
    system("gnome-terminal -- ./cpp/build.sh");
}

void MainWindow::runCppTest() {
    int fizz = fizzSpinBox->value();
    int buzz = buzzSpinBox->value();
    int start = startSpinBox->value();
    int end = endSpinBox->value();
    std::string command = std::string("gnome-terminal -- ./cpp/fb_test -f ") 
        + std::to_string(fizz)
        + std::string(" -b ")
        + std::to_string(buzz)
        + std::string(" -s ")
        + std::to_string(start)
        + std::string(" -e ")
        + std::to_string(end);
    system(command.data());
}

void MainWindow::runPythonTest() {
    int fizz = fizzSpinBox->value();
    int buzz = buzzSpinBox->value();
    int start = startSpinBox->value();
    int end = endSpinBox->value();
    std::string command = std::string("gnome-terminal -- ./python/fb_test.py -f ") 
        + std::to_string(fizz)
        + std::string(" -b ")
        + std::to_string(buzz)
        + std::string(" -s ")
        + std::to_string(start)
        + std::string(" -e ")
        + std::to_string(end);
    system(command.data());
}

void MainWindow::buildNodejsTest() {
    system("gnome-terminal -- tsc ./javascript/fb_test.ts");
}

void MainWindow::runNodejsTest() {
    int fizz = fizzSpinBox->value();
    int buzz = buzzSpinBox->value();
    int start = startSpinBox->value();
    int end = endSpinBox->value();
    std::string command = std::string("gnome-terminal -- node ./javascript/fb_test.js -f ") 
        + std::to_string(fizz)
        + std::string(" -b ")
        + std::to_string(buzz)
        + std::string(" -s ")
        + std::to_string(start)
        + std::string(" -e ")
        + std::to_string(end);
    system(command.data());
}

void MainWindow::runJavaTest() {
    int fizz = fizzSpinBox->value();
    int buzz = buzzSpinBox->value();
    int start = startSpinBox->value();
    int end = endSpinBox->value();
    std::string command = std::string("gnome-terminal -- java ./java/fb_test.java -f ") 
        + std::to_string(fizz)
        + std::string(" -b ")
        + std::to_string(buzz)
        + std::string(" -s ")
        + std::to_string(start)
        + std::string(" -e ")
        + std::to_string(end);
    system(command.data());
}
