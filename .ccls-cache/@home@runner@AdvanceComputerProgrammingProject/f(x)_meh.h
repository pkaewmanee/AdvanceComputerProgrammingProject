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

void menu() {
  professor *l;
  unsigned int choice; // user's choice
  int num = 0;         // insert the amount of dataset you need
  string name, sub;
  int i, j, temp, pass, sort_wel[num], sort_sat[num], sort_qual[num];

  instructions(); // display the menu
  cout << "? ";
  cin >> choice;

  // loop while user does not choose 4
  while (choice != 4) {

    switch (choice) {
    case 1:

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

      break;

    case 2:

      unsigned int choice2;
      int i;

      instructions2(); // display the menu2
      cout << "? ";
      cin >> choice2;

      while (choice2 != 4) {
        switch (choice2) {
        case 1:

          bsort(sort_wel, num);

          break;

        case 2:

          bsort(sort_sat, num);

          break;

        case 3:

          bsort(sort_qual, num);

          break;

        default:
          cout << "Invalid choice." << endl;
          instructions2();
        }
        choice2 = 4;
      }

      break;

    case 3:

      unsigned int choice3;

      instructions3(); // display the menu2
      cout << "? ";
      cin >> choice3;

      while (choice3 != 4) {
        switch (choice3) {
        case 1:

          cout << "Professor " << l[0].get_name() << endl;
          cout << "Subject: " << l[0].get_sub() << endl << endl;

          print_bar(sort_wel, num);

          break;

        case 2:

          cout << "Professor " << l[0].get_name() << endl;
          cout << "Subject: " << l[0].get_sub() << endl << endl;

          print_bar(sort_sat, num);

          break;

        case 3:

          cout << "Professor " << l[0].get_name() << endl;
          cout << "Subject: " << l[0].get_sub() << endl << endl;

          print_bar(sort_qual, num);

          break;

        default:
          cout << "Invalid choice." << endl;
          instructions3();
        }
        choice3 = 4;
      }

      break;

      break;

    default:
      cout << "Invalid choice." << endl;
      instructions();
      break;
    } // end switch

    
    cout << "? ";
    cin >> choice;
  } // end while

  delete []l;

  puts("End of run.");
}

void instructions(void) {
  cout << "Enter your choice:\n"
          "   1 to create an element into the list.\n"
          "   2 to sort element based on category.\n"
          "   3 to make a bar graph.\n"
          "   4 to end."
       << endl;
}

void instructions2(void) {
  cout << "Enter your choice:\n"
          "   1 sort element based on How well they taught.\n"
          "   2 sort element based on Student Satisfaction.\n"
          "   3 sort element based on Quality of the Material."
       << endl;
}

void instructions3(void) {
  cout << "Enter your choice:\n"
          "   1 bar graph accord to How well they taught.\n"
          "   2 bar graph accord to Student Satisfaction.\n"
          "   3 bar graph accord to Quality of the Material."
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