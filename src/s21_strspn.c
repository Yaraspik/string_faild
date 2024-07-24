#include "s21_string.h"

/**
// @brief Возвращает длину максимального начального сегмента (span)
// байтовой строки с нулевым завершением, на которую указывает @str1,
// которая состоит только из символов, найденных в байтовой строке с нулевым
завершением,
// на которую указывает @str2.
// @param str1 - строка, по которой выполняется поиск
// @param str2 - строка, по которой выполняется поиск
// @return s21_size_t - возвращает максимальную длину начальной подстроки,
// состоящей только из символов str2 */
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;

  for (const char *a = str1; *a; a++) {
    unsigned short was = 0;
    for (const char *b = str2; *b; b++) {
      if (*a == *b) {
        counter++;
        was = 1;
        break;
      }
    }
    if (!was) break;
  }
  return counter;
}