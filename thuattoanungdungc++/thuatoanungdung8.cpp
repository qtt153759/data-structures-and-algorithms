#include<iostream>
using namespace std;
int main(){
	int n,m;
	do{
		cin>>n;
	}while(n<1||n>31);
	long nArr[n];
	for(int i=0;i<n;i++){
		cin>>nArr[i];
	}
	do{
		cin>>m;
	}while(m<1||m>31);
	long mArr[n];
	bool check=false;
	for(int i=0;i<m;i++){
		check=false;
		cin>>mArr[i];
		for(int j=0;j<n;j++){
			if(nArr[j]==mArr[i]){
				check=true;
			}
		}
		if(check==false) break;
	}
	if(check==true){
		printf("1");
	}
	else{
		printf("0");
	}
	
	
}
