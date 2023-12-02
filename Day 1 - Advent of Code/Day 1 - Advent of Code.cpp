// Day 1 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <ctype.h>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int extractDigits(std::string line);
std::string swapWrittenNumbers(std::string line);

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
    std::cout << line << "\n";
    totalValue += extractDigits(swapWrittenNumbers(line));
  }
  std::cout << "\n We Done here \n The Total Value is " << totalValue;

  return 0;
}

// Part 1
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

// Part 2
std::string swapWrittenNumbers(std::string line) {
  std::string replaced{line};
  std::unordered_map<std::string, std::string> numbers;

  numbers = {{"o1e", "one"},     {"t2o", "two"},     {"th3ee", "three"},
             {"fo4ur", "four"},  {"fi5ve", "five"},  {"s6x", "six"},
             {"se7en", "seven"}, {"ei8ht", "eight"}, {"ni9ne", "nine"}};

  int strIndex{};
  for (auto x : numbers) {
    while ((strIndex = replaced.find(x.second)) != std::string::npos) {
      std::cout << "match found starting at index: " << strIndex << "\n";
      replaced.replace(strIndex, x.second.length(), x.first);
      std::cout << replaced << "\n";
    }
  }

  return replaced;
}