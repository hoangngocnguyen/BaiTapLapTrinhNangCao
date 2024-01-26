#include<iostream>
#include<iomanip>	// ham setprecision
#include<math.h>	// ham sqrt()
using namespace std;
void nhapMang(double a[]);
double tinhChieuDaiVector(double a[]);
void vectorTong2Vector(double a[], double b[], double c[]);

int main(){
	double a[5], b[5], c[5];
	cout<<"Nhap mang a: ";
	nhapMang(a);
	cout<<"Nhap mang b: ";
	nhapMang(b);
	
	// chieudai 
	cout<<fixed<<setprecision(2);
	cout<<"Chieu dai vector a: "<<tinhChieuDaiVector(a)<<endl;
	cout<<"Chieu dai vector b: "<<tinhChieuDaiVector(b)<<endl;
	// tong 2 vector
	vectorTong2Vector(a,b,c);
	cout<<"Vector tong 2 vector a va b la vector c = ( ";
	for(int i=0; i<5; i++){
		cout<<c[i]<<" ";
	}
	cout<<")";
	return 0;
}
void nhapMang(double a[]){
	for(int i=0; i<5; i++){
		cin>>a[i];
	}
}
double tinhChieuDaiVector(double a[]){
	double TongBinhPhuong = 0;
	for(int i=0; i<5; i++){
		TongBinhPhuong+= a[i]*a[i];
	}
	double ChieuDai = sqrt(TongBinhPhuong);
	return ChieuDai; 
}
void vectorTong2Vector(double a[], double b[], double c[]){
	for(int i=0; i<5; i++){
		c[i] = a[i] + b[i];
	}
}