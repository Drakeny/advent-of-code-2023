// Day 4 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct CARDGAME {
  int id;
  vector<int> numbers;
  vector<int> winningNumbers;
  int numbersWon;
} card_game;

int power(int);
void part1();
void part2();
CARDGAME buildCardGame(int id, string line);


int main() { part2(); }

void part1() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Read failed";
    return;
  }

  int totalPoints{};
  string line{};
  while (inputFile >> line) {
    getline(inputFile, line);
    vector<int> numbers{};
    vector<int> winningNumbers{};
    int numbersWon{};

    int strIndex{};
    bool switchToWinningNumbers{false};
    string extract{};

    size_t found = line.find(":");
    if (found != string::npos) {
      line.erase(0, found + 1);
    }

    stringstream ss(line);

    while (ss >> extract) {
      if (extract == "|") {
        switchToWinningNumbers = true;
        continue;
      }
      if (!switchToWinningNumbers) {
        numbers.push_back(stoi(extract));
      } else {
        winningNumbers.push_back(stoi(extract));
      }
    }

    cout << "Your numbers are:" << endl;
    for (auto x : numbers) {
      cout << "{" << x << "}";
    }
    cout << endl;
    cout << "The winning numbers are:" << endl;
    for (auto x : winningNumbers) {
      cout << "{" << x << "}";
    }
    cout << endl;

    for (auto myNumber : numbers) {
      if (std::find(winningNumbers.begin(), winningNumbers.end(), myNumber) !=
          winningNumbers.end()) {
        cout << "Winner number matched! It is: " << myNumber << endl;
        numbersWon++;
      }
    }
    cout << "-------------------------------------------" << endl;
    totalPoints += power(numbersWon);
  }

  cout << "Total points is: " << totalPoints << endl;
}

void part2() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Read failed";
    return;
  }

  

  string line{};
  int id{1};
  vector<string> cards{};
  vector<CARDGAME> allCardGames{};
  allCardGames.push_back(buildCardGame(0, ""));

  while (inputFile >> line) {
    getline(inputFile, line);
    allCardGames.push_back(buildCardGame(id, line));
    id++;
  }

    int initialMax = allCardGames.size();
  for (size_t x = 0; x < allCardGames.size(); x++) {
    //if (x > initialMax) cout << "NOW DEALING WITH THE GENERATED COPIES" << endl;
    //cout << "Current Index: " << x << endl;
    //cout << "Dealing with game: " << allCardGames[x].id << endl;
    for (size_t i = 1; i <= allCardGames[x].numbersWon; i++) {
      //cout << "Adding a copy of game: " << allCardGames[allCardGames[x].id + i].id << endl;
      allCardGames.push_back(allCardGames[allCardGames[x].id + i]);
    }
  }

  int test{0};
  for (auto x : allCardGames) {
    if (x.id == 4) test++;
  }
  //cout << "instances of test: " << test << endl;


    cout << allCardGames.size()-1;


}

CARDGAME buildCardGame(int id, string card) {
  vector<int> numbers{};
  vector<int> winningNumbers{};
  int numbersWon{};

  int strIndex{};
  bool switchToWinningNumbers{false};
  string extract{};

  size_t found = card.find(":");
  if (found != string::npos) {
    card.erase(0, found + 1);
  }

  stringstream ss(card);

  while (ss >> extract) {
    if (extract == "|") {
      switchToWinningNumbers = true;
      continue;
    }
    if (!switchToWinningNumbers) {
      numbers.push_back(stoi(extract));
    } else {
      winningNumbers.push_back(stoi(extract));
    }
  }

  /*cout << "Your numbers are:" << endl;
  for (auto x : numbers) {
    cout << "{" << x << "}";
  }
  cout << endl;
  cout << "The winning numbers are:" << endl;
  for (auto x : winningNumbers) {
    cout << "{" << x << "}";
  }
  cout << endl;*/
  for (auto myNumber : numbers) {
    if (std::find(winningNumbers.begin(), winningNumbers.end(), myNumber) !=
        winningNumbers.end()) {
      //cout << "Winner number matched! It is: " << myNumber << endl;
      numbersWon++;
    }
  }
  cout << "-------------------------------------------" << endl;
  CARDGAME cardgame;
  cardgame.id = id;
  cardgame.numbers = numbers;
  cardgame.winningNumbers = winningNumbers;
  cardgame.numbersWon = numbersWon;

  return cardgame;
}

int power(int numDoublings) {
  int result = pow(2, numDoublings - 1);

  cout << "After doubling " << numDoublings
       << " times, the result is: " << result << endl;

  return result;
}