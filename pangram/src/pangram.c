#include <stdio.h> // remove

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool all_nonzero(const int *list, int count)
{
  for (int i = 0; i < count; i++)
    if (list[i] == 0)
      return false;

  return true;
}

bool is_pangram(const char *sentence)
{
  if (sentence == NULL)
    return false;

  int *found = calloc('z' - 'a' + 1, sizeof(int));
  int i, items;
  bool result = true;
  char chr;

  for (i = 0, items = strlen(sentence); i < items; i++)
  {
    chr = sentence[i];
    if (!isalpha(chr))
      continue;

    found[(int)(tolower(chr) - 'a')]++;
  }

  result = all_nonzero(found, 'z' - 'a');

  free(found);

  return result;
}
