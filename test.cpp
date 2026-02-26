// Copyright 2023 <Michael Jreij>"

#include <iostream>
#include <string>

#include "EDistance.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(testOpt) {
  EDistance L3("AACAGTTACC", "TAAGGTCA");
  int optDistance = L3.optDistance();
  BOOST_REQUIRE_EQUAL(optDistance, 7);
}

BOOST_AUTO_TEST_CASE(testPenalty) {
  EDistance l4;
  BOOST_REQUIRE_EQUAL(l4.penalty('a', 'a'), 0);
}

BOOST_AUTO_TEST_CASE(testMin3) {
  EDistance l3;
  BOOST_REQUIRE_EQUAL(l3.min3(2, 6, 9), 2);
}
