// Day 3 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    std::cerr << "Well shit";
    return 1;
  }

  int numberSize{};

  int partNumberSum{};

  vector<string> engine{};
  string line{};
  while (inputFile >> line) {
    engine.push_back(line);
  }
  for (size_t i = 0; i < engine.size(); i++) {
    string const symbols = "@#$%&+-=/*";
    size_t symbolPos{0};
    while ((symbolPos = engine[i].find_first_of(symbols, symbolPos)) !=
           string::npos) {
      cout << "Found symbol> " << engine[i][symbolPos] << "\n";
      // Check same line backwards
      if (isdigit(engine[i][symbolPos - 1])) {
        string foundValue{engine[i][symbolPos - 1]};
        size_t currentPos = symbolPos - 1;

        while (isdigit(engine[i][currentPos - 1])) {
          foundValue = engine[i][currentPos - 1] + foundValue;
          currentPos--;
          if (currentPos == 0) {
            break;
          }
        }

        cout << "Left - On line: " << i << "\n";
        cout << foundValue << "\n";
        partNumberSum += std::stoi(foundValue);
      }

      // Check same line Forward
      if (isdigit(engine[i][symbolPos + 1])) {
        string foundValue{engine[i][symbolPos + 1]};
        size_t currentPos = symbolPos + 1;
        while (isdigit(engine[i][currentPos + 1])) {
          foundValue = foundValue + engine[i][currentPos + 1];
          currentPos++;
        }
        cout << "Right - On line: " << i << "\n";
        cout << foundValue << "\n";
        partNumberSum += std::stoi(foundValue);
      }

      // Check line above
      if (i >= 1) {
        bool skip{false};
        // Middle
        // check edge case
        if (isdigit(engine[i - 1][symbolPos - 1]) &&
            isdigit(engine[i - 1][symbolPos]) &&
            isdigit(engine[i - 1][symbolPos + 1])) {
          string foundValue{};
          foundValue = foundValue + engine[i - 1][symbolPos - 1] +
                       engine[i - 1][symbolPos] + engine[i - 1][symbolPos + 1];
          partNumberSum += std::stoi(foundValue);
          cout << "Hit Edge case UP! value is: " << foundValue << "\n";
          skip = true;
        }

        // middle up forward
        if (isdigit(engine[i - 1][symbolPos]) &&
            isdigit(engine[i - 1][symbolPos + 1]) && !skip) {
          string foundValue{engine[i - 1][symbolPos]};
          size_t currentPos = symbolPos;
          while (isdigit(engine[i - 1][currentPos + 1])) {
            foundValue = foundValue + engine[i - 1][currentPos + 1];
            currentPos++;
          }
          cout << "Up middle right - On line: " << i << "\n";
          cout << foundValue << "\n";
          partNumberSum += std::stoi(foundValue);
        }

        // up forward
        if (isdigit(engine[i - 1][symbolPos + 1]) &&
            !isdigit(engine[i - 1][symbolPos]) && !skip) {
          string foundValue{engine[i - 1][symbolPos + 1]};
          size_t currentPos = symbolPos + 1;
          while (isdigit(engine[i - 1][currentPos + 1])) {
            foundValue = foundValue + engine[i - 1][currentPos + 1];
            currentPos++;
          }
          cout << "Up right - On line: " << i << "\n";
          cout << foundValue << "\n";
          partNumberSum += std::stoi(foundValue);
        }

        // middle up backwards
        if (isdigit(engine[i - 1][symbolPos]) &&
            isdigit(engine[i - 1][symbolPos - 1]) && !skip) {
          string foundValue{engine[i - 1][symbolPos]};
          size_t currentPos = symbolPos;
          while (isdigit(engine[i - 1][currentPos - 1])) {
            foundValue = engine[i - 1][currentPos - 1] + foundValue;
            currentPos--;
            if (currentPos == 0) {
              break;
            }
          }
          cout << "Up middle left - On line: " << i << "\n";
          cout << foundValue << "\n";
          partNumberSum += std::stoi(foundValue);
        }

        // up backwards
        if (isdigit(engine[i - 1][symbolPos - 1]) &&
            !isdigit(engine[i - 1][symbolPos]) && !skip) {
          string foundValue{engine[i - 1][symbolPos - 1]};
          size_t currentPos = symbolPos - 1;
          while (isdigit(engine[i - 1][currentPos - 1])) {
            foundValue = engine[i - 1][currentPos - 1] + foundValue;
            currentPos--;
            if (currentPos == 0) {
              break;
            }
          }
          cout << "Up left - On line: " << i << "\n";
          cout << foundValue << "\n";
          partNumberSum += std::stoi(foundValue);
        }
      }

      // Check line Below
      bool skip{false};
      // Middle
      // check edge case
      if (isdigit(engine[i + 1][symbolPos - 1]) &&
          isdigit(engine[i + 1][symbolPos]) &&
          isdigit(engine[i + 1][symbolPos + 1])) {
        string foundValue{};
        foundValue = foundValue + engine[i + 1][symbolPos - 1] +
                     engine[i + 1][symbolPos] + engine[i + 1][symbolPos + 1];
        partNumberSum += std::stoi(foundValue);
        cout << "Hit Edge case DOWN! value is: " << foundValue << "\n";
        skip = true;
      }

      // down middle forward
      if (isdigit(engine[i + 1][symbolPos]) &&
          isdigit(engine[i + 1][symbolPos + 1]) && !skip) {
        string foundValue{engine[i + 1][symbolPos]};
        size_t currentPos = symbolPos;
        while (isdigit(engine[i + 1][currentPos + 1])) {
          foundValue = foundValue + engine[i + 1][currentPos + 1];
          currentPos++;
        }
        cout << "Down middle right - On line: " << i << "\n";
        cout << foundValue << "\n";
        partNumberSum += std::stoi(foundValue);
      }

      // down forward
      if (!isdigit(engine[i + 1][symbolPos]) &&
          isdigit(engine[i + 1][symbolPos + 1]) && !skip) {
        string foundValue{engine[i + 1][symbolPos + 1]};
        size_t currentPos = symbolPos + 1;
        while (isdigit(engine[i + 1][currentPos + 1])) {
          foundValue = foundValue + engine[i + 1][currentPos + 1];
          currentPos++;
        }
        cout << "Down right - On line: " << i << "\n";
        cout << foundValue << "\n";
        partNumberSum += std::stoi(foundValue);
      }

      // down middle backwards
      if (isdigit(engine[i + 1][symbolPos]) &&
          isdigit(engine[i + 1][symbolPos - 1]) && !skip) {
        string foundValue{engine[i + 1][symbolPos]};
        size_t currentPos = symbolPos;
        while (isdigit(engine[i + 1][currentPos - 1])) {
          foundValue = engine[i + 1][currentPos - 1] + foundValue;
          currentPos--;
          if (currentPos == 0) {
            break;
          }
        }
        cout << "Down middle right - On line: " << i << "\n";
        cout << foundValue << "\n";
        partNumberSum += std::stoi(foundValue);
      }

      // down backwards
      if (!isdigit(engine[i + 1][symbolPos]) &&
          isdigit(engine[i + 1][symbolPos - 1]) && !skip) {
        string foundValue{engine[i + 1][symbolPos - 1]};
        size_t currentPos = symbolPos - 1;
        while (isdigit(engine[i + 1][currentPos - 1])) {
          foundValue = engine[i + 1][currentPos - 1] + foundValue;
          currentPos--;
          if (currentPos == 0) {
            break;
          }
        }
        cout << "Down right - On line: " << i << "\n";
        cout << foundValue << "\n";
        partNumberSum += std::stoi(foundValue);
      }

      symbolPos++;
    }
  }
  cout << "Total: " << partNumberSum << "\n";
}
