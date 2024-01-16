#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
void nhapMang(int *arr, int n);
void inMang(int* arr,int n);
void chenMang(int x, int *arr, int *n);
void nhapMang(int *arr, int n){
		for(int i=0;i<n;i++){
		cin>> arr[i];
	}
}
void inMang(int* arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void chenMang(int x, int *arr, int *n){
	(*n)++;
	if(x>arr[0]){
		
		// don cac phan tu lui phia sau
		for(int i=*n-1;i>=1;i--){
			arr[i] = arr[i-1];
		}
		// chen x vao
		arr[0] = x;
	}
	else if(x<arr[*n-1-1]){
		// chen x vao
		arr[*n-1] = x;
	}
	else{
		for(int i=0;i<*n-1-1;i++){
			if((arr[i]>=x) && (x>=arr[i+1])){
				// don cac phan tu bat dau tu i+1 ve phia sau
				int key = i+1;
				for(int j=*n-1;j>key;j--){
					arr[j] = arr[j-1];
				}
				arr[key] = x;
			}
		}
		
	}
}
int main(){
	int n;
	cout<<"Nhap so luong phan tu cua mang: ";
	cin>>n;
	int *arr = new int[n];
	cout<<"Nhap cac phan tu vao mang: ";
	nhapMang(arr, n);
	
	int x;
	cout<<"Nhap so nguyen x muon chen:";
	cin>>x;
	chenMang(x,arr,&n);
	cout<<"Mang sau khi chen la: ";
	inMang(arr,n);
	return 0;
	
}