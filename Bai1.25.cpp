#include<iostream>
#include<math.h>
using namespace std;
void nhapMang(double a[], int n);
void inMang(double a[],int n);
void merge_arrays(double a[],double b[],double c[], int n, int m);

int main(){
	int na,nb;
	cout<<"Nhap so luong phan tu cua mang a: ";
	cin>>na;
	cout<<"Nhap so luong phan tu cua mang b: ";
	cin>>nb;
	
	double a[na];
	double b[nb];
	double c[na+nb];
	cout<<"Nhap cac phan tu vao mang a (tang dan): ";
	nhapMang(a, na);	// chi nhap tang dan
	cout<<"Nhap cac phan tu vao mang b (tang dan): ";
	nhapMang(b, nb);	// chi nhap tang dan
	
	// goi ham sap xep, 
	 merge_arrays(a, b, c, na, nb);
	cout<<"Mang c sau khi sap xep la: ";
	inMang(c,na + nb);
	
	
	return 0;
	
}
void nhapMang(double a[], int n){
		for(int i=0;i<n;i++){
		cin>> a[i];
	}
}
void inMang(double a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void merge_arrays(double a[],double b[],double c[], int n, int m){
	int index=0, i=0, j=0;  // chi so cho mang c, a, b
	while( (i<n) &&  (j<m) ){
		if(a[i] <= b[j]){
			c[index]= a[i];
			index++;	// tang chi so mang c
			i++;		// tang chi so mang a
		}
		else{
			c[index]= b[j];
			index++;	// tang chi so mang c
			j++;		// tang chi so mang b
		}
	}
	// neu mang a con du phan tu
	while(i<n){
		c[index] = a[i];
		index++;
		i++;
	}
	// neu mang b con du phan tu
	while(j<m){
		c[index] = b[j];
		index++;
		j++;
	}
}