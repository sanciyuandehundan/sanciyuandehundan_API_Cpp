// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"
#include"array"
#include"iostream"
#include "wincrypt.h"
#include"mmeapi.h"
#include"Windows.h"
#include"mmsystem.h"
#include"tchar.h"
#pragma comment(lib,"winmm.lib")
#include<locale>
using namespace std;


extern "C" _declspec(dllexport) UINT mci_play(wchar_t* order)
{
	return  mciSendString(order, 0, 0, NULL);
}