#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "resolver.h"
#include "types.h"

void free_header(header *head) {
    free(head);
}

void teardown() {
  reset_counter();
}

void test_returns_ip_addr_for_domain_name() {
    char* ip = resolve("www.thoughtworks.com");
    char* expectedIp = "161.47.4.22";
    assert_equals_str(ip, expectedIp);
}

void test_parses_string_input_to_message_creates_header_with_query() {
}

void test_build_header_for_query_sets_to_query() {
    header *head = build_header();
    assert_equals_int(head->qr, 0);
    free_header(head);
}

void test_build_header_generates_id() {
    header *header1 = build_header();
    assert_equals_int(header1->id, 1);
    free_header(header1);

    header *header2 = build_header();
    assert_equals_int(header2->id, 2);
    free_header(header2);
}

void test_build_header_sets_opcode_for_standard_query() {
    header *head = build_header();
    assert_equals_int(head->opcode, 0);
    free_header(head);
}

void test_build_header_sets_authoritative_answer_as_non_authoritative() {
    header *head = build_header();
    assert_equals_int(head->aa, 0);
    free_header(head);
}

void test_build_header_sets_truncation_to_not_truncated() {
    header *head = build_header();
    assert_equals_int(head->tc, 0);
    free_header(head);
}

void test_build_header_sets_recursion_desired_to_true() {
    header *head = build_header();
    assert_equals_int(head->rd, 1);
    free_header(head);
}

void test_build_header_sets_recursion_available_to_false() {
    header *head = build_header();
    assert_equals_int(head->rs, 0);
    free_header(head);
}

void test_build_header_sets_response_code_to_no_errors() {
    header *head = build_header();
    assert_equals_int(head->rcode, 0);
    free_header(head);
}

void test_build_header_sets_qdcount_to_number_of_questions_asked() {
    header *head = build_header();
    assert_equals_int(head->qdcount, 1);
    free_header(head);
}

void test_build_header_sets_qdcount_to_number_of_rrs_in_answer_section() {
    header *head = build_header();
    assert_equals_int(head->ancount, 0);
    free_header(head);
}

void test_build_header_sets_qdcount_to_number_of_rrs_in_authority_section() {
    header *head = build_header();
    assert_equals_int(head->nscount, 0);
    free_header(head);
}

void test_build_header_sets_qdcount_to_number_of_rrs_in_additional_section() {
    header *head = build_header();
    assert_equals_int(head->arcount, 0);
    free_header(head);
}

void test_count_words_returns_number_of_words_separated_by_dots() {
    char* test_str = "something.else.another";

    int num_words = count_words(test_str);

    assert_equals_int(num_words, 3);
}

void test_split_by_dot_separates_string() {
    char* test_str = "something.else.another";
    char *expected[] = {
      "something",
      "else",
      "another"
    };

    char **words = split_by_period(test_str);

    assert_equals_str(words[0], expected[0]);
    assert_equals_str(words[1], expected[1]);
    assert_equals_str(words[2], expected[2]);

    free(words[0]);
    free(words[1]);
    free(words[2]);
    free(words);
}
