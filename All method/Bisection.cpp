#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
    //nhap ham f , gia su la x^3-x-1;
    return  x*x*x-x-1;
}
void bisection(double a, double b, double epsilon,double iter) {
   int i=1;
   double p,FP;
   double FA=f(a);
   while(i<=iter){
   		p= a +(b - a)/2;
   		FP= f(p);
   		if(FP==0 || (b-a)/2 <epsilon){
   			break;
		   }
   		i+=1;
   		if(FA*FP>0) a = p;
   		else b = p;
   }
   if(i>iter)cout<<"khong tim thay nghiem sau "<< iter << "lan lap";
   else cout<<"nghiem tim duoc la "<< p <<"sau "<<i <<"lan lap";
}
int main(){
     double a=0, b=3, epsilon=0.001,iter = 1000;
    
    //cin >> a >> b;
   
    // cin >> epsilon;
    bisection(a, b, epsilon,iter);
	
    return 0;

}
