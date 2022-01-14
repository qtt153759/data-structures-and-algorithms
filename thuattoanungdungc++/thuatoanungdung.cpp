#include<iostream>
using namespace std;
int main(){
	unsigned long long a,b,c,d;
	cin>>a>>b;
	unsigned long long x1,x2,y1,y2;
	x1=a/10;
	y1=a%10;
	x2=b/10;
	y2=b%10;
	c=(x1+x2)+(y1+y2)/10;
	if(c>0){
		cout<<c;
	}
	d=(y1+y2)%10;
	cout<<d;
	//cach counter tong vuot qua unsigned long long la dau tien tinh phan du sau khi lay tong hang don vi
	//sau do cong vao phan truoc roi printf,,,,sau do tinh hang don bang cach lay hang don vi cua tong hang don vi a va b
}
