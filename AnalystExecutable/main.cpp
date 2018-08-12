#include <iostream>
#include <thread>
#include <QtCore/QCoreApplication>
#include <QtGlobal>
#include <windows.h>

#include "libglobal.h"
#include <QDebug>
#include "Database.h"
#include "InputHooks.h"

Q_DECLARE_METATYPE(POINT);

using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using namespace InputCapture;

int HookMain(){
    qRegisterMetaType<POINT>("POINT");
    hooks = InputHooks::createInstance();
    QObject::connect(hooks,&InputHooks::addKeystroke,
            dbPtr,&Database::addKeystroke);
    QObject::connect(hooks,&InputHooks::addMouseaction,
            dbPtr,&Database::addMouseaction);
    hooks->run();
    return 0;
}

int main(int argc, char**argv){
    Q_INIT_RESOURCE(resource_file);
    QCoreApplication app(argc,argv);
    dbPtr = new Database("F:/name.db");
    std::thread hookerThread(&HookMain);
    int ret = app.exec();
    delete dbPtr;
    hookerThread.detach();
    return ret;
}
/* TODO: create shared library for Functions / Network Packet capture(Wireshark api?):
 * SOCKET WSAAPI socket
 * BOOL PASCAL WSAConnectByList
 * int connect
 * BOOL PASCAL ConnectEx
 * int bind
 * INT GetAddressByName
 * struct hostent* FAR gethostbyname
 * int send
 * int WSAConnect
 * BOOL PASCAL WSAConnectByList
 * BOOL PASCAL WSAConnectByName
 * TODO: Create Heatmap for Mouse/Keyboard
 * TODO: Capture most used Programs/files/directories
 */