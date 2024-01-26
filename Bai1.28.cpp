#include<iostream>
#include<math.h>      // sd ham sqrt()
#include<iomanip>		// sd setfill
#include <cstdlib> // sd system (exit, cls)
using namespace std;
void nhap_n(int &n);
void nhapMang(int *a, int n);
void cauC(int *a, int n);
void cauD(int *a, int n);
bool kiemTraChinhPhuong(int n);
void XuLiChucNang(int rs, int *a, int n);
void menu();
int main(){
	int n;
	nhap_n(n);
	int *a = new int[n];
	nhapMang(a,n);
	///menu
	menu();
	// xu li chuc nang
	int rs;
	while(1){
		XuLiChucNang(rs, a, n);
	}
	delete[] a;
	return 0;
}
//////////////////////
void menu(){
	cout<<"MENU"<<endl;
	cout<<setfill('-')<<setw(25)<<" "<<endl;
	cout<<"Vui long chon 1 trong cac chuc nang duoi!"<<endl;
	cout<<"1. In ra man hinh so chinh phuong lon nhat"<<endl;
	cout<<"2. In ra man hinh tbc cac so duong o vi tri le (a[0] vi tri 1)"<<endl;
	cout<<"3. Thoat chuong trinh"<<endl;
}
void nhap_n(int &n){
	do{
		cout<<"Nhap so phan tu cua day so: ";
		cin>>n;
	}
	while ((n<10) || (n>100));
}
void nhapMang(int *a, int n){
	cout<<"Nhap cac phan tu cua day so: ";
	for(int i=0;i<n;i++){
		cin>> a[i];
	}
}
void XuLiChucNang(int rs, int *a, int n){
	do{
		cout<<"NHAP: ";
		cin>>rs;
	}
	while(rs>3);
	
	switch(rs){
		case 1:
			cauC(a,n);
			break;
		case 2:
			cauD(a,n);
			break;
		case 3:
			cout<<"Hen gap lai!";
			exit(0);
		default:
			break;
	}
}
bool kiemTraChinhPhuong(int n){
	// neu cb2 cua n la` mot so nguyen thi n so chinh phuong
	if(n<0){
		return false;
	}
	else{
		int cb2 = sqrt(n);
		if(cb2*cb2 == n){
			return true;
		}
		else{
			return false;
		}
	}
	
}
void cauC(int *a, int n){
	//in ra man hinh so chinh phuong lon nhat
	
	// kiem tra so chinh phuong
	// tim so chinh phuong max
	int max = 0;
	for(int i=0; i<n; i++){
		if((kiemTraChinhPhuong(a[i]) == true) && (a[i] > max)){
			max = a[i];
		}
	}
	if(max == 0){
		cout<<"Day khong co so chinh phuong nao";
	}
	else{
		cout<<"So chinh phuong lon nhat trong day la: "<<max;
	}
	cout<<"\n";
}
void cauD(int *a, int n){
	// trung binh cong cac so duong + o vi tri le
	
	int tong = 0, cntLe = 0;		// cnt: dem phan tu vi tri le
	double avg;
	// kiem tra dieu kien ket hop
	for(int i = 0; i<n; i++){
		if((a[i] > 0) && ((i+1) %2 ==1)){
			tong+= a[i];
			cntLe++;
		}
	}
	if(cntLe == 0){
		cout<<"Day khong co so nguyen duong nao o vi tri le";
	}
	else{
		// tbc
		avg = (double)tong/cntLe;
		cout<<fixed<<setprecision(2);
		cout<<"Trung bing cong cac so duong o vi tri le la: "<<avg;
	}
	cout<<"\n";
	
}