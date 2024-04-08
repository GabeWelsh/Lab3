#include "prompt.h"
#include "response.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

string Prompt::outputs[] = {"What now?",
                            "What should you do?",
                            "Choose wisely...",
                            "Be careful.",
                            "Your fate hangs in the balance.",
                            "How should you proceed?",
                            "And you pick...",
                            "What should you pick?",
                            "You decide to...",
                            "Welp... Now what?"};

Prompt::Prompt(const string &) {}
Prompt::Prompt(const Prompt &) {}

int Prompt::getId() { return id; }
string Prompt::getQuestion() { return question; }
void Prompt::setQuestion(string a) { question = a; }
void Prompt::setId(int a) { id = a; }

// append the paramater Response to `responses`
void Prompt::addResponse(Response a) {
  responses.emplace_back(a); // TODO
  id = responses.size() - 1;
}

// clear `responses` vector.
void Prompt::clearResponses() { 
  responses.clear();
  id = 0;
}

// prints text of prompt and its responses
// and randomly select one of the `outputs`.
ostream &operator<<(ostream &os, const Prompt &prompt) {
  os << prompt.question << endl;

  return os;
}

// reads a prompt from a text input file.
istream &operator>>(istream &is, Prompt &prompt) { return is; }