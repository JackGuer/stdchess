#include <stdlib.h>

#include "bit_board.h"
#include "chess_error.h"

int
main(int argc, char* argv[]) {
  int rc = EXIT_SUCCESS;
  U64 board = 0ULL;
  // bprint(mask_pawn_attacks(h4, white));
  for (int rank = 0; rank <8; rank++) {
    for (int file = 0; file <8; file++) {
      int square = rank * 8 + file;
      if (file != 7)
        setbit(board, square);
    }
  }
  bprint(board);
  return rc;
}
