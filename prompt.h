#ifndef PROMPT_H
#define PROMPT_H

#include "response.h"
#include <iostream>
#include <vector>

using namespace std;
class Prompt {
private:
  vector<Response> responses;
  static string outputs[];
  string question;
  int id;

public:
  Prompt() : id(0) {}
  Prompt(const string &);
  Prompt(const Prompt &);
  int getId();
  string getQuestion();
  void setQuestion(string);
  void setId(int);

  // append the paramater Response to `responses`
  void addResponse(Response);

  // clear `responses` vector.
  void clearResponses();

  // prints text of prompt and its responses
  // and randomly select one of the `outputs`.
  friend ostream &operator<<(ostream &os, const Prompt &prompt);
  
  // reads a prompt from a text input file.
  friend istream &operator>>(istream &is, Prompt &prompt);
};

#endif