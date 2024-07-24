#include "s21_string.h"

// src: ABCDEFG
// dest: ..[CDEFG]
// buf:
// res:

/**
 * @brief Копирует n байт из области памяти src в область памяти dest. Память
 * ares могут перекрываться: копирование происходит так, как будто сначала
 * копируются байты из src в массив tmp, который не перекрывает src или dest, а
 * затем байты копируются из tmp в dest.
 *
 * @параметр dest
 * @param src
 * @param n
 * @возвращает значение void*
 */

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *to = (char *)dest;
  char *from = (char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);

  if (tmp) {
    s21_memcpy(tmp, from, n);
    s21_memcpy(to, tmp, n);
    free(tmp);
  }
  return dest;
}