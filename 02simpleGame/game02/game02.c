#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <SDL.h>
#include "balak.h"
#include "markagailuak.h"
#include "animazioak.h"
#include "mugimendua.h"

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define MUSIKA_FONDO ".\\sound\\Gurea\\MusikaFondo.wav"
#define GOLPE_EN_LA_CARA ".\\sound\\Gurea\\GolpeEnLaCara.wav"
#define PISTOLA ".\\sound\\Gurea\\pistola.wav"
#define PERTSONAIA_HIL_MUTILA ".\\sound\\Gurea\\pertsonaiaMutilaHil.wav"
#define PERTSONAIA_HIL_NESKA ".\\sound\\Gurea\\pertsonaiaNeskaHil.wav"
#define OU ".\\sound\\Gurea\\ou.wav"
#define ESKOPETA ".\\sound\\Gurea\\eskopeta.wav"
#define BIZI_GUTXI ".\\sound\\Gurea\\biziGutxi.wav"
#define JOKOA_SOUND ".\\sound\\132TRANCE_02.wav"
#define JOKOAREN_PANTAILA ".\\img\\Bozetoak\\Jokoaren pantaila\\background.bmp"
#define JOLASTEKO_GIDA ".\\img\\Bozetoak\\Jokoaren pantaila\\jolastekoGida.bmp"
#define JOKALARIA_AUTATU ".\\img\\Bozetoak\\Jokoaren pantaila\\pertsonaiaAutatu.bmp"
#define MENUA ".\\img\\Bozetoak\\Jokoaren pantaila\\menua2.bmp"
#define JOKALARIA1 ".\\img\\Bozetoak\\Pertsonaiak\\Amaituta.bmp"
#define JOKALARIA0 ".\\img\\Bozetoak\\Pertsonaiak\\Amaituta1.bmp"
#define ERLEA1 ".\\img\\Bozetoak\\Etsaiak\\Berezia\\ERLEA\\Erlea1.bmp"
#define ETSAIA  ".\\img\\Bozetoak\\Etsaiak\\Normala\\2.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\BugleCall.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\terminator.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_1.bmp"
#define BIZITZA_BARRA ".\\img\\Bozetoak\\Bizitza barrak\\pertsonaia\\barra1.bmp"
#define HASIERAKO_BALAK 90
#define HASIERAKO_DENBORA 300
#define BIZITZA 100

int sarreraMenua();
void bordeak();
int BUKAERA_irudiaBistaratu();
void pertsonaiaHitbox(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void hitboxErdia(int x1, int x2, int y1, int y2);
//void aldaketaLortu(int pertsonaiaErdia[], int EtsaiaPos[], int txanda, int aldaketaX, int bPos);
void posizioakHasieratu();
void etsaienBizitzakHasieratu();
void etsaiaHitbox(int n1, int m1, int n2, int m2);
int kolisioaEtsaiarekin(int i);
int etsaiariJo(int i);
void erlearenBizitzaHasieratu();
void disparatuErlea1();
void disparatuErlea2();
void disparatuErlea3();
void disparatuErlea4();
void hasieratuEtsaienIrudia(int zeinTxanda);
void pertsonairenIrudiaAldatu(int aldea);
int erlearekinKolisioa();
int erleariJo();

int erdiaX = 300, erdiaY = 240;

//-----Menuak-------//
int sarreraMenua()
{
	int x1= erdiaX - 60, x2= erdiaX - 70, y1= erdiaY - 40, y2= erdiaY - 50, y3= erdiaY - 30;
	int ebentu = 0, pos=0, menua;
	menua = irudiaKargatu(MENUA);

	do
	{
		pantailaBerriztu();
		pantailaGarbitu();
		irudiakMarraztu(menua);
		textuaIdatzi(erdiaX - 50, erdiaY - 50, "JOLASTU");
		textuaIdatzi(erdiaX - 50, erdiaY, "JOKALARIA HAUTATU");
		textuaIdatzi(erdiaX - 50, erdiaY + 50, "JOLASTEKO GIDA");
		arkatzKoloreaEzarri(255, 0, 128);
		zuzenaMarraztu(x1, y1, x2, y2);
		zuzenaMarraztu(x2, y2, x2, y3);
		zuzenaMarraztu(x2, y3, x1, y1);
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN)
		{
			if (pos != 3)
			{
				y1 += 50;
				y2 += 50;
				y3 += 50;
				pos++;
			}
			if (pos == 3)
			{
				y1 = erdiaY - 40;
				y2 = erdiaY - 50;
				y3 = erdiaY - 30;
				pos = 0;
			}
			printf("%d", pos);
		}
	} while (ebentu!=TECLA_RETURN);
	return pos;
}
int pertsonaiaAutatu()
{
	int x1 = 50, y1 = 120, x2 = 130, y2 = 120, x3 = 130, y3 = 210, x4 = 50, y4 = 210;
	int ebentu = 0, autatu, pos=1, aldaketaX=100;
	autatu = irudiaKargatu(JOKALARIA_AUTATU);

	do
	{
		pantailaBerriztu();
		pantailaGarbitu();
		irudiakMarraztu(autatu);
		ebentu = ebentuaJasoGertatuBada();
		arkatzKoloreaEzarri(255, 0, 128);
		zuzenaMarraztu(x1, y1, x2, y2);
		zuzenaMarraztu(x2, y2, x3, y3);
		zuzenaMarraztu(x3, y3, x4, y4);
		zuzenaMarraztu(x4, y4, x1, y1);
		if (ebentu==TECLA_RIGHT)
		{

			if (pos<5)
			{
				if (pos == 0)
				{
					aldaketaX = 100;
					x1 = 50;
					x2 = 130;
					x3 = 130;
					x4 = 50;
					y1 = 120;
					y2 = 120;
					y3 = 210;
					y4 = 210;
				}
				if (pos >= 1)
				{
					x1 += aldaketaX;
					x2 += aldaketaX;
					x3 += aldaketaX;
					x4 += aldaketaX;
				}
				pos++;
				aldaketaX = aldaketaX + 2;
			}
			if (pos==5)
			{
				pos = 0;
			}
		}
	} while (ebentu != TECLA_RETURN);
}
void jokoarenGida()
{
	int ebentu = 0, gida;
	gida = irudiaKargatu(JOLASTEKO_GIDA);

	do
	{
		pantailaBerriztu();
		pantailaGarbitu();
		irudiakMarraztu(gida);
		ebentu = ebentuaJasoGertatuBada();

	} while (ebentu != TECLA_RETURN);
}

EGOERA jokatu(void) {
	int balakPos[6];
	int arma = 0;
	int mugitu = 0; //boolean
	EGOERA  egoera = JOLASTEN;
	int ebentu = 0;
	int segunduak = 0;
	int x1 = erdiaX - 10, y1 = erdiaY - 25, x2 = erdiaX + 30, y2 = erdiaY - 25, x3 = erdiaX + 30, y3 = erdiaY + 35, x4 = erdiaX - 10, y4 = erdiaY + 35;
	int vx = 10, vy = 10;
	int metrailetaBalak = HASIERAKO_BALAK, eskopetaBalak = HASIERAKO_BALAK, balakDisparatu;
	//-----------------------
	int zeinTxanda = 7, etsaientzakoTxanda=1, zeinScore = 0, zeinDenbora = HASIERAKO_DENBORA;
	//-----------------------
	int jokoarePantaila, jokalaria, bizitzaBarra, etsaia, erlearenIrudia;
	int pertsonaiaErdia[2];
	int marraztuErlea = 0;
	int zenbatKolisio;
	int bizitza = 100;
	int pertsonaiarenIrudiaHasieratu = 1, irudiaAldatutaEskuina=0, irudiaAldatutaEzkerra=0;
	pertsonaia.aldea = 0;//0=ezkerra eta 1=eskuina
	//--------ETSAIEN MUGIMENDURAKO--------//

	int etsaiNormalak = 1, etsaiakHasieratu = 1, etsaiaMugitu = 0, etsaienIrudiaHasieratuta=1;
	int n1, m1;
	erlea.x = erdiaX - 37, erlea.y = erdiaY - 37;
	int erleaMugimendua = 0, etsaiaHilda=0, erlearenDisparoa1=0, erlearenDisparoa2=0, erlearenDisparoa3=0, erlearenDisparoa4=0;
	int erlearenBizitzaHasieratuta = 0;
	posizioakHasieratu();
	//----------IRUDIAK-----------------//
	jokoarePantaila = irudiaKargatu(JOKOAREN_PANTAILA);
	bizitzaBarra = irudiaKargatu(BIZITZA_BARRA);
	erlearenIrudia = irudiaKargatu(ERLEA1);
	etsaienBizitzakHasieratu();
	//---------SOINUAK---------------//
	audioInit();
	loadTheMusic(MUSIKA_FONDO);
	playMusic();

	do {
		Sleep(2);
		if (etsaienIrudiaHasieratuta==1)
		{
			hasieratuEtsaienIrudia(etsaientzakoTxanda);
			etsaienIrudiaHasieratuta = 0;
		}
		pantailaGarbitu();
		etsaiaMugitu++;
		segunduak++;
		//printf("%d", bizitza);
		pertsonaia.x = x1 - 10;
		pertsonaia.y = y1 - 20;
		if (segunduak == 200 && zeinDenbora != 0)
		{
			zeinDenbora--;
			denbora(zeinDenbora);
			segunduak = 0;
		}
		//printf("\n%d", pertsonaiaErdia[1]);
	//	irudiakMarraztu(erlearenIrudia[marraztuErlea]);
		//irudiaKendu(erlearenIrudia[marraztuErlea]);
		//pantailaBerriztu();
		if (marraztuErlea < 11)
		{
			marraztuErlea++;
		}
		if (marraztuErlea == 11)
		{
			marraztuErlea = 0;
		}
		//irudiaKendu(erlearenIrudia[marraztuErlea]);
		irudiakMarraztu(bizitzaBarra);
		irudiakMarraztu(jokoarePantaila);
		//irudiaMugitu(erlearenIrudia[marraztuErlea], erleaX , erleaY);

		if (pertsonaiarenIrudiaHasieratu)
		{
			pertsonaia.irudia[0] = irudiaKargatu(JOKALARIA0);
			pertsonaiarenIrudiaHasieratu = 0;
		}
		irudiakMarraztu(pertsonaia.irudia[0]);

		irudiaMugitu(pertsonaia.irudia[0], pertsonaia.x, pertsonaia.y);

		irudiaMugitu(bizitzaBarra, pertsonaia.x - 10, pertsonaia.y - 10);



		hitboxErdia(x1, x2, y1, y4);


		if( zeinTxanda % 7!=0)
		{
			
			if (etsaiaMugitu == 20)
			{

				for (int i = 0; i < etsaientzakoTxanda * 2; i++)
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

					etsaiaMugitu = 0;

					if (etsaiak[i].bizitzak == 0)
					{
						etsaiaHilda++;
						if (etsaiaHilda== etsaientzakoTxanda *2)
						{
							zeinScore += 200 * etsaientzakoTxanda;
							zeinTxanda++;
							etsaientzakoTxanda++;
							posizioakHasieratu();
							etsaienBizitzakHasieratu();
							etsaiaHilda = 0;
							etsaienIrudiaHasieratuta = 1;

						}
					}
				}
				etsaiaHilda = 0;
			}
			for (int i = 0; i < etsaientzakoTxanda * 2; i++)
			{
				n1 = etsaiak[i].x;
				m1 = etsaiak[i].y;
				zuzenaMarraztu(n1, m1, n1+50, m1);
				zuzenaMarraztu(n1 + 25, m1, n1 + 25, m1+25);
				zuzenaMarraztu(n1 + 25, m1 + 25, n1, m1+25);
				zuzenaMarraztu(n1, m1 + 25, n1, m1);
				irudiakMarraztu(etsaiarenIrudia.id[i]);
				irudiaMugitu(etsaiarenIrudia.id[i], n1, m1);
			}
		}
		for (int i = 0; i < etsaientzakoTxanda *2; i++)
		{
			if (kolisioaEtsaiarekin(i))
			{
				if (bizitza > 0)
				{
					printf("a");
					if (etsaiak[i].x + 25 < pertsonaia.x + 20)
					{
						pertsonaia.x += 50;
						x1 += 50;
						x2 += 50;
						x3 += 50;
						x4 += 50;
					}
					if (etsaiak[i].x + 25 > pertsonaia.x + 20)
					{
						pertsonaia.x -= 50;
						x1 -= 50;
						x2 -= 50;
						x3 -= 50;
						x4 -= 50;
					}
					irudiaMugitu(pertsonaia.irudia[pertsonaia.aldea], pertsonaia.x, pertsonaia.y);
					//bizitza -= 25;
				}
				else
				{
					egoera = GALDU;
				}
			}

		}
		if (zeinTxanda % 7 == 0)
		{
			if (erlearenBizitzaHasieratuta == 0)
			{
				erlearenBizitzaHasieratu();
				erlearenBizitzaHasieratuta = 1;
			}
			if (erlea.bizitza > 0)
			{
                irudiakMarraztu(erlearenIrudia);
				irudiaMugitu(erlearenIrudia, erlea.x, erlea.y);
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
						disparatuErlea1();
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
						disparatuErlea2();
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
						disparatuErlea3();
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
						disparatuErlea4();
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
						disparatuErlea1();
					}
				}
			}
			if (erlea.bizitza == 0)
			{
				bizitza = BIZITZA + 100;
				eskopetaBalak = HASIERAKO_BALAK;
				metrailetaBalak = HASIERAKO_BALAK;

				//--------------------------PERTSONAIAREN HOBEKUNTZA -------------------------------
				if (zeinDenbora % 2)
				{
					//bizitza gehitu
					bizitza = BIZITZA + 200;

				}

				else if (zeinDenbora % 5)
				{
					//balak gehitu
					HASIERAKO_BALAK + 30;
					HASIERAKO_BALAK + 30;
				}

				else if (zeinDenbora % 7)
				{
					//denbora hasieratu
					zeinDenbora = 300;
				}

				else
				{
					zeinDenbora = 300;
				}
			}
			//--------------------------PERTSONAIAREN HOBEKUNTZA -------------------------------
		}

		sortuBalakPos(balakPos, x1, x2, y1, y4);
		bordeak();
		txanda(zeinTxanda);
		score(zeinScore);
		denbora(zeinDenbora);

		if (arma == 0)
		{
			balaKop(metrailetaBalak);
		}
		if (arma == 1)
		{
			balaKop(eskopetaBalak);
		}

		pertsonaiaHitbox(x1, y1, x2, y2, x3, y3, x4, y4);
		ebentu = ebentuaJasoGertatuBada();
		//------TEKLAK--------//
		switch (ebentu)
		{
		case TECLA_d:
			if (pertsonaia.erdiaX != 570)
			{
				x1 += vx;
				x2 += vx;
				x3 += vx;
				x4 += vx;
			}
		case TECLA_e:
			erlea.bizitza = 0;

			break;
		case TECLA_a:
			if (pertsonaia.erdiaX != 70)
			{
				x1 -= vx;
				x2 -= vx;
				x3 -= vx;
				x4 -= vx;

			}
			pertsonaia.aldea = 0;
			if (irudiaAldatutaEzkerra == 0)
			{
				pertsonairenIrudiaAldatu(pertsonaia.aldea);
				irudiaAldatutaEskuina = 0;
				irudiaAldatutaEzkerra = 1;
			}

			break;
		case TECLA_w:
			if (pertsonaia.erdiaY != 35)
			{
				y1 -= vy;
				y2 -= vy;
				y3 -= vy;
				y4 -= vy;
			}
			break;
		case TECLA_s:
			if (pertsonaia.erdiaY != 385)
			{
				y1 += vy;
				y2 += vy;
				y3 += vy;
				y4 += vy;
			}
			break;
		case TECLA_m:if (arma == 0)arma++;
			break;
		case TECLA_n:if (arma == 1)arma--;
			break;
		case TECLA_SPACE:
			printf("\n%d", arma);
			if (arma == 0)
			{
				if (metrailetaBalak > 0)
				{
					metrailetaBalak--;
					for (balakDisparatu = 0; balakDisparatu < 40; balakDisparatu++)
					{

						Sleep(10);
						pantailaGarbitu();
						irudiakMarraztu(jokoarePantaila);
						balakSortu(arma, balakPos, x1, x2, y1, y4);
						disparatu(arma, balakPos);
						bordeak();
						pertsonaiaHitbox(x1, y1, x2, y2, x3, y3, x4, y4);
						markagailuak(zeinDenbora, zeinTxanda, zeinScore, metrailetaBalak);
						for (int j = 0; j < etsaientzakoTxanda * 2; j++)
						{
							if (etsaiariJo(j) && etsaiak[j].bizitzak > 0)
							{
								printf("d");
								etsaiak[j].bizitzak -= 25;
								printf("\n%d", etsaiak[j].bizitzak);
								balakDisparatu = 41;
							}
							if (etsaiak[j].bizitzak == 0)
							{
								etsaiak[j].x = 700;
							}

						}
						pantailaBerriztu();
					}
					//Sleep(200);

				}

				else if (metrailetaBalak == 0)
				{
					textuaIdatzi(erdiaX - 100, 50, "EZ DAUDE BALA GEHIAGO!");
					pantailaBerriztu();
					Sleep(500);
				}


			}
			else if (arma == 1)
			{
				if (eskopetaBalak > 0)
				{
					eskopetaBalak = eskopetaBalak - 3;
					for (balakDisparatu = 0; balakDisparatu < 30; balakDisparatu++)
					{
						Sleep(10);
						pantailaGarbitu();
						irudiakMarraztu(jokoarePantaila);
						balakSortu(arma, balakPos, x1, x2, y1, y4);
						disparatu(arma, balakPos);
						bordeak();
						pertsonaiaHitbox(x1, y1, x2, y2, x3, y3, x4, y4);
						markagailuak(zeinDenbora, zeinTxanda, zeinScore, eskopetaBalak);

						for (int i = 0; i < etsaientzakoTxanda * 2; i++)
						{
							if (etsaiariJo(i) && etsaiak[i].bizitzak > 0)
							{
								printf("d");
								etsaiak[i].bizitzak -= 25;
								printf("\n%d", etsaiak[i].bizitzak);
								balakDisparatu = 31;
							}
							if (etsaiak[i].bizitzak == 0)
							{
								etsaiak[i].x = 700;
							}
						}
						pantailaBerriztu();
					}

				}
				else if (eskopetaBalak == 0)
				{

					textuaIdatzi(erdiaX - 100, 50, "EZ DAUDE BALA GEHIAGO!");
					pantailaBerriztu();
					Sleep(500);
				}
				printf("%d", metrailetaBalak);
				printf("%d", eskopetaBalak);
			}
			break;
		default:
			break;
		}
		//------TEKLAK--------//

		pantailaBerriztu();
	} while (egoera == JOLASTEN);
		irudiaKendu(jokalaria);
		toggleMusic();
		audioTerminate();
		pantailaGarbitu();
		pantailaBerriztu();
		return egoera;
	
}

void bordeak()
{
	//----------Bordeak---------//
	arkatzKoloreaEzarri(255, 0, 128);
	zuzenaMarraztu(30, 30, 570, 30);
	zuzenaMarraztu(570, 30, 570, 450);
	zuzenaMarraztu(570, 450, 30, 450);
	zuzenaMarraztu(30, 450, 30, 30);
}
void pertsonaiaHitbox(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	zuzenaMarraztu(x1, y1, x2, y2);
	zuzenaMarraztu(x2, y2, x3, y3);
	zuzenaMarraztu(x3, y3, x4, y4);
	zuzenaMarraztu(x4, y4, x1, y1);
}
void hitboxErdia(int x1, int x2, int y1, int y2)
{

	pertsonaia.erdiaX = x1+20;
	pertsonaia.erdiaY = y1 + ((y2 - y1) / 2);

}

void etsaiaHitbox(int n1, int m1, int n2, int m2)
{

	arkatzKoloreaEzarri(0, 128, 0);
	zuzenaMarraztu(n1, m1, n2, m1);
	zuzenaMarraztu(n2, m1, n2, m2);
	zuzenaMarraztu(n2, m2, n1, m2);
	zuzenaMarraztu(n1, m2, n1, m1);
}

void pertsonairenIrudiaAldatu(int aldea)
{
	irudiaKendu(pertsonaia.irudia[0]);
	if (aldea == 0)
	{
		pertsonaia.irudia[0] = irudiaKargatu(JOKALARIA0);
	}
	if (aldea == 1)
	{
		pertsonaia.irudia[0] = irudiaKargatu(JOKALARIA1);
	}
	
}

void posizioakHasieratu()
{
	//-----Ezkerra----//
	etsaiak[0].x = 80;
	etsaiak[0].y = 130;
	etsaiak[1].x = 80;
	etsaiak[1].y = 180;
	etsaiak[2].x = 80;
	etsaiak[2].y = 230;
	etsaiak[3].x = 80;
	etsaiak[3].y = 280;
	etsaiak[4].x = 80;
	etsaiak[4].y = 330;
	etsaiak[5].x = 80;
	etsaiak[5].y = 380;
	//-----Eskuma----//
	etsaiak[6].x = 520;
	etsaiak[6].y = 130;
	etsaiak[7].x = 520;
	etsaiak[7].y = 180;
	etsaiak[8].x = 520;
	etsaiak[8].y = 230;
	etsaiak[9].x = 520;
	etsaiak[9].y = 280;
	etsaiak[10].x = 520;
	etsaiak[10].y = 330;
	etsaiak[11].x = 520;
	etsaiak[11].y = 380;	
}

void etsaienBizitzakHasieratu()
{
	etsaiak[0].bizitzak = 50;
	etsaiak[1].bizitzak = 50;
	etsaiak[2].bizitzak = 50;
	etsaiak[3].bizitzak = 50;
	etsaiak[4].bizitzak = 50;
	etsaiak[5].bizitzak = 50;
	etsaiak[6].bizitzak = 50;
	etsaiak[7].bizitzak = 50;
	etsaiak[8].bizitzak = 50;
	etsaiak[9].bizitzak = 50;
	etsaiak[10].bizitzak = 50;
	etsaiak[11].bizitzak = 50;
}

void hasieratuEtsaienIrudia(int zeinTxanda)
{

		for (int i = 0; i < (zeinTxanda - 1) * 2; i++)
		{
			irudiaKendu(etsaiarenIrudia.id[i]);
		}
		for (int i = 0; i < zeinTxanda * 2; i++)
		{
			etsaiarenIrudia.id[i] = irudiaKargatu(ETSAIA);
		}

}
int kolisioaEtsaiarekin(int i)
{
	int kolisioa = 0;
	if (etsaiak[i].x + 12 > pertsonaia.x + 20)
	{
		if ((etsaiak[i].x > pertsonaia.x && etsaiak[i].x < pertsonaia.x + 40) && (etsaiak[i].y > pertsonaia.y && etsaiak[i].y < pertsonaia.y + 60))
		{
			kolisioa = 1;
		}
	}
	if (etsaiak[i].x + 12 < pertsonaia.x + 20)
	{
		if ((etsaiak[i].x + 25 > pertsonaia.x && etsaiak[i].x + 50 < pertsonaia.x + 40) && (etsaiak[i].y > pertsonaia.y && etsaiak[i].y < pertsonaia.y + 60))
		{
			kolisioa = 1;
		}
	}
	
	return kolisioa;
}

int etsaiariJo(int i)
{
	int kolisioa = 0;

		if ((etsaiak[i].x < bala[0].x && etsaiak[i].x + 25 > bala[0].x) && (etsaiak[i].y < bala[0].y && etsaiak[i].y + 25 > bala[0].y))
		{
			kolisioa=1;
		}
		if ((etsaiak[i].x < bala[1].x && etsaiak[i].x + 25 > bala[1].x) && (etsaiak[i].y < bala[1].y && etsaiak[i].y + 25 > bala[1].y))
		{
			kolisioa=1;
		}
		if ((etsaiak[i].x < bala[2].x && etsaiak[i].x + 25 > bala[2].x) && (etsaiak[i].y < bala[2].y && etsaiak[i].y + 25 > bala[2].y))
		{
			kolisioa=1;
		}

	return kolisioa;
}

void erlearenBizitzaHasieratu()
{
	erlea.bizitza = 100;
}

int erlearekinKolisioa()
{
	int kolisioa = 0;

	if ((erlea.x > pertsonaia.x && erlea.x+75 < pertsonaia.x + 40) && (erlea.y > pertsonaia.y && erlea.y+75 < pertsonaia.y + 60))
	{
		kolisioa = 1;
	}
	if ((pertsonaia.x < erleaDisparoa[0].x && pertsonaia.x + 40 > erleaDisparoa[0].x) && (pertsonaia.y < erleaDisparoa[0].y && pertsonaia.y + 60 > erleaDisparoa[0].y))
	{
		kolisioa = 2;
	}
	if ((pertsonaia.x < erleaDisparoa[1].x && pertsonaia.x + 40 > erleaDisparoa[1].x) && (pertsonaia.y < erleaDisparoa[1].y && pertsonaia.y + 60 > erleaDisparoa[1].y))
	{
		kolisioa = 2;
	}
	if ((pertsonaia.x < erleaDisparoa[2].x && pertsonaia.x + 40 > erleaDisparoa[2].x) && (pertsonaia.y < erleaDisparoa[2].y && pertsonaia.y + 60 > erleaDisparoa[2].y))
	{
		kolisioa = 2;
	}
	return kolisioa;
}
int erleariJo()
{
	int kolisioa = 0;

	if ((erlea.x < bala[0].x && erlea.x + 75 > bala[0].x) && (erlea.y < bala[0].y && erlea.y + 75 > bala[0].y))
	{
		kolisioa = 1;
	}
	if ((erlea.x < bala[1].x && erlea.x + 75 > bala[1].x) && (erlea.y < bala[1].y && erlea.y + 75 > bala[1].y))
	{
		kolisioa = 1;
	}
	if ((erlea.x < bala[2].x && erlea.x + 75 > bala[2].x) && (erlea.y < bala[2].y && erlea.y + 75 > bala[2].y))
	{
		kolisioa = 1;
	}

	return kolisioa;
}

void disparatuErlea1()
{
	erleaDisparoa[0].x = erlea.x + 75;
	erleaDisparoa[0].y = erlea.y + 75;
	erleaDisparoa[1].x = erlea.x + 75;
	erleaDisparoa[1].y = erlea.y + 75;
	erleaDisparoa[2].x = erlea.x + 75;
	erleaDisparoa[2].y = erlea.y + 75;
	for (int i = 0; i < 40; i++)
	{
		Sleep(20);
		zirkuluaMarraztu(erleaDisparoa[0].x, erleaDisparoa[0].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[1].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[2].y, 4);
		irudiaMugitu(pertsonaia.irudia[1], pertsonaia.x, pertsonaia.y);
		erleaDisparoa[0].x += 4;
		erleaDisparoa[0].y += 2;
		erleaDisparoa[1].x += 4;
		erleaDisparoa[1].y += 4;
		erleaDisparoa[2].x += 4;
		erleaDisparoa[2].y += 6;
		pantailaBerriztu();
	}

}
void disparatuErlea2()
{
	erleaDisparoa[0].x = erlea.x + 75;
	erleaDisparoa[0].y = erlea.y ;
	erleaDisparoa[1].x = erlea.x + 75;
	erleaDisparoa[1].y = erlea.y;
	erleaDisparoa[2].x = erlea.x + 75;
	erleaDisparoa[2].y = erlea.y;
	for (int i = 0; i < 40; i++)
	{
		Sleep(20);
		zirkuluaMarraztu(erleaDisparoa[0].x, erleaDisparoa[0].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[1].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[2].y, 4);
		erleaDisparoa[0].x += 4;
		erleaDisparoa[0].y -= 2;
		erleaDisparoa[1].x += 4;
		erleaDisparoa[1].y -= 4;
		erleaDisparoa[2].x += 4;
		erleaDisparoa[2].y -= 6;
		pantailaBerriztu();
	}
}
void disparatuErlea3()
{
	erleaDisparoa[0].x = erlea.x;
	erleaDisparoa[0].y = erlea.y;
	erleaDisparoa[1].x = erlea.x;
	erleaDisparoa[1].y = erlea.y;
	erleaDisparoa[2].x = erlea.x;
	erleaDisparoa[2].y = erlea.y;
	for (int i = 0; i < 40; i++)
	{
		Sleep(20);
		zirkuluaMarraztu(erleaDisparoa[0].x, erleaDisparoa[0].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[1].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[2].y, 4);
		erleaDisparoa[0].x -= 4;
		erleaDisparoa[0].y -= 2;
		erleaDisparoa[1].x -= 4;
		erleaDisparoa[1].y -= 4;
		erleaDisparoa[2].x -= 4;
		erleaDisparoa[2].y -= 6;
		pantailaBerriztu();
	}
}
void disparatuErlea4()
{
	erleaDisparoa[0].x = erlea.x;
	erleaDisparoa[0].y = erlea.y + 75;
	erleaDisparoa[1].x = erlea.x;
	erleaDisparoa[1].y = erlea.y + 75;
	erleaDisparoa[2].x = erlea.x;
	erleaDisparoa[2].y = erlea.y + 75;
	for (int i = 0; i < 40; i++)
	{
		Sleep(20);
		zirkuluaMarraztu(erleaDisparoa[0].x, erleaDisparoa[0].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[1].y, 4);
		zirkuluaMarraztu(erleaDisparoa[1].x, erleaDisparoa[2].y, 4);
		erleaDisparoa[0].x -= 4;
		erleaDisparoa[0].y += 2;
		erleaDisparoa[1].x -= 4;
		erleaDisparoa[1].y += 4;
		erleaDisparoa[2].x -= 4;
		erleaDisparoa[2].y += 6;
		pantailaBerriztu();
	}
}



EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa) {
  EGOERA  ret = JOLASTEN;
  if (jokalaria.pos.x >oztopoa.pos.x - 20 && jokalaria.pos.x <oztopoa.pos.x + 20 && jokalaria.pos.y >oztopoa.pos.y - 20 && jokalaria.pos.y <oztopoa.pos.y + 20) {
    ret = IRABAZI;
  }
  else if (jokalaria.pos.x > 600) {
    ret = GALDU;
  }
  return ret;
}

int  jokoAmaierakoa(EGOERA egoera)
{
  int ebentu = 0, id;
  int idAudioGame;

  loadTheMusic(BUKAERA_SOUND_1);
  if (egoera == IRABAZI) {
    idAudioGame = loadSound(JOKOA_SOUND_WIN);
    playSound(idAudioGame);
  }
  else {
    idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
    playSound(idAudioGame);
  }
  id=BUKAERA_irudiaBistaratu();
  do 
  {
    ebentu = ebentuaJasoGertatuBada();
  } while ((ebentu!= TECLA_RETURN) && (ebentu!= SAGU_BOTOIA_ESKUMA));
  audioTerminate();
  irudiaKendu(id);
  return (ebentu != TECLA_RETURN) ? 1 : 0;
}
int BUKAERA_irudiaBistaratu() {
  int id = -1;
  id = irudiaKargatu(BUKAERA_IMAGE);
  irudiaMugitu(id, 200, 200);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  return id;
}
