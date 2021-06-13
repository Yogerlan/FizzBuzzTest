#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QtWidgets>

class MainWindow : public QWidget {
    public:
        MainWindow();
    private:
        QSpinBox *fizzSpinBox;
        QSpinBox *buzzSpinBox;
        QSpinBox *startSpinBox;
        QSpinBox *endSpinBox;
        void buildCppTest();
        void runCppTest();
        void runPythonTest();
        void buildNodejsTest();
        void runNodejsTest();
        void runJavaTest();
};

#endif  // MAIN_WINDOW_H_
