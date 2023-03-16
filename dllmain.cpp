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
//using namespace std;
extern "C" _declspec(dllexport) void midi_play()
{ 
    //midiOutShortMsg(handle, 0x7e << 16 | 60 << 8 | 0x90);
    /*Music music = Music();//初始化music实例
    music.play_mid(handle);*/
    //mciSendStringA("open C:\\Users\\a0905\\Desktop\\mydata.mid type sequencer alias m1", 0, 0, 0);
    if (0 == mciSendString(L"open C:\\Users\\a0905\\Downloads\\yingui_all.MID type sequencer Alias midi", NULL, 0, NULL)) {
        cout << "s";
        //midiOutShortMsg(handle, 0x7e << 16 | 60 << 8 | 0x90);
        mciSendString(L"play midi", NULL, 0, NULL);
        Sleep(1000000);
    }
    //mciSendStringW("open C:\Users\a0905\source\repos\sanciyuandehundan\music\bin\Debug\yingui0_1.mid",0,0,0);
    //Sleep(5000);
    //delete &music;//删除music实例
    /*MCI_OPEN_PARMS OpenParms;
    OpenParms.lpstrDeviceType =(LPCWSTR)MCI_DEVTYPE_SEQUENCER;//MIDI类型
    OpenParms.lpstrElementName = (LPCWSTR)"C:\\Users\\a0905\\Desktop\\mydata.mid";
    OpenParms.wDeviceID = 0;
    mciSendCommand(NULL, MCI_OPEN, MCI_WAIT | MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&OpenParms);
    MCI_PLAY_PARMS PlayParms;
    PlayParms.dwFrom = 0;
    // 指定从什么地方（时间）播放
    mciSendCommand(OpenParms.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD)(LPVOID)&PlayParms);*/
}