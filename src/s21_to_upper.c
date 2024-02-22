#include "s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *result = (char *)malloc(len + 1);
  if (result == s21_NULL) {
    return s21_NULL;
  }
  for (s21_size_t i = 0; i < len; i++) {
    char c = str[i];
    if (c >= 'a' && c <= 'z') {
      result[i] = c - 32;
    } else {
      result[i] = c;
    }
  }
  result[len] = '\0';
  return result;
}