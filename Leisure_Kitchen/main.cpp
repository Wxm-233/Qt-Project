
#include "game.h"
#include "start_window.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Start_Window sw;
    sw.show();
    return a.exec();
}
