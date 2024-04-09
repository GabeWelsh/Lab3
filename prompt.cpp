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
  id = -1;
}

// get next index from the `inth` element in `responses`
int Prompt::getResponseIdx(int inth) {
  // return responses[inth];
  return responses[inth].getindex();
}

int Prompt::getResponsesSize() { return responses.size(); }

// prints text of prompt and its responses
// and randomly select one of the `outputs`.
ostream &operator<<(ostream &os, const Prompt &prompt) {
  // set the stage :)
  os << prompt.question << endl;

  // print responses vec
  int i = 0;
  for (vector<Response>::const_iterator lol = prompt.responses.cbegin();
       lol != prompt.responses.cend(); lol++) {
    os << "(" << i << ") " << lol->getResponseText() << endl;
    i++;
  }

  // print random thing
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 9);
  int index = dist6(rng);
  os << prompt.outputs[index] << " ";

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