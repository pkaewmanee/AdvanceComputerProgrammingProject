#include <iostream>
#include <string.h>
using namespace std;
#include "f(x).h"

void instructions(void);
void menu();

void menu() {
  professor *l;
  int num = 0; // insert the amount of dataset you need
  string name, sub;
  int i, j, temp, pass, sort_wel[num], sort_sat[num], sort_qual[num];

  while (num <= 2) {
    cout << "How many set of data you want (At least 3): ";
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

      cout << "Mean of How Well they Teach: " << mean1 << endl;

      cout << "Median of How Well they Teach: " << median1 << endl;

      cout << "Mode of How Well they Teach: " << mode1 << endl;

      cout << "Raw Data on how Well they Teach: ";
      print_sort(sort_wel,num);

      cout << endl;

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

      cout << "Raw Data on Student Satisfaction: ";
      print_sort(sort_sat,num);

      cout << endl;

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

      cout << "Raw Data on Quality of the Material Sorted: ";
      print_sort(sort_wel,num);

      cout << endl;

      break;

    default:
      cout << "Invalid choice." << endl;
      instructions();
    }

    cout<<endl;
    instructions();
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
          "   3 bar graph accord to Quality of the Material.\n"
          "   4 to end."
       << endl;
}