
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"


int encontramapa(MAPA *map, POSICAO*p, char c) {
	
	int i, j;
	
	for(i=0; i< map->linhas; i++) {
		for(j=0; j< map->colunas; j++) {
			if(map->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return 1;
			}
			
		}
	}	
	
	return 0;
}

void lemapa(MAPA *map) {
	
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa\n");
		exit(1);
	}
	
	fscanf(f, "%d %d", &(map->linhas), &(map->colunas));
	
	alocamapa(map);
	
	int j;
	
	for(j = 0; j<map->colunas; j++) {
		fscanf(f, "%s", map->matriz[j]);
	}
	fclose(f);
	
}

void alocamapa(MAPA *map) {

    // aloca espa�o para a matriz
	map->matriz = (char**)malloc(sizeof(char*)* map->linhas);
	
	int i;
	for(i = 0; i< map->linhas; i++) {
		map->matriz[i] = (char*)malloc(sizeof(char) * (map->colunas + 1));	
	}
			
}

void copiaMapa(MAPA *destino, MAPA *origem) {
	
	destino->linhas = origem->linhas;
	destino->colunas = origem->colunas;
	
	alocamapa(destino);
	int i;
	for(i = 0; i< origem->linhas; i++) {
		strcpy(destino->matriz[i], origem->matriz[i]);
	}
	
}


void liberamapa(MAPA *map) {
	
	int i;
	
	for(i = 0; i< map->linhas;i++) {
		free(map->matriz[i]);
	}
}

void andanoMapa(MAPA*map, int xorigem, int yorigem, int xdestino, int ydestino) {
	
	char personagem = map->matriz[xorigem][yorigem];
	map->matriz[xdestino][ydestino] = personagem;
	map->matriz[xorigem][yorigem] = VAZIO;
	
}

// funcao que retorna a quantidade do elemento passado para a funcao
int qtdElementosMapa(MAPA *map, char c) {
	
	int i, j, qtdElem;
	
	for(i=0; i< map->linhas; i++) {
		for(j=0; j< map->colunas; j++) {
			if(map->matriz[i][j] == c) {
		
			   qtdElem++;
			}
	
		}
	
	}	
	
	return qtdElem;
}

int podeAndar(MAPA *map, char personagem ,int x, int y) {
	return 
	    posicaoValida(map, x, y) &&
	    !ehParede(map,  x, y) &&
	    !ehPersonagem(map, personagem, x, y);
	
}


int posicaoValida(MAPA *map, int x, int y) {
	
	if(x >= map->linhas)
		return 0;
	if(y >= map->colunas)
		return 0;
	
	return 1;
	
}

int ehPersonagem(MAPA *map, char personagem , int x, int y) {
	
	return map->matriz[x][y] == personagem;
	
}


int ehParede(MAPA *map, int x, int y) {
	
	return map->matriz[x][y] == PAREDE_VERTICAL ||
	       map->matriz[x][y] == PAREDE_HORIZONTAL;
	       
	
}

// ===================