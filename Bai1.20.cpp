#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int DienTich(double a, double b, double c, double *S){
	// dieu kien tam giac
	if(a+b>c && b+c>a && a+c>b){
		double p = (a+b+c)/2;
		*S= sqrt(p*(p-a)*(p-b)*(p-c));
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	double a,b,c,S;
	cin>>a>>b>>c;
	if(DienTich(a,b,c,&S) == 1){
		cout<<"Dien tich tam giac bang: "<<fixed<<setprecision(2)<<S;
	}
	else{
		cout<<"Khong tinh duoc dien tich tam giac";
	}
	return 0;
	
}