/**
 * @file bitboard.h
 * @brief This header file defines public functions related to Bit Boards
 *
 * @author JJG
 * @date 02/21/2026
 */
#ifndef BITBOARD_H
#define BITBOARD_H

uint64_t bitboard_mask_pawn_attacks(int square, int side);

void bitboard_print(uint64_t board);

#endif
