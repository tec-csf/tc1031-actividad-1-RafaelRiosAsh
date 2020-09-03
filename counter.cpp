#include <iostream>
#include <time.h> 
 //THIS CODE IS USED TO TAKE TIME, NOT DONE BY ME
using namespace std;

void tiempo(){

unsigned t0, t1;

t0 = clock();

t1 = clock();

double time = (double(t1+t0)/CLOCKS_PER_SEC);
cout << "Execution Time: " << time << endl;

}