#include "Array.h"

#include "unity.h"

void setUp() {

}

void tearDown() {

}

void test_should_pass() {
  TEST_ASSERT_EQUAL(0, 0);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_should_pass);
  return UNITY_END();
}