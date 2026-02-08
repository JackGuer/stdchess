/*
 * File: chess_error.h
 * Author: Jack Guerin
 * Description: This file defines functions and constants for error
 * handling.
 */
#ifndef CHESS_ERROR_H
#define CHESS_ERROR_H

#include <stdio.h>
#include <stdarg.h>

/* Consants */

static const char* ERRNO_FMT = "%s (%d): Error: %s\n";

/* Functions */

static inline void perrorf(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

#endif
