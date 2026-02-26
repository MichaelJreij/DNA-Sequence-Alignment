// Copyright 2023 <Michael Jreij>"
#include <iostream>
#include <fstream>
#include <string>
#include "EDistance.hpp"

int main(int argc, char* argv[]) {
  std::string s1, s2;
  std::cin >> s1 >> s2;

  EDistance var(s1, s2);

int temp3 = var.optDistance();
std::cout <<  "Edit distance = " << temp3 << '\n';
var.alignment();
  return 0;
}
