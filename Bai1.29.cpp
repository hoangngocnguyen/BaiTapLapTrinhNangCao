#include<iostream>
#include<iomanip>		// sd setfill
#include <cstdlib> // sd system (exit, cls)
#include<vector>
#include<algorithm>		// ham sort
using namespace std;

void XuLiChucNang(int rs,vector<vector<int>> &matrix , int hang, int cot);
void menu();
void nhapHangCot(int &hang, int &cot);
void nhapMaTran(vector<vector<int>> &matrix, int &hang, int &cot);
void inMaTran(vector<vector<int>> &matrix, int &hang, int &cot);
void cauA(const vector<vector<int>> &matrix, int hang, int cot);
void cauB(const vector<vector<int>> &matrix, int hang, int cot);
void cauC(vector<vector<int>> &matrix, int hang, int cot);

int main(){
	int hang, cot;
	nhapHangCot(hang, cot);
	
	// khai bao vector vector
	vector<vector<int>> matrix(hang, vector<int>(cot));
	nhapMaTran(matrix, hang, cot);
	
	menu();
	//xu li chuc nang
	int rs;
	while(1){
		XuLiChucNang(rs, matrix, hang, cot);
	}
	return 0;
}
void menu(){
	cout<<"MENU"<<endl;
	cout<<setfill('-')<<setw(25)<<" "<<endl;
	cout<<"Vui long chon 1 trong cac chuc nang duoi!"<<endl;
	cout<<"1. Thong bao len man hinh phan tu lon nhat va be nhat cua ma tran A"<<endl;
	cout<<"2. Dem, in ra vi tri phan tu ma tran bang voi so nguyen cho truoc"<<endl;
	cout<<"3. Sap xep ma tran A tang dan cua moi hang & in ra man hinh"<<endl;
	cout<<"4. Thoat chuong trinh"<<endl;
}
void nhapHangCot(int &hang, int &cot){
	cout<<"Nhap so hang ma tran: ";
	cin>>hang;
	cout<<"Nhap so cot ma tran: ";
	cin>>cot;
}
void nhapMaTran(vector<vector<int>> &matrix, int &hang, int &cot){
	// nhap gia tri cho ma tran
	cout<<"Nhap ma tran: "<<endl;
	
	for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
        	cout<<"matrix["<<i<<"]["<<j<<"]= ";
            cin>>matrix[i][j];
        }
    }
}
void  inMaTran(vector<vector<int>> &matrix, int &hang, int &cot){
	cout<<"Ma tran nhu sau: \n";
	for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout<< matrix[i][j] <<" ";
        }
        cout<<"\n";
    }
}
void cauA(const vector<vector<int>> &matrix, int hang, int cot){
	// thong bao min, max ma tran
	int min = matrix[0][0], max = 0;
	int i_min = 0, j_min = 0, i_max = 0, j_max = 0;
	for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            if(matrix[i][j] < min){
            	min = matrix[i][j];
            	i_min = i;
            	j_min = j;
			}
			if(matrix[i][j] > max){
				max = matrix[i][j];
				i_max = i;
				j_max = j;
			}
        }
    }
    cout<<"Phan tu be nhat la A["<<i_min<<"]["<<j_min<<"]= "<<min<<"\n";
    cout<<"Phan tu lon nhat la A["<<i_max<<"]["<<j_max<<"]= "<<max<<"\n";
}
void cauB(const vector<vector<int>> &matrix, int hang, int cot){
	// dem so luong phan tu bang so nguyen x cho truoc, hien thi vi tri
	cout<<"Nhap vao x can kiem tra: ";
	int x;
	cin>>x;
	// khoi tao bien dem
	int cnt = 0;
	cout<<"Cac phan tu bang voi x = "<<x<<" la: ";
	for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
        	if(matrix[i][j] == x){
        		cnt++;
        		cout<<"A["<<i<<"]["<<j<<"]   ";
			}	
        }
    }
    cout<<"\n";
    if(cnt == 0){
    	cout<<"Khong co phan tu nao bang "<<x<<" !";
	}
	else{
		cout<<"Tong cong co "<<cnt<<" phan tu"<<endl;
	}
}

void cauC(vector<vector<int>> &matrix, int hang, int cot){
	cout<<"Ma tran ban dau:"<<endl;
	inMaTran(matrix, hang, cot);
	// sap xep tang dan theo hang
	// chuyen tung hang thanh 1 mang va sap xep va in ra
	cout<<"Ma tran sau khi sap xep la:"<<endl;
	// sort tung hang, nghia la vector[i], trong moi vector[i] lai co nhung vector [j]
	for(int i=0; i< hang; i++){
		sort(matrix[i].begin(), matrix[i].end());
	}
	inMaTran(matrix, hang, cot);
}
void XuLiChucNang(int rs, vector<vector<int>> &matrix, int hang, int cot){
	do{
		cout<<"NHAP: ";
		cin>>rs;
	}
	while(rs<1 || rs>4);
	
	switch(rs){
		case 1:
			cauA(matrix, hang, cot);
			break;
		case 2:
			cauB(matrix, hang, cot);
			break;
		case 3:
			cauC(matrix, hang, cot);
			break;
		case 4:
			cout<<"Hen gap lai!";
			exit(0);
		default:
			break;
	}
}
