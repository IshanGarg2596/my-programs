// quicksort on array worstcase o(n^2) averagecase o(nlogn)
#include <iostream>
using namespace std;
void quicksort(int *,int ,int );
int partition(int *,int ,int );
void printlist(int *,int );

int count = 0;

int main(){
	int *a,n;
	cout<<"Enter number of elements to be entered in array:";
	cin>>n;
	a = new int[n];
	for(int i = 1;i <= n ;i++){
		cin>>*(a+i);
	}
	quicksort(a,1,n);
	printlist(a,n);	
	delete[] a;
	return 0;
}

void quicksort(int *a,int p,int r){
	if(p < r){
		int q = partition(a,p,r);
	    quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int partition(int *a,int p,int r){
	int x = a[r];
	int i = p-1;
	for(int j = p; j <= r-1; j++){
		if(a[j] <= x){
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i+1;
}

void printlist(int *a,int n){
	for(int i=1; i <= n; ++i){
		cout<<"\n"<<*(a+i);
	}
}