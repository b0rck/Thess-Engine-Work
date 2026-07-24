


#include "board.h"
#include <stdio.h>
#include <ctype.h>

void board_init_empty(Board *board)
 {
    for (int row = 0; row < BOARD_MAX_ROWS; row++) {
        for (int column = 0; column < BOARD_MAX_COLUMNS; column++) {
            board->squares[row][column].type = PIECE_NONE;
            board->squares[row][column].color = COLOR_NONE;
        }
    }
 }

void vision_clear(Vision *vision) {
    for (int row = 0; row < BOARD_MAX_ROWS; row++) {
        for (int column = 0; column < BOARD_MAX_COLUMNS; column++) {
            vision->squares[row][column] = false;
        }
    }
}

static char piece_to_char(const Piece *piece)
{
    if (piece->type == PIECE_NONE)
        return '.';

    switch (piece->type)
    {
        case PIECE_PAWN: return 'P';
        case PIECE_KNIGHT: return 'N';
        case PIECE_BISHOP: return 'B';
        case PIECE_ROOK: return 'R';
        case PIECE_QUEEN: return 'Q';
        case PIECE_KING: return 'K';
        default: return '?';
    }
}

char piece_to_symbol(const Piece *piece)
{
    char symbol = piece_to_char(piece);

    if (piece->color == COLOR_BLACK)
        symbol = tolower(symbol);

    return symbol;
}

void board_print(const Board *board, const Vision *vision)
{
    for (int row = 0; row < BOARD_MAX_ROWS; row++)
    {
        for (int col = 0; col < BOARD_MAX_COLUMNS; col++)
        {
            const Piece *piece = &board->squares[row][col];

            char symbol = piece_to_symbol(piece);

            if (piece->color == COLOR_BLACK)
                symbol = tolower(symbol);

            printf("%c ", symbol);
        }
        printf("\n");
    }
}