#ifndef _PACMAN_H_
#define _PACMAN_H_


// constantes
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

// PILULA
void explodePilula();
void explodePilula2(int x, int y, int somax, int somay,int qtd);


void infoGame();
void move(char direcao);
int ehdirecao(char direcao);
int gameOver();

// Fantasmas
void inteligenciaFantasmas();
int ondeFanstasmaVai(int xatual, int yatual, int *xdestino, int *ydestino);


#endif