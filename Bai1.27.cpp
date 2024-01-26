#include<iostream>
#include<iomanip>	// sd setprecision
#include <algorithm>	// sd ham  sort
#include <cstdlib> // sd system (exit, cls)
using namespace std;
void menu();
void nhap_n(int &n);
void nhapMang(int *a, int n);
void cauB(int *a, int n);
void cauC(int *a, int n);
void cauD(int *a, int n);
void cauE(int *a, int n);
void nhap(int *a, int &n);
void XuLiChucNang(int rs, int *a, int n);

int main(){
	int n;
	nhap_n(n);
	int *a = new int[n];
	nhapMang(a,n);
	//system("cls");
	menu();
	// xu li chuc nang
	int rs;
	while(1){
		XuLiChucNang(rs, a, n);
	}
	delete[] a;
	return 0;
}
void cauB(int *a, int n){
	int min = a[0], max = a[0];
	int i_min =0, i_max = 0;
	for(int i=1; i<n; i++){
		if(a[i] < min){
			min = a[i];
			i_min = i;
		}
		if(a[i] > max){
			max = a[i];
			i_max = i;
		}
	}
	// in ra min, max
	cout<<"Min = a["<<i_min<<"]= "<< min<<" va Max = a["<<i_max<<"]= "<<max<<endl;
}
void cauC(int *a, int n){
	long long tongAm = 0, tongDuong = 0;
	double avg;
	int cntSD =0;		// dem so duong
	
	// tinh tong cac so am, tong cac so duong
	for(int i=0; i<n; i++){
		if(a[i] < 0){
			tongAm+= a[i];
		}
		else{
			tongDuong+= a[i];
			cntSD++;
		}	
	}
	avg = (double)tongDuong/cntSD;
	cout<<"Tong cac so am: "<<tongAm<<endl;
	cout<<"Trung binh cong so duong: "<<fixed<<setprecision(2)<<avg<<endl;
	
}
void cauD(int *a, int n){
	int key;
	cout<<"Nhap phan tu can kiem tra: ";
	cin>> key;
	
	// duyet trong mang a, co key khong?
	bool cnt = false;		//dem key
	for(int i=0; i<n; i++){
		if(a[i] == key){
			cnt= true;
			break;		// neu co key thi thoat ra
		}
	}
	if(cnt== false){
		cout<<"So "<<key<<" khong co trong mang a!";
	}
	else{
		cout<<"So "<<key<<" co xuat hien trong mang a!";
	}
	cout<<"\n";
	
}
void cauE(int *a, int n){
	// in mang a ban dau:
	cout<<"Mang a ban dau: ";
	for(int i=0; i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	
	// duyet tung phan tu de kiem tra tang dan
	bool kt = true;
	for(int i=1; i<n; i++){
		if(a[i] < a[i-1]){
			kt = false;
			break;
		}
	}
	if(kt == true){
		cout<<"Mang a da duoc sap xep tang dan!"<<endl;
	}
	else{
		cout<<"Mang a chua duoc sap xep tang dan!"<<endl;
		// tien hanh sap xep mang a tang dan
			// tao ban sao mang a;
		int b[n];
		for(int i=0;i<n; i++){
			b[i] = a[i];
		}
		// sap xep mang b
		sort(b,b+n);	
		cout<<"Mang a sau khi duoc sap xep tang dan: ";	
		for(int i=0;i<n; i++){
			cout<<b[i]<<" ";
		}
		cout<<"\n";
	}
			
}
void nhap_n(int &n){
	do{
		cout<<"Nhap so phan tu cua mang a: ";
		cin>>n;
	}
	while (n>50);
	
}
void nhapMang(int *a, int n){
	cout<<"Nhap cac phan tu vao mang a: ";
	for(int i=0;i<n;i++){
		cin>> a[i];
	}
}
void XuLiChucNang(int rs, int *a, int n){
	do{
		cout<<"NHAP: ";
		cin>>rs;
	}
	while(rs>5);
	
	switch(rs){
		case 1:
			cauB(a,n);
			break;
		case 2:
			cauC(a,n);
			break;
		case 3:
			cauD(a,n);
			break;
		case 4:
			cauE(a,n);
			break;
		case 5:
			cout<<"Hen gap lai!";
			exit(0);
		default:
			break;
	}
}
void menu(){
		cout<<"MENU"<<endl;
	cout<<setfill('-')<<setw(25)<<" "<<endl;
	cout<<"Vui long chon 1 trong cac chuc nang duoi!"<<endl;
	cout<<"1. Tim phan tu min-max cua mang"<<endl;
	cout<<"2. Tinh tong cac so am va tbc cac so duong"<<endl;
	cout<<"3. Kiem tra mot so co xuat hien trong mang khong"<<endl;
	cout<<"4. Kiem tra mang co sap xep tang dan khong"<<endl;
	cout<<"5. Thoat chuong trinh"<<endl;
}