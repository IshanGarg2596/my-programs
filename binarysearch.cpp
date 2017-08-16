#include <iostream> 
#define MAX 100
using namespace std;
int binarysearch(int a[],int l,int r,int x);

int main(){
	int a[MAX],n;
	cout<<"Enter no of elements in array(less than 100):";
	cin>>n;
	cout<<"Enter sorted array:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x;
	cout<<"Element to search for:";
	cin>>x;
	int result = binarysearch(a,0,n,x);
	if(result == -1){
		cout<<"Element not found";
	}
	else{
		cout<<"Element found at "<<result+1;
	}
	return 0;
}

int binarysearch(int a[],int l,int r,int x){
	int mid;
	while(l<r)
	{
		mid  = (l+r)/2;
		if(x < a[mid]){
			r = mid - 1;
		}
		else if(x > a[mid]){
			l = mid + 1;
		}
		else if(x == a[mid]){
			return mid;
		}
		else{
			return -1;
		}

	}
}