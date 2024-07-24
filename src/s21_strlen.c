#include "s21_string.h"

/**
// @brief возвращает длину строки
// @warning S21_NULL str приводит к сбою UB, возможно, к сбою SEGFAULT
// @param str string
// @return s21_size_t length*/
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;

  if (str) {
    for (int i = 0; str[i]; i++) {
      len++;
    }
  }
  return len;
}