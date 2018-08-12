//
// Created by Chrystalkey on 25.07.2018.
//

#ifndef ALLDATAFLOWANALYST_INPUTHOOKS_H
#define ALLDATAFLOWANALYST_INPUTHOOKS_H

#include <QThread>
#include <windows.h>

#include "libglobal.h"

namespace InputCapture {

    class InputHooks : public QObject {
    Q_OBJECT
    public:
        ~InputHooks();

        void run();

        static InputHooks *createInstance();

    signals:
        void addKeystroke(quint16, quint16, quint16, qint64);
        void addMouseaction(POINT, quint32, QString, quint32, qint64);

    private:
        InputHooks(QObject *parent = nullptr);
        InputHooks(const InputHooks&) = delete;
        static qint8 escapecount;

        static LRESULT CALLBACK llKeyHook(int nCode, WPARAM wParam, LPARAM lParam);

        static LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);

        static HHOOK mouseHook;
        static HHOOK keyHook;
        static InputHooks *hook;
    };
}

#endif //ALLDATAFLOWANALYST_INPUTHOOKS_H
