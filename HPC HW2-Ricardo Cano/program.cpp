#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>


using namespace std;

double xn1; double a; double b; double alp; double bet;

int Map(double &xn, double &yn)
	{
	
	a = 1.4; b = 0.3; alp= 1; bet = 1;

	xn1= a - alp*pow(xn,2) + b*yn;
	yn= bet*xn;
	xn=xn1;
	return 0;
	}

int Map2(double &xn, double &yn)
	{
	
	a = 1; b = 1; alp= 0.2; bet = 1.01;

	xn1= a - alp*pow(xn,2) + b*yn;
	yn= bet*xn;
	xn=xn1;
	return 0;
	}

int main()
	{
	
	fstream file;
	file.open("ThirdPoint.txt",ios::out); 
	int counter;
	double x,y;
	int iter;
	int R;
	double p;
	int i;
	iter = 1000; R = 100; counter = 0;
	for(double j = 0.4; j < 4; j+= 0.4)
	{	
		for(double k = -3.6; k < 0; k+=0.4)
		{
			x=j;
			y=k;			
			for(i=0 ; i<=iter ; i++)
			{		
				Map2(x,y);
				p=sqrt(pow(x,2)+pow(y,2));
				if( p > R)
				{
					file<<p<<endl;
					i=iter;
 					
				}
	
			}
			if(i == iter)
			{
				file << R <<endl;
			} 
			counter++;	
			
		}
	
	}
	file.close();
	return 0;
}



