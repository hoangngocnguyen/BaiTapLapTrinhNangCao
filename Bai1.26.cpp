#include<iostream>
#include<math.h>
#include<map>
using namespace std;
void nhapMang(double a[], int n);
void hienThi(double a[], int  n);

int main(){
	int na;
	cout<<"Nhap so phan tu cua mang a: ";
	cin>>na;
	
	double a[na];
	cout<<"Nhap cac phan tu vao mang a: ";
	nhapMang(a,na);
	hienThi(a,na);
	
	return 0;
	
}
void nhapMang(double a[], int n){
		for(int i=0;i<n;i++){
		cin>> a[i];
	}
}
void hienThi(double a[], int  n){
	// khoi tao map
	map<double, int> mp;    // <gia tri, so lan xh>
	for(int i=0; i<n; i++){
		mp[a[i]]++;
	}
	cout<<"Cac phan tu chi xuat hien mot lan: ";
	
	// khai bao iterator
	map<double, int>::iterator it = mp.begin();
	int cnt=0;
    // in cac phan tu co so lan xh la 1
	while (it != mp.end()) {
        if(it->second == 1){
        	cout<< it->first<<" ";
        	cnt++;		// dem so pt xh 1 lan
		}
        it++;	// tang iterator lên 1 don vi
    }
    if(cnt==0){
    	cout<<"Khong co!";
	}
}