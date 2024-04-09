#include "prompt.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  // 1: initialize vector by reading through "GameInput.csv"
  vector<Prompt> cool;
  ifstream inputFile("GameInput.csv");
  if (!inputFile.is_open()) {
    cerr << "Error: Unable to open the file." << endl;
    return 1;
  }
  string line;
  int i = 0;
  while (getline(inputFile, line)) {
    Prompt prompt;
    istringstream iss(line);
    iss >> prompt;
    cool.push_back(prompt);
  }
  inputFile.close();

  // 2: Game Loop :D
  int index = 0;
  do {
    cout << cool[index];
    string tempS;
    int tempI; // bigger than `cool` :)
    cin >> tempS;
    // verify input
    try {
      tempI = stoi(tempS);
    } catch (const exception &e) {
      cout << "---- Try again with valid input bucko ----" << endl;
      continue;
    }
    if (tempI < 0) {
      break;
    }
    if (tempI > cool[index].getResponsesSize() - 1) {
      cout << "---- Try again with valid input bucko ----" << endl;
      continue;
    }

    index = cool[index].getResponseIdx(tempI);

  } while (index >= 0);

  cout << "Sayonara!" << endl;

  return 0;
}