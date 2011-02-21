/*
 *  chessboard.h
 *  HillClimbing
 *
 *  Created by Francois-Guillaume Ribreau on 21/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H

#include "lib/env.h"
#include "lib/Stack.h"
#include "queen.h"

typedef struct Chessboard* pChessboard;

/* Echequier */
struct Chessboard{
	int**	queens;
	int		size;
	int		h;
} Chessboard;


/* Etat d'une reine */

typedef struct Matrix* pMatrix;

typedef struct Matrix{
	int**		values;
	int			size;
} Matrix;


pChessboard Chessboard_constructor(int size);

//Vide l'echequier
void Chessboard_empty(pChessboard board);

//Dessine l'echequier
void Chessboard_show(pChessboard board);

//Retourne la position d'une reine dans une colonne
int Chessboard_getQueenPos(pChessboard pBoard, int col);

//Valorise la matrice avec values
void Chessboard_setQueens(pChessboard pBoard, int* values);

//Return true si 
bool Chessboard_equals(pChessboard pBoardB, pChessboard pBoardA);

//Retourne le H d'une matrice
int Chessboard_getH(pChessboard pBoard);

//Libérer l'échéquier de la mémoire
void Chessboard_free(pChessboard pBoard);

//Clone
pChessboard Chessboard_clone(pChessboard pBoardToClone);

//Déplacer la reine présente dans la colonne à la position indiquée
void Chessboard_moveQueenTo(pChessboard pBoard, int col, int line);

//
pChessboard Chessboard_getNextState(pChessboard pBoardCurrentState, int k, int T);
void Stack_showLowerValues(pStack stack);

pMatrix Matrix_constructor(pChessboard pBoard);
void Matrix_destructor(pMatrix hMatrix);

//Retourne un nouveau H générée à partir d'une nouvelle position
int* Matrix_getNewH(pMatrix hMat);

//Tools
void __showMatrix(int** mat, int size);
#endif
