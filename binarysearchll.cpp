#include <iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prev; 
};

class linkedlist
{
	struct node* List;
public:	
	linkedlist(){
		List = NULL;
	};

	void insert(int data){
		struct node* temp = new node;
		temp->data = data;
		if(List == NULL){
			List = temp;
			List->next = NULL;
			List->prev = NULL;
		} 
		else{
			temp->next = List;
			temp->prev = NULL;
			List->prev = temp;
			List = temp;
		}
	}

	void selectionsort(){
		//implements selection sort on linked list
		struct node* i = List;
		struct node* j = List;
		struct node* min = List;
    	while(i->next != NULL){
			while(j->next != NULL){
				if(j->data < i->data){
					min = j;
				}
				j = j->next;
			}
			int temp = min-> data;
			min->data = List->data;
			List->data = temp;  
			i = i->next;
		}


	}

	struct node* middlenode(struct node* head,struct node* tail){
		if(List == NULL){
			return NULL;
		}
		struct node* ptr1 = head;
		struct node* ptr2 = head->next;

		while(ptr2 != tail){
			ptr2 = ptr2->next;
			if(ptr2 != tail){
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
		}
		return ptr1;
	}

	struct node* binarysearch(int x){
		struct node* sn = List;
		struct node* en = NULL;

		do
		 {
		 	struct node* middle  = middlenode(sn,en);
		 	if (middle == NULL)
		 	{
		 		return NULL;
			}
			if(middle->data == x){
				return middle;
			}
			else if(middle->data < x){
				sn = middle->next;
			}
			else{
				en = middle;
			}
		 } while (en == NULL || en->next != sn); 
		 return NULL;
	}


	void printlist(){
		struct node* element = List;
		while(element->next != NULL){
			cout<<element->data<<"  ";
			element = element->next;
		}
		cout<<element->data;
	}

	~linkedlist(){
		delete []List;
	}
};

int main(){
	linkedlist L;
	int e,n;
	cout<<"Enter number of elements to be added in linkedlist";
	cin>>n;
	cout<<"Enter"<<n<<"elements of list:";
	for(int i=0;i<n;i++){
		cin>>e; 
		L.insert(e);
	}
	L.selectionsort();
	int x;
	cout<<"Enter number to be searched for:";
	cin>>x;
	struct node* result = L.binarysearch(x);
	if(result == NULL){
		cout<<"number not found"<<"\n";
	}
	else{
		cout<<"number found "<<result->data<<"\n";
	}
	L.printlist();
	return 0;
}