#include <bits/stdc++.h>
#include<set>
#include <fstream>
#include <ginac/ginac.h>
#include "matplotlib-cpp-master/matplotlibcpp.h"

namespace plt = matplotlibcpp;

using namespace std;
using namespace GiNaC;



#define PI 3.14159265


symbol x("x"), y("y");



ex ecoul( float U = 1, float R = 1){
	ex r = sqrt(pow(x,2) + pow(y, 2));
    ex theta = atan2(y, x);
    return U * (r - R*R / r) * sin(theta);
}

ex vity(ex psi){
  	return psi.diff(y);
}

ex vitx(ex psi){
  	return -psi.diff(x);
}


void trc_circle(double rad){
	int n = 5000; // number of data points
	vector<double> x(n),y(n); 
	for(int i=0; i<n; ++i) {
		double t = 2*PI*i/n;
		x.at(i) = rad*sin(t);
		y.at(i) = rad*cos(t);
	}
	plt::plot(x, y, "-k");
}


void trc_cour(ex u, ex v){
    // u and v are respectively the x and y components of the arrows we're plotting
    std::vector<double> xx, yy, lu, lv;

    for (double i = -7; i <= 7; i+= 1) {
        for (double j = -7; j <= 7; j+=1) {
            if( i == 0 )
            	continue;

            xx.push_back(i);
            yy.push_back(j);
            
            ex f = evalf(u.subs(x==i).subs(y==j));
            ex g = evalf(v.subs(x==i).subs(y==j));

            
           	lu.push_back( ex_to<numeric>(f).to_double() );
           	lv.push_back( ex_to<numeric>(g).to_double() );
           	
        }
    }

   	//cout << u.subs(x==1) << endl;
    plt::quiver(xx, yy, lu, lv);

}




void trc_ligneCourant(ex u, ex v, double R = 1){

	plt::suptitle("My plot");
	plt::xlim(-5,5);
	plt::ylim(-5,5);

	trc_circle(R);
	trc_cour( u, v);

  plt::show();
}




int main(){

  double R = 3;
	
	ex psi = ecoul( 1, R);
	ex u = vity(psi);
	ex v = vitx(psi);

	trc_ligneCourant( u, v, R);



return 0;}
