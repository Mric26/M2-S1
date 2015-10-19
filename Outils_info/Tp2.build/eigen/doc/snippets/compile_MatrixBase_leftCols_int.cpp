#include <Eigen/Eigen>
#include <iostream>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif


using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  Array44i a = Array44i::Random();
cout << "Here is the array a:" << endl << a << endl;
cout << "Here is a.leftCols(2):" << endl;
cout << a.leftCols(2) << endl;
a.leftCols(2).setZero();
cout << "Now the array a is:" << endl << a << endl;

  return 0;
}
