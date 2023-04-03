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


extern "C" _declspec(dllexport) UINT open(/* path*/)
{ 
    return mciSendString(L"",0,0,NULL);
}

extern "C" _declspec(dllexport) UINT play(/* path*/)
{
    return 0;
}

extern "C" _declspec(dllexport) UINT stop(/* path*/)
{
    return 0;
}

extern "C" _declspec(dllexport) UINT close(/* path*/)
{
    return 0;
}