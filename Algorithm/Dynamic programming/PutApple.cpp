#include<iostream>
using namespace std;

int putApple(int m,int n){
   if(m==0||n==1) return 1;
   if(n>m) 
       return putApple(m,m);
   else
        return putApple(m,n-1)+putApple(m-n,n);
}

int main(){
	int m,n;
	cin>>m>>n;
        int k = putApple(m,n);
	cout<<k<<endl;
	return 0;
}
 

