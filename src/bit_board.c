/*
 * File: bit_board.c
 * Author: Jack Guerin
 * Description: This source file defines the logic for the functions
 * pre-defined in the associated header file.
 */
#include <stdio.h>

#include "bit_board.h"

U64
mask_pawn_attacks(int square, int side) {
  U64 attacks = 0ULL;
  U64 board = 0ULL;
  // Set piece on board
  setbit(board, square);
  // White pawns
  if (!side) {
    attacks |= (board >> 7);
  }
  // Black pawns
  else {
    attacks |= (board << 7);
  }
  return attacks;
}

void
bprint(U64 board) {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      int square = rank * 8 + file;
      if (!file) {
        printf(ROWS, 8 - rank);
      }
      printf(SQUARE_FMT, getbit(board, square) ? 1 : 0);
    }
    printf("\n");
  }
  printf("%s", COLUMNS);
  printf("Bitboard: %llu\n\n", board);
}
