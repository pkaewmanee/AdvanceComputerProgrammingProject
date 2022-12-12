#include "Node.h"
#include "fx.h"
#include <iostream>
using namespace std;

class Queue {
  NodePtr headPtr, tailPtr;
  professor *data;
  int num;
  int size;

public:
  void enqueue(professor *x, int n = 0);
  professor *dequeue();
  professor *return_prof();
  int get_num() { return num; }
  int get_size() { return size; }
  int isEmpty();
  Queue();
  ~Queue(); // dequeue all
};

void Queue::enqueue(professor *x, int n) {
  NodePtr new_node = new Node(x); // okie

  if (new_node) {
    if (headPtr == NULL)
      headPtr = new_node;
    else
      tailPtr->set_next(new_node);

    tailPtr = new_node;

    ++size;
  }
}

professor *Queue::dequeue() {
  NodePtr temp;
  temp = headPtr; // 1. Save the node to be deleted
  if (temp != NULL) {
    professor *data = temp->get_data(); // 1.5 take the value out to value
    headPtr = headPtr->get_next();      // 2. Move (Head)

    if (size == 1 || headPtr == NULL)
      tailPtr = NULL;

    delete temp;
    --size;
    return data;
  }
  return NULL;
}

professor *Queue::return_prof() {
  NodePtr temp;
  temp = headPtr; // 1. Save the node to be deleted
  if (temp != NULL) {
    professor *data = temp->get_data(); // 1.5 take the value out to value
    headPtr = headPtr->get_next();      // 2. Move (Head)

    if (size == 1 || headPtr == NULL)
      tailPtr = NULL;

    return data;
  }
  return NULL;
}

Queue::Queue() {
  headPtr = NULL;
  tailPtr = NULL;
  size = 0;
}

Queue::~Queue() {
  professor *deq;
  int n = size;
  for (int i = 0; i < n; i++) {
    deq = dequeue();
  }
}

int Queue::isEmpty() {
  if (headPtr == NULL) {
    return 1;
  } else {
    return 0;
  }
}