#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

int main() {
  char str[MAX_SIZE];
  char substr[MAX_SIZE];
  char *ptr = NULL;

  printf("Введите строку: ");
  fgets(str, MAX_SIZE, stdin);
  str[strcspn(str, "\n")] = '\0';

  printf("Введите подстроку: ");
  fgets(substr, MAX_SIZE, stdin);
  substr[strcspn(substr, "\n")] = '\0';

  ptr = strstr(str, substr);

  if (ptr != NULL) {
    printf("Адрес подстроки: %p\n", (void *)ptr);
    printf("Остаток строки с найденной подстрокой: : %s\n", ptr);
  } else {
    printf("Подстрока не найдена (NULL)\n");
  }

  return 0;
}
