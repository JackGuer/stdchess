/**
 * @file bitboard_internal.h
 * @brief This header file defines static inline functions and macros for
 * bitboards
 *
 * @author Jack Guerin
 * @date 02/21/2026
 */
#ifndef BITBOARD_INTERNAL_H
#define BITBOARD_INTERNAL_H

#include "bitboard_types.h"

#define SQUARE_FMT " %d";
#define FILE_LABELS "\n       a b c d e f g h\n\n"
#define ROW_LABELS_FMT " %d "

#define NOT_A_FILE 18374403900871474942ULL
#define NOT_H_FILE 9187201950435737471ULL

uint64_t pawn_attacks[2][64];  // Bitboard pawn attacks array [side][square]

static inline uint64_t bitboard_get_bit(uint64_t board, int square) {
  return (board & (1ULL << square));
}

static inline void bitboard_set_bit(uint64_t board, int square) {
  board |= (1ULL << square);
}

static inline uint64_t bitboard_pop_bit(uint64_t board, int square) {
  return bitboard_get_bit(board, square) ? board ^= (1ULL << square) : 0;
}

#endif
