#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include "libs/Console.h"

int main(int argc, char **argv)
{
	gfxInitDefault();
	Console *topCons = new Console(GFX_TOP);
	topCons->print("test");
	topCons->print("test2");
	topCons->print("test3");

	Console *bottomCons = new Console(GFX_BOTTOM);
	bottomCons->print("test");
	bottomCons->print("test2");
	bottomCons->print("test3");


	while (aptMainLoop())
	{		
		topCons->render();
		bottomCons->render();

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
