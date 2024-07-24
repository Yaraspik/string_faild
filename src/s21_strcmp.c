#include "s21_string.h"

/**
 * @brief Сравнивает строку str1 на языке Си со строкой str2 на языке Си.
 *
 * @param str1 Сравниваемая строка на языке Си.
 * @param str2 сравниваемая строка на языке Си.
 * @return int 0 - содержимое обеих строк одинаково, другой код - нет.
 * равный
 */
int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;

  if (str1 && str2) {
    int i = 0;

    while (str1[i] && str1[i] == str2[i]) {
      i++;
    }
    res = str1[i] - str2[i];
  }
  return res;
}