#include<iostream>
#include<iomanip>	// ham setprecision
using namespace std;
double HePT(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double*y){
	// giai he pt theo dinh thuc Crammer
	double D = a1*b2 - a2*b1;
	double Dx = c1*b2 - c2*b1;
	double Dy = a1*c2 - a2*c1;
	
	if(D==0){
		if(Dx == 0 && Dy == 0){
			return 0;
		}
		else{
			return -1;
		}
	}
	else{
		*x = Dx/D;
		*y = Dy/D;
		return 1;
	}
}
int main(){
	double a1,b1,c1,a2,b2,c2,x,y;
	cout<<"Nhap vao a1: ";
	cin>> a1;
	cout<<"Nhap vao b1: ";
	cin>> b1;
	cout<<"Nhap vao c1: ";
	cin>> c1;
	cout<<"Nhap vao a2: ";
	cin>> a2;
	cout<<"Nhap vao b2: ";
	cin>> b2;
	cout<<"Nhap vao c2: ";
	cin>> c2;
	
	//giai he pt
	if(HePT(a1, b1, c1, a2, b2, c2, &x, &y) == -1){
		cout<<"He vo nghiem!";
	}
	else if(HePT(a1, b1, c1, a2, b2, c2, &x, &y) == 0){
		cout<<"He co vo so nghiem (nghiem tuy y)!";
	}
	else{
		cout<<"He co nghiem duy nhat (da lam tron 2 chu so):"<<"\n";
		cout<<fixed<<setprecision(2);
		cout<<"x= "<< x<<endl;
		cout<<"y= "<<y<<endl;
	}
	
	return 0;
	
}