#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include "3ds-libs/include/Console.h"
#include "3ds-libs/include/OpusAudioPlayer.h"
#include "3ds-libs/include/renderable/Sprite.h"
#include "3ds-libs/include/renderable/Scene.h"

using std::string;
using std::vector;
using std::to_string;

int main(int argc, char **argv)
{
	romfsInit();
	ndspInit();
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

	Console *topCons = new Console(GFX_TOP);
	topCons->print(topCons->bg(red)+topCons->fg(yellow)+"Test ANSI colors");
	topCons->print(topCons->fg(magenta)+"this is a test");
	topCons->print("Press "+topCons->ansi(bold)+"A"+topCons->ansi(reset)+" to show a test message");
	topCons->print("Press "+topCons->ansi(bold)+"B"+topCons->ansi(reset)+" to show another test message");
	topCons->print("Press "+topCons->ansi(bold)+"SELECT"+topCons->ansi(reset)+" to clear the console");
	topCons->print("Press "+topCons->ansi(bold)+"START"+topCons->ansi(reset)+" to exit");
	

	Console *bottomCons = new Console(GFX_BOTTOM);	
	bottomCons->print("bottom test");
	bottomCons->print("bottom test2");
	bottomCons->print("bottom test3");
	bottomCons->print("bottom test4");

    ndspChnReset(0);
    ndspSetOutputMode(NDSP_OUTPUT_STEREO);
    ndspChnSetInterp(0, NDSP_INTERP_POLYPHASE);
    ndspChnSetRate(0, 48000);
    ndspChnSetFormat(0, NDSP_FORMAT_STEREO_PCM16);


	TreeElement* el = new TreeElement();
	Scene* scene = new Scene(GFX_BOTTOM,C2D_Color32f(1.0f,0.0f,0.0f,1.0f));
	Sprite* s = new Sprite();
	Sprite* s2 = new Sprite();
	
	s->setScale(0.2,0.2);

	//scene->name = "scene";
	//s->name = "s1";
	//s2->name = "s2";
	topCons->print(scene->name);
	topCons->print(s->name);
	topCons->print(s2->name);

	s->loadFromSheetFile("romfs:/gfx/test.t3x");
	scene->addChild(s);
	scene->addChild(s2);
	//scene->addChild(el);
	
	vector<TreeElement*> desc = scene->getChildren();
	topCons->print(to_string(desc.size()));
	
	for(TreeElement* d : desc){
		topCons->print(d->getType());
	}
	float speed = 5;
	float rotSpeed = 0.05;
	while (aptMainLoop())
	{

		//topCons->render();
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
		if (kDown & KEY_SELECT){
			topCons->clear();
		}

		if(kHeld & KEY_LEFT){
			s->posX -= speed;
		};
		if(kHeld & KEY_RIGHT){
			s->posX += speed;
		};
		if(kHeld & KEY_UP){
			s->posY -= speed;
		};
		if(kHeld & KEY_DOWN){
			s->posY += speed;
		};

		if(kHeld & KEY_L){
			s->rotationRad -= rotSpeed;
		}
		if(kHeld & KEY_R){
			s->rotationRad += rotSpeed;
		}

		
		if (kDown & KEY_START) break;
		
		gfxFlushBuffers();
		//gfxSwapBuffers();

		scene->render();

		gspWaitForVBlank();
	}
	C2D_Fini();
	C3D_Fini();
	ndspExit();
	romfsExit();
	gfxExit();
	return 0;
}
