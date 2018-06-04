#include<Windows.h>
HMODULE hm;
DWORD addget;
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
__declspec(naked)int GetModuleHandl()
{
	__asm{
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname1;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}
	
}
extern "C" __declspec(naked) __declspec(dllexport)   int GetModuleHandleList()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname2;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetModulePath()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname3;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetModuleSize()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname4;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetNumberOfModules()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname5;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetNumberOfProcesses()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname6;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessBaseSize()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname7;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessIDList()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname8;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessPath()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname9;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
extern "C" __declspec(naked) __declspec(dllexport)   int GetProcessPathID()
{
	__asm {
		pushad;
		pushfd;
		push ebp;
		mov ebp, esp;
		sub esp, 0x10;
		lea edx, funname10;
		push edx;
		push hm;
		call addget;
		add esp, 0x10;
		mov esp, ebp;
		pop ebp;
		popfd;
		mov[esp + 28], eax;
		popad;
		jmp eax;
		ret;
	}

}
BOOL WINAPI DllMain(_In_ HINSTANCE hinstDll,
	_In_ DWORD fdwReason,
	_In_ LPVOID lpvReserved) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		MessageBoxA(NULL, "I am attached new!", "MyDll", MB_OKCANCEL);
		hm = LoadLibraryA("PROCSold.DLL");
		addget = (DWORD)GetProcAddress(LoadLibraryA("kernel32.dll"), "GetProcAddress");
		//axx = (DWORD)GetProcAddress(hm, "TestFuction");
		break;
	case DLL_PROCESS_DETACH:
		MessageBoxA(NULL, "I am detached new!", "MyDll", MB_OKCANCEL);
		break;
	default:
		break;
	}
	return true;
}