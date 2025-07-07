#include <stdio.h>
#include <string.h>

#define MENU                                                                                                         \
  "1) Добавить абонента\n2) Удалить абонента\n3) Поиск абонентов по " \
  "имени\n4) Вывод всех записей\n5) Выход"

struct abonent {
  char name[10];
  char second_name[10];
  char tel[10];
};

struct catalog {
  struct abonent abonent_list[100];
};

int is_record_free(struct abonent* p_abonent) {
  char* ch = (char*)p_abonent;
  int result = 1;
  for (unsigned int i = 0; i < sizeof(struct abonent); i++) {
    if (ch[i] != 0) {
      result = 0;
      break;
    }
  }
  return result;
}

struct abonent* get_free_record(struct catalog* my_catalog) {
  struct abonent* free_record = NULL;
  for (int i = 0; i < 100; i++) {
    if (is_record_free(&my_catalog->abonent_list[i])) {
      free_record = &my_catalog->abonent_list[i];
      break;
    }
  }
  return free_record;
}

int write_a_new_record(struct catalog* my_catalog) {
  struct abonent* a_new_record = get_free_record(my_catalog);
  if (a_new_record == NULL) {
    printf("Каталог полон, невозможно добавить нового абонента.\n");
  } else {
    printf("Введите имя: ");
    scanf("%9s", a_new_record->name);
    printf("Введите фамилию: ");
    scanf("%9s", a_new_record->second_name);
    printf("Введите телефон: ");
    scanf("%9s", a_new_record->tel);
  }
  return (a_new_record == NULL) ? 1 : 0;
}

void delete_abonent(struct catalog* my_catalog) {
  int index;
  printf("Введите индекс абонента для удаления (0-99): ");
  scanf("%d", &index);

  if (index < 0 || index >= 100) {
    printf("Неверный индекс!\n");
    return;
  }

  memset(&my_catalog->abonent_list[index], 0, sizeof(struct abonent));
  printf("Абонент удален.\n");
}

void search_by_name(struct catalog* my_catalog) {
  char name[10];
  printf("Введите имя для поиска: ");
  scanf("%9s", name);

  printf("Найденные абоненты:\n");
  for (int i = 0; i < 100; i++) {
    if (!is_record_free(&my_catalog->abonent_list[i]) &&
        strcmp(my_catalog->abonent_list[i].name, name) == 0) {
      printf("%d: %s %s, тел.: %s\n", i, my_catalog->abonent_list[i].name,
             my_catalog->abonent_list[i].second_name,
             my_catalog->abonent_list[i].tel);
    }
  }
}

void print_all_records(struct catalog* my_catalog) {
  printf("Все абоненты:\n");
  for (int i = 0; i < 100; i++) {
    if (!is_record_free(&my_catalog->abonent_list[i])) {
      printf("%d: %s %s, тел.: %s\n", i, my_catalog->abonent_list[i].name,
             my_catalog->abonent_list[i].second_name,
             my_catalog->abonent_list[i].tel);
    }
  }
}

void work_loop(struct catalog* my_catalog) {
  int choice;
  do {
    printf("\n%s\n", MENU);
    printf("Выберите действие: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        write_a_new_record(my_catalog);
        break;
      case 2:
        delete_abonent(my_catalog);
        break;
      case 3:
        search_by_name(my_catalog);
        break;
      case 4:
        print_all_records(my_catalog);
        break;
      case 5:
        printf("Выход...\n");
        break;
      default:
        printf("Неверный выбор!\n");
    }
  } while (choice != 5);
}

int main() {
  struct catalog my_catalog = {0};
  work_loop(&my_catalog);
  return 0;
}