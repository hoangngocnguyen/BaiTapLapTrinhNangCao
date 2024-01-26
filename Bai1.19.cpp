#include <iostream> 
using namespace std; 
int main()
{
 int a[]={10,15,4,25,3,-4},*p,i;
 p=&a[2];
 int b=0;
 cout<<"\nCac gia tri cua mang:\n\n";
 for (i=0;i<6;i++)
 cout<<"a["<<i<<"] = "<<a[i]<<endl;
 cout<<"\nCho biet gia tri cua cac bieu thuc\n\n";
 cout<<"a) *(p+1) = "<<*(p+1);			// a[3]
 cout<<"b) *(p-1) = "<<*(p-1);			// a[1]
 
 cout<<"d) a[(*p)++)] = "<<a[(*p)++]; 	
 // *p = a[2] = 4, a[(*p)++] = 4 (in ra roi cong vao sau)
 // sau do *p = a[2] = 4+1 = 5.
 
 cout<<"e) *(a+a[2]) = "<<*(a+a[2]);
 // a la mot con tro, a = &a[0], *a = 10
 // a + a[2] = a + 5 = &a[5]
 // *(a + a[2]) = a[5] = -4
 
 return 0;
}