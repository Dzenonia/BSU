#include <QApplication>

#include "main_window.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
    QApplication app(argc, argv);

    MainWindow window;
    window.show();


    return QApplication::exec();
}
