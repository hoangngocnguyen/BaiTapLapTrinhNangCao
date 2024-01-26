#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int Ptb2(double a, double b, double c, double *x1, double *x2){
	// tinh delta
	double dt = b*b - 4*a*c;
	// kiem tra delta
	if(dt<0){
		return -1;
	}
	else if(dt==0){
		*x1= -b/(2*a);
		*x2 = *x1;
		return 0;
	}
	else{
		*x1= (-b+sqrt(dt))/(2*a);
		*x2= (-b-sqrt(dt))/(2*a);
		return 1;
	}
}
int main(){
	double a,b,c,x1,x2;
	cout<<"Nhap vao a, b, c: ";
	cin>>a>>b>>c;
	if(Ptb2(a,b,c,&x1,&x2) == -1){
		cout<<"Phuong trinh vo nghiem.";
	}
	else if(Ptb2(a,b,c,&x1,&x2) == 0){
		cout<<"Phuong trinh co nghiem kep x1 = x2 = ";
		cout<<fixed<<setprecision(2)<<x1;
	}
	else{
		cout<<"Phuong trinh co hai nghiem phan biet:"<<endl;
		cout<<fixed<<setprecision(2);
		cout<<"x1= "<<x1<<"   x2= "<<x2;
	}
	return 0;
	
}