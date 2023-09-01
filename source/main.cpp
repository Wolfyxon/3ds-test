#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include "libs/Console.h"

int main(int argc, char **argv)
{
	gfxInitDefault();
	Console *topCons = new Console(GFX_TOP);
	topCons->print("top test");
	topCons->print("top test2");
	topCons->print("top test3");

	Console *bottomCons = new Console(GFX_BOTTOM);
	bottomCons->print(to_string(GFX_BOTTOM));
	bottomCons->print(to_string(GFX_TOP));
	
	bottomCons->print("bottom test");
	bottomCons->print("bottom test2");
	bottomCons->print("bottom test3");
	bottomCons->print("bottom test4");


	while (aptMainLoop())
	{		
		//topCons->render();
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
