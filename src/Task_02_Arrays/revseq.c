#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int number;
  struct Node *prev;
  struct Node *next;
} Node;

int main() {
  Node *head = NULL;
  Node *tail = NULL;
  int num;
  char c;

  printf("Введите числа через пробел: ");

  while (scanf("%d", &num) == 1) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
      printf("Ошибка выделения памяти\n");
      exit(1);
    }

    new_node->number = num;
    new_node->prev = tail;
    new_node->next = NULL;

    if (head == NULL) {
      head = new_node;
    } else {
      tail->next = new_node;
    }
    tail = new_node;

    c = getchar();
    if (c == '\n') break;
    if (c != ' ') {
      printf("Ошибка: числа должны разделяться пробелами\n");
      exit(1);
    }
  }

  printf("Массив в обратном порядке: ");
  Node *current = tail;
  while (current != NULL) {
    printf("%d ", current->number);
    current = current->prev;
  }
  printf("\n");

  current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }

  return 0;
}