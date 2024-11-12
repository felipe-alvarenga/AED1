#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct item
{
  char name[21];
  struct item *next;
};

struct item *add_item_to_end(struct item *head, char name[21])
{
  struct item *new_item = malloc(sizeof(struct item));
  strncpy(new_item->name, name, 20);
  new_item->name[20] = '\0';
  new_item->next = NULL;

  if (head->next == NULL)
  {
    head->next = new_item;
  }
  else
  {
    struct item *last_item = head->next;
    while (last_item->next != NULL)
      last_item = last_item->next;
    last_item->next = new_item;
  }
  return new_item;
}

void clear_list(struct item *head)
{
  struct item *current = head->next;
  while (current != NULL)
  {
    struct item *temp = current;
    current = current->next;
    free(temp);
  }
  head->next = NULL;
}

void print_items(const struct item *head)
{
  const struct item *current_item = head->next;
  bool isFirst = true;
  while (current_item != NULL)
  {
    if (!isFirst)
      printf(" ");
    printf("%s", current_item->name);
    isFirst = false;
    current_item = current_item->next;
  }
  printf("\n");
}

bool is_unique(const struct item *head, const char name[21])
{
  const struct item *current = head->next;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
      return false;
    current = current->next;
  }
  return true;
}

void sort_list(struct item *head)
{
  if (head->next == NULL)
    return;

  bool sorted;
  do
  {
    sorted = true;
    struct item *prev = head;
    struct item *current = head->next;

    while (current != NULL && current->next != NULL)
    {
      if (strcmp(current->name, current->next->name) > 0)
      {
        struct item *next = current->next;
        current->next = next->next;
        next->next = current;
        prev->next = next;

        sorted = false;
        prev = next;
      }
      else
      {
        prev = current;
        current = current->next;
      }
    }
  } while (!sorted);
}

int main()
{
  int n;
  struct item head = {.name = "", .next = NULL};

  do
  {
    scanf("%d", &n);
  } while (n <= 0 || n > 100);

  getchar();
  for (int i = 0; i < n; i++)
  {
    char line_text[21000];
    fgets(line_text, sizeof(line_text), stdin);

    clear_list(&head);
    char word[21];
    int word_count = 0;

    for (int j = 0; line_text[j] != '\0'; j++)
    {
      if (line_text[j] == ' ' || line_text[j] == '\n')
      {
        if (word_count > 0)
        {
          word[word_count] = '\0';
          if (is_unique(&head, word))
          {
            add_item_to_end(&head, word);
          }
          word_count = 0;
        }
      }
      else if (word_count < 20)
      {
        word[word_count++] = line_text[j];
      }
    }
    sort_list(&head);
    print_items(&head);
  }

  clear_list(&head);
  return 0;
}
