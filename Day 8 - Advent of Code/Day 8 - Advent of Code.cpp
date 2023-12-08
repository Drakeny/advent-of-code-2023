// Day 8 - Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string, std::cout, std::endl;

struct NODE {
  string name{};
  string left{};
  string right{};
  int loops{0};
};

void part1();
void part2();

int main() { part2(); }

void part1() {
  std::ifstream inputFile("input.txt");
  if (!inputFile) {
    std::cerr << "Read failed";
    return;
  }

  string line{};
  string instructions{};
  std::unordered_map<string, NODE> nodes{};
  bool firstNode{true};
  bool firstLine{true};
  string currentNode{"AAA"};

  while (std::getline(inputFile, line)) {
    if (firstLine) {
      instructions = line;
      firstLine = false;
      cout << "Instructions are: " << instructions << " with a lenght of "
           << instructions.length() << endl;
      continue;
    }

    if (line.length() == 0) continue;

    NODE node{};
    node.name = line.substr(0, 3);
    size_t delim = line.find_first_of(",");
    node.left = line.substr(delim - 3, 3);
    node.right = line.substr(delim + 2, 3);

    nodes.insert({node.name, node});
    firstNode = false;
  }

  int steps{0};
  for (size_t i = 0; i < instructions.length(); i++) {
    cout << "Instruction is: " << instructions[i] << endl;
    if (instructions[i] == 'L') {
      cout << "Moving left: " << currentNode << " -> "
           << nodes[currentNode].left << endl;
      currentNode = nodes[currentNode].left;
    } else {
      cout << "Moving right: " << currentNode << " -> "
           << nodes[currentNode].right << endl;
      currentNode = nodes[currentNode].right;
    }

    steps++;

    if (i == instructions.length() - 1 && currentNode != "ZZZ") {
      i = -1;
    }
  }

  cout << "Number of steps: " << steps << endl;
}

void part2() {
  std::ifstream inputFile("input.txt");
  if (!inputFile) {
    std::cerr << "Read failed";
    return;
  }

  string line{};
  string instructions{};
  std::unordered_map<string, NODE> nodes{};
  std::unordered_map<string, int> ghostNodeStart{};
  bool firstLine{true};
  bool firstA{true};
  string currentNode{"AAA"};

  while (std::getline(inputFile, line)) {
    if (firstLine) {
      instructions = line;
      cout << "Instructions are: " << instructions << " with a lenght of "
           << instructions.length() << endl;
      firstLine = false;
      continue;
    }

    if (line.length() == 0) continue;

    NODE node{};
    node.name = line.substr(0, 3);
    size_t delim = line.find_first_of(",");
    node.left = line.substr(delim - 3, 3);
    node.right = line.substr(delim + 2, 3);

    nodes.insert({node.name, node});
    if (node.name[2] == 'A') {
      ghostNodeStart.insert({node.name, 0});
    }
  }

  int steps{0};
  std::vector<long long> lcmSteps{};
  for (auto &n : ghostNodeStart) {
    currentNode = n.first;
    steps = 0;
    cout << "Node " << currentNode;
    int loops{0};
    for (size_t i = 0; i < instructions.length(); i++) {
      if (instructions[i] == 'L') {
        currentNode = nodes[currentNode].left;
      } else {
        currentNode = nodes[currentNode].right;
      }
      steps++;
      if (i == instructions.length() - 1 && currentNode[2] != 'Z') {
        i = -1;
        loops++;
      }
    }
    n.second = steps;
    lcmSteps.push_back(steps);
    cout << " takes " << loops << " loops "
         << "and " << steps << " steps to reach Z " << endl;
  }

  //boost has LCM but i can't get it to work so i used a online calc the answer.
  //12833235391111

  // Below is raw brute force, it seems it'll take 100 years to finish

  // currentNode = n.first;
  // for (size_t i = 0; i < instructions.length(); i++) {
  //  if (instructions[i] == 'L') {
  //    for (auto &g : ghostNodeStart) {
  //      /*cout << "Moving left: " << g.second << " -> " <<
  //      nodes[g.second].left
  //           << endl;*/
  //      g.second = nodes[g.second].left;
  //    }
  //  } else {
  //    for (auto &g : ghostNodeStart) {
  //      /*cout << "Moving right: " << g.second << " -> " <<
  //         nodes[g.second].right
  //           << endl;*/
  //      g.second = nodes[g.second].right;
  //    }
  //  }

  //  steps++;

  //  if (i == instructions.length() - 1) {
  //    int ghostNodesAtEnd{0};
  //    for (auto &g : ghostNodeStart) {
  //      if (g.second[2] == 'Z') ghostNodesAtEnd++;
  //    }
  //    if (ghostNodesAtEnd != ghostNodeStart.size()) {
  //      i = -1;
  //    }
  //  }
  //}

  cout << "Number of steps: " << steps << endl;
}