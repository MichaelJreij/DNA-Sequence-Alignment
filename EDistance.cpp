// Copyright 2023 <Michael Jreij>"
#include "EDistance.hpp"
#include <iostream>
#include <fstream>
#include <string>

EDistance::EDistance() {
}


EDistance::EDistance(std::string s1, std::string s2) {
  row = s1.size()+1;
  col = s2.size()+1;
    array = new int*[row];
    _s1 = s1;
    _s2 = s2;
    for (int i = 0; i < row; i++) {
    array[i] = new int[col];
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      array[i][j] = 0;
    }
  }
}

int EDistance::penalty(char a, char b) {
    if (a == b) {
     return 0;
  } else {
     return 1;
  }
return 0;
}

int EDistance::min3(int a, int b, int c) {
  int minAB;
  if (a < b) {
    minAB = a;
  } else {
    minAB = b;
  }

  if (minAB < c) {
    return minAB;
  } else {
    return c;
  }
}

int EDistance::optDistance() {
  for (int i = row - 1; i >= 0; i--) {
        array[i][col - 1] = (row - 1 - i) * 2;
    }

    for (int j = col - 2; j >= 0; j--) {
        array[row - 1][j] = (col - 1 - j) * 2;
    }

for (int i = row - 2; i >= 0; i--) {
        for (int j = col - 2; j >= 0; j--) {
            int diag = array[i + 1][j + 1] + penalty(_s1[i], _s2[j]);
            int down = array[i + 1][j] + 2;
            int right = array[i][j + 1] + 2;

            array[i][j] = min3(diag, down, right);
        }
    }
  return array[0][0];

return 0;
}

std::string EDistance::alignment() {
    int i = 0;
    int j = 0;
    std::string result;

    while (i < row - 1 && j < col - 1) {
        int diag = array[i + 1][j + 1];
        int down = array[i + 1][j];

         int p = penalty(_s1[i], _s2[j]);

        if (array[i][j] == diag+p) {
            std::cout << _s1[i] << " " << _s2[j];
            std::cout << " " << penalty(_s1[i], _s2[j]) << std::endl;
            result = result  + _s1[i] + " " +
             _s2[j] + " " + std::to_string(p) + "\n";
            i++;
            j++;
        } else if (array[i][j] == down+2) {
std::cout << _s1[i] << " -" << " 2" << std::endl;
          result = result + _s1[i] + "-" + " 2" + "\n";
            // std::cout << "_ " << _s2[j] << " 2"<< std::endl;
            // result = result + "_ " + _s2[j] + " 2" + "\n";
            i++;
        } else {
            // std::cout << _s1[i] << " _" << " 2" << std::endl;
            // result = result + _s1[i] + " _" + " 2" + "\n";
std::cout << "- " << _s2[j] << " 2"<< std::endl;
            result = result + "-" + _s2[j] + "2" + "\n";
            j++;
        }
    }

    return result;
}
