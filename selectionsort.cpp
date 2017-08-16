// Selection sort has n squared complexity
#include <iostream> 
#define MAX 100
using namespace std;
void selectionsort(int a[],int n);
void printlist(int a[],int n);

int main(){
	int a[MAX],n;
	cout<<"Enter no of elements in array(less than 100):";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	selectionsort(a,n);
	printlist(a,n);
	return 0;
}

//performs Selection sort on Array 
void selectionsort(int a[],int n){
	int min,index;
	for (int i = 0; i < n; ++i)
	{
		index = i;
		min = a[i];
		for (int j = i+1; j < n; ++j)
		{
			if(a[j]<min){
				index = j;
				min = a[j];
			}
		}
		int temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}
}

//prints sorted list(Array) 
void printlist(int a[],int n){
	for(int i = 0;i < n;i++){
		cout<<a[i]<<"  ";
	}
}
