/*
 * File: bit_board.h
 * Author: Jack Guerin
 * Description: This header file defines structures, enumerations,
 * constants, and functions.
 */
#ifndef BIT_BOARD_H
#define BIT_BOARD_H

#include <stdint.h>

/* Constants */

#define U64 uint64_t
#define getbit(board, square) (board & (1ULL << square))
#define setbit(board, square) (board |= (1ULL << square))
#define popbit(board, square) (getbit(board, square) ? board ^= (1ULL << square) : 0)

static const char* SQUARE_FMT = " %d";
static const char* COLUMNS = "\n     a b c d e f g h\n\n";
static const char* ROWS = "  %d ";

static const U64 NOT_A_FILE = 18374403900871474942ULL;
static const U64 NOT_H_FILE = 9187201950435737471ULL;

/* Globals */

U64 pawn_attacks[2][64];  // Pawn attacks array [side][square]

/* Enumerations */

enum {
  a8, b8, c8, d8, e8, f8, g8, h8,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a1, b1, c1, d1, e1, f1, g1, h1
};

enum {
  white,
  black
};

/* Functions */

U64 mask_pawn_attacks(int square, int side);

void bprint(U64 board);

#endif
