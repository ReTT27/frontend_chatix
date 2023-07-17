/********************************************************************************
** Form generated from reading UI file 'messenger.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSENGER_H
#define UI_MESSENGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Messenger
{
public:
    QPushButton *pushButton;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Messenger)
    {
        if (Messenger->objectName().isEmpty())
            Messenger->setObjectName(QString::fromUtf8("Messenger"));
        Messenger->resize(912, 548);
        Messenger->setMinimumSize(QSize(912, 548));
        Messenger->setMaximumSize(QSize(912, 548));
        pushButton = new QPushButton(Messenger);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(860, 510, 40, 30));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"     background-color: rgb(180,180,180);\n"
" }"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/embleminput/send-message.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setAutoDefault(false);
        listWidget = new QListWidget(Messenger);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 40, 211, 421));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }\n"
"\n"
"\n"
"QListView::item:selected {\n"
"     border: none;\n"
"	background-color:rgb(152,180,180);\n"
" }"));
        listWidget_2 = new QListWidget(Messenger);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(230, 10, 671, 491));
        QFont font;
        font.setPointSize(11);
        listWidget_2->setFont(font);
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }\n"
"\n"
"QListView::item:selected {\n"
"     border: none;\n"
"	background-color:rgb(152,180,180);\n"
" }"));
        listWidget_2->setWordWrap(true);
        lineEdit_2 = new QLineEdit(Messenger);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 480, 113, 23));
        QFont font1;
        font1.setPointSize(9);
        font1.setItalic(false);
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }"));
        lineEdit_2->setMaxLength(50);
        label = new QLabel(Messenger);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 460, 211, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Noto Sans Light"));
        font2.setPointSize(8);
        font2.setItalic(true);
        label->setFont(font2);
        lineEdit = new QLineEdit(Messenger);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 510, 621, 29));
        QFont font3;
        font3.setPointSize(10);
        font3.setItalic(false);
        lineEdit->setFont(font3);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }"));
        lineEdit->setMaxLength(100);
        pushButton_2 = new QPushButton(Messenger);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 480, 91, 23));
        QFont font4;
        font4.setPointSize(9);
        font4.setItalic(true);
        pushButton_2->setFont(font4);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }\n"
"    QPushButton:pressed {\n"
"    background-color:rgb(180,180,180);\n"
"    }"));
        label_2 = new QLabel(Messenger);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 10, 91, 15));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Noto Sans Light"));
        font5.setPointSize(9);
        font5.setItalic(true);
        label_2->setFont(font5);
        pushButton_3 = new QPushButton(Messenger);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 10, 21, 21));
        pushButton_3->setFont(font4);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    }"));
        pushButton_4 = new QPushButton(Messenger);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 510, 211, 30));
        pushButton_4->setFont(font4);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"    background-color:rgb(230,230,230);\n"
"    border-radius: 5px;\n"
"    }\n"
"    QPushButton:pressed {\n"
"    background-color:rgb(180,180,180);\n"
"    }"));

        retranslateUi(Messenger);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Messenger);
    } // setupUi

    void retranslateUi(QDialog *Messenger)
    {
        Messenger->setWindowTitle(QCoreApplication::translate("Messenger", "ChatiX", nullptr));
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("Messenger", "\320\233\320\276\320\263\320\270\320\275 \320\270\320\273\320\270 \321\203\320\275\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\265 \320\270\320\274\321\217 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Messenger", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", nullptr));
        label_2->setText(QCoreApplication::translate("Messenger", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\207\320\260\321\202\320\276\320\262", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Messenger", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Messenger: public Ui_Messenger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSENGER_H
