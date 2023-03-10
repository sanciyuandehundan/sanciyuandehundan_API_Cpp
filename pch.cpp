// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
// 当使用预编译的头时，需要使用此源文件，编译才能成功。

Music::Music() {
	//midi_dll::handle = GlobalAlloc(GHND, size);//为缓冲区准备空间
	//midi_dll::midihdr.lpData = (LPSTR)GlobalLock(handle);//将缓冲区交予midihdr
	//midi_dll::midihdr.dwBufferLength = size;//将缓冲区大小与midihdr同步
	//midi_dll::midihdr.dwFlags = 0;//未知
};//建构函数


void Music::play_longmsg(int g[], HMIDIOUT handle) {
	//mciSendString((LPCWSTR)"play C:\\5dce7c575fb3adb0c988e.mp3 repeat", 0, 0, 0);
    //HMIDIOUT midiout;
    WNDCLASS;
	MIDIHDR     midiHdr;
	HANDLE      hBuffer;
	UINT        err = 0;
    DWORD j[] = { 0xF0, 0x7D, 0x50, 0x61, 0x75, 0x6C, 0xF7 };
    //MIDIEVENT midievent[];
    //midiOutOpen(&midiout, (UINT) - 1, 0, 0, 0);
    //midiOutShortMsg(midiout, 0x7e4090);
	//int sysEx[] = { 0xF0,0x90|0x40<<8|100<<16, 0xF7 };
	//int test0[] = { 0xf0,0x4d ,0x54 ,0x68 ,0x64 ,0x00 ,0x00 ,0x00 ,0x06 ,0x00 ,0x01 ,0x00 ,0x02 ,0x01 ,0xe0 ,0x4d ,0x54 ,0x72 ,0x6b ,0x00 ,0x00 ,0x00 ,0x19 ,0x00 ,0xff ,0x59 ,0x02 ,0x00 ,0x00 ,0x00 ,0xff ,0x58 ,0x04 ,0x04 ,0x02 ,0x18 ,0x08 ,0x00 ,0xff ,0x51 ,0x03 ,0x07 ,0xa1 ,0x20 ,0x00 ,0xff ,0x2f ,0x00 ,0x4d ,0x54 ,0x72 ,0x6b ,0x00 ,0x00 ,0x00 ,0x2c ,0x00 ,0xc0 ,0x00 ,0x00 ,0x90 ,0x40 ,0x5f ,0x83 ,0x60 ,0x80 ,0x40 ,0x00 ,0x00 ,0x90 ,0x41 ,0x5f ,0x83 ,0x30 ,0x80 ,0x41 ,0x00 ,0x30 ,0x90 ,0x40 ,0x5f ,0x83 ,0x30 ,0x80 ,0x40 ,0x00 ,0x30 ,0x90 ,0x40 ,0x5f ,0x83 ,0x30 ,0x80 ,0x40 ,0x00 ,0x83 ,0x60 ,0xff ,0x2f ,0x00 ,0xf7};
	//int test1[] = { 0xF0, 0x7F, 0x7F, 0x04, 0x01, 0x7F, 0x7F, 0xF7 };
	hBuffer = GlobalAlloc(GHND, sizeof(j));//分配缓冲区
	midiHdr.lpData = (LPSTR)GlobalLock(hBuffer);//将缓冲区交予midihdr
	midiHdr.dwBufferLength = sizeof(j);////将缓冲区大小与midihdr同步
	midiHdr.dwFlags = 0;//未知
	err = midiOutPrepareHeader(handle, &midiHdr, sizeof(midiHdr));//准备缓冲区和midiHdr
	midiOutShortMsg(handle, 100 << 16 | 60 << 8 | 0x90);
	memcpy(midiHdr.lpData, &j[0], sizeof(j));//将midi命令放入缓冲区
	midiOutLongMsg(handle, &midiHdr, sizeof(midiHdr));//演奏
    
};
void Music::play_MCI(int pu[], HMIDIOUT midiip) {
	/*
	LPCTSTR lpszCommand = (LPCTSTR)"open C:\\Users\\a0905\\Downloadsmid\\(13).mid";
	mciSendString((LPCTSTR)"play C:\\Users\\a0905\\Downloadsmid\\(13).mid" , 0, 0, 0);
	LPTSTR lpszReturnString;
	UINT cchReturn;
	HANDLE hwndCallback;
	//mciSendString(lpszCommand,lpszReturnString,cchReturn,hwndCallback);
	char buf[50];

	//mciSendString(lpszCommand,lpszReturnString, strlen(buf), NULL);
	*/

}

DWORD playMIDIFile(HWND hWndNotify, LPSTR lpszMIDIFileName)
{

    UINT wDeviceID;
    DWORD dwReturn;
    MCI_OPEN_PARMS mciOpenParms;
    MCI_PLAY_PARMS mciPlayParms;
    MCI_STATUS_PARMS mciStatusParms;
    MCI_SEQ_SET_PARMS mciSeqSetParms;

    // Open the device by specifying the device and filename.
    // MCI will attempt to choose the MIDI mapper as the output port.
    mciOpenParms.lpstrDeviceType = (LPCWSTR)"sequencer";
    mciOpenParms.lpstrElementName = (LPCWSTR)lpszMIDIFileName;
    if (dwReturn = mciSendCommand(NULL, MCI_OPEN,
        MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
        (DWORD)(LPVOID)&mciOpenParms))
    {
        // Failed to open device. Don't close it; just return error.
        return (dwReturn);
    }

    // The device opened successfully; get the device ID.
    wDeviceID = mciOpenParms.wDeviceID;

    // Check if the output port is the MIDI mapper.
    mciStatusParms.dwItem = MCI_SEQ_STATUS_PORT;
    if (dwReturn = mciSendCommand(wDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
    {
        mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
        return (dwReturn);
    }

    // The output port is not the MIDI mapper. 
    // Ask if the user wants to continue.
    if (LOWORD(mciStatusParms.dwReturn) != MIDI_MAPPER)
    {
        /*if (MessageBox(hMainWnd, (LPCWSTR)"The MIDI mapper is not available. Continue?", (LPCWSTR)"", MB_YESNO) == IDNO)
        {
            // User does not want to continue. Not an error;
            // just close the device and return.
            mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
            return (0L);
        }*/
    }

    // Begin playback. The window procedure function for the parent 
    // window will be notified with an MM_MCINOTIFY message when 
    // playback is complete. At this time, the window procedure closes 
    // the device.
    mciPlayParms.dwCallback = (DWORD)hWndNotify;
    if (dwReturn = mciSendCommand(wDeviceID, MCI_PLAY, MCI_NOTIFY,
        (DWORD)(LPVOID)&mciPlayParms))
    {
        mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
        return (dwReturn);
    }

    return (0L);
}

UINT Music::in_num() {
    return midiInGetNumDevs();
}

UINT Music::out_num() {
    return midiOutGetNumDevs();
}