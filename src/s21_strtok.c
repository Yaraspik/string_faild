#include "s21_string.h"

/**
// @brief Находит следующий токен в байтовой строке, заканчивающейся нулем, на
которую указывает
// str. Символы-разделители идентифицируются байтовой строкой, заканчивающейся
нулем,
// на которую указывает delim.
// @warning Strtok изменяет исходную строку. Документы CPP: "Если бы такой
персонаж был
// найден, он заменяется нулевым символом '\0', а указатель на
следующий символ * сохраняется в статическом расположении для последующего
использования.
// призывы."
// Строка @param str, которую нужно обозначить, или S21_NULL.
// @param определяет разделители строки.
// @return char* Следующий токен.*/
char *s21_strtok(char *str, const char *delim) {
  static int next_null, tok;
  static s21_size_t ind;
  static char *max_ptr;
  static char *addr;

  // Мы не можем инициализировать статические переменные неконстантным значением
  // поскольку статические переменные хранятся в разделе .data двоичного файла
  if (str) {
    tok = 1;
    ind = 0, next_null = 0;
    addr =
        str +
        s21_strspn(
            str, delim);  // пропуск конечных разделителей, если таковые имеются
    max_ptr = str + s21_strlen(str);
  }
  char *res = S21_NULL;
  if (!(addr >= max_ptr || next_null)) {
    int non_delim = 1;
    for (int i = 0; addr[i]; i++) {
      s21_size_t step = s21_strspn(addr + i, delim);
      if (step) {
        non_delim = 0;
        for (s21_size_t j = i; j < i + step; j++) addr[j] = '\0';
        ind = step + i;
        break;
      }
    }
    if (tok == 1 && non_delim) next_null = 1;
    res = addr;   // старое начало строки
    addr += ind;  // новое начало новой строки
  }
  ++tok;
  return res;
}