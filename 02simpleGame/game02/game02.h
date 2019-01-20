#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"

int sarreraMenua();
EGOERA jokatu(void);
int pertsonaiaAutatu();
void jokoarenGida();
int  jokoAmaierakoa(EGOERA egoera);
struct ERLEA
{
	int x, y, bizitza;

}erlea;
struct etsaia
{
	int x, y, bizitzak;

}etsaiak[12];
struct EtsaienIrudia
{
	int id[12];

}etsaiarenIrudia;
struct balak
{
	int x, y;
}bala[3];
struct pertsonaiaPos
{
	int x, y, irudia[2], erdiaX, erdiaY, aldea;
}pertsonaia;
struct erlearenDisparoa
{
	int x, y;

}erleaDisparoa[3];
#endif