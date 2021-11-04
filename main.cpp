#include <QApplication>
#include<nestedlayout.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto D =new nestedlayout;
    D->setWindowTitle("Nested Layout Test");

    D->show();

    return a.exec();
}
