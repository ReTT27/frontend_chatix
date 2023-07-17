#ifndef MESSENGER_H
#define MESSENGER_H

#include <QDialog>

#include "widget.h"

#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QRegularExpression>
#include <QTimer>

namespace Ui {
class Messenger;
}

class Messenger : public QDialog
{
    Q_OBJECT

public:
    explicit Messenger(QWidget *parent = nullptr);
    ~Messenger();

    QTcpSocket* socket;
    QByteArray Data;
    QString loginned;
    QString loginSelectedToChat;

    QFont sansFont = QFont("Segoe UI", 7);
    QColor timeCol = QColor(0, 0, 0, 120);

    QStringList text;
    QStringList emoji;

    QJsonDocument doc;
    QJsonParseError docError;
    QTimer *tmr;

    int counter = 0;

    QString* lsave;
    QString* psave;
    bool* reg;
    void formLoaded();
    void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);

public slots:
    void sockReady();
    void sockDisconnect();
private slots:
    void updateTime();

    void on_pushButton_2_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Messenger *ui;
};

#endif // MESSENGER_H
