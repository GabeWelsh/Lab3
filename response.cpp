#include "response.h"
#include <iostream>

// Getter and setter for response text
void Response::setResponseText(const string &text) { responseText = text; }
string Response::getResponseText() const { return responseText; }

// Getter and setter for next prompt index
void Response::setindex(int idx) { index = idx; }
int Response::getindex() const { return index; }

// Overloaded insertion operator
ostream &operator<<(ostream &os, const Response &response) {
  os << response.responseText;
  return os;
}