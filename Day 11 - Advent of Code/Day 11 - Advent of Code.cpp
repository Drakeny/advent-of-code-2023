// Day 11 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string, std::cout, std::endl;

struct GALAXY {
  int id, x, y;

  GALAXY(int ID, int X, int Y) {
    id = ID;
    x = X;
    y = Y;
  }
};

void part1();

int main() { part1(); }

void part1() {
  std::ifstream inputFile("inputTest.txt");
  if (!inputFile) {
    std::cerr << "Read failed";
    return;
  }

  std::vector<GALAXY> galaxies{};
  std::vector<string> universeX{};
  std::vector<string> universeY{};
  int nLines{0};
  int nGalaxies{0};
  string line{};

  // Get original Universe
  while (std::getline(inputFile, line)) {
    nLines++;
    universeX.push_back(line);
    if (line.find('#') == string::npos) {
      universeX.push_back(line);
      cout << "expanding universe" << endl;
    }
  }

  int offset{};
  // transpose
  for (size_t x = 0; x < universeX[x].size(); x++) {
    universeY.push_back("");
    for (size_t y = 0; y < universeX.size(); y++) {
      universeY[x+offset] += universeX[y][x];
      //std::reverse(universeY[x + offset].begin(), universeY[x + offset].end());
    }
    if (universeY[x+offset].find('#') == string::npos) {
      universeY.push_back(universeY[x + offset]);
      cout << "expanding universe" << endl;
      offset++;
    }
  }

  for (size_t i = 0; i < universeY.size(); i++) {
    size_t fIndex{0};
    while ((fIndex = universeY[i].find('#', fIndex)) != string::npos) {
      nGalaxies++;
      galaxies.push_back(GALAXY(nGalaxies, fIndex, i));
      fIndex++;
    }
  }
  cout << "Universe" << endl;
  for (auto &l : universeX) {
    cout << l << endl;
  }
  cout << "Transposed universe" << endl;
  for (auto &l : universeY) {
    cout << l << endl;
  }
  cout << "Number of Galaxies: " << nGalaxies << endl;
  cout << "Expanded universe number of Lines: " << universeY.size() << endl;

  int allLenghts{};
  int sum{};
  int pairs{};
  //Calc and sum distances
  for (auto &g : galaxies) {
    cout << "Checking galaxy " << g.id << endl;
    for (size_t i = g.id; i < galaxies.size(); i++) {
      if (g.id < galaxies[i].id) {
        cout << "X: " << g.id << " " << g.x << " - " << galaxies[i].id << " "
             << galaxies[i].x;
        cout << " Y: " << g.id << " " << g.y << " - " << galaxies[i].id << " "
             << galaxies[i].y;
        sum = std::abs(g.x - galaxies[i].x) + std::abs(g.y - galaxies[i].y);
        cout << " / Distance between galaxy " << g.id << " and galaxy "
             << galaxies[i].id << " is: " << sum << endl;
        pairs++;
        allLenghts += sum;
      }
    }
  }
  cout << "Number of pairs: " << pairs << endl;
  cout << "Sum of Lenghts: " << allLenghts << endl;

}
