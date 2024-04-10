/* FILE: response.h
 * PURPOSE: declare Response class
 */
#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <string>
using namespace std;

class Response {
private:
  string responseText; // the response to a prompt
  int index; // the next response's index in an array/vector

public:
  // Default constructor
  Response() : index(0), responseText("") {}

  // Constructor with parameters
  Response(const string &text, int index) : responseText(text), index(index) {}

  // Copy constructor
  Response(const Response &other)
      : responseText(other.responseText), index(other.index) {}

  // Getter and setter for response text
  void setResponseText(const string &text);
  string getResponseText() const;

  // Getter and setter for next prompt index
  void setindex(int idx);
  int getindex() const;

  // Overloaded insertion operator
  friend ostream &operator<<(ostream &os, const Response &response);
};

#endif
