// Advent of Code - Day 2.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

int sumValidGames() {
  std::ifstream inputFile("input.txt");
  std::string line{};

  std::unordered_map<std::string, std::string> colors = {
      {"red", "12"},
      {"green", "13"},
      {"blue", "14"},
  };

  if (!inputFile) {
    std::cerr << "Failed";
    return 1;
  }

  int tempId{0};
  int totalIdSum{};

  while (inputFile >> line) {
    std::getline(inputFile, line);
    int offset = line.find_first_of(":");
    bool invalidGame{0};

    tempId++;
    std::cout << "Checking line " << tempId << ": " << line << "\n";

    for (auto x : colors) {
      int findResult{};
      std::cout << "Searching for " << x.first << "\n";
      while ((findResult = line.find(x.first, findResult)) !=
             std::string::npos) {
        if (isdigit(line[findResult - 3])) {
          std::string n{};
          n += line[findResult - 3];
          n += line[findResult - 2];
          if (std::stoi(n) > std::stoi(x.second)) {
            std::cout << "Invalid amount found: " << n << "\n";
            invalidGame = true;
          }
        }
        findResult++;
      }
    }

    if (!invalidGame) {
      totalIdSum += tempId;
      std::cout << "Valid game, total id sum is: " << totalIdSum << "\n";
    } else {
      std::cout << "Invalid Game. \n";
    }
    std::cout << "------------------------------ \n";
  }

  std::cout << "Validation complete, total id sum is: " << totalIdSum << "\n";

  return 0;
}

int main() {
  sumValidGames();

  return 0;
}
