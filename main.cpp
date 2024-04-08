#include "prompt.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  vector<Prompt> cool;
  ifstream inputFile("GameInput.csv");
  if (!inputFile.is_open()) {
    cerr << "Error: Unable to open the file." << endl;
    return 1; // Exit with error
  }
  string line;
  while (getline(inputFile, line)) {
    Prompt prompt;
    istringstream iss(line);
    iss >> prompt;
    cool.push_back(prompt);
  }

  // Close the file
  inputFile.close();
  return 0;
}