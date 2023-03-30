// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"
#include"array"
#include"iostream"
#include "wincrypt.h"
#include"mmeapi.h"
#include"Windows.h"
#include"mmsystem.h"
#pragma comment(lib,"winmm.lib")
#include<locale>
using namespace std;


extern "C" _declspec(dllexport) UINT play(/* path*/)
{ 
    /*wstring sl = wstring(path.begin(), path.end());
    LPCWSTR s = sl.c_str();
    if (0 == mciSendString(s, 0, 0, NULL)) {
        cout << "s";
        //midiOutShortMsg(handle, 0x7e << 16 | 60 << 8 | 0x90);
        return mciSendString(L"play midi", NULL, 0, NULL);
        Sleep(1000000);
    }*/
    return 0;
}