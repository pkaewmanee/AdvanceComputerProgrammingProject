#include <iostream>
#include <string.h>
using namespace std;
#include "DCLL.h"
#include "queue.h"

void menu();
void menu2(void);
void display_data(professor *, int[], int[], int[], int, int, int, int,
                  unsigned int);
professor create_professor(professor, string, string, int);
void instruction();

void menu() {
  professor *l, *z;
  professor l2;
  DCLL pds, tpds;
  int num = 0; // insert the amount of dataset you need
  string name, sub;
  int i, sort_wel[num], sort_sat[num], sort_qual[num];
  Queue q, qq, tempq;
  unsigned int choice;

  instruction();
  cout << "? ";
  cin >> choice;

  while (choice != 4) {
    switch (choice) {
    case 1: {

      if (pds.isEmpty() == 1 && q.isEmpty() == 1) {

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
        tpds.insert(l, num);
        q.enqueue(l, num);
        qq.enqueue(l, num);
        tempq.enqueue(l, num);
        num = 0;
        break;

      } else {

        num = 0;

        while (num <= 2) {
          cout << "How many set of data you want (At least 3): ";
          cin >> num;
        }

        cin.ignore();
        cout << "Enter the professor's name: ";
        getline(cin, name);

        if (pds.find(name) != NULL &&
            name == pds.find(name)->get_data()->get_name()) {

          cout << "There's already Professor " << name << " in the dataset.\n"
               << endl;
          break;

        } else {
          cout << "Enter the professor's subject: ";
          getline(cin, sub);

          l = new professor[num];

          for (i = 0; i < num; i++) {
            l[i] = create_professor(l2, name, sub, i);
          }

          pds.insert(l, num);
          tpds.insert(l, num);
          q.enqueue(l, num);
          qq.enqueue(l, num);
          tempq.enqueue(l, num);
          num = 0;
          break;
        }
      }
    }
    case 2: {
      int n = q.get_size();
      cout << q.get_size() << "= 44444\n"; // check
      Queue tq;
      NodePtr ll;
      professor *f;
      int numf;

      if (n > 1) {

        if (tpds.isEmpty() == 0) {

          cout << "Professor Name: ";

          for (i = 0; i < n; i++) {
            string name_pr = q.dequeue()->get_name();
            cout << name_pr << " ";
          }

          cout << "\n" << endl;

        } else if (tpds.isEmpty() == 1) {
          cout << "Please Create a Professor First." << endl;
          break;
        }

        cout << "Queue Professor By Name: " << endl;
        cin.ignore();

        for (i = 0; i < n; i++) {

          cout << "Enter the professor's name: ";
          getline(cin, name);
          int j = i;

          if (tpds.find(name) == NULL) {
            cout << "There's no Professor " << name << " in the dataset.\n"
                 << endl; // case sensitive
            i = j;
          } else if (tpds.find(name) != NULL) {

            ll = tpds.deletes(name);
            f = ll->get_data();
            numf = ll->get_num();

            q.enqueue(f, numf);
            qq.enqueue(f, numf);
            tempq.enqueue(f, numf);

            cout << "Professor " << name << " is now queued.\n" << endl;
          }
        }

        cout << "The Professor Current Queue: " << endl;

        for (i = 0; i < n; i++) {
          string name_pr = tempq.dequeue()->get_name();
          cout << name_pr << " ";
        }

        cout << "\n" << endl;
      } else {
        cout << "There's only one professor in the queue." << endl;
        break;
      }
      break;
    }

    case 3: {
      int numq = q.get_size();
      cout << q.get_size() << "= 44444\n"; // check
      if (q.isEmpty() == 1) {
        cout << "Please queue professor(s) first." << endl;
        break;
      } else {
        for (i = 0; i < numq; i++) {
          q.dequeue();
          z = qq.dequeue();
          int numf = pds.find(z->get_name())->get_num();

          print_prof(z, numf);

          insert_sat(sort_sat, z, numf);
          insert_wel(sort_wel, z, numf);
          insert_qual(sort_qual, z, numf);

          bsort(sort_wel, numf);

          bsort(sort_sat, numf);

          bsort(sort_qual, numf);

          menu2(); // display the menu2
          cout << "? ";
          cin >> choice;

          int mean1, median1, mode1;

          while (choice != 4) {

            display_data(z, sort_wel, sort_sat, sort_qual, mean1, median1,
                         mode1, numf, choice);

            cout << endl;
            menu2();
            cout << "? ";
            cin >> choice;
          }
          cout << "The Data of Professor " << z->get_name()
               << " is printed therefore unaccessible now.\n"
               << endl;
          delete[] z;
        }
      }
      break;
    }
    default:
      cout << "Invalid choice." << endl;
    }
    instruction();
    cout << "? ";
    cin >> choice;
  }
  puts("End of run.");
  delete[] l;
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
          "   2 Put Professor(s) Data in a Queue yourself.\n"
          "   3 Print Professor(s) Data in a Queue.\n"
          "   4 to end."
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

    cout << "Raw Data on how Well they Teach: ";
    print_sort_as(sort_wel, num);

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

    print_sort_as(sort_sat, num);

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
    print_sort_as(sort_qual, num);

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