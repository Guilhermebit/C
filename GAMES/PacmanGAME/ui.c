#include <stdio.h>
#include "mapa.h"

char desenhoParede[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char desenhoFantasma[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char desenhoHeroi[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char desenhoPilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char desenhoVazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};


void imprimeParte(char desenho[4][7] , int parte, int cor) {
	
	textcolor(cor);
	printf("%s", desenho[parte]);
}

void imprimemapa(MAPA *map) {
	
	int i, j, parte;
	
	for(i=0; i< map->linhas; i++) {
		
	  for(parte=0; parte< 4; parte++) {
		
		for(j=0; j< map->colunas; j++) {
		
				switch(map->matriz[i][j]) {
					case FANTASMA:
						imprimeParte(desenhoFantasma, parte, COR_FANTASMA);
						break;
					case HEROI:
						imprimeParte(desenhoHeroi, parte, COR_HEROI);
						break;
					
					case PILULA:
						imprimeParte(desenhoPilula, parte, COR_PILULA);
						break;
					
					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						imprimeParte(desenhoParede, parte, COR_PAREDES);
						break;
					case VAZIO:
						imprimeParte(desenhoVazio, parte, COR_VAZIO);
						break;  
				}
		
	        }
	        
	        printf("\n");
	    }
	    
    }
}



