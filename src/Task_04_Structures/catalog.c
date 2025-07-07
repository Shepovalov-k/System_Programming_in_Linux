#include <stdio.h>

#define MENU                                                                                                         \
  "1) Добавить абонента\n2) Удалить абонента\n3) Поиск абонентов по " \
  "имени\n4) Вывод всех записей\n5) Выход"

struct abonent {
  char name[10];
  char second_name[10];
  char tel[10];
};

struct catalog
{
  struct abonent abonent_list[100];
  unsigned __int128 state;
};


void work_loop(struct catalog* my_catalog) { printf(MENU); }

int main() {
  struct catalog my_catalog = {0};
  work_loop(&my_catalog);
  return 0;
}