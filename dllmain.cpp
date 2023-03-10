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
using namespace std;
extern "C" _declspec(dllexport) void midi_play(int yuepu[], HMIDIOUT midiout)
{ 
    Music music = Music();
    //MIDIEVENT met;
    //midiOutShortMsg(midiout, 0x7e << 16 | 70 << 8 | 0x90);
    //music.play_longmsg(yuepu, midiout);
    //return music.out_num();
    //return music.in_num();
    midiOutMessage(midiout, 0x90, 0x40, 0x7e);
    DWORD d = 0x90|0x40<<8|0x7e<<16;
    //midiOutShortMsg(midiout, d);
}
/*LRESULT CALLBACK SysexWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    int i;
    MIDIEVENT Evt;
    HDC hDC;
    char text[4];
    SIZE TextSize;
    static int x = 0;

    switch (iMsg)
    {
    case WM_CREATE:
        // open the input device
        //if ((hMidiIn = OpenMidiIn(hWnd, INPUT_DEVICE, 0, MIDIIN_DEFAULT)) == 0)
            //return -1;
        // midi in must be started before messages will be processed
        //StartMidiIn(hMidiIn);
        //Page 75
            // open the output device
            //if ((hMidiOut = OpenMidiOut(hWnd, OUTPUT_DEVICE, 0,
                //MIDIOUT_DEFAULT)) == 0)
                //return -1;
        // send the sysex
        // initialize the MidiEvent's status field
        Evt.dwDeltaTime = 1;//对开始等待时间赋值
        // output bytes until the EOX is sent
        i = 0;
        do {
        //fle:///C|/BOOK/CHAP06.HTM (2 of 11)3/27/2005 1:52:22 PM
            Maximum MIDI - Chapter 6
                Evt.data1 = sx[i++];
            PutMidiOut(hMidiOut, &Evt);
        } while (Evt.data1 != 0xF7);
        return 0;
    case MIDI_DATA:
        while ((lpMsg = GetMidiIn(hMidiIn)) != NULL)
        {
            // If this is part of a sysex, display the hex bytes
            if (lpMsg->status == 0xF0)
            {
                hDC = GetDC(hWnd);
                wsprintf(text, "%2.2X ", lpMsg->data1);
                TextOut(hDC, x, 0, text, strlen(text));
                GetTextExtentPoint(hDC, text, strlen(text), &TextSize);
                x += TextSize.cx;
                ReleaseDC(hWnd, hDC);
            }
        }
        return 0;
    case WM_CLOSE:
        //CloseMidiOut(hMidiOut);关掉midi设备
        //midiOutClose(hMidiOut)
        //DestroyWindow(hWnd);卸载窗口
        return 0;
    case WM_DESTROY:
        //PostQuitMessage(0);显示退出信息
        return 0;
    }
    // All messages that are not completely processed above
    // must be processed here.
    return DefWindowProc(hWnd, iMsg, wParam, lParam);
}*/

