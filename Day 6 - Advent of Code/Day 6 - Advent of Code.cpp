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
  int distanceRecord;

  int minCharge;
  int maxCharge;
  int possibleWins;

  int const validateRace(int chargeTime) {
   return (raceTime - chargeTime) * chargeTime;
  }
  void const findPossibleWins() {
    //Minimum charge
    for (size_t i = 1; i < raceTime; i++) {
     if (validateRace(i) > distanceRecord) {
        minCharge = i;
       break;
     }
    }

    // Max charge
    for (size_t i = raceTime-1; i < raceTime; i--) {
     if (validateRace(i) > distanceRecord) {
       maxCharge = i;
       break;
     }
    }    
    possibleWins = maxCharge - minCharge + 1;
    cout << "There are " << possibleWins << " possible wins" << endl;
  }


  void debugStruct() {
    cout << "Time: " << raceTime << " "
         << "Distance " << distanceRecord << endl;
  }
};

void part1();
bool isNumber(string s);

int main() { part1(); }

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
    totalResult = y.possibleWins* totalResult;
  }

  cout << "Result: " << totalResult << endl;
}