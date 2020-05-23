#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define PILULA 'P'

// Cores
#define COR_HEROI 14 // AMARELO
#define COR_FANTASMA 4 // VERMELHO
#define COR_PILULA 2 // VERDE
#define COR_PAREDES 1 // AZUL
#define COR_VAZIO 0 // PRETO

struct mapa {
	
	char** matriz;
	int linhas;
	int colunas;
	
};

typedef struct mapa MAPA;

struct posicao {
	
	int x;
	int y;
		
};

typedef struct posicao POSICAO;


void lemapa(MAPA *map);
void copiaMapa(MAPA *destino, MAPA *origem);
int encontramapa(MAPA *map, POSICAO*p, char c);
void alocamapa(MAPA *map);
void liberamapa(MAPA *map);
int qtdElementosMapa(MAPA *map, char c);
void andanoMapa(MAPA *map, int xorigem, int yorigem, int xdestino, int ydestino);


int ehPersonagem(MAPA *map, char personagem , int x, int y);
int ehParede(MAPA *map, int x, int y);
int podeAndar(MAPA *map, char personagem, int x, int y);
int posicaoValida(MAPA *map, int x, int y);


#endif