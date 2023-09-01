#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include "libs/Console.h"

int main(int argc, char **argv)
{
	gfxInitDefault();
	Console *cons = new Console(GFX_TOP);
	cons->print("test");
	cons->print("test2");
	cons->print("test3");

	while (aptMainLoop())
	{		
		cons->render();

		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
