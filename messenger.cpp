#include "messenger.h"
#include "ui_messenger.h"
#include "QIcon"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

Messenger::Messenger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Messenger)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo-chatix.png"));
    ui->pushButton->setIcon(QIcon(":/send-message.png"));
    ui->pushButton_3->setIcon(QIcon(":/door.png"));
    ui->pushButton->setShortcut(Qt::Key_Return);
    ui->pushButton_3->setToolTip("Возврат в форму авторизации");

    socket = new QTcpSocket(this);
        connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisconnect()));

    tmr = new QTimer();
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->setInterval(500);
}

Messenger::~Messenger()
{
    delete ui;
}

void Messenger::formLoaded()
{

    text.append("<3");
    emoji.append("💗");

    text.append(":)");
    emoji.append("🙂");

    text.append(":|");
    emoji.append("😐");

    text.append(":0");
    emoji.append("😮");

    text.append(":змея:");
    emoji.append("🐍");

    text.append(":дракон:");
    emoji.append("🐉");

    text.append(":фак:");
    emoji.append("🖕");

    text.append(":привет:");
    emoji.append("👋");

    text.append(":чат:");
    emoji.append("💬");

    text.append(":ок:");
    emoji.append("✅");

    text.append(":нет:");
    emoji.append("❌");

    text.append(":думаю:");
    emoji.append("🤔");

    text.append(":буратино:");
    emoji.append("🤥");

    text.append(":сон:");
    emoji.append("😴");

    text.append(":блев:");
    emoji.append("🤮");

    text.append(":фу:");
    emoji.append("🤢");

    text.append(":крутой:");
    emoji.append("😎");

    text.append(":пж:");
    emoji.append("🥺");

    text.append(":дерьмо:");
    emoji.append("💩");

    text.append(":клоун:");
    emoji.append("🤡");

    //ui->label->setText(*lsave+" "+*psave);

    //7.tcp.eu.ngrok.io:15595
    //socket->connectToHost("7.tcp.eu.ngrok.io",13448);
    socket->connectToHost("127.0.0.1",8080);

    QString login = *lsave;
    QString password = *psave;


    if(!socket->waitForConnected(500)){ QMessageBox::information(this,"Информация","Соединение не установлено"); qApp->exit();   return; }
    socket->waitForBytesWritten(500);

    if(*reg)
    {
        QRegularExpression re("^(?=.*[A-Z])(?=.*[0-9])(?!.*[*&{}|+]).{4,16}$");

        QRegularExpressionMatch match = re.match(password);

        if(login.length()<3+1)
        {
            QJsonDocument reg;
            QJsonObject obj;
            obj.insert("type", "register");
            obj.insert("error", "1");
            reg.setObject(obj);
            socket->write(reg.toJson());

            //QMessageBox::information(this,"Логин не соответсвует требованиям","Логин не может стостоять из <3 символов");
            //Widget* login = new Widget;
            //login->show();
            //this->close();
            return;
        }

        match.hasMatch();
        if(match.hasMatch()!=true)
        {
            QJsonDocument reg;
            QJsonObject obj;
            obj.insert("type", "register");
            obj.insert("error", "2");
            reg.setObject(obj);
            socket->write(reg.toJson());
            //QMessageBox::information(this,"Пароль не соответсвует требованиям","Требования к паролю:\n• должен содержать от 4 до 16 символов \n• не должно быть символов из набора: * & { } | + \n• должны встречаться заглавные буквы \n• должны встречаться цифры");
            //Widget* login = new Widget;
            //login->show();
            //this->close();
            return;
        }

        QJsonDocument reg;
        QJsonObject obj;
        obj.insert("type", "register");
        obj.insert("login", login);
        obj.insert("password", password);
        reg.setObject(obj);
        socket->write(reg.toJson());

        return;
    }

    if(!socket->waitForConnected(500)){ QMessageBox::information(this,"Информация","Соединение не установлено"); qApp->exit();   return; }
    socket->waitForBytesWritten(500);

    QJsonDocument log;
    QJsonObject obj;
    obj.insert("type", "login");
    obj.insert("login", login);
    obj.insert("password", password);
    log.setObject(obj);
    socket->write(log.toJson());
}

void Messenger::updateTime()
{
    //ну не лагает зато
    if(!socket->waitForConnected(500)){ QMessageBox::information(this,"Информация","Соединение не установлено"); return; }
    //socket->waitForBytesWritten(500);

    if(loginSelectedToChat=="")
    {
        ui->listWidget_2->clear();
        return;
    }

    QJsonDocument t;
    QJsonObject obj;
    obj.insert("type", "reciveallmsg");
    obj.insert("from", loginned);
    obj.insert("to", loginSelectedToChat);
    t.setObject(obj);
    socket->write(t.toJson());
}

void Messenger::sockReady()
{
    //ну не лагает зато
    if(!socket->waitForConnected(500)){ QMessageBox::information(this,"Информация","Соединение не установлено"); return; }

    //socket->waitForReadyRead(100);
    Data = socket->readAll();
    qDebug() << Data;

    doc = QJsonDocument::fromJson(Data,&docError);

    QString type = doc.object().value("type").toString();


    if(docError.errorString().toInt()!=QJsonParseError::NoError){ QMessageBox::information(this, "Информация", "Ошибка в распознании документа с сервера: "+docError.errorString()); return; }

    if ((type == "connect")&&(doc.object().value("status").toString() != "ok")){ QMessageBox::information(this,"Информация","Соединение не установлено"); qApp->exit();  return; }
    else { /* Удалить потом QMessageBox::information(this,"Информация","Соединение установлено"); */ }

    if(type == "msg")
    {
        if(doc.object().value("status").toString()=="1")
        {
            Widget* login = new Widget;
            login->show();
            this->close();
            QMessageBox::information(this,"Сообщение от сервера",doc.object().value("str").toString());
            return;
        }
        QMessageBox::information(this,"Сообщение от сервера",doc.object().value("str").toString());
    }

    if((doc.object().value("login").toString() != ""))
    {
        loginned = doc.object().value("login").toString();

        QJsonDocument chatList;
        QJsonObject obj;
        obj.insert("type", "getchats");
        obj.insert("login", loginned);
        chatList.setObject(obj);
        socket->write(chatList.toJson());
        socket->waitForBytesWritten(150);
        updateTime();
        tmr->start();
    }

    if(type == "allmsg")
    {
        QJsonArray a = doc.object().value("result").toArray();
        //QMessageBox m;
        //m.setText(QString::number(a.count()*2)+ " " +QString::number(ui->listWidget_2->count()));
        //m.exec();
        //if(((a.count()*2)==ui->listWidget_2->count()))
        //{
        //    if(a[a.count()-1].toObject().value("from").toString()==loginned)
        //    {
                //return;
        //    }
            //return;
        //}
        ui->listWidget_2->clear();
        for(int i = 0;i<a.count();i++)
        {
            ui->listWidget_2->addItem("["+a[i].toObject().value("date").toString()+"]");
            ui->listWidget_2->item(ui->listWidget_2->count()-1)->setFont(sansFont);
            ui->listWidget_2->item(ui->listWidget_2->count()-1)->setForeground(timeCol);
            ui->listWidget_2->addItem(a[i].toObject().value("from").toString()+": "+a[i].toObject().value("str").toString());
        }
        if(counter == 0)
        {
            ui->listWidget_2->scrollToBottom();
            counter++;
        }
    }

    if(type == "addchat")
    {
        QString add = doc.object().value("addedlogin").toString();
        ui->lineEdit_2->clear();
        ui->listWidget->addItem(add);
    }

    if(type == "getchats")
    {
        QString chatsString = doc.object().value("chats").toString();
        if(chatsString=="")
        {
            return;
        }
        QStringList chats = chatsString.split(";");
        for(auto i:chats)
            ui->listWidget->addItem(i);
    }
};

void Messenger::sockDisconnect()
{
    socket->deleteLater();
};

void Messenger::on_pushButton_2_clicked()
{
    //Добавить друга

    if(!socket->waitForConnected(500)){ QMessageBox::information(this,"Информация","Соединение не установлено"); qApp->exit(); return; }
    socket->waitForBytesWritten(500);

    QString name = ui->lineEdit_2->text();


    std::string te = name.toStdString();
    for (int i = 0;i<text.count();i++)
    {
        findAndReplaceAll(te,text[i].toStdString(),emoji[i].toStdString());
    }
    name = QString::fromStdString(te);

    if(name == "")
    {
        QMessageBox::information(this,"Информация","Введите логин того кого хотите добавить");
        return;
    }

    if(loginned == "")
    {
        QMessageBox::information(this,"Информация","Войдите в аккаунт");
        return;
    }

    QJsonDocument t;
    QJsonObject obj;
    obj.insert("type", "addfriend");
    obj.insert("login", loginned);
    obj.insert("addlogin", name);
    t.setObject(obj);
    socket->write(t.toJson());
}

void Messenger::on_listWidget_currentRowChanged(int currentRow)
{
    //смена чата
    loginSelectedToChat = ui->listWidget->item(currentRow)->text();
    counter = 0;
}


void Messenger::findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
    }
}

void Messenger::on_pushButton_clicked()
{
    if(!socket->waitForConnected(500)){ QMessageBox::information(this,"Информация","Соединение не установлено"); qApp->exit();  return; }

    QString msg = ui->lineEdit->text();

    if(msg=="")
    {
        return;
    }

    std::string te = msg.toStdString();
    for (int i = 0;i<text.count();i++)
    {
        findAndReplaceAll(te,text[i].toStdString(),emoji[i].toStdString());
    }
    msg = QString::fromStdString(te);

    if(loginned == "")
    {
        QMessageBox::information(this,"Информация","Войдите в аккаунт");
        return;
    }

    if(loginSelectedToChat=="")
    {
        QMessageBox::information(this,"Информация","Выберете в списке слева имя получателя");
        ui->listWidget_2->clear();
        return;
    }

    QJsonDocument t;
    QJsonObject obj;
    obj.insert("type", "msg");
    obj.insert("date", "");
    obj.insert("from", loginned);
    obj.insert("to", loginSelectedToChat);
    obj.insert("str", msg);
    t.setObject(obj);
    socket->write(t.toJson());
    socket->waitForBytesWritten(100);
    ui->listWidget_2->addItem("Загрузка..");
    ui->listWidget_2->scrollToBottom();
    ui->lineEdit->clear();
}

void Messenger::on_pushButton_3_clicked()
{
    sockDisconnect();
    Widget* login = new Widget;
    login->show();
    this->close();
}

void Messenger::on_pushButton_4_clicked()
{
    //Создать группу

    if(!socket->waitForConnected(500)){ QMessageBox::information(this,"Информация","Соединение не установлено"); qApp->exit(); return; }
    socket->waitForBytesWritten(500);

    QString name = ui->lineEdit_2->text();

    std::string te = name.toStdString();
    for (int i = 0;i<text.count();i++)
    {
        findAndReplaceAll(te,text[i].toStdString(),emoji[i].toStdString());
    }
    name = QString::fromStdString(te);

    if(name == "")
    {
        QMessageBox::information(this,"Информация","Введите уникальное имя группы которую хотите создать");
        return;
    }

    if(loginned == "")
    {
        QMessageBox::information(this,"Информация","Войдите в аккаунт");
        return;
    }

    QJsonDocument t;
    QJsonObject obj;
    obj.insert("type", "addgroup");
    obj.insert("login", loginned);
    obj.insert("addlogin", name);
    t.setObject(obj);
    socket->write(t.toJson());
}
