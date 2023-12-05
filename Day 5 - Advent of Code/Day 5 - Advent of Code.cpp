// Day 5 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <omp.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct MAPPEDCOORDINATES {
  long long destination;
  long long source;
  long long range;

  void debugStruct() {
    cout << "{" << destination << "}"
         << "{" << source << "}"
         << "{" << range << "}" << endl;
  }
} coordinates;

void part1();

int main() { part1(); }

void part1() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Read failed";
    return;
  }

  vector<long long> seeds{};
  vector<MAPPEDCOORDINATES> seedToSoil{};
  vector<MAPPEDCOORDINATES> soulToFetilizer{};
  vector<MAPPEDCOORDINATES> fertilizerToWater{};
  vector<MAPPEDCOORDINATES> waterToLight{};
  vector<MAPPEDCOORDINATES> lightToTemperature{};
  vector<MAPPEDCOORDINATES> temperatureToHumidity{};
  vector<MAPPEDCOORDINATES> humidityToLocation{};

  vector<vector<MAPPEDCOORDINATES>> mappedCoordinates{
      seedToSoil,        soulToFetilizer,    fertilizerToWater,
      waterToLight,      lightToTemperature, temperatureToHumidity,
      humidityToLocation};

  string line{};

  getline(inputFile, line);
  line.erase(0, line.find_first_of(':') + 1);
  stringstream ss(line);
  while (ss >> line) {
    seeds.push_back(stoll(line));
    cout << line << endl;
  }

  int mapIndex{};
  while (getline(inputFile, line)) {
    if (line.find_first_of(':') != string::npos) {
      mapIndex++;
      continue;
    };

    if (line == "") {
      continue;
    }

    stringstream ss(line);
    vector<long long> values{};
    MAPPEDCOORDINATES coords;

    switch (mapIndex) {
      case 1:
        while (ss >> line) {
          values.push_back(stoll(line));
        }
        coords.destination = values[0];
        coords.source = values[1];
        coords.range = values[2];
        seedToSoil.push_back(coords);

        break;
      case 2:
        while (ss >> line) {
          values.push_back(stoll(line));
        }
        coords.destination = values[0];
        coords.source = values[1];
        coords.range = values[2];
        soulToFetilizer.push_back(coords);

        break;
      case 3:
        while (ss >> line) {
          values.push_back(stoll(line));
        }
        coords.destination = values[0];
        coords.source = values[1];
        coords.range = values[2];
        fertilizerToWater.push_back(coords);

        break;
      case 4:
        while (ss >> line) {
          values.push_back(stoll(line));
        }
        coords.destination = values[0];
        coords.source = values[1];
        coords.range = values[2];
        waterToLight.push_back(coords);

        break;
      case 5:
        while (ss >> line) {
          values.push_back(stoll(line));
        }
        coords.destination = values[0];
        coords.source = values[1];
        coords.range = values[2];
        lightToTemperature.push_back(coords);

        break;
      case 6:
        while (ss >> line) {
          values.push_back(stoll(line));
        }
        coords.destination = values[0];
        coords.source = values[1];
        coords.range = values[2];
        temperatureToHumidity.push_back(coords);

        break;
      case 7:
        while (ss >> line) {
          values.push_back(stoll(line));
        }
        coords.destination = values[0];
        coords.source = values[1];
        coords.range = values[2];
        humidityToLocation.push_back(coords);

        break;
    }
  }

  long long finalCoord = LLONG_MAX;

#pragma omp parallel for num_threads(8)
  for (size_t i = 0; i < seeds.size(); i += 2) {
    for (long long x = 0; x < seeds[i + 1]; x++) {
      long long current{seeds[i] + x};
      for (auto coord : seedToSoil) {
        if ((current >= coord.source) &&
            (current <= coord.source + coord.range - 1)) {
          current = current + (coord.destination - coord.source);

          break;
        }
      }
      for (auto coord : soulToFetilizer) {
        if ((current >= coord.source) &&
            (current <= coord.source + coord.range - 1)) {
          current = current + (coord.destination - coord.source);
          break;
        }
      }
      for (auto coord : fertilizerToWater) {
        if ((current >= coord.source) &&
            (current <= coord.source + coord.range - 1)) {
          current = current + (coord.destination - coord.source);
          break;
        }
      }
      for (auto coord : waterToLight) {
        if ((current >= coord.source) &&
            (current <= coord.source + coord.range - 1)) {
          current = current + (coord.destination - coord.source);
          break;
        }
      }
      for (auto coord : lightToTemperature) {
        if ((current >= coord.source) &&
            (current <= coord.source + coord.range - 1)) {
          current = current + (coord.destination - coord.source);
          break;
        }
      }
      for (auto coord : temperatureToHumidity) {
        if ((current >= coord.source) &&
            (current <= coord.source + coord.range - 1)) {
          current = current + (coord.destination - coord.source);
          break;
        }
      }
      for (auto coord : humidityToLocation) {
        if ((current >= coord.source) &&
            (current <= coord.source + coord.range - 1)) {
          current = current + (coord.destination - coord.source);
          break;
        }
      }
      if (current < finalCoord) {
        finalCoord = current;
        cout << "Pushing back: " << current << endl;
      }
    }
  }

  cout << "Second Finish" << endl;
  cout << finalCoord << endl;
}