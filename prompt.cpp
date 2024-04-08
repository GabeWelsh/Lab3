#include "prompt.h"
#include "response.h"
#include <iostream>
#include <random>
#include <vector>

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

// constructor with parameter string
Prompt::Prompt(const string &s) {}

// copy constructor
Prompt::Prompt(const Prompt &p) {
  question = p.question;
  id = p.id;
  responses = p.responses;
}
// get and set functions for `id` and `question`
int Prompt::getId() { return id; }
string Prompt::getQuestion() { return question; }
void Prompt::setQuestion(string a) { question = a; }
void Prompt::setId(int a) { id = a; }

// append the paramater Response to `responses`
void Prompt::addResponse(Response a) {
  responses.emplace_back(a);
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

  // print responses vec
  for (vector<Response>::const_iterator lol = prompt.responses.cbegin();
       lol != prompt.responses.cend(); lol++) {
    os << lol->getResponseText();
  }

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, prompt.responses.size() - 1);
  int index = dis(gen);

  os << prompt.outputs[index] << endl;

  return os;
}

// reads a prompt from a text input file.
istream &operator>>(istream &is, Prompt &prompt) {
  string temp;
  // get id
  getline(is, temp, '|');
  prompt.id = stoi(temp);
  // get prompt text
  getline(is, temp, '|');
  prompt.setQuestion(temp);
  // get response then index 🔁
  while (getline(is, temp, '|') && temp != "\r") {
    Response respond;

    respond.setResponseText(temp);
    getline(is, temp, '|');
    respond.setindex(stoi(temp));

    prompt.addResponse(respond);
  }

  return is;
}