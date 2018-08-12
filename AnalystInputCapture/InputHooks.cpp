//
// Created by Chrystalkey on 25.07.2018.
//
#include <iostream>
#include <QDebug>
#include <QtCore/QCoreApplication>
#include <chrono>

#include "InputHooks.h"
#include "Database.h"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

namespace InputCapture {
    HHOOK InputHooks::mouseHook = NULL;
    HHOOK InputHooks::keyHook = NULL;
    InputHooks *InputHooks::hook = nullptr;
    qint8 InputHooks::escapecount = 0;

    InputHooks *InputHooks::createInstance() {
        if (hook) {
            return nullptr;
        } else {
            return new InputHooks;
        }
    }

    InputHooks::InputHooks(QObject *parent) : QObject(parent) {
        std::cerr << "InputHooks::InputHooks\n";
        keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, llKeyHook, 0, 0);
        mouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseHookProc, 0, 0);
    }

    InputHooks::~InputHooks() {
        UnhookWindowsHookEx(keyHook);
        UnhookWindowsHookEx(mouseHook);
    }

    LRESULT CALLBACK InputHooks::llKeyHook(int nCode, WPARAM wParam, LPARAM lParam) {
        if (nCode == HC_ACTION) {
            PKBDLLHOOKSTRUCT p;
            p = (PKBDLLHOOKSTRUCT) lParam;
            hooks->addKeystroke(p->vkCode, p->scanCode, wParam,
                                duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
            if (VK_ESCAPE == p->vkCode) {
                escapecount++;
            }else{
                escapecount = 0;
            }
            if(escapecount == 10 ){
                PostQuitMessage(0);
                QCoreApplication::quit();
            }
        }
        return CallNextHookEx(keyHook, nCode, wParam, lParam);
    }

    LRESULT CALLBACK InputHooks::mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
        if (nCode == HC_ACTION) {
            //LPSTR wndTxt = (LPSTR)malloc(256);
            char *wndTxt = nullptr;
            int txtLen;
            HWND w;
            PMOUSEHOOKSTRUCT pms;
            QString str;
            switch (wParam) {
                case WM_LBUTTONDOWN:
                case WM_LBUTTONDBLCLK:
                case WM_LBUTTONUP:
                case WM_RBUTTONDBLCLK:
                case WM_RBUTTONDOWN:
                case WM_RBUTTONUP:
                    pms = (PMOUSEHOOKSTRUCT) lParam;
                    w = WindowFromPoint(pms->pt);
                    txtLen = GetWindowTextLength(w);
                    wndTxt = (PSTR) VirtualAlloc((LPVOID) NULL, (DWORD) (txtLen + 1), MEM_COMMIT, PAGE_READWRITE);
                    GetWindowText(w, wndTxt, txtLen + 1);
                    str = QString::fromLatin1(wndTxt);
                    VirtualFree(wndTxt, txtLen + 1, MEM_RELEASE);
                    hooks->addMouseaction(pms->pt, wParam, str, pms->wHitTestCode,
                                          duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
                    break;
                default:
                    break;
            }
        }
        return CallNextHookEx(mouseHook, nCode, wParam, lParam);
    }

    void InputHooks::run() {
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}