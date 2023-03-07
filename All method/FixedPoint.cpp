#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return pow(x, 3) - x - 1; // hàm f(x) = x^3 - 2x - 5
}

double g(double x){
	
	return pow(x+1,1.0/3);//chon gx=x;
}

int main() {
    double x0, x1, eps;
    int iter, i=1,n=0;

    cout << "Nhap gia tri khoi tao x0: ";
    cin >> x0;

    cout << "Nhap sai so epsilon: ";
    cin >> eps;

    cout << "Nhap so buoc lap toi da: ";
    cin >> iter;

   	while(i<=iter){
   		x1=g(x0);
   		n++;
   		if(fabs(x1-x0)<eps){
   			x1=x0;
   			break;
		   }
		i++;
		x0=x1;
	   }
    if(n<iter)
    cout <<"nghiem xap xi tim duoc la: "<<x1<< " sau " <<  n << " buoc lap" << endl;
    else cout<<"Khong tim nghiem thanh cong .";
    return 0;
}
