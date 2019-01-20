/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "game02.h"
#define JOKOAREN_PANTAILA ".\\img\\Bozetoak\\Jokoaren pantaila\\background.bmp"
#define JOLASTEKO_GIDA ".\\img\\Bozetoak\\Jokoaren pantaila\\jolastekoGida.bmp"
#define JOKALARIA_AUTATU ".\\img\\Bozetoak\\Jokoaren pantaila\\pertsonaiaAutatu.bmp"
#define MENUA ".\\img\\Bozetoak\\Jokoaren pantaila\\menua.bmp"
#define MENUA1 ".\\img\\Bozetoak\\Jokoaren pantaila\\menua1.bmp"

int main(int argc, char * str[]) {
  int jarraitu = 0, zerEgin;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 600x480 video: %s\n", SDL_GetError());
    return 1;
  }
  textuaGaitu(); 
  zerEgin = sarreraMenua();
   while (zerEgin != 0){
	  if (zerEgin == 1)
	  {
		  pertsonaiaAutatu();
	  }
	  if (zerEgin == 2)
	  {
		  jokoarenGida();
	  }
	  zerEgin = sarreraMenua();
}

  do
  {
	egoera = jokatu();
	jarraitu = jokoAmaierakoa(egoera);
  } while (jarraitu);
  sgItxi();
  return 0;
}

