#include <iostream>
#include <string.h>
using namespace std;
#include "professor.h"

void instructions(void);
void instructions2(void);
void instructions3(void);
void menu();
void insert_sat(int[], professor *, int);
void insert_wel(int[], professor *, int);
void insert_qual(int[], professor *, int);
void bsort(int[], int);
void print_bar(int[], int);
int mean(int[], int);
int median(int[], int);
int mode(int[], int);

void menu() {
  professor *l;
  int num = 0; // insert the amount of dataset you need
  string name, sub;
  int i, j, temp, pass, sort_wel[num], sort_sat[num], sort_qual[num];

  while (num <= 2) {
    cout << "How many set of data you want: ";
    cin >> num;
  }

  cin.ignore();
  cout << "Enter the professor's name: ";
  getline(cin, name);

  cout << "Enter the professor's subject: ";
  getline(cin, sub);

  l = new professor[num];

  for (i = 0; i < num; i++) {
    int wel = -1, sat = -1, qual = -1;
    cout << endl;
    cout << "Please rate the professor from 0 - 10" << endl;
    cout << "Dataset " << i + 1 << ": " << endl;
    l[i].set_name(name);
    l[i].set_sub(sub);

    while (wel > 11 || wel <= -1) {
      cout << "How well they teach: ";
      cin >> wel;
    }
    l[i].set_wel(wel);

    while (sat > 11 || sat <= -1) {
      cout << "Student Satisfaction: ";
      cin >> sat;
    }
    l[i].set_sat(sat);

    while (qual >= 11 || qual <= -1) {
      cout << "Quality of the Material: ";
      cin >> qual;
    }
    l[i].set_qual(qual);

    cout << endl;
  }

  insert_sat(sort_sat, l, num);
  insert_wel(sort_wel, l, num);
  insert_qual(sort_qual, l, num);

  bsort(sort_wel, num);

  bsort(sort_sat, num);

  bsort(sort_qual, num);

  unsigned int choice3;

  instructions(); // display the menu2
  cout << "? ";
  cin >> choice3;

  int mean1, median1, mode1;

  while (choice3 != 4) {
    switch (choice3) {
    case 1:

      cout << "Professor " << l[0].get_name() << endl;
      cout << "Subject: " << l[0].get_sub() << endl << endl;

      print_bar(sort_wel, num);

      mean1 = mean(sort_wel, num);
      median1 = median(sort_wel, num);
      mode1 = mode(sort_wel, num);

      cout << "Mean of How well they teach: " << mean1 << endl;

      cout << "Median of How well they teach: " << median1 << endl;

      cout << "Mode of How well they teach: " << mode1 << endl;

      break;

    case 2:

      cout << "Professor " << l[0].get_name() << endl;
      cout << "Subject: " << l[0].get_sub() << endl << endl;

      print_bar(sort_sat, num);

      mean1 = mean(sort_sat, num);
      median1 = median(sort_sat, num);
      mode1 = mode(sort_sat, num);

      cout << "Mean of Student Satisfaction: " << mean1 << endl;

      cout << "Median of Student Satisfaction: " << median1 << endl;

      cout << "Mode of Student Satisfaction: " << mode1 << endl;

      break;

    case 3:

      cout << "Professor " << l[0].get_name() << endl;
      cout << "Subject: " << l[0].get_sub() << endl << endl;

      print_bar(sort_qual, num);

      mean1 = mean(sort_wel, num);
      median1 = median(sort_wel, num);
      mode1 = mode(sort_wel, num);

      cout << "Mean of Quality of the Material: " << mean1 << endl;

      cout << "Median of Quality of the Material: " << median1 << endl;

      cout << "Mode of Quality of the Material: " << mode1 << endl;

      break;

    default:
      cout << "Invalid choice." << endl;
      instructions();
    }
    cout << "? ";
    cin >> choice3;
  }

  delete[] l;

  puts("End of run.");
}

void instructions(void) {
  cout << "Enter your choice:\n"
          "   1 bar graph accord to How well they taught.\n"
          "   2 bar graph accord to Student Satisfaction.\n"
          "   3 bar graph accord to Quality of the Material."
          "   4 to end."
       << endl;
}

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