/********************************************************************************
** Form generated from reading UI file 'start_window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_WINDOW_H
#define UI_START_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start_Window
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *Start_Window)
    {
        if (Start_Window->objectName().isEmpty())
            Start_Window->setObjectName("Start_Window");
        Start_Window->resize(800, 600);
        QFont font;
        font.setPointSize(9);
        Start_Window->setFont(font);
        pushButton = new QPushButton(Start_Window);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(265, 330, 270, 90));
        QFont font1;
        font1.setPointSize(20);
        pushButton->setFont(font1);
        label = new QLabel(Start_Window);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 140, 491, 171));
        label->setFont(font);

        retranslateUi(Start_Window);

        QMetaObject::connectSlotsByName(Start_Window);
    } // setupUi

    void retranslateUi(QWidget *Start_Window)
    {
        Start_Window->setWindowTitle(QCoreApplication::translate("Start_Window", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Start_Window", "Click to Start", nullptr));
        label->setText(QCoreApplication::translate("Start_Window", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">Leisure Kitchen</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start_Window: public Ui_Start_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_WINDOW_H
