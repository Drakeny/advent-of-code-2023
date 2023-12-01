// Day 1 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <ctype.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int extractDigits(std::string line) {
  std::string combinedDigits{};

  for (int i = 0; i < line.length(); i++) {
    if (isdigit(line[i])) {
      combinedDigits += line[i];
      break;
    }
  }

  for (int i = line.length() - 1; i >= 0; i--) {
    if (isdigit(line[i])) {
      combinedDigits += line[i];
      break;
    }
  }

  std::cout << "Sum of of both values is: " << combinedDigits << "\n";

  return std::stoi(combinedDigits);
}

int main() {
  std::ifstream inputFile("input.txt");

  if (!inputFile) {
    std::cerr << "Well shit";
    return 1;
  } else {
    std::cout << "File read successfully \n";
  }

  std::string line{};
  int totalValue{};
  while (inputFile >> line) {
    std::cout << "-----------------------"
              << "\n";
    // inputFile >> line;
    std::cout << line << "\n";
    totalValue += extractDigits(line);
  }
  std::cout << "\n We Done here \n The Total Value is " << totalValue;

  return 0;
}