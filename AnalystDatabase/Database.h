//
// Created by Chrystalkey on 29.07.2018.
//

#ifndef ALLDATAFLOWANALYST_DATABASE_H
#define ALLDATAFLOWANALYST_DATABASE_H

#include <QtCore/QObject>
#include <QtCore/QFile>
#include <QSqlDatabase>
#include <windef.h>

class Database : public QObject {
    Q_OBJECT
public:
    Database(const QString &dbName = "name.db", QObject *parent = nullptr);

    ~Database();

public slots:

    void resetDatabase();

    void addKeystroke(quint16 vkCode, quint16 scancode, quint16 keyState, qint64 timestamp);

    void addMouseaction(POINT point, quint32 clickType, const QString &windowName, quint32 cursorSpot,
                        qint64 timestamp);

public:
    QSqlQuery getKeystrokes();

    QSqlQuery getKeystrokesByTimestamp(qint64 timeStart, qint64 timeEnd);

    QSqlQuery getKeystrokesByVkCode(quint16 vkCode);

    QSqlQuery getKeystrokesByScanCode(quint16 scanCode);

    QSqlQuery getKeystrokesByKeystate(quint32 keyState);

    QSqlQuery getMouseactions();

    QSqlQuery getMouseactionsByTimestamp(qint64 timeStart, qint64 timeEnd);

    QSqlQuery getMouseactionsByPosition(quint32 xPos, quint32 yPos);

    QSqlQuery getMouseactionsByClickType(quint32 clickType);

    QSqlQuery getMouseactionsByWindowName(const QString &wndName);

    QSqlQuery getMouseactionsByCursorSpot(quint32 crsSpot);
private:
    void prepareNextId();

    QStringList dbStructure;
    QString dbName;
    QSqlDatabase db;
    long long lastId = 0;
};


#endif //ALLDATAFLOWANALYST_DATABASE_H
