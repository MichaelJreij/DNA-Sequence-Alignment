// Copyright 2023 <Michael Jreij>"
#pragma once
#include <iostream>
#include <fstream>
#include <string>


class EDistance {
 private:
    int row;
    int col;
    int** array;
    std::string _s1;
    std::string _s2;


char filename;

 public:
EDistance();
std::string alignment();
EDistance(std::string s1, std::string s2);
static int penalty(char a, char b);
static int min3(int a, int b, int c);
int optDistance();
};
