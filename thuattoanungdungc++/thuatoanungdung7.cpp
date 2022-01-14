#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	do{
		cin>>n;
		getchar();
	}while(n>100||n<1);
	int i=0;
	while(i<n){
		string sLine;
		getline(cin,sLine);
		if(sLine.size()>0&&sLine.size()<101){
		    if(sLine.size()<=10){
			   cout<<sLine<<endl;
			   i++;	
			   continue;
	     	}
	     	else{
		         cout<<sLine[0]<<sLine.length()-2<<sLine[sLine.size()-1]<<endl;
		         i++;	
	     	}
	     
     	}
     	
	}
	return 0;
	//docjd kyx dedef
}
