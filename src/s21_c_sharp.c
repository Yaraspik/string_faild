#include "s21_string.h"

/**
 * @brief Возвращает копию строки (str), преобразованную в верхний регистр. В
 * случае любой ошибки
 * * возвращает значение 21_NULL.
 * @внимание, эта функция использует malloc, поэтому от пользователя требуется
 * free.
 * @param str - строка в верхнем регистре для создания копии.
 * @возвращает указатель на вновь созданную строку.
 */

void *s21_to_upper(const char *str) {
  char *str_copy = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);

    str_copy = (char *)malloc(sizeof(char) * (len + 1));

    if (str_copy) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_copy[i] = (str[i] - 'a') + 'A';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

/**
 * @brief Возвращает копию строки (str), преобразованную в нижний регистр. В
случае любой ошибки * возвращает значение S21_NULL.
 * @warning Эта функция использует malloc, поэтому от пользователя требуется
free.
 * @параметр str - str для создания строчной копии.
 * @возвращает указатель на вновь созданную строку.
 */

void *s21_to_lower(const char *str) {
  char *str_copy = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);

    str_copy = (char *)malloc(sizeof(char) * (len + 1));

    if (str_copy) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str_copy[i] = (str[i] - 'A') + 'a';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

/**
 * @brief Возвращает новую строку, в которую указанная строка (str) вставляется
в указанную позицию индекса (start_index) в данной строке (src). В случае
 * при любой ошибке возвращайте значение S21_NULL
 * @warning Если значение start_index больше, чем str_len, это рассматривается
как ошибка.
 * Будет возвращено значение S21_NULL.
 * используется @warning Malloc, который требуется освободить от пользователя.
 *
 * необходимо вставить строку @param src.
 * @param str Цель вставки.
 * @param start_index Начальный индекс вставки src в цель.
 * @return void* указатель на новую объединенную строку.
 */

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t new_len = src_len + str_len;

    res = calloc(new_len + 1, sizeof(char));

    if (res) {
      for (s21_size_t i = 0, j = 0, m = 0; i < new_len; i++) {
        if (i < start_index || !str[m])
          res[i] = src[j++];
        else
          res[i] = str[m++];
      }
      res[new_len] = '\0';
    }
  } else if (str == S21_NULL && src != S21_NULL) {
    res = calloc(s21_strlen(src) + 1, sizeof(char));
    s21_strcpy(res, src);
  }
  return res;
}

/**
 * @brief Возвращает новую строку, в которой все начальные и конечные вхождения
 * набора указанных символов (trim_chars) из заданной строки (src)
 * удалены. В случае какой-либо ошибки возвращает значение 21_NULL
 * Функция @warning выделяет память, которую пользователь, как предполагается,
 * освобождает.
 *
 * @param src - объект для обрезки.
 * @param trim_chars - символы, которые должны быть удалены из src.
 * @return void - Указатель на новую строку с обрезанными символами.
 */

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;

  if (src) {
    if (trim_chars && *trim_chars) {
      s21_size_t len = s21_strlen(src);
      s21_size_t chars_len = s21_strlen(trim_chars);

      s21_trim_left(&src, trim_chars, &len, chars_len);
      if (len) s21_trim_right(&src, trim_chars, &len, chars_len);
      res = (char *)malloc(sizeof(char) * (len + 1));
      if (res) {
        for (s21_size_t i = 0; i < len + 1; i++) {
          if (i < len) {
            res[i] = src[i];
          } else {
            res[i] = '\0';
          }
        }
      }
    } else {
      res = s21_trim(src, "\t\n");
    }
  }
  return res;
}

void s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t m = 0;

  while (src && m != trim_chars_len) {
    if ((**src) == trim_chars[m]) {
      (*src)++;
      (*src_len) -= 1;
      m = 0;
      continue;
    }
    m++;
  }
}

void s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t m = 0;
  s21_size_t i = (*src_len) - 1;

  while (src && m != trim_chars_len) {
    if ((*src)[i] == trim_chars[m]) {
      i--;
      (*src_len)--;
      m = 0;
      continue;
    }
    m++;
  }
}