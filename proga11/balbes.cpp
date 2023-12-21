#include <iostream>
#include <vector>
#include "shishka.h"
#include <math.h>

using namespace std;

int main () {
double r = 1.4;
CRational a(8, 2);
CRational b(2, 2);
CRational h (r);
long long int y = 2;
CRational c = h * a;
c.show();
cout << c.value() << endl;
return 0;
}