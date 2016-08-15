#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "types.h"
#include "constants.h"

char* resolve(char* domain_name) {
    return "161.47.4.22";
}

uint16_t counter = 1;

void reset_counter() {
  counter = 1;
}

uint16_t generate_id() {
  uint16_t c = counter;
  counter++;
  return c;
}

header* build_header() {
  header *head = malloc(sizeof(header));
  head -> id = generate_id();
  head -> qr = QUERY;
  head -> opcode = STANDARD_QUERY;
  head -> aa = NOT_AUTHORITATIVE;
  head -> tc = NOT_TRUNCATED;
  head -> rd = RECURSION_DESIRED;
  head -> rs = RECURSION_NOT_AVAILABLE;
  head -> rcode = NO_ERRORS;
  head -> qdcount = ONE_QUESTION;
  head -> ancount = NO_RESOURCE_RECORDS_IN_ANSWER;
  head -> nscount = NO_RESOURCE_RECORDS_IN_AUTHORITY;
  head -> arcount = NO_RESOURCE_RECORDS_IN_ADDITIONAL;
  return head;
};

int count_words(char* string) {
  int word_counter = 1;
  for(int i = 0; i < strlen(string); i++){
    if (string[i] == '.') {
      word_counter++;
    }
  }
  return word_counter;
};

char** split_by_period(char* string) {
  int word_count = count_words(string);
  char **words = malloc(word_count);

  char *s = strdup(string);
  char *delim = ".";

  for(int i=0; i < word_count; i++) {
    char *word = strsep(&s, delim);
    words[i] = malloc(strlen(word)+1);
    strcpy(words[i], word);
  }
  return words;
};
