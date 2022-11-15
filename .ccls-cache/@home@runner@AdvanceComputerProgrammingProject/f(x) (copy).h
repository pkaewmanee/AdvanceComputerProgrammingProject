#include <iostream>
using namespace std;
#include "professor.h"

void instructions(void);
void instructions2(void);
void menu();
void bsort(int[]);
void menu2(int[], professor *, int);

void menu() {
  professor *l;
  unsigned int choice; // user's choice
  int num = 0;         // insert the amount of dataset you need
  string name, sub;
  int i, sort[1];

  instructions(); // display the menu
  cout << "? ";
  cin >> choice;

  // loop while user does not choose 4
  while (choice != 4) {

    while (num <= 2) {
      cout << "How many set of data you want: ";
      cin >> num;
    }

    switch (choice) {
    case 1:

      cout << "Enter the professor's name: ";
      cin >> name;
      getline(cin, name);

      cout << "Enter the professor's subject: ";
      cin >> sub;
      getline(cin, sub);

      l = new professor[num];

      for (i = 0; i < num; i++) {
        int wel = -1, sat = -1, qual = -1;
        cout << "Please rate the professor from 0 - 10" << endl;
        cout << "Dataset " << i + 1 << ": " << endl;
        l[i].set_name(name);
        l[i].set_sub(sub);
        while (wel >= 10 || wel <= -1) {
          cout << "How well they teach: ";
          cin >> wel;
        }
        l[i].set_wel(wel);
        while (sat > 10 || sat <= -1) {
          cout << "Student Satisfaction: ";
          cin >> sat;
        }
        l[i].set_sat(sat);
        while (qual >= 10 || qual <= -1) {
          cout << "Quality of the Material: ";
          cin >> qual;
        }
        l[i].set_qual(qual);
      }

      sort[num];

      break;

    case 2:

      // menu2(sort, l, num);

      unsigned int choice2;
      int i, j, temp;

      instructions2(); // display the menu2
      cout << "? ";
      cin >> choice2;

      while (choice2 != 4) {
        switch (choice2) {
        case 1:

          for (i = 0; i < num; i++) {
            sort[i] = l[i].get_wel();
            cout << sort[i];
          }

          bsort(sort);

          choice2 = 4;

          break;

        case 2:

          for (i = 0; i < num; i++) {
            sort[i] = l[i].get_sat();
          }

          choice2 = 4;

          bsort(sort);

          break;

        case 3:

          for (i = 0; i < num; i++) {
            sort[i] = l[i].get_qual();
          }

          bsort(sort);

          choice2 = 4;

          break;

        default:
          cout << "Invalid choice." << endl;
          instructions2();
        }
      }

      break;

    case 3:
      cout << "Sorted Element List ...\n";
      for (i = 0; i < num; i++) {
        cout << sort[i] << "\t";
      }

      break;

    default:
      cout << "Invalid choice." << endl;
      instructions();
      break;
    } // end switch

    cout << "? ";
    cin >> choice;
  } // end while

  puts("End of run.");
  return;
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

/*void menu2(int sort[], professor *l, int num) {
  unsigned int choice2;
  int i, j, temp;

  instructions2(); // display the menu2
  cout << "? ";
  cin >> choice2;

  while (choice2 != 4) {
    switch (choice2) {
    case 1:

      for (i = 0; i < num; i++) {
        sort[i] = l[i].get_wel();
      }

      bsort(sort);

      choice2 = 4;

      break;

    case 2:

      for (i = 0; i < num; i++) {
        sort[i] = l[i].get_sat();
      }

      choice2 = 4;

      bsort(sort);

      break;

    case 3:

      for (i = 0; i < num; i++) {
        sort[i] = l[i].get_qual();
      }

      bsort(sort);

      choice2 = 4;

      break;

    default:
      cout << "Invalid choice." << endl;
      instructions2();
    }
  }
}*/

void bsort(int sort[]) {
  int i, j, temp, pass = 0;
  for (i = 0; i < 10; i++) {
    for (j = i + 1; j < 10; j++) {
      if (sort[j] < sort[i]) {
        temp = sort[i];
        sort[i] = sort[j];
        sort[j] = temp;
      }
    }
    pass++; // in case you want to count amount it take
  }
}