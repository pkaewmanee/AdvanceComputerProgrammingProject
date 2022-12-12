#ifndef NODE_H
#define NODE_H

#include "fx.h"
#include <iomanip>
#include <iostream>
using namespace std;

class Node {
private:
  professor *data;
  int num;
  Node *nextPtr;
  Node *pPtr; // for doubly linked list
public:
  Node(professor *x, int n = 0);
  ~Node();
  Node *get_next();
  Node *get_prev();
  void set_next(Node *t);
  void set_prev(Node *t);
  void print();
  professor *get_data() { return data; }
  int get_num() { return num; }
};

typedef Node *NodePtr; // synonym for Node*

Node::Node(professor *x, int n) {
  pPtr = NULL;
  data = x;
  num = n;
  nextPtr = NULL;
}

Node::~Node() { cout << ""; }

NodePtr Node::get_next() { return nextPtr; }

NodePtr Node::get_prev() { return pPtr; }

void Node::set_prev(NodePtr t) { pPtr = t; }

void Node::set_next(NodePtr t) { nextPtr = t; }

#endif