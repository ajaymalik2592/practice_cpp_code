// setfill example
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw
using namespace std;
int main () {
  cout << setfill ('x') << setw (10);
  cout << 77 << endl;
  return 0;
}