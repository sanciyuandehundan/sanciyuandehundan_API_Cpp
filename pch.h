// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"
#include"array"
#include"iostream"
#include "wincrypt.h"
#include"mmeapi.h"
#include"Windows.h"
#include"mmsystem.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

#endif ;//PCH_H

class Music {
public:
	//MIDIHDR midihdr;//存储
	//HANDLE handle;//缓冲区句柄
	Music();//建构函数
	void play_longmsg(int g[], HMIDIOUT a);//演奏,用midioutlongmsg
	void play_MCI(int pu[], HMIDIOUT midiip);//演奏，用MCI
	void play_mid(HMIDIOUT handle);//演奏，用midi流
	UINT in_num();//没有midi输入设备
	UINT out_num();//检测midi输出设备

	UINT play(string path);
};