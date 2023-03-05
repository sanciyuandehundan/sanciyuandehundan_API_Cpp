// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

extern "C" _declspec(dllexport) void midi_play(int yuepu[], HMIDIOUT midiout)
{
    //midiOutShortMsg(midiout, 0x7e << 16 | 70 << 8 | 0x90);
    Music music = Music();
    music.play_longmsg(yuepu, midiout);
}

