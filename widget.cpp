#include "widget.h"
#include "ui_widget.h"
#include "QIcon"
#include "messenger.h"
#include "QPixmap"
#include "QFile"
#include <QDesktopServices>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit_2->setToolTip("• должен содержать от 4 до 16 символов\n• не должно быть символов из набора: * & { } | +\n• должны встречаться заглавные буквы\n• должны встречаться цифры ");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo-chatix.png"));
    QPixmap pix(":/embleminput/logo-chatix2.png");
    ui->label_3->setPixmap(pix.scaled(230,90, Qt::KeepAspectRatio));    
    ui->pushButton->setShortcut(Qt::Key_Return);

    path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/daan.qwe";
    if(QFile::exists(path))
        {
            QFile fin(path);
            QByteArray dat;
            if(fin.open(QIODevice::ReadOnly))
            {
                dat = fin.readAll();
                if(dat!="")
                {
                    QStringList list = QString(dat).split(":");
                    ui->lineEdit->setText(list[0]);
                    ui->lineEdit_2->setText(list[1]);
                    if (list[0] != "")
                    ui->checkBox->setChecked(true);
                }
            }
        }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(ui->checkBox_2->isChecked())
        reg = true;

    lsave = ui->lineEdit->text();
    psave = ui->lineEdit_2->text();

    if((lsave == "")||(psave == ""))
    {
        QMessageBox::information(this,"Информация","Введите логин или пароль");
        return;
    }

    QFile f(path);
    if(!f.open(QIODevice::WriteOnly))
        return;
    QTextStream write(&f);
    if(ui->checkBox->isChecked())
    {
        write << ui->lineEdit->text() << ":" << ui->lineEdit_2->text();
    }
    else
    {
        write <<""<< ":" <<"";
    }
    f.close();

    Messenger p;
    p.lsave = &lsave;
    p.psave = &psave;
    p.reg = &reg;
    p.formLoaded();
    this->close();
    p.exec();
}
