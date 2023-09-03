#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include "3ds-libs/Console.h"
#include "3ds-libs/SpriteRenderer.h"
#include "3ds-libs/OpusAudioPlayer.h"

int main(int argc, char **argv)
{
	romfsInit();
	ndspInit();
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

	OpusAudioPlayer* audio = new OpusAudioPlayer();
	if(audio->load("romfs:/sample.opus")) topCons->print("Audio loaded");
	audio->play();
	SpriteRenderer* sr = new SpriteRenderer(GFX_BOTTOM);
	Sprite s = sr->getSpriteFromSheetFile("romfs:/gfx/test.t3x",0);
	sr->addSprite(&s);
	float speed = 5;
	while (aptMainLoop())
	{		
		topCons->render();
		sr->render();
		//bottomCons->render();


		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kHeld = keysHeld();
		if (kDown & KEY_A) {
			topCons->print("A pressed");			
			bottomCons->print("A pressed");
		}
		if (kDown & KEY_B){
			topCons->print("B pressed");
			bottomCons->print("B pressed");
		};

		if(kHeld & KEY_LEFT){
			s.posX -= speed;
		};
		if(kHeld & KEY_RIGHT){
			s.posX += speed;
		};
		if(kHeld & KEY_UP){
			s.posY -= speed;
		};
		if(kHeld & KEY_DOWN){
			s.posY += speed;
		};
		
		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}
	ndspExit();
	romfsExit();
	gfxExit();
	return 0;
}
