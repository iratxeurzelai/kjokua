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


void etsaiarenMugimendua(int zeinTxanda, int x1, int y1)
{
	for (int i = 0; i < zeinTxanda * 2; i++)
	{
		int distantziaX = x1 - etsaiak[i].x + 40;
		int distantziaY = y1 - etsaiak[i].y + 40;

		if (distantziaX > 0) {
			etsaiak[i].x += 4;

		}
		else if (distantziaX < 0) {
			etsaiak[i].x -= 4;

		}
		if (distantziaY > 0) {
			etsaiak[i].y += 4;

		}
		else if (distantziaY < 0) {
			etsaiak[i].y -= 4;

		}

		//------------
		else if (distantziaX = 0)
		{
			pantailaBerriztu();
		}
		//------------
	}
	for (int i = 0; i < zeinTxanda * 2; i++)
	{
		int n1 = etsaiak[i].x;
		int m1 = etsaiak[i].y;
		zuzenaMarraztu(n1, m1, n1 + 50, m1);
		zuzenaMarraztu(n1 + 50, m1, n1 + 50, m1 + 25);
		zuzenaMarraztu(n1 + 50, m1 + 25, n1, m1 + 25);
		zuzenaMarraztu(n1, m1 + 25, n1, m1);
	}
}
void erleaMugitu()
{
	int erleaMugimendua = 0;
	erlea.x = 300 - 37, erlea.y = 240 - 37;

	zuzenaMarraztu(erlea.x, erlea.y, erlea.x + 75, erlea.y);
	zuzenaMarraztu(erlea.x + 75, erlea.y, erlea.x + 75, erlea.y + 75);
	zuzenaMarraztu(erlea.x + 75, erlea.y + 75, erlea.x, erlea.y + 75);
	zuzenaMarraztu(erlea.x, erlea.y + 75, erlea.x, erlea.y);

	if (erleaMugimendua == 0)
	{
		if (erlea.y > 31)
		{
			erlea.y -= 4;
		}
		else
		{
			erleaMugimendua++;

		}

	}
	if (erleaMugimendua == 1)
	{
		if (erlea.x > 31)
		{
			erlea.x -= 4;
		}
		else
		{
			erleaMugimendua++;
		}

	}
	if (erleaMugimendua == 2)
	{
		if (erlea.y < 374)
		{
			erlea.y += 4;
		}
		else
		{
			erleaMugimendua++;
		}

	}
	if (erleaMugimendua == 3)
	{
		if (erlea.x < 494)
		{
			erlea.x += 4;

		}
		else
		{
			erleaMugimendua++;
		}

	}
	if (erleaMugimendua == 4)
	{
		if (erlea.y > 31)
		{
			erlea.y -= 4;
		}
		else
		{
			erleaMugimendua++;
		}
	}
	if (erleaMugimendua == 5)
	{
		if (erlea.x > 31)
		{
			erlea.x -= 4;
		}
		else
		{
			erleaMugimendua = 2;
		}
	}
}