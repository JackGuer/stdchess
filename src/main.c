#include <stdlib.h>

#include "bit_board.h"
#include "chess_error.h"

int
main(int argc, char* argv[]) {
  int rc = EXIT_SUCCESS;
  U64 board = 0ULL;
  setbit(board, e2);
  setbit(board, e3);
  popbit(board, e3);
  bprint(board);
  return rc;
}
