#include <iostream>
using namespace std;
#include "professor.h"
typedef professor *professor_data;

class Professor {
private:
  professor_data data[];

public:
  Professor(professor_data[], int);
  ~Professor();
  professor *get_data();
};

Professor::Professor(professor_data p_data[], int num) {
  for (int i = 0; i < num; i++) {
    data[i] = p_data[i];
  }
}