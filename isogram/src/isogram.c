#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_isogram(const char phrase[])
{
  int len = strlen(phrase);
  int i, chr;
  char *ptr;

  for (i = 0; i < len; i++)
  {
    chr = tolower(phrase[i]);

    if (chr == '-' || chr == ' ')
      continue;

    ptr = (char *)(phrase + i);

    while (*(ptr++))
      if (tolower(*ptr) == chr)
        return false;
  }

  return true;
}
