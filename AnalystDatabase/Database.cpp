//
// Created by Chrystalkey on 29.07.2018.
//

#include <QtSql/QSqlQuery>
#include <QDebug>
#include <c++/iostream>
#include "Database.h"


Database::Database(const QString &dbName, QObject *parent) : QObject(parent), dbName(dbName) {
    QFile tmp(":/dbstructure.sql");
    tmp.open(QFile::ReadOnly);
    dbStructure = QString(tmp.readAll()).split('\n');
    tmp.close();
    if (!QFile::exists(dbName)) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);
        Q_ASSERT(db.open() == true);
        QSqlQuery query;
        qDebug() << dbStructure;
        for (QString &q:dbStructure) Q_ASSERT(query.exec(q) == true);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);
        Q_ASSERT(db.open() == true);
    }
    prepareNextId();
}

void Database::prepareNextId() {
    QSqlQuery query;
    query.exec("SELECT id FROM TABLE keystrokes ORDER BY id DESC");
    if (!query.first()) {
        lastId = 0;
    } else {
        lastId = query.value(0).toLongLong() + 1;
    }
    query.clear();
    query.exec("SELECT id FROM TABLE mouseactions ORDER BY id DESC;");
    if (query.first()) {
        long long i = query.value(0).toLongLong();
        lastId = i >= lastId ? i + 1 : lastId;
    }
    std::cerr << lastId << " \n";
}

Database::~Database() {
    //db.close();
    //QSqlDatabase::removeDatabase(db.connectionName());
}

void Database::resetDatabase() {
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    Q_ASSERT(db.open() == true);
    QSqlQuery query;
    for (QString &q:dbStructure)
        Q_ASSERT(query.exec(q) == true);
}

void Database::addKeystroke(quint16 vkCode, quint16 scancode, quint16 keyState, qint64 timestamp) {
    QSqlQuery query;
    Q_ASSERT(QSqlDatabase::database().isOpen());
    Q_ASSERT(QSqlDatabase::database().isValid());
    QString queryString;
    queryString = "INSERT INTO keystrokes(id, vkCode, scanCode, keyState, timestmp) VALUES (" +
                  QString::number(lastId++) + ", " +
                  QString::number(vkCode) + ", " +
                  QString::number(scancode) + ", " +
                  QString::number(keyState) + ", " +
                  QString::number(timestamp) + ");";
//    qDebug() << queryString;
    Q_ASSERT(query.exec(queryString));
}

void Database::addMouseaction(POINT point, quint32 clickType, const QString &windowName,
                              quint32 cursorSpot, qint64 timestamp) {
    Q_ASSERT(QSqlDatabase::database().isOpen());
    Q_ASSERT(QSqlDatabase::database().isValid());
    QString queryString;
    QSqlQuery query;
    queryString = "INSERT INTO mouseactions(id, xPos,yPos,clickType,windowName,cursorSpot,timestmp) VALUES (";
    queryString +=
            QString::number(lastId++) + ", " +
            QString::number(point.x) + ", " +
            QString::number(point.y) + ", " +
            QString::number(clickType) + ", '" +
            windowName + "', " +
            QString::number(cursorSpot) + ", " +
            QString::number(timestamp) + ");";
//    qDebug() << queryString;
    Q_ASSERT(query.exec(queryString));
}

QSqlQuery Database::getKeystrokes() {
    return QSqlQuery("SELECT * FROM TABLE keystrokes;");
}

QSqlQuery Database::getKeystrokesByVkCode(quint16 vkCode) {
    return QSqlQuery("SELECT * FROM TABLE keystrokes WHERE vkCode = " + QString::number(vkCode) + ";");
}

QSqlQuery Database::getKeystrokesByScanCode(quint16 scanCode) {
    return QSqlQuery("SELECT * FROM TABLE keystrokes WHERE scanCode = " + QString::number(scanCode) + ";");
}

QSqlQuery Database::getKeystrokesByTimestamp(qint64 timeStart, qint64 timeEnd) {
    return QSqlQuery("SELECT * FROM TABLE keystrokes WHERE timestmp > " + QString::number(timeStart) +
                     " AND timestmp < " + QString::number(timeEnd) + ";");
}

QSqlQuery Database::getKeystrokesByKeystate(quint32 keyState) {
    return QSqlQuery("SELECT * FROM TABLE keystrokes WHERE keyState = " + QString::number(keyState) + ";");
}

QSqlQuery Database::getMouseactions() {
    return QSqlQuery("SELECT * FROM TABLE mouseactions;");
}

QSqlQuery Database::getMouseactionsByClickType(quint32 clickType) {
    return QSqlQuery("SELECT * FROM TABLE mouseactions WHERE clickType = " + QString::number(clickType) + ";");
}

QSqlQuery Database::getMouseactionsByCursorSpot(quint32 crsSpot) {
    return QSqlQuery("SELECT * FROM TABLE mouseactions WHERE cursorSpot = " + QString::number(crsSpot) + ";");
}

QSqlQuery Database::getMouseactionsByPosition(quint32 xPos, quint32 yPos) {
    return QSqlQuery("SELECT * FROM TABLE mouseactions WHERE xPos = " + QString::number(xPos) + " AND yPos = " +
                     QString::number(yPos) + ";");
}

QSqlQuery Database::getMouseactionsByTimestamp(qint64 timeStart, qint64 timeEnd) {
    return QSqlQuery("SELECT * FROM TABLE mouseactions WHERE timestmp > " + QString::number(timeStart) +
                     " AND timestmp < " + QString::number(timeEnd) + ";");
}

QSqlQuery Database::getMouseactionsByWindowName(const QString &wndName) {
    return QSqlQuery("SELECT * FROM TABLE mouseactions WHERE windowName = '" + wndName + "';");
}