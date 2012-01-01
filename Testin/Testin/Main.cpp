#include <Windows.h>
#include "Engine.h"

int main()
{
	Engine* engine = new Engine(640, 480, 20);

	try{
		engine->Start();
	}
	catch(char* e)
	{
		MessageBoxA(NULL, e, "Exception Occured", MB_OK | MB_ICONERROR);
	}
	return 0;
}