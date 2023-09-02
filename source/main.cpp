#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include "3ds-libs/Console.h"
#include "3ds-libs/SpriteRenderer.h"

int main(int argc, char **argv)
{
	romfsInit();
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

	Console *topCons = new Console(GFX_TOP);
	topCons->print("top test");
	topCons->print("top test2");
	topCons->print("top test3");

	Console *bottomCons = new Console(GFX_BOTTOM);	
	bottomCons->print("bottom test");
	bottomCons->print("bottom test2");
	bottomCons->print("bottom test3");
	bottomCons->print("bottom test4");


	SpriteRenderer* sr = new SpriteRenderer(GFX_BOTTOM);
	sr->addSprite(sr->getSpriteFromSheetFile("romfs:/gfx/test.t3x",0));
	while (aptMainLoop())
	{		
		topCons->render();
		sr->render();
		//bottomCons->render();


		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A) {
			topCons->print("A pressed");			
			bottomCons->print("A pressed");
		}
		if (kDown & KEY_B){
			topCons->print("B pressed");
			bottomCons->print("B pressed");
		};
		
		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	romfsExit();
	gfxExit();
	return 0;
}
