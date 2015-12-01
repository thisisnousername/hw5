/*
author: markus
  date: 2015-11-26
*/

#include <cmath>
#include <iostream>

using namespace std;

int main(){

	const double pi = acos(-1);
	const int N = 2000;				// number of steps
	const int n = 2;				// length of array
	const double dt=pi/100;				// step length

	double y = 1;
	double f[n];					// forward array
	double b[n];					// backward array

	double temp;					// temprorary variable

	f[0]=1;						// initial conditions
	f[1]=0;
	b[0]=1;
	b[1]=0;

	cout << 0 << "\t" << y << "\t" << f[0] << "\t" << b[0] << endl;

	for(int i=0; i<N; i++){

		y = cos(dt*(i+1));

		temp=f[0];

		f[0] = f[0]+f[1]*dt;
		f[1] = f[1]-temp*dt;

		temp=b[0];

		b[0] = (b[0]+b[1]*dt)/(1+dt*dt);
		b[1] = b[1] - dt*(temp+b[1]*dt)/(1+dt*dt);

	cout << i*dt << "\t" << y << "\t" << f[0] << "\t" << b[0] << endl;
	}

	return 0;
}
