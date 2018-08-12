//
// Created by Chrystalkey on 29.07.2018.
//

#ifndef ALLDATAFLOWANALYST_LIBGLOBAL_H
#define ALLDATAFLOWANALYST_LIBGLOBAL_H

#include <QtCore/QString>

QString operator*(const QString &left, quint32 right);

extern "C"{
    void hexdump(const char *data, unsigned int size, FILE *output = stdout);
}
class Database;

extern Database *dbPtr;

namespace InputCapture {

    class InputHooks;

    extern InputHooks *hooks;
}
#endif //ALLDATAFLOWANALYST_LIBGLOBAL_H
