#include <iostream>
using namespace std;

class professor {

private:
  string name, sub;
  int wel, sat, qual;

public:
  ~professor();
  string get_name();
  string get_sub();
  int get_wel();
  int get_sat();
  int get_qual();
  void set_name(string n) { name = n; }
  void set_sub(string n) { sub = n; }
  void set_wel(int n) {
    if (n > 10) {
      wel = 10;
    } else if (n <= 0) {
      wel = 0;
    } else {
      wel = n;
    }
  }
  void set_sat(int n) {
    if (n > 10) {
      sat = 10;
    } else if (n <= 0) {
      sat = 0;
    } else {
      sat = n;
    }
  }
  void set_qual(int n) {
    if (n > 10) {
      qual = 10;
    } else if (n <= 0) {
      qual = 0;
    } else {
      qual = n;
    }
  }
  professor();
  professor(string, string, int, int, int);
  void print_all();
};

string professor::get_name() { return name; }
string professor::get_sub() { return sub; }
int professor::get_wel() { return wel; }
int professor::get_sat() { return sat; }
int professor::get_qual() { return qual; }

professor::professor() {
  name = "";
  sub = "";
  wel = 0;
  sat = 0;
  qual = 0;
}

professor::professor(string n, string su, int w, int sa, int q) {
  name = n;
  sub = su;
  wel = w;
  sat = sa;
  qual = q;
}

professor::~professor() { cout << ""; }