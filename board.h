


#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define BOARD_SIZE 8

typedef enum {
    PIECE_NONE,
    PIECE_PAWN,
    PIECE_KNIGHT,
    PIECE_BISHOP,
    PIECE_ROOK,
    PIECE_QUEEN,
    PIECE_KING
} PieceType;

typedef enum {
    COLOR_NONE,
    COLOR_WHITE,
    COLOR_BLACK
} PieceColor;

typedef struct {
    PieceType;
    PieceColor;
} Piece;

typedef struct
{
    Piece squares[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct {
    bool squares[BOARD_SIZE][BOARD_SIZE];
} Vision;

void board_init_empty(Board *board);
void board_print(const Board *board, const Vision *vision);

void vision_clear(Vision *vision);
void vision_calculate_rook(
    const Board *board,
    Vision *vision,
    int row,
    int colum
);

#endif