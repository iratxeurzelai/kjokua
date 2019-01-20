#include "balak.h"
#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <SDL.h>

//---------------------------------------------------------------------------//
void sortuBalakPos(int balakPos[], int x1, int x2, int y1, int y2)
{
	int posizioa[2];
	if (pertsonaia.aldea ==1)
	{
		bala[0].x = pertsonaia.erdiaX + 20;
		bala[0].y = pertsonaia.erdiaY + 9;
		bala[1].x = pertsonaia.erdiaX + 20;
		bala[1].y = pertsonaia.erdiaY + 9;
		bala[2].x = pertsonaia.erdiaX + 20;
		bala[2].y = pertsonaia.erdiaY + 9;
	}

	if (pertsonaia.aldea ==0)
	{
		bala[0].x = pertsonaia.erdiaX - 20;
		bala[0].y = pertsonaia.erdiaY  + 9;
		bala[1].x = pertsonaia.erdiaX - 20;
		bala[1].y = pertsonaia.erdiaY  + 9;
		bala[2].x = pertsonaia.erdiaX - 20;
		bala[2].y = pertsonaia.erdiaY  + 9;
	}
	


}
void balakSortu(int zeinArma, int balakPos[])
{

	arkatzKoloreaEzarri(0, 0, 255);
	if (zeinArma == 0)
	{
		zirkuluaMarraztu(bala[0].x, bala[0].y, 4);
	}
	else if (zeinArma == 1)
	{
		zirkuluaMarraztu(bala[1].x, bala[1].y, 4);
		zirkuluaMarraztu(bala[0].x, bala[0].y, 4);
		zirkuluaMarraztu(bala[2].x, bala[2].y, 4);
	}
}
void disparatu(int zeinArma, int balakPos[])
{
	if (pertsonaia.aldea == 1)
	{
		if (zeinArma == 0)
		{
			bala[0].x += 4;
		}
		else if (zeinArma == 1)
		{
			//Erdiko bala
			bala[0].x += 4;
			//Goiko bala
			bala[1].x += 4;
			bala[1].y -= 1;
			//Beheko bala
			bala[2].x += 4;
			bala[2].y += 1;
		}
	}
	if (pertsonaia.aldea ==0)
	{
		if (zeinArma == 0)
		{
			bala[0].x -= 4;
		}
		else if (zeinArma == 1)
		{
			//Erdiko bala
			bala[0].x -= 4;
			//Goiko bala
			bala[1].x -= 4;
			bala[1].y -= 1;
			//Beheko bala
			bala[2].x -= 4;
			bala[2].y += 1;
		}
	}
}