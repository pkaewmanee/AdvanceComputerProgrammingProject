#include "Node.h"
#include <iostream>
using namespace std;

class DCLL {
  NodePtr hol; // head of linked list
  int size;

public:
  DCLL();

  NodePtr deletes(string name);
  NodePtr find(string name);
  int get_size() { return size; }
  int isEmpty();
  void insert(professor *data, int num);
  // void DCLL::print_prof(professor_ds, int);
  ~DCLL();
};

DCLL::DCLL() {
  hol = NULL;
  size = 0;
}

DCLL::~DCLL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}

// insert a new value into the list in sorted order
void DCLL::insert(professor *data, int num) {
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = new Node(data, num); // create node & put value in

  if (newPtr != NULL) { // is space available

    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
    }                                      // end while

    // insert new node at beginning of list
    if (previousPtr == NULL) {
      newPtr->set_next(hol);
      hol = newPtr;

      // 1.how about the first node insertion?????

    }      // end if
    else { // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      newPtr->set_next(currentPtr);
      // 2.finish set_prev by yourselves
      if (currentPtr != NULL) {
        currentPtr->set_prev(newPtr);
      }
      newPtr->set_prev(previousPtr);

      // 3.how about the last node insertion?????

    } // end else
    ++size;
  } // end if
  else {
    cout << data << " Not inserted. No memory available." << endl;
  } // end else

} // end function insert

// delete a list element
NodePtr DCLL::deletes(string name) {
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list
  NodePtr tempPtr;     // temporary node pointer

  // delete first node
  if (name == hol->get_data()->get_name()) {
    tempPtr = hol;         // hold onto node being removed
    hol = hol->get_next(); // de-thread the node
    size--;
    if (hol)
      hol->set_prev(NULL);
    return tempPtr;
    delete tempPtr; // free the de-threaded node
  }                 // end if
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    // loop to find the correct location in the list
    while (currentPtr != NULL && currentPtr->get_data()->get_name() != name) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
    }                                      // end while

    // delete node makeat currentPtr
    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->set_next(currentPtr->get_next());
      currentPtr = currentPtr->get_next();

      if (currentPtr != NULL) {
        currentPtr->set_prev(previousPtr);
      }

      return tempPtr;

      delete tempPtr;
      size--;
    } // end if
  }   // end else

  return NULL;
} // end function delete

NodePtr DCLL::find(string name) {
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list
  NodePtr tempPtr;     // temporary node pointer

  // delete first node
  if (name == hol->get_data()->get_name()) {
    tempPtr = hol; // hold onto node being removed
    size--;
    return tempPtr;
  } // end if
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    // loop to find the correct location in the list
    while (currentPtr != NULL && currentPtr->get_data()->get_name() != name) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
    }                                      // end while

    // delete node makeat currentPtr
    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->set_next(currentPtr->get_next());
      currentPtr = currentPtr->get_next();

      if (currentPtr != NULL) {
        currentPtr->set_prev(previousPtr);
      }

      return tempPtr;
      size--;
    } // end if
  }   // end else

  return NULL;
} // end function delete

// return 1 if the list is empty, 0 otherwise

int DCLL::isEmpty() {
  if (hol == NULL) {
    return 1;
  } else {
    return 0;
  }
} // end function isEmpty