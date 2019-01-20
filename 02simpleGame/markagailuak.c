#include "balak.h"
#include "markagailuak.h"
#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <SDL.h>

void balaKop(int balaKop)
{
	char balak[128];
	sprintf(balak, "%d", balaKop);
	textuaIdatzi(545, 457, balak);
	textuaIdatzi(567, 457, "/ 90");
}
void score(int score)
{
	char scorea[128];
	sprintf(scorea, "%d", score);
	textuaIdatzi(520, 4, scorea);
}
void txanda(int txanda)
{
	char txandak[128];
	sprintf(txandak, "%d", txanda);
	textuaIdatzi(85, 457, txandak);
}
void denbora(int denbora)
{
	char segunduak[128];
	sprintf(segunduak, "%d", denbora);
	textuaIdatzi(100, 4, segunduak);
	textuaIdatzi(130, 4, "s");
}
void markagailuak(int denboraa, int txandaa, int scoree, int balaKopp)
{
	txanda(txandaa);
	score(scoree);
	denbora(denboraa);
	balaKop(balaKopp);
}