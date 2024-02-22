#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *original = dest;
  while ((*dest++ = *src++) != '\0') continue;
  return original;
}