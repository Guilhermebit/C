#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.c>

#include "pacman.h"
#include "mapa.h"
#include "ui.h"

MAPA map;
POSICAO heroi;
int temPilula = 0;

// FANTASMAS

void inteligenciaFantasmas() {
	
	MAPA copia;
	
	copiaMapa(&copia, &map);
	
	int lin, col;
	for(lin = 0; lin<map.linhas; lin++) {
		for(col = 0; col< map.colunas; col++) {
			
			if(copia.matriz[lin][col] == FANTASMA) {
				
				int xdestino;
				int ydestino;
				
				int encontrou = ondeFanstasmaVai(lin, col, &xdestino, &ydestino);
				
				if(encontrou) {
					andanoMapa(&map, lin, col, xdestino , ydestino);	
				}
				
			}
			
		}
		
    }
	
	liberamapa(&copia);
}

int ondeFanstasmaVai(int xatual, int yatual, int *xdestino, int *ydestino) {
	
	
	int opcoes[4][2] = {
		{ xatual, yatual +1},
    	{ xatual +1, yatual},
		{ xatual, yatual -1},
    	{ xatual -1, yatual}
	};
	
	srand(time(0));
	int i;
	// tentativas de mover os fantasmas
	for(i =0; i< 10; i++) {
		
		int posicao = rand() % 4;
		
		if(podeAndar(&map, FANTASMA, opcoes[posicao][0] , opcoes[posicao][1])) {
			*xdestino = opcoes[posicao][0];
			*ydestino = opcoes[posicao][1];
			
			return 1;
		}
	}
	
	return 0;
}


// ===================

// OUTRAS VERIFICACOES

int gameOver() {
	
	POSICAO pos;
	
	int pacmanMapa = encontramapa(&map, &pos, HEROI);
	return !pacmanMapa;	
}

int ehdirecao(char direcao) {
	
	return direcao == ESQUERDA ||
	   direcao == CIMA ||
       direcao == BAIXO ||
	   direcao == DIREITA; 
}



// ===================

// MOVIMENTACAO

void move(char direcao) {
	
       if(!ehdirecao(direcao))
	      return;	   	   
    

	   int proximox = heroi.x;
	   int proximoy = heroi.y;
	

	switch(direcao) {
		case ESQUERDA:
			proximoy--;
			break;
		case CIMA:
		    proximox--;
		    break;
		case BAIXO:
		    proximox++;
		    break;
		case DIREITA:
			proximoy++;
			break;
		
	}
	
	if(!podeAndar(&map, HEROI, proximox, proximoy))
	   return;
	   
	   //se esbarrar em um fantasma o heroi morre
	if(ehPersonagem(&map, FANTASMA, proximox, proximoy))
	   return;
   
   
   if (ehPersonagem(&map, PILULA, proximox, proximoy)) {
   	   temPilula++;	     
    }
   

	andanoMapa(&map, heroi.x, heroi.y, proximox, proximoy);

	heroi.x = proximox;
	heroi.y = proximoy;
			
}

// ===================

// PILULA

void explodePilula() {
	
	if(!temPilula) return;
	
	explodePilula2(heroi.x, heroi.y, 0, 1, 3);
	explodePilula2(heroi.x, heroi.y, 0,-1, 3);
	explodePilula2(heroi.x, heroi.y, 1, 0, 3);
	explodePilula2(heroi.x, heroi.y,-1, 0, 3);

	temPilula = 0;
}

void explodePilula2(int x, int y, int somax, int somay, int qtd) {
	
	
	if(qtd == 0) return;
	
	int novox = x + somax;
	int novoy = y + somay;
	
	if(!posicaoValida(&map, novox, novoy)) return;
	if(ehParede(&map, novox, novoy)) return;
	
	map.matriz[novox][novoy] = VAZIO;
	explodePilula2(x, y , novox, novoy, qtd - 1);
	
}

// ===================

void infoGame() {
	
	textcolor(WHITE);
	printf("PILULAS: %d\n", temPilula);
	
	int qtdFantasmas = qtdElementosMapa(&map, FANTASMA);
	printf("FANTASMAS: %d\n", qtdFantasmas);
	
}


int main() {
	
	lemapa(&map);
	encontramapa(&map, &heroi, HEROI);

	do {
			
		imprimemapa(&map);
		infoGame();

		char tecla;
		printf("\nTecla : ");
		scanf(" %c", &tecla);
		move(tecla);
	
		if(tecla == BOMBA) explodePilula();
		
		inteligenciaFantasmas();
	
	} while(!gameOver());
	
	liberamapa(&map);
	
	return 0;
}

