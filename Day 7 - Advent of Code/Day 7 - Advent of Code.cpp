// Day 7 - Advent of Code.cpp : This file contains the 'main' function. Program
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

enum class HANDTYPE {
  HIGH,
  ONE_PAIR,
  TWO_PAIR,
  THREE_OF_KIND,
  FULLHOUSE,
  FOUR_OF_KIND,
  FIVE_OF_KIND,
};

struct HAND {
  string cards;
  int multiplier;
  HANDTYPE type;
  int highest;
};

std::unordered_map<string, int> labels{
    {"A", 14}, {"K", 13}, {"Q", 12}, {"J", 11}, {"T", 10}, {"9", 9}, {"8", 8},
    {"7", 7},  {"6", 6},  {"5", 5},  {"4", 4},  {"3", 3},  {"2", 2},
};

bool compareCards(string &card1, string &card2);
void part1();
bool sortHands(const HAND &a, const HAND &b);
HANDTYPE rankHand(const string &cards);

int main() { part1(); }

void part1() {
  std::ifstream inputFile("inputTest.txt");
  if (!inputFile) {
    std::cerr << "Read failed";
    return;
  }

  std::vector<HAND> allHands{};

  string line{};
  while (std::getline(inputFile, line)) {
    std::stringstream ss(line);
    HAND x{};
    size_t delimiter = line.find_first_of(" ");
    x.cards = line.substr(0, delimiter);
    x.multiplier = stoi(line.substr(delimiter));

    // Sort line?
    // Determine HAND Type
    x.type = rankHand(x.cards);

    // Determine highest

    allHands.push_back(x);
  }
  for (auto &x : allHands) {
    // cout << x.cards << " " << x.multiplier << endl;
  }

  // std::sort(allHands.begin(), allHands.end());
}

bool compareCards(const string &card1, const string &card2) {
  return labels[card1] < labels[card2];
}

bool sortHands(const HAND &a, const HAND &b) { return a.cards < b.cards; }

HANDTYPE rankHand(const string &cards) {
  std::vector<int> sortedCards{};
  string s{};
  HANDTYPE type{};
  for (auto c : cards) {
    s = c;
    sortedCards.push_back(labels[s]);
  }

  cout << std::count(sortedCards.begin(), sortedCards.end(), sortedCards[0]) << 
          endl;

  return HANDTYPE::FULLHOUSE;
}