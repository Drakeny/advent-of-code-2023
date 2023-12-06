// Day 6 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct RACE {
  int raceTime;
  long long distanceRecord;

  long long minCharge;
  long long maxCharge;
  int possibleWins;

  long long const validateRace(long long chargeTime) {
    return (raceTime - chargeTime) * chargeTime;
  }
  void const findPossibleWins() {
    // Minimum charge
    for (size_t i = 1; i < raceTime; i++) {
      if (validateRace(i) > distanceRecord) {
        minCharge = i;
        break;
      }
    }

    // Max charge
    for (size_t i = raceTime - 1; i < raceTime; i--) {
      if (validateRace(i) > distanceRecord) {
        maxCharge = i;
        break;
      }
    }
    possibleWins = maxCharge - minCharge + 1;
  }

  void debugStruct() {
    cout << "Time: " << raceTime << " "
         << "Distance " << distanceRecord << endl;
  }
};

void part1();
void part2();
bool isNumber(string s);

int main() { part2(); }

bool isNumber(string s) {
  for (char c : s) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

void part1() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Read failed";
    return;
  }

  string line{};
  int lineN{0};
  int col{0};

  vector<vector<int>> raceValues{};
  vector<RACE> races{};

  while (getline(inputFile, line)) {
    stringstream ss(line);
    vector<int> v2{};
    while (ss >> line) {
      if (isNumber(line)) {
        if (lineN > 0) {
          races[col].distanceRecord = stoi(line);
          col++;
        } else {
          RACE x{};
          x.raceTime = stoi(line);
          races.push_back(x);
        }
      }
    }
    lineN++;
  }

  int totalResult{1};
  for (auto y : races) {
    y.debugStruct();
    y.findPossibleWins();
    totalResult = y.possibleWins * totalResult;
  }

  cout << "Result: " << totalResult << endl;
}

void part2() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Read failed";
    return;
  }

  string line{};
  int lineN{0};

  RACE raceData{};

  while (getline(inputFile, line)) {
    stringstream ss(line);
    string data{};
    while (ss >> line) {
      if (isNumber(line)) {
        data += line;
      }
    }
    if (lineN > 0) {
      raceData.distanceRecord = stoll(data);
    } else {
    raceData.raceTime = stoi(data);
    }
    lineN++;
  }

  raceData.debugStruct();
  raceData.findPossibleWins();

  cout << "Result: " << raceData.possibleWins << endl;
}