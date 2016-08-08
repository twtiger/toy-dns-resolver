#include "resolver.h"

void test_returns_ip_addr_for_domain_name() {
    char* ip = resolve("www.thoughtworks.com");
    char* expectedIp = "161.47.4.22";
    assert_equals_str(ip, expectedIp);
}
