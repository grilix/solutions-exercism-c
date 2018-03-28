#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *abbreviate(const char *phrase)
{
  if (phrase == NULL)
    return NULL;

  int i, acr_len = 0, len = strlen(phrase);
  char current, next;

  if (len == 0)
    return NULL;

  // We'll just guess the max length to be
  // no more than len / 2
  char *result = calloc(len / 2, sizeof(char));

  if (result == NULL)
    return NULL;

  for (i = 0; i < len; i++)
  {
    next = toupper(phrase[i + 1]);
    current = toupper(phrase[i]);

    if (i == 0)
      result[acr_len++] = current;

    if (current == ' ' || current == '-')
      result[acr_len++] = next;

  }

  return result;
}
