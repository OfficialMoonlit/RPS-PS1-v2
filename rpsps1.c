#include <psx.h>
#include <stdio.h>
#include <stdlib.h>
#include <psxcdrom.h>

unsigned int prim_list[0x4000];
unsigned short padbuf;

volatile int display_is_old = 1;
volatile int time_counter = 0;
volatile int bgmcounter = 0;
int dbuf=0, hx=0, hy=0;
int i;

volatile int player1_score = 0;
volatile int player2_score = 0;
volatile int weapon1 = 0;
volatile int weapon2 = 0;
volatile int pause = 0;
volatile int newround = 0;

GsImage tim_image1;
GsImage tim_image2;
GsImage tim_image3;
GsImage tim_image4;
GsImage tim_rock;
GsImage tim_paper;
GsImage tim_scissor;
GsImage tim_loading;
GsImage tim_panel;
GsImage tim_winled;
GsImage tim_lit50;
GsImage tim_litstart;
GsImage tim_0;
GsImage tim_1;
GsImage tim_2;
GsImage tim_3;
GsImage tim_4;
GsImage tim_5;
GsImage tim_6;
GsImage tim_7;
GsImage tim_8;
GsImage tim_9; 
GsImage tim_A;
GsImage tim_B;
GsImage tim_C;
GsImage tim_D;
GsImage tim_E;
GsImage tim_F;
GsImage tim_G;
GsImage tim_H;
GsImage tim_I;
GsImage tim_J;
GsImage tim_K;
GsImage tim_L;
GsImage tim_M;
GsImage tim_N;
GsImage tim_O;
GsImage tim_P;
GsImage tim_Q;
GsImage tim_R;
GsImage tim_S;
GsImage tim_T;
GsImage tim_U;
GsImage tim_V;
GsImage tim_W;
GsImage tim_X;
GsImage tim_Y;
GsImage tim_Z; 

GsSprite sprite_bg1;
GsSprite sprite_bg2;
GsSprite sprite_rock;
GsSprite sprite_paper;
GsSprite sprite_scissor;
GsSprite sprite_loading;
GsSprite sprite_panel;
GsSprite sprite_winled;
GsSprite sprite_lit50;
GsSprite sprite_litstart;
GsSprite sprite_0;
GsSprite sprite_1;
GsSprite sprite_2;
GsSprite sprite_3;
GsSprite sprite_4;
GsSprite sprite_5;
GsSprite sprite_6;
GsSprite sprite_7;
GsSprite sprite_8;
GsSprite sprite_9; 
GsSprite sprite_A;
GsSprite sprite_B;
GsSprite sprite_C;
GsSprite sprite_D;
GsSprite sprite_E;
GsSprite sprite_F;
GsSprite sprite_G;
GsSprite sprite_H;
GsSprite sprite_I;
GsSprite sprite_J;
GsSprite sprite_K;
GsSprite sprite_L;
GsSprite sprite_M;
GsSprite sprite_N;
GsSprite sprite_O;
GsSprite sprite_P;
GsSprite sprite_Q;
GsSprite sprite_R;
GsSprite sprite_S;
GsSprite sprite_T;
GsSprite sprite_U;
GsSprite sprite_V;
GsSprite sprite_W;
GsSprite sprite_X;
GsSprite sprite_Y;
GsSprite sprite_Z; 

unsigned short pad1;
unsigned short pad2;

unsigned char data_large[0x20000]; // 128 kilobytes
unsigned char data_small[0xF000]; // 128 kilobytes

void prog_vblank_handler() {
	display_is_old = 1;
	time_counter++;
	bgmcounter++;
}

void writeWord(char str[30], int x, int y)	{
	int w;
	for (w = 0; str[w]!=0; w++)	{
		if(str[w] == '0') {
			sprite_0.x = x + (16 * w); sprite_0.y = y;
			GsSortSprite(&sprite_0);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '1') {
			sprite_1.x = x + (16 * w); sprite_1.y = y;
			GsSortSprite(&sprite_1);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '2') {
			sprite_2.x = x + (16 * w); sprite_2.y = y;
			GsSortSprite(&sprite_2);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '3') {
			sprite_3.x = x + (16 * w); sprite_3.y = y;
			GsSortSprite(&sprite_3);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '4') {
			sprite_4.x = x + (16 * w); sprite_4.y = y;
			GsSortSprite(&sprite_4);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '5') {
			sprite_5.x = x + (16 * w); sprite_5.y = y;
			GsSortSprite(&sprite_5);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '6') {
			sprite_6.x = x + (16 * w); sprite_6.y = y;
			GsSortSprite(&sprite_6);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '7') {
			sprite_7.x = x + (16 * w); sprite_7.y = y;
			GsSortSprite(&sprite_7);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '8') {
			sprite_8.x = x + (16 * w); sprite_8.y = y;
			GsSortSprite(&sprite_8);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == '9') {
			sprite_9.x = x + (16 * w); sprite_9.y = y;
			GsSortSprite(&sprite_9);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'A') {
			sprite_A.x = x + (16 * w); sprite_A.y = y;
			GsSortSprite(&sprite_A);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'B') {
			sprite_B.x = x + (16 * w); sprite_B.y = y;
			GsSortSprite(&sprite_B);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'C') {
			sprite_C.x = x + (16 * w); sprite_C.y = y;
			GsSortSprite(&sprite_C);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'D') {
			sprite_D.x = x + (16 * w); sprite_D.y = y;
			GsSortSprite(&sprite_D);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'E') {
			sprite_E.x = x + (16 * w); sprite_E.y = y;
			GsSortSprite(&sprite_E);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'F') {
			sprite_F.x = x + (16 * w); sprite_F.y = y;
			GsSortSprite(&sprite_F);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'G') {
			sprite_G.x = x + (16 * w); sprite_G.y = y;
			GsSortSprite(&sprite_G);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'H') {
			sprite_H.x = x + (16 * w); sprite_H.y = y;
			GsSortSprite(&sprite_H);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'I') {
			sprite_I.x = x + (16 * w); sprite_I.y = y;
			GsSortSprite(&sprite_I);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'J') {
			sprite_J.x = x + (16 * w); sprite_J.y = y;
			GsSortSprite(&sprite_J);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'K') {
			sprite_K.x = x + (16 * w); sprite_K.y = y;
			GsSortSprite(&sprite_K);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'L') {
			sprite_L.x = x + (16 * w); sprite_L.y = y;
			GsSortSprite(&sprite_L);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'M') {
			sprite_M.x = x + (16 * w); sprite_M.y = y;
			GsSortSprite(&sprite_M);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'N') {
			sprite_N.x = x + (16 * w); sprite_N.y = y;
			GsSortSprite(&sprite_N);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'O') {
			sprite_O.x = x + (16 * w); sprite_O.y = y;
			GsSortSprite(&sprite_O);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'P') {
			sprite_P.x = x + (16 * w); sprite_P.y = y;
			GsSortSprite(&sprite_P);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'Q') {
			sprite_Q.x = x + (16 * w); sprite_Q.y = y;
			GsSortSprite(&sprite_Q);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'R') {
			sprite_R.x = x + (16 * w); sprite_R.y = y;
			GsSortSprite(&sprite_R);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'S') {
			sprite_S.x = x + (16 * w); sprite_S.y = y;
			GsSortSprite(&sprite_S);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'T') {
			sprite_T.x = x + (16 * w); sprite_T.y = y;
			GsSortSprite(&sprite_T);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'U') {
			sprite_U.x = x + (16 * w); sprite_U.y = y;
			GsSortSprite(&sprite_U);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'V') {
			sprite_V.x = x + (16 * w); sprite_V.y = y;
			GsSortSprite(&sprite_V);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'W') {
			sprite_W.x = x + (16 * w); sprite_W.y = y;
			GsSortSprite(&sprite_W);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'X') {
			sprite_X.x = x + (16 * w); sprite_X.y = y;
			GsSortSprite(&sprite_X);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'Y') {
			sprite_Y.x = x + (16 * w); sprite_Y.y = y;
			GsSortSprite(&sprite_Y);
			printf("Char %i is %c\n", w, str[w]);
		}
		else if(str[w] == 'Z') {
			sprite_Z.x = x + (16 * w); sprite_Z.y = y;
			GsSortSprite(&sprite_Z);
			printf("Char %i is %c\n", w, str[w]);
		}
		else	{
			printf("Char %i is [Unknown]\n", w);
		};
	};
}


void runSplash() {	
	
// Loading...

	FILE *f;
		
	f = fopen("cdrom:\\LOADING.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	int fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);
	
	GsImageFromTim(&tim_loading, data_small);
	GsUploadImage(&tim_loading);
	GsSpriteFromImage(&sprite_loading, &tim_loading, 1);

	sprite_loading.x = 80; sprite_loading.y = 110;
	sprite_loading.w = 160; sprite_loading.h = 240;
	sprite_loading.r = 128; sprite_loading.g = 128;	sprite_loading.b = 128;
	
	dbuf=!dbuf;
	GsSetDispEnvSimple(0, dbuf ? 0 : 256);
	GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);
	GsSortSprite(&sprite_loading);

	GsDrawList();
	while(GsIsDrawing());
	
// Init Splash

	f = fopen("cdrom:\\START1L.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_large, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_image1, data_large);
	GsUploadImage(&tim_image1);
	GsSpriteFromImage(&sprite_bg1, &tim_image1, 1);

	sprite_bg1.x = 0; sprite_bg1.y = 0;
	sprite_bg1.w = 160; sprite_bg1.h = 240;
	sprite_bg1.r = 128; sprite_bg1.g = 128;	sprite_bg1.b = 128;
		
	f = fopen("cdrom:\\START1R.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_large, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_image2, data_large);
	GsUploadImage(&tim_image2);
	GsSpriteFromImage(&sprite_bg2, &tim_image2, 1);

	sprite_bg2.x = 160; sprite_bg2.y = 0;
	sprite_bg2.w = 160; sprite_bg2.h = 240;
	sprite_bg2.r = 128; sprite_bg2.g = 128;	sprite_bg2.b = 128;
	
	//writeWord("ROCK PAPER SCISSORS", 6, 66);
//-------------------------------------------------------
	
	// Preload match sprites
	f = fopen("cdrom:\\LITPANEL.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_panel, data_large);
	GsUploadImage(&tim_panel);
	GsSpriteFromImage(&sprite_panel, &tim_panel, 1);
	
	sprite_panel.w = 250; sprite_panel.h = 36;
	sprite_panel.r = 128; sprite_panel.g = 128;	sprite_panel.b = 128;

	f = fopen("cdrom:\\ROCK.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_rock, data_small);
	GsUploadImage(&tim_rock);
	GsSpriteFromImage(&sprite_rock, &tim_rock, 1);
	
	sprite_rock.w = 67; sprite_rock.h = 68;
	sprite_rock.r = 128; sprite_rock.g = 128;	sprite_rock.b = 128;
	
	f = fopen("cdrom:\\PAPER.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_paper, data_small);
	GsUploadImage(&tim_paper);
	GsSpriteFromImage(&sprite_paper, &tim_paper, 1);
	
	sprite_paper.w = 67; sprite_paper.h = 68;
	sprite_paper.r = 128; sprite_paper.g = 128;	sprite_paper.b = 128;
	
	f = fopen("cdrom:\\SCISSOR.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_scissor, data_small);
	GsUploadImage(&tim_scissor);
	GsSpriteFromImage(&sprite_scissor, &tim_scissor, 1);
	
	sprite_scissor.w = 67; sprite_scissor.h = 68;
	sprite_scissor.r = 128; sprite_scissor.g = 128;	sprite_scissor.b = 128;
	
	f = fopen("cdrom:\\LIT50.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_lit50, data_small);
	GsUploadImage(&tim_lit50);
	GsSpriteFromImage(&sprite_lit50, &tim_lit50, 1);
	
	sprite_lit50.w = 101; sprite_lit50.h = 36;
	sprite_lit50.r = 128; sprite_lit50.g = 128;	sprite_lit50.b = 128;
	
	f = fopen("cdrom:\\LITSTART.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_litstart, data_small);
	GsUploadImage(&tim_litstart);
	GsSpriteFromImage(&sprite_litstart, &tim_litstart, 1);
	
	sprite_litstart.w = 45; sprite_litstart.h = 36;
	sprite_litstart.r = 128; sprite_litstart.g = 128;	sprite_litstart.b = 128;
	
	f = fopen("cdrom:\\0.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_0, data_small);
	GsUploadImage(&tim_0);
	GsSpriteFromImage(&sprite_0, &tim_0, 1);
	
	sprite_0.w = 16; sprite_0.h = 16;
	sprite_0.r = 128; sprite_0.g = 128;	sprite_0.b = 128;	
					
	f = fopen("cdrom:\\1.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_1, data_small);
	GsUploadImage(&tim_1);
	GsSpriteFromImage(&sprite_1, &tim_1, 1);
	
	sprite_1.w = 16; sprite_1.h = 16;
	sprite_1.r = 128; sprite_1.g = 128;	sprite_1.b = 128;	
	
	f = fopen("cdrom:\\2.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_2, data_small);
	GsUploadImage(&tim_2);
	GsSpriteFromImage(&sprite_2, &tim_2, 1);
	
	sprite_2.w = 16; sprite_2.h = 16;
	sprite_2.r = 128; sprite_2.g = 128;	sprite_2.b = 128;	

	f = fopen("cdrom:\\3.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_3, data_small);
	GsUploadImage(&tim_3);
	GsSpriteFromImage(&sprite_3, &tim_3, 1);
	
	sprite_3.w = 16; sprite_3.h = 16;
	sprite_3.r = 128; sprite_3.g = 128;	sprite_3.b = 128;	
	
	f = fopen("cdrom:\\4.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_4, data_small);
	GsUploadImage(&tim_4);
	GsSpriteFromImage(&sprite_4, &tim_4, 1);
	
	sprite_4.w = 16; sprite_4.h = 16;
	sprite_4.r = 128; sprite_4.g = 128;	sprite_4.b = 128;	
	
	f = fopen("cdrom:\\5.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_5, data_small);
	GsUploadImage(&tim_5);
	GsSpriteFromImage(&sprite_5, &tim_5, 1);
	
	sprite_5.w = 16; sprite_5.h = 16;
	sprite_5.r = 128; sprite_5.g = 128;	sprite_5.b = 128;	
	
	f = fopen("cdrom:\\6.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_6, data_small);
	GsUploadImage(&tim_6);
	GsSpriteFromImage(&sprite_6, &tim_6, 1);
	
	sprite_6.w = 16; sprite_6.h = 16;
	sprite_6.r = 128; sprite_6.g = 128;	sprite_6.b = 128;	
	
	f = fopen("cdrom:\\7.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_7, data_small);
	GsUploadImage(&tim_7);
	GsSpriteFromImage(&sprite_7, &tim_7, 1);
	
	sprite_7.w = 16; sprite_7.h = 16;
	sprite_7.r = 128; sprite_7.g = 128;	sprite_7.b = 128;	
	
	f = fopen("cdrom:\\8.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_8, data_small);
	GsUploadImage(&tim_8);
	GsSpriteFromImage(&sprite_8, &tim_8, 1);
	
	sprite_8.w = 16; sprite_8.h = 16;
	sprite_8.r = 128; sprite_8.g = 128;	sprite_8.b = 128;	
	
	f = fopen("cdrom:\\9.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_9, data_small);
	GsUploadImage(&tim_9);
	GsSpriteFromImage(&sprite_9, &tim_9, 1);
	
	sprite_9.w = 16; sprite_9.h = 16;
	sprite_9.r = 128; sprite_9.g = 128;	sprite_9.b = 128;	
	
 // alpha
	f = fopen("cdrom:\\FONT\\A.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_A, data_small);
	GsUploadImage(&tim_A);
	GsSpriteFromImage(&sprite_A, &tim_A, 1);
	
	sprite_A.w = 16; sprite_A.h = 16;
	sprite_A.r = 128; sprite_A.g = 128;	sprite_A.b = 128;	
	
		f = fopen("cdrom:\\FONT\\B.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_B, data_small);
	GsUploadImage(&tim_B);
	GsSpriteFromImage(&sprite_B, &tim_B, 1);
	
	sprite_B.w = 16; sprite_B.h = 16;
	sprite_B.r = 128; sprite_B.g = 128;	sprite_B.b = 128;	
	
		f = fopen("cdrom:\\FONT\\C.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_C, data_small);
	GsUploadImage(&tim_C);
	GsSpriteFromImage(&sprite_C, &tim_C, 1);
	
	sprite_C.w = 16; sprite_C.h = 16;
	sprite_C.r = 128; sprite_C.g = 128;	sprite_C.b = 128;	
	
		f = fopen("cdrom:\\FONT\\D.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_D, data_small);
	GsUploadImage(&tim_D);
	GsSpriteFromImage(&sprite_D, &tim_D, 1);
	
	sprite_D.w = 16; sprite_D.h = 16;
	sprite_D.r = 128; sprite_D.g = 128;	sprite_D.b = 128;	
	
		f = fopen("cdrom:\\FONT\\E.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_E, data_small);
	GsUploadImage(&tim_E);
	GsSpriteFromImage(&sprite_E, &tim_E, 1);
	
	sprite_E.w = 16; sprite_E.h = 16;
	sprite_E.r = 128; sprite_E.g = 128;	sprite_E.b = 128;	
	
		f = fopen("cdrom:\\FONT\\F.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_F, data_small);
	GsUploadImage(&tim_F);
	GsSpriteFromImage(&sprite_F, &tim_F, 1);
	
	sprite_F.w = 16; sprite_F.h = 16;
	sprite_F.r = 128; sprite_F.g = 128;	sprite_F.b = 128;	
	
		f = fopen("cdrom:\\FONT\\G.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_G, data_small);
	GsUploadImage(&tim_G);
	GsSpriteFromImage(&sprite_G, &tim_G, 1);
	
	sprite_G.w = 16; sprite_G.h = 16;
	sprite_G.r = 128; sprite_G.g = 128;	sprite_G.b = 128;	
	
		f = fopen("cdrom:\\FONT\\H.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_H, data_small);
	GsUploadImage(&tim_H);
	GsSpriteFromImage(&sprite_H, &tim_H, 1);
	
	sprite_H.w = 16; sprite_H.h = 16;
	sprite_H.r = 128; sprite_H.g = 128;	sprite_H.b = 128;	
	
		f = fopen("cdrom:\\FONT\\I.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_I, data_small);
	GsUploadImage(&tim_I);
	GsSpriteFromImage(&sprite_I, &tim_I, 1);
	
	sprite_I.w = 16; sprite_I.h = 16;
	sprite_I.r = 128; sprite_I.g = 128;	sprite_I.b = 128;	
	
		f = fopen("cdrom:\\FONT\\J.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_J, data_small);
	GsUploadImage(&tim_J);
	GsSpriteFromImage(&sprite_J, &tim_J, 1);
	
	sprite_J.w = 16; sprite_J.h = 16;
	sprite_J.r = 128; sprite_J.g = 128;	sprite_J.b = 128;	
	
		f = fopen("cdrom:\\FONT\\K.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_K, data_small);
	GsUploadImage(&tim_K);
	GsSpriteFromImage(&sprite_K, &tim_K, 1);
	
	sprite_K.w = 16; sprite_K.h = 16;
	sprite_K.r = 128; sprite_K.g = 128;	sprite_K.b = 128;	
	
		f = fopen("cdrom:\\FONT\\L.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_L, data_small);
	GsUploadImage(&tim_L);
	GsSpriteFromImage(&sprite_L, &tim_L, 1);
	
	sprite_L.w = 16; sprite_L.h = 16;
	sprite_L.r = 128; sprite_L.g = 128;	sprite_L.b = 128;	
	
		f = fopen("cdrom:\\FONT\\M.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_M, data_small);
	GsUploadImage(&tim_M);
	GsSpriteFromImage(&sprite_M, &tim_M, 1);
	
	sprite_M.w = 16; sprite_M.h = 16;
	sprite_M.r = 128; sprite_M.g = 128;	sprite_M.b = 128;	
	
		f = fopen("cdrom:\\FONT\\N.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_N, data_small);
	GsUploadImage(&tim_N);
	GsSpriteFromImage(&sprite_N, &tim_N, 1);
	
	sprite_N.w = 16; sprite_N.h = 16;
	sprite_N.r = 128; sprite_N.g = 128;	sprite_N.b = 128;	
	
		f = fopen("cdrom:\\FONT\\O.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_O, data_small);
	GsUploadImage(&tim_O);
	GsSpriteFromImage(&sprite_O, &tim_O, 1);
	
	sprite_O.w = 16; sprite_O.h = 16;
	sprite_O.r = 128; sprite_O.g = 128;	sprite_O.b = 128;	
	
		f = fopen("cdrom:\\FONT\\P.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_P, data_small);
	GsUploadImage(&tim_P);
	GsSpriteFromImage(&sprite_P, &tim_P, 1);
	
	sprite_P.w = 16; sprite_P.h = 16;
	sprite_P.r = 128; sprite_P.g = 128;	sprite_P.b = 128;	
	
		f = fopen("cdrom:\\FONT\\Q.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_Q, data_small);
	GsUploadImage(&tim_Q);
	GsSpriteFromImage(&sprite_Q, &tim_Q, 1);
	
	sprite_Q.w = 16; sprite_Q.h = 16;
	sprite_Q.r = 128; sprite_Q.g = 128;	sprite_Q.b = 128;	
	
		f = fopen("cdrom:\\FONT\\R.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_R, data_small);
	GsUploadImage(&tim_R);
	GsSpriteFromImage(&sprite_R, &tim_R, 1);
	
	sprite_R.w = 16; sprite_R.h = 16;
	sprite_R.r = 128; sprite_R.g = 128;	sprite_R.b = 128;	
	
		f = fopen("cdrom:\\FONT\\S.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_S, data_small);
	GsUploadImage(&tim_S);
	GsSpriteFromImage(&sprite_S, &tim_S, 1);
	
	sprite_S.w = 16; sprite_S.h = 16;
	sprite_S.r = 128; sprite_S.g = 128;	sprite_S.b = 128;	
	
		f = fopen("cdrom:\\FONT\\T.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_T, data_small);
	GsUploadImage(&tim_T);
	GsSpriteFromImage(&sprite_T, &tim_T, 1);
	
	sprite_T.w = 16; sprite_T.h = 16;
	sprite_T.r = 128; sprite_T.g = 128;	sprite_T.b = 128;	
	
		f = fopen("cdrom:\\FONT\\U.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_U, data_small);
	GsUploadImage(&tim_U);
	GsSpriteFromImage(&sprite_U, &tim_U, 1);
	
	sprite_U.w = 16; sprite_U.h = 16;
	sprite_U.r = 128; sprite_U.g = 128;	sprite_U.b = 128;	
	
		f = fopen("cdrom:\\FONT\\V.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_V, data_small);
	GsUploadImage(&tim_V);
	GsSpriteFromImage(&sprite_V, &tim_V, 1);
	
	sprite_V.w = 16; sprite_V.h = 16;
	sprite_V.r = 128; sprite_V.g = 128;	sprite_V.b = 128;	
	
		f = fopen("cdrom:\\FONT\\W.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_W, data_small);
	GsUploadImage(&tim_W);
	GsSpriteFromImage(&sprite_W, &tim_W, 1);
	
	sprite_W.w = 16; sprite_W.h = 16;
	sprite_W.r = 128; sprite_W.g = 128;	sprite_W.b = 128;	
	
		f = fopen("cdrom:\\FONT\\X.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_X, data_small);
	GsUploadImage(&tim_X);
	GsSpriteFromImage(&sprite_X, &tim_X, 1);
	
	sprite_X.w = 16; sprite_X.h = 16;
	sprite_X.r = 128; sprite_X.g = 128;	sprite_X.b = 128;	
	
		f = fopen("cdrom:\\FONT\\Y.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_Y, data_small);
	GsUploadImage(&tim_Y);
	GsSpriteFromImage(&sprite_Y, &tim_Y, 1);
	
	sprite_Y.w = 16; sprite_Y.h = 16;
	sprite_Y.r = 128; sprite_Y.g = 128;	sprite_Y.b = 128;	
	
		f = fopen("cdrom:\\FONT\\Z.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_Z, data_small);
	GsUploadImage(&tim_Z);
	GsSpriteFromImage(&sprite_Z, &tim_Z, 1);
	
	sprite_Z.w = 16; sprite_Z.h = 16;
	sprite_Z.r = 128; sprite_Z.g = 128;	sprite_Z.b = 128;	
	
 // alpha	
	f = fopen("cdrom:\\WINLED.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_small, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_winled, data_small);
	GsUploadImage(&tim_winled);
	GsSpriteFromImage(&sprite_winled, &tim_winled, 1);
	
	sprite_winled.w = 5; sprite_winled.h = 6;
	sprite_winled.r = 128; sprite_winled.g = 128;	sprite_winled.b = 128;


	for (i = 0; i < 1280; i++)
	{
				dbuf=!dbuf;
				GsSetDispEnvSimple(0, dbuf ? 0 : 256);
				GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);

				sprite_bg1.r = i / 10; sprite_bg1.g = i / 10;	sprite_bg1.b = i / 10;	
				sprite_bg2.r = i / 10; sprite_bg2.g = i / 10;	sprite_bg2.b = i / 10;
				GsSortSprite(&sprite_bg1);
				GsSortSprite(&sprite_bg2);

				GsDrawList();
				while(GsIsDrawing());
	}
	
    do{
        for (i = 0; i < 6000; i++)
            {
            	PSX_ReadPad(&pad1, &pad2);

				if(pad1 & PAD_START)	{
				    break;
				}
				else {               
					if(display_is_old)	{
						dbuf=!dbuf;
						GsSetDispEnvSimple(0, dbuf ? 0 : 256);
						GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);
						GsSortSprite(&sprite_bg1);
						GsSortSprite(&sprite_bg2);
						writeWord(" RPS 2 BY MOONLIT", 14, 72);
						GsDrawList();
						while(GsIsDrawing());

						display_is_old=0;
					}
				}
            }

        for (i = 0; i < 6000; i++)
            {
            	PSX_ReadPad(&pad1, &pad2);

				if(pad1 & PAD_START)	{
				    break;
				}
				else {               
					if(display_is_old)	{
						dbuf=!dbuf;
						GsSetDispEnvSimple(0, dbuf ? 0 : 256);
						GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);
						GsSortSprite(&sprite_bg1);
						GsSortSprite(&sprite_bg2);
						writeWord("HIT START TO PLAY", 14, 72);						
						GsDrawList();
						while(GsIsDrawing());

						display_is_old=0;
					}
				}
            }
    }
    while(!(pad1 & PAD_START)); 
	
	for (i = 1280; i > 0; i--){
				dbuf=!dbuf;
				GsSetDispEnvSimple(0, dbuf ? 0 : 256);
				GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);

				sprite_bg1.r = i / 10; sprite_bg1.g = i / 10;	sprite_bg1.b = i / 10;	
				sprite_bg2.r = i / 10; sprite_bg2.g = i / 10;	sprite_bg2.b = i / 10;
				GsSortSprite(&sprite_bg1);
				GsSortSprite(&sprite_bg2);

				GsDrawList();
				while(GsIsDrawing());

			
	}
	
	f = fopen("cdrom:\\PLAY1L.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_large, sizeof(char), fsize, f);
	fclose(f);
	
	GsImageFromTim(&tim_image1, data_large);
	GsUploadImage(&tim_image1);
	GsSpriteFromImage(&sprite_bg1, &tim_image1, 1);

	sprite_bg1.x = 0; sprite_bg1.y = 0;
	sprite_bg1.w = 160; sprite_bg1.h = 240;
	sprite_bg1.r = 128; sprite_bg1.g = 128;	sprite_bg1.b = 128;
	
	//int data_large[0x40000] = {0};
		
	f = fopen("cdrom:\\PLAY1R.TIM;1", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(data_large, sizeof(char), fsize, f);
	fclose(f);

	GsImageFromTim(&tim_image2, data_large);
	GsUploadImage(&tim_image2);
	GsSpriteFromImage(&sprite_bg2, &tim_image2, 1);

	sprite_bg2.x = 160; sprite_bg2.y = 0;
	sprite_bg2.w = 160; sprite_bg2.h = 240;
	sprite_bg2.r = 128; sprite_bg2.g = 128;	sprite_bg2.b = 128;
	
	for (i = 0; i < 1280; i++)
	{
				dbuf=!dbuf;
				GsSetDispEnvSimple(0, dbuf ? 0 : 256);
				GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);

				sprite_bg1.r = i / 10; sprite_bg1.g = i / 10;	sprite_bg1.b = i / 10;	
				sprite_bg2.r = i / 10; sprite_bg2.g = i / 10;	sprite_bg2.b = i / 10;
				GsSortSprite(&sprite_bg1);
				GsSortSprite(&sprite_bg2);

				GsDrawList();
				while(GsIsDrawing());
	}
  }
  
void drawPlayfield() {
	
	dbuf=!dbuf;
	GsSetDispEnvSimple(0, dbuf ? 0 : 256);
	GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);

	GsSortSprite(&sprite_bg1);
	GsSortSprite(&sprite_bg2);
	
}

void drawStats() {
	
	dbuf=!dbuf;
	GsSetDispEnvSimple(0, dbuf ? 0 : 256);
	GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);

	if (player1_score == 0) {
	sprite_0.x = 26; sprite_0.y = 134;
	GsSortSprite(&sprite_0);
	} else if (player1_score == 1) {
	sprite_1.x = 26; sprite_1.y = 134;
	GsSortSprite(&sprite_1);
	} else if (player1_score == 2) {
	sprite_2.x = 26; sprite_2.y = 134;
	GsSortSprite(&sprite_2);
	} else if (player1_score == 3) {
	sprite_3.x = 26; sprite_3.y = 134;
	GsSortSprite(&sprite_3);
	} else if (player1_score == 4) {
	sprite_4.x = 26; sprite_4.y = 134;
	GsSortSprite(&sprite_4);
	} else if (player1_score == 5) {
	sprite_5.x = 26; sprite_5.y = 134;
	GsSortSprite(&sprite_5);
	} else if (player1_score == 6) {
	sprite_6.x = 26; sprite_6.y = 134;
	GsSortSprite(&sprite_6);
	} else if (player1_score == 7) {
	sprite_7.x = 26; sprite_7.y = 134;
	GsSortSprite(&sprite_7);
	} else if (player1_score == 8) {
	sprite_8.x = 26; sprite_8.y = 134;
	GsSortSprite(&sprite_8);
	} else if (player1_score == 9) {
	sprite_9.x = 26; sprite_9.y = 134;
	GsSortSprite(&sprite_9);
	} else if (player1_score == 10) {
	sprite_1.x = 15; sprite_1.y = 134;
	GsSortSprite(&sprite_1);
	sprite_0.x = 26; sprite_0.y = 134;
	GsSortSprite(&sprite_0);
	}
	
	if (player2_score == 0) {
	sprite_0.x = 291; sprite_0.y = 134;
	GsSortSprite(&sprite_0);
	} else if (player2_score == 1) {
	sprite_1.x = 291; sprite_1.y = 134;
	GsSortSprite(&sprite_1);
	} else if (player2_score == 2) {
	sprite_2.x = 291; sprite_2.y = 134;
	GsSortSprite(&sprite_2);
	} else if (player2_score == 3) {
	sprite_3.x = 291; sprite_3.y = 134;
	GsSortSprite(&sprite_3);
	} else if (player2_score == 4) {
	sprite_4.x = 291; sprite_4.y = 134;
	GsSortSprite(&sprite_4);
	} else if (player2_score == 5) {
	sprite_5.x = 291; sprite_5.y = 134;
	GsSortSprite(&sprite_5);
	} else if (player2_score == 6) {
	sprite_6.x = 291; sprite_6.y = 134;
	GsSortSprite(&sprite_6);
	} else if (player2_score == 7) {
	sprite_7.x = 291; sprite_7.y = 134;
	GsSortSprite(&sprite_7);
	} else if (player2_score == 8) {
	sprite_8.x = 291; sprite_8.y = 134;
	GsSortSprite(&sprite_8);
	} else if (player2_score == 9) {
	sprite_9.x = 291; sprite_9.y = 134;
	GsSortSprite(&sprite_9);
	} else if (player2_score == 10) {
	sprite_1.x = 280; sprite_1.y = 134;
	GsSortSprite(&sprite_1);
	sprite_0.x = 291; sprite_0.y = 134;
	GsSortSprite(&sprite_0);
	}

}

void newRound() {

}

unsigned char file_buffer[0x60000];
int load_file_into_buffer(char *fname)
{
        FILE *f;
        int sz;

        /*int fd;
        
        fd = open(fname, O_RDONLY);
        
        printf("%s (%d)\n", fname, get_file_size(fname));
        
        read(fd, file_buffer, get_file_size(fname));
        
        close(fd);*/
        f = fopen(fname, "rb");
        
        //f->pos = 0;
        fseek(f, 0, SEEK_END);  

        sz = ftell(f);

        fseek(f, 0, SEEK_SET);

        printf("%s (%d)\n", fname, sz);
        
        fread(file_buffer, sizeof(char), sz, f);
        
        fclose(f);
        
        return sz;
}

int main() {
	printf("PSX Init...");
	PSX_Init();
	printf("PSX Init Done...");
	GsInit();
	printf("GS Init...");
	GsSetList(prim_list);
	printf("Clearing GS Memory...");
	GsClearMem();
	printf("GS Memory Clear Done");
	GsSetVideoMode(320, 240, VMODE_SELECT);
	SetVBlankHandler(prog_vblank_handler);
	//==============================================

int c;
int sample_pos[1];
printf("SS Init...");
SsInit();
printf("SS Init Done");
// VAG AUDIO
sample_pos[0] = SPU_DATA_BASE_ADDR;
c = load_file_into_buffer("cdrom:\\BGM.RAW;1");
SsUpload(file_buffer, c, sample_pos[0]);
SsVoiceStartAddr(0, sample_pos[0]);
SsVoiceRepeatAddr(0, sample_pos[0]);
SsVoiceVol(0, 0x3fff, 0x3fff);
SsVoicePitch(0, 0x1000 / (44100 / 44100));
// VAG AUDIO
printf("BGM Loaded");
//==============================================
printf("Splash Init...");
	runSplash();
printf("Splash Done");
printf("Loading Play Area...");
	int tst;

	
	while(1) {
	
			// VAG AUDIO
			if(bgmcounter <= 1)	{
				SsVoiceStartAddr(0, sample_pos[0]);
				//SsKeyOn(0);
			}
			// VAG AUDIO
			
		if(display_is_old)	{
			dbuf=!dbuf;
			GsSetDispEnvSimple(0, dbuf ? 0 : 256);
			GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);
			
			drawPlayfield();
			drawStats();
			
			if(newround == 1)	{
				while((pause + 240) > time_counter)	{};
				newround = 0;
			};			
			
			PSX_ReadPad(&pad1, &pad2);

			if(pad1 & PAD_SQUARE)	{
				//P1 ROCK
				weapon1 = 1;
			}
			else if(pad1 & PAD_CROSS)	{
				//P1 PAPER
				weapon1 = 2;
			}
			else if(pad1 & PAD_CIRCLE)	{
				//P1 SCISSORS
				weapon1 = 3;
			};
						
			if(pad2 & PAD_SQUARE)	{
				//P2 ROCK
				weapon2 = 1;
			}
			else if(pad2 & PAD_CROSS)	{
				//P2 PAPER
				weapon2 = 2;
			}
			else if(pad2 & PAD_CIRCLE)	{
				//P2 SCISSORS
				weapon2 = 3;
			};

			/*if(pad1 & PAD_TRIANGLE)	{
				//P1 ROCK
				tst = CdGetStatus();
				if (tst == 0) {
				sprite_0.x = 108; sprite_0.y = 134;
				GsSortSprite(&sprite_0);
				} else if (tst == 1) {
				sprite_1.x = 108; sprite_1.y = 134;
				GsSortSprite(&sprite_1);
				} else if (tst == 2) {
				sprite_2.x = 108; sprite_2.y = 134;
				GsSortSprite(&sprite_2);
				} else if (tst == 3) {
				sprite_3.x = 108; sprite_3.y = 134;
				GsSortSprite(&sprite_3);
				} else if (tst == 4) {
				sprite_4.x = 108; sprite_4.y = 134;
				GsSortSprite(&sprite_4);
				} else if (tst == 5) {
				sprite_5.x = 108; sprite_5.y = 134;
				GsSortSprite(&sprite_5);
				} else if (tst == 6) {
				sprite_6.x = 108; sprite_6.y = 134;
				GsSortSprite(&sprite_6);
				} else if (tst == 7) {
				sprite_7.x = 108; sprite_7.y = 134;
				GsSortSprite(&sprite_7);
				} else if (tst == 8) {
				sprite_8.x = 108; sprite_8.y = 134;
				GsSortSprite(&sprite_8);
				} else if (tst == 9) {
				sprite_9.x = 108; sprite_9.y = 134;
				GsSortSprite(&sprite_9);
				}
				
			//}
			*/
			
			if(pad1 & PAD_L1)	{
				//Music On
				sprite_panel.x = 60; sprite_panel.y = 10;
				//GsSortSprite(&sprite_panel);
				SsKeyOn(0);
				bgmcounter = 0;
				writeWord("BGM ON", 14, 72);
			}		
			
			if(pad1 & PAD_L2)	{
				//Music Off
				sprite_panel.x = 60; sprite_panel.y = 10;
				//GsSortSprite(&sprite_panel);
				SsKeyOff(0);
				bgmcounter = -1;
				writeWord("BGM OFF", 14, 72);
			}	
			
			if(pad1 & PAD_R2)	{
				//P1 ROCK
				sprite_panel.x = 60; sprite_panel.y = 10;
				GsSortSprite(&sprite_panel);
				tst = CdPlayTrack(2);
				SsEnableCd();
				SsCdVol(0x3FFF, 0x3FFF);
				writeWord("CDDA ON BORK", 14, 72);
			}
			
			
			pause = time_counter;
			
			if(weapon1 > 0 && weapon2 > 0)	{
				if(weapon1 == 1) {
					sprite_rock.x = 53; sprite_rock.y = 131;
					GsSortSprite(&sprite_rock);
				};
				if(weapon1 == 2) {
					sprite_paper.x = 53; sprite_paper.y = 131;
					GsSortSprite(&sprite_paper);
				};
				if(weapon1 == 3) {
					sprite_scissor.x = 53; sprite_scissor.y = 131;
					GsSortSprite(&sprite_scissor);
				};
				if(weapon2 == 1) {
					sprite_rock.x = 198; sprite_rock.y = 131;
					GsSortSprite(&sprite_rock);
				};
				if(weapon2 == 2) {
					sprite_paper.x = 198; sprite_paper.y = 131;
					GsSortSprite(&sprite_paper);
				};
				if(weapon2 == 3) {
					sprite_scissor.x = 198; sprite_scissor.y = 131;
					GsSortSprite(&sprite_scissor);
				};
				
				// It's a draw.
				if(weapon1 == 1 && weapon2 == 1)	{
					// Rock draw                 '
					writeWord("DRAW     HEAVY MAN", 14, 72);
				};
				if(weapon1 == 2 && weapon2 == 2)	{
					// Paper draw
					writeWord("DRAW      FLAT OUT", 14, 72);
				};
				if(weapon1 == 3 && weapon2 == 3)	{
					// Scissors draw
					writeWord("DRAW    CUT IT OUT", 14, 72);
				};
				
				// Player 1 wins.
				if(weapon1 == 1 && weapon2 == 3)	{
					// P1 rock beats P2 scissors
					sprite_winled.x = 130; sprite_winled.y = 131;
					GsSortSprite(&sprite_winled);
					writeWord("ROCK BEAT SCISSORS", 14, 72);
					player1_score++;
				};
				if(weapon1 == 2 && weapon2 == 1)	{
					// P1 paper beats P2 rock
					sprite_winled.x = 130; sprite_winled.y = 131;
					GsSortSprite(&sprite_winled);
					writeWord("PAPER WRAPS ROCK", 14, 72);
					player1_score++;
				};
				if(weapon1 == 3 && weapon2 == 2)	{
					// P1 scissors beats P2 paper
					sprite_winled.x = 130; sprite_winled.y = 131;
					GsSortSprite(&sprite_winled);
					writeWord("SCISSORS CUT PAPER", 14, 72);
					player1_score++;
				};

				// Player 2 wins.
				if(weapon2 == 1 && weapon1 == 3)	{
					// P2 rock beats P1 scissors
					sprite_winled.x = 182; sprite_winled.y = 131;
					GsSortSprite(&sprite_winled);
					writeWord("ROCK BEAT SCISSORS", 14, 72);
					player2_score++;
				};
				if(weapon2 == 2 && weapon1 == 1)	{
					// P2 paper beats P1 rock
					sprite_winled.x = 182; sprite_winled.y = 131;
					GsSortSprite(&sprite_winled);
					writeWord("PAPER WRAPS ROCK", 14, 72);
					player2_score++;
				};
				if(weapon2 == 3 && weapon1 == 2)	{
					// P2 scissors beats P1 paper
					sprite_winled.x = 182; sprite_winled.y = 131;
					GsSortSprite(&sprite_winled);
					writeWord("SCISSORS CUT PAPER", 14, 72);
					player2_score++;
				};
				
				newround = 1;
				weapon1 = 0;
				weapon2 = 0;
			};			
			
		if(player1_score == 10 || player2_score == 10)	{
			do{
				PSX_ReadPad(&pad1, &pad2);
				if(pad1 & PAD_START)	{
						player1_score = 0;
						player2_score = 0;
						newround = 0;
						break;
				}
				else if(pad1 & PAD_TRIANGLE) {
					do{
						PSX_ReadPad(&pad1, &pad2);
						dbuf=!dbuf;
						GsSetDispEnvSimple(0, dbuf ? 0 : 256);
						GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);
						GsSortCls(0,0,0);
						writeWord("RPS 2 CREDITS", 8, 8);
						
						writeWord("CODE AND GRAPHICS", 8, 32);
						writeWord("MOONLIT", 8, 48);
						
						writeWord("TESTING", 8, 72);
						writeWord("PRECIOUSROY AND", 8, 88);
						writeWord("FAMICOMAN", 8, 104);
						writeWord("GREETS", 8, 144);
						writeWord("UNPERSONS AND", 8, 160);
						writeWord("THE NEW TECH", 8, 176);
						writeWord("        PRESS START", 8, 224);
						GsDrawList();
						while(GsIsDrawing());

						display_is_old=0;
					}while(!(pad1 & PAD_START));
				}
				else {               
					PSX_ReadPad(&pad1, &pad2);
					if(display_is_old)	{
						dbuf=!dbuf;
						GsSetDispEnvSimple(0, dbuf ? 0 : 256);
						GsSetDrawEnvSimple(0, dbuf ? 256 : 0, 320, 240);
						drawPlayfield();
						drawStats();
						sprite_lit50.x = 68; sprite_lit50.y = 5;
						GsSortSprite(&sprite_lit50);
						sprite_litstart.x = 251; sprite_litstart.y = 5;
						GsSortSprite(&sprite_litstart);
						if(player2_score == 10)	{
							writeWord("     PLAYER 2 WINS", 14, 72);						
						}
						else if(player1_score == 10)	{
							writeWord("PLAYER 1 WINS", 14, 72);						
						};
						GsDrawList();
						while(GsIsDrawing());

						display_is_old=0;
					};
				};
			}while(!(pad1 & PAD_START));
		};
		
			
			GsDrawList();
			
			// VAG AUDIO
			if(bgmcounter >= 780)	{
				SsKeyOff(0);
				bgmcounter = 0;
			}
			// VAG AUDIO
			
		while(GsIsDrawing());

		display_is_old=0;
			

		}
	}

	return 0;
}

