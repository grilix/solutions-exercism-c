#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "word_count.h"

void add_word(word_count_word_t *words, int *current_count, const char *word,
    int word_len)
{
  int i = 0;

  for (i = 0; i < (*current_count); i++)
    if (strncmp(words[i].text, word, word_len) == 0)
    {
      words[i].count++;
      return;
    }

  // we have no room for more words
  if (i == MAX_WORDS)
  {
    *current_count = -2;
    return;
  }

  memcpy(words[i].text, word, word_len);
  words[i].text[word_len] = '\0';
  words[i].count = 1;

  *current_count += 1;
}

char fix_char(char current, char next, int current_len)
{
  if (isalnum(current)) // it's already okay
    return current;

  if (current == '\'') // we might be able to fix that
    // on the middle of a string is okay
    if (current_len > 0 && isalnum(next))
      return current;

  // This character cannot be included
  // in a string.
  return '\0';
}

// word_count - routine to classify the unique words and their frequency
// in a test input string
// inputs:
//    input_text =  a null-terminated string containing that is analyzed
//
// outputs:
//    words = allocated structure to record the words found and their
//            frequency
//    uniqueWords - number of words in the words structure
//           returns a negative number if an error.
//           words will contain the results up to that point.
int word_count(const char *input_text, word_count_word_t *words)
{
  int count = 0, current_len = 0;
  char word[MAX_WORD_LENGTH], chr;
  char *ptr = (char *)input_text;

  // clean the garbage from previous runs
  memset(words, 0, MAX_WORDS * sizeof(word_count_word_t));

  do {
    chr = fix_char(*ptr, *(ptr + 1), current_len);

    if (chr != '\0')
    {
      // we can't keep adding characters forever
      if (current_len == MAX_WORD_LENGTH)
        return -1;

      word[current_len++] = tolower(chr);
    }
    else if (current_len > 0)
    {
      add_word(words, &count, word, current_len);
      current_len = 0;
    }
  } while ((count >= 0) && *(ptr++));

  return count;
}
