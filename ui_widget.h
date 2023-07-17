/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(350, 350);
        Widget->setMinimumSize(QSize(350, 350));
        Widget->setMaximumSize(QSize(350, 350));
        Widget->setSizeIncrement(QSize(350, 250));
        Widget->setBaseSize(QSize(350, 350));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 310, 75, 23));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(175);
        sizePolicy.setVerticalStretch(175);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setBaseSize(QSize(100, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans Light"));
        font.setItalic(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }\n"
"    QPushButton:pressed {\n"
"    background-color:rgb(180,180,180);\n"
"    }"));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 180, 113, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }"));
        lineEdit->setMaxLength(25);
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 220, 113, 20));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }"));
        lineEdit_2->setInputMethodHints(Qt::ImhNone);
        lineEdit_2->setMaxLength(25);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 180, 47, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Noto Serif Light"));
        font1.setPointSize(11);
        font1.setItalic(true);
        label->setFont(font1);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 220, 61, 16));
        label_2->setFont(font1);
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(130, 280, 121, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Noto Sans Light"));
        font2.setPointSize(9);
        font2.setItalic(true);
        checkBox->setFont(font2);
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"     background-color:rgb(180,180,180);\n"
" }\n"
"\n"
"QCheckBox::indicator:checked {\n"
"     background-color:rgb(66,66,66);\n"
" }\n"
""));
        checkBox_2 = new QCheckBox(Widget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(130, 260, 101, 17));
        checkBox_2->setFont(font2);
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox::indicator{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"     background-color:rgb(180,180,180);\n"
" }\n"
"\n"
"QCheckBox::indicator:checked {\n"
"     background-color:rgb(66,66,66);\n"
" }\n"
""));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 40, 230, 90));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\320\222\321\205\320\276\320\264", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\320\227\320\260\320\277\320\276\320\274\320\275\320\270\321\202\321\214 \320\274\320\265\320\275\321\217", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
