// Advent of Code - Day 2.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

int sumValidGames();
void powerGameCubes(int red, int green, int blue);

int main() {
  sumValidGames();

  return 0;
}

int sumValidGames() {
  std::ifstream inputFile("input.txt");
  std::string line{};

  int highestRed{}, highestGreen{}, highestBlue{};

  std::unordered_map<std::string, std::string> colors = {
      {"red", "12"},
      {"green", "13"},
      {"blue", "14"},
  };
  std::unordered_map<std::string, std::string> minValues{};

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

    minValues = minValues = {
        {"red", "0"},
        {"green", "0"},
        {"blue", "0"},
    };

    tempId++;
    std::cout << "Checking line " << tempId << ": " << line << "\n";

    for (auto x : colors) {
      int findResult{};
      std::cout << "Searching for " << x.first << "\n";
      while ((findResult = line.find(x.first, findResult)) !=
             std::string::npos) {
        std::string n{};
        n += line[findResult - 3];
        n += line[findResult - 2];
        std::cout << n << "\n";
        if (std::stoi(n) > std::stoi(x.second)) {
          std::cout << "Invalid amount found: " << n << "\n";
          invalidGame = true;
        }

        if (std::stoi(n) > std::stoi(minValues[x.first])) {
          minValues[x.first] = n;
        }

        findResult++;
      }
    }
    powerGameCubes(std::stoi(minValues["red"]), std::stoi(minValues["green"]),
                   std::stoi(minValues["blue"]));

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

// part 2
int powerSum{};
void powerGameCubes(int red, int green, int blue) {
  powerSum += red * green * blue;
  std::cout << "Sum of the power of all games is: " << powerSum << "\n";
}