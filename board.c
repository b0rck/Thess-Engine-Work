


#include "board.h"
#include <stdio.h>

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
