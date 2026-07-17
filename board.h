


#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define BOARD_MAX_ROWS 16
#define BOARD_MAX_COLUMS 16

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
    Piece squares[BOARD_MAX_ROWS][BOARD_MAX_COLUMS];
} Board;

typedef struct {
    bool squares[BOARD_MAX_ROWS][BOARD_MAX_COLUMS];
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