/**
 * @file bitboard.c
 * @brief This source file contains the logic for pre-defined functions in
 * bitboard.h
 *
 * @author JJG
 * @date 02/21/2026
 */
#include <stdio.h>

#include "bitboard.h"
#include "bitboard_internal.h"

uint64_t
bitboard_mask_pawn_attacks(int square, int side) {
  uint64_t attacks = 0ULL;
  uint64_t board = 0ULL;
  bitboard_set_bit(board, square);
  if (!side) {
    attacks |= (board >> 7);
  } else {
    attacks |= (board << 7);
  }
  return attacks;
}

void
bitboard_print(uint64_t board) {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      int square = rank * 8 + file;
      if (!file) {
        printf(ROW_LABEL_FMT, 8 - rank);
      }
      printf(SQUARE_FMT, getbit(board, square) ? 1 : 0);
    }
    printf("\n");
  }
  printf("%s", COLUMN_LABELS);
  printf("Bitboard: %llu\n\n", board);
}
