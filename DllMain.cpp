#include <Windows.h>

int __stdcall DllMain(HINSTANCE mod, unsigned long reason, void* reserved) {

	switch (reason) {
	case DLL_PROCESS_ATTACH:

		break;

	case DLL_PROCESS_DETACH:

		break;
	}

	return 1;
}