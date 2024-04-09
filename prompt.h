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
  Prompt() : id(-1), question("") {} // default constructor
  Prompt(const string &);            // string constructor
  Prompt(const Prompt &);            // copy constructor

  // get and set functions for `id` and `question`
  int getId();
  string getQuestion();
  void setQuestion(string);
  void setId(int);

  int getResponsesSize();
  // append the paramater Response to `responses`
  void addResponse(Response);

  // get next index from the `inth` element in `responses`
  int getResponseIdx(int inth);

  // clear `responses` vector.
  void clearResponses();

  // prints text of prompt and its responses
  // and randomly select one of the `outputs`.
  friend ostream &operator<<(ostream &os, const Prompt &prompt);

  // reads a prompt from a text input file.
  friend istream &operator>>(istream &is, Prompt &prompt);
};

#endif