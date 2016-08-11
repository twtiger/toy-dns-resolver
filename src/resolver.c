#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "types.h"

const uint16_t QUERY = 0;
const uint16_t STANDARD_QUERY = 0;
const uint16_t NOT_AUTHORITATIVE = 0;
const uint16_t NOT_TRUNCATED = 0;
const uint16_t RECURSION_DESIRED = 1;
const uint16_t RECURSION_NOT_AVAILABLE = 0;
const uint16_t NO_ERRORS = 0;
const uint16_t ONE_QUESTION = 1;
const uint16_t NO_RESOURCE_RECORDS_IN_ANSWER = 0;
const uint16_t NO_RESOURCE_RECORDS_IN_AUTHORITY = 0;
const uint16_t NO_RESOURCE_RECORDS_IN_ADDITIONAL = 0;

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

void append(char* string, char character) {
  int last = strlen(string);
  realloc(string, last + 2);
  string[last] = character;
  string[last + 1] = '\0';
}

char** split_by_period(char* string) {
  char **words = malloc(count_words(string));
  int word_count = 0;
  char *tmp_string = malloc(1);
  for (int i = 0; i <= strlen(string); i++){
    if (string[i] == '.' || i == strlen(string)) {
      words[word_count] = tmp_string;
      tmp_string = malloc(1);
      word_count++;
    } else {
      append(tmp_string, string[i]);
    }
  }
  return words;
};
