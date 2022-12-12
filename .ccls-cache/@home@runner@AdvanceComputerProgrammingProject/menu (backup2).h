#include <iostream>
#include <string.h>
using namespace std;
#include "DCLL.h"

void menu();
void menu2(void);
void display_data(professor *, int[], int[], int[], int, int, int, int,
                  unsigned int);
professor create_professor(professor, string, string, int);
void instruction();

void menu() {
  professor *l;
  professor l2;
  DCLL pds;
  int num = 0; // insert the amount of dataset you need
  string name, sub;
  int i, sort_wel[num], sort_sat[num], sort_qual[num];
  unsigned int choice;

  instruction();
  cout << "? ";
  cin >> choice;
  cout << endl;

  while (choice != 3) {
    switch (choice) {
    case 1: {
      if (pds.isEmpty() == 1) {

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
          l[i] = create_professor(l2, name, sub, i);
        }

        pds.insert(l, num);
        num = 0;
        break;

      } else if (pds.isEmpty() == 0) {
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
          l[i] = create_professor(l2, name, sub, i);
        }
        pds.insert(l, num);
        num = 0;
        break;
      }
    }
    case 2: {
      string find_name;
      cin.ignore();
      cout << "Enter name of the professor: ";
      getline(cin, find_name);

      if (pds.isEmpty() == 0) {

        if(){
        
        NodePtr ll = pds.deletes(find_name);
        
        if (ll == NULL) {
          cout << "There's no Professor " << find_name
               << " in the data storage." << endl;
          break;
        } else {

          professor *f = ll->get_data();
          int numf = ll->get_num();
          print_prof(f, numf);

          insert_sat(sort_sat, f, numf);
          insert_wel(sort_wel, f, numf);
          insert_qual(sort_qual, f, numf);

          bsort(sort_wel, numf);

          bsort(sort_sat, numf);

          bsort(sort_qual, numf);

          menu2(); // display the menu2
          cout << "? ";
          cin >> choice;
          cout << endl;

          int mean1, median1, mode1;

          while (choice != 4) {

            display_data(f, sort_wel, sort_sat, sort_qual, mean1, median1,
                         mode1, numf, choice);

            cout << endl;
            menu2();
            cout << "? ";
            cin >> choice;
            cout << endl;
          }

          delete[] f;

          cout << "The Data of Professor " << find_name
               << " is now printed and deleted. Therefore, it can't be access any longer.\n";

          break;
        }
        }
      } else {
        cout << "The Dataset is empty. Please make Professor(s) first." << endl;
        break;
      }
      }
    }
    default:
      cout << "Invalid choice." << endl;
    }
    instruction();
    cout << "? ";
    cin >> choice;
    cout << endl;
  }
  puts("End of run.");
}

void menu2(void) {
  cout << "Enter your choice:\n"
          "   1 bar graph accord to How well they taught.\n"
          "   2 bar graph accord to Student Satisfaction.\n"
          "   3 bar graph accord to Quality of the Material.\n"
          "   4 to end."
       << endl;
}

void instruction() {
  cout << "Enter your choice:\n"
          "   1 Make Professor(s).\n"
          "   2 Print Data on Professor(s).\n"
          "   3 to end."
       << endl;
}

void display_data(professor *l, int sort_wel[], int sort_sat[], int sort_qual[],
                  int mean1, int median1, int mode1, int num,
                  unsigned int choice) {
  switch (choice) {
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

    print_sort_as(sort_wel, num);
    print_sort_de(sort_wel, num);

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

    print_sort_as(sort_wel, num);
    print_sort_de(sort_wel, num);

    cout << endl;

    break;

  case 3:

    cout << "Professor " << l[0].get_name() << endl;
    cout << "Subject: " << l[0].get_sub() << endl << endl;

    print_bar(sort_qual, num);

    mean1 = mean(sort_qual, num);
    median1 = median(sort_qual, num);
    mode1 = mode(sort_qual, num);

    cout << "Mean of Quality of the Material: " << mean1 << endl;

    cout << "Median of Quality of the Material: " << median1 << endl;

    cout << "Mode of Quality of the Material: " << mode1 << endl;

    cout << "Raw Data on Quality of the Material Sorted: ";
    
    print_sort_as(sort_wel, num);
    print_sort_de(sort_wel, num);

    cout << endl;

    break;

  default:
    cout << "Invalid choice." << endl;
  }
}

professor create_professor(professor l, string name, string sub, int i) {

  int wel = -1, sat = -1, qual = -1;
  cout << endl;
  cout << "Please rate the professor from 0 - 10" << endl;
  cout << "Dataset " << i + 1 << ": " << endl;
  l.set_name(name);
  l.set_sub(sub);

  while (wel > 11 || wel <= -1) {
    cout << "How well they teach: ";
    cin >> wel;
  }
  l.set_wel(wel);

  while (sat > 11 || sat <= -1) {
    cout << "Student Satisfaction: ";
    cin >> sat;
  }
  l.set_sat(sat);

  while (qual >= 11 || qual <= -1) {
    cout << "Quality of the Material: ";
    cin >> qual;
  }
  l.set_qual(qual);

  cout << endl;
  return l;
}