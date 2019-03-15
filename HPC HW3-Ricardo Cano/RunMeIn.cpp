#include <iostream>
#include <ctime> 
using namespace std;


int main()
	{
	unsigned t0, t1;
	int n;
	int m;
	m=0;
	cout << "Enter a number: ";
	cin >>n;
	t0=clock();
	for (int i=0; i<=10000000; i++)
		{
		m=n*i;
		//cout << n << " * " << i << " = " << n * i << endl;		
		}
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time <<" seconds"<< endl;
	return 0;	
	}
