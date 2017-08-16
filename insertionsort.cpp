#include <iostream>
#define MAX 100
using namespace std;
int* insertionsort(int *,int );
void printlist(int *,int );

int main(){
	int *a,n;
	cout<<"Enter number of elements to be entered in array:";
	cin>>n;
	a = new int[n];
	for(int i = 0;i < n ;i++){
		cin>>*(a+i);
	}
	a = insertionsort(a,n);
	printlist(a,n);	
	delete[] a;
	return 0;
}

int* insertionsort(int *a,int n){
  	int key,i,j;
	for(i =1; i < n; i++){
  		key = *(a+i);
  		for(j = i-1; j >= 0 && *(a+j)>=key; j--){
  			*(a+j+1) = *(a+j);
		  }  
		  *(a+j+1) = key;
	}
	return a;
}

void printlist(int *a,int n){
	for(int i=0; i < n; ++i){
		cout<<"\n"<<*(a+i);
	}
}

