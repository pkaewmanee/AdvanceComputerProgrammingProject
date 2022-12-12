#ifndef FX_H
#define FX_H

#include <iostream>
#include <string.h>
using namespace std;
#include "professor.h"
#include <iomanip>

void insert_sat(int[], professor *, int);
void insert_wel(int[], professor *, int);
void insert_qual(int[], professor *, int);
void bsort(int[], int);
void print_bar(int[], int);
int mean(int[], int);
int median(int[], int);
int mode(int[], int);
void print_sort_as(int[], int num);
void print_sort_de(int[], int num);
void print_prof(professor *, int);

void insert_wel(int sort_wel[], professor *l, int num) {
  int i;
  for (i = 0; i < num; i++) {
    sort_wel[i] = l[i].get_wel();
  }
}

void insert_sat(int sort_sat[], professor *l, int num) {
  int i;
  for (i = 0; i < num; i++) {
    sort_sat[i] = l[i].get_sat();
  }
}

void insert_qual(int sort_qual[], professor *l, int num) {
  int i;
  for (i = 0; i < num; i++) {
    sort_qual[i] = l[i].get_qual();
  }
}

void bsort(int sort[], int num) {
  int i, j;
  for (i = 0; i < num - 1; i++) {
    for (j = 0; j < num - i - 1; j++) {
      if (sort[j] > sort[j + 1]) {
        swap(sort[j], sort[j + 1]);
      }
    }
  }
}

void print_bar(int sort[], int num) {
  int i;

  string c0 = "", c1 = "", c2 = "", c3 = "", c4 = "", c5 = "", c6 = "", c7 = "",
         c8 = "", c9 = "", c10 = "", meh = "*";

  for (i = 0; i < num; i++) {
    if (sort[i] == 1) {
      c1 += meh;
    } else if (sort[i] == 2) {
      c2 += meh;
    } else if (sort[i] == 3) {
      c3 += meh;
    } else if (sort[i] == 4) {
      c4 += meh;
    } else if (sort[i] == 5) {
      c5 += meh;
    } else if (sort[i] == 6) {
      c6 += meh;
    } else if (sort[i] == 7) {
      c7 += meh;
    } else if (sort[i] == 8) {
      c8 += meh;
    } else if (sort[i] == 9) {
      c9 += meh;
    } else if (sort[i] == 10) {
      c10 += meh;
    } else if (sort[i] == 0) {
      c0 += meh;
    }
  }

  cout << "0 "
       << "\t" << c0 << endl;
  cout << "1 "
       << "\t" << c1 << endl;
  cout << "2 "
       << "\t" << c2 << endl;
  cout << "3 "
       << "\t" << c3 << endl;
  cout << "4 "
       << "\t" << c4 << endl;
  cout << "5 "
       << "\t" << c5 << endl;
  cout << "6 "
       << "\t" << c6 << endl;
  cout << "7 "
       << "\t" << c7 << endl;
  cout << "8 "
       << "\t" << c8 << endl;
  cout << "9 "
       << "\t" << c9 << endl;
  cout << "10 "
       << "\t" << c10 << endl;
}

int mean(int sort[], int num) {
  int i, mean = 0;
  for (i = 0; i < num; i++) {
    mean += sort[i];
  }

  mean /= num;

  return mean;
}

int median(int sort[], int num) {
  int median, i;
  i = num / 2;
  median = sort[i];
  return median;
}

int mode(int sort[], int num) {
  int counter = 0;
  for (int pass = 0; pass < num - 1; pass++) {
    for (int count = pass + 1; count < num; count++) {
      if (sort[count] == sort[pass]) {
        counter++;
      }
    }
  }
  return counter;
}

void print_sort_as(int sort[], int num) {
  for (int s; s < num; s++) {
    cout << sort[s] << " ";
  }
}

void print_sort_de(int sort[], int num) {
  for (int s = num; num > 0; s--) {
    cout << sort[s] << " ";
  }
}

void print_prof(professor *l, int num) {
  int i = 0;
  cout << "Name: " << l[i].get_name() << endl;
  cout << "Subject: " << l[i].get_sub() << endl;
  cout << "How many students: ";
  cout << setw(30) << "How well they teach: ";
  cout << setw(30) << "Student Satisfaction: ";
  cout << setw(30) << "Quality of the Material: " << endl;
  for (i; i < num; i++) {
    cout << "Student " << i + 1 << setw(30) << l[i].get_wel() << setw(30)
         << l[i].get_sat() << setw(30) << l[i].get_qual() << endl;
  }
  cout << endl;
}

#endif