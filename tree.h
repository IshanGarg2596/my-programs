//node defination
struct node{
	int key;
	struct node* parent; 
	struct node* left;
	struct node* right;
};

//define binary search tree, related function
class Tree{
	struct node* currentparent;
public:
	struct node* root;

	Tree(){
		root = NULL;
	}

	//inserts node into the tree
	void insert(int data);
	void inorder_traversal(struct node* x);

};

void Tree::insert(int data) {
	struct node* temp = new node;
	temp->key = data;
	temp->right = NULL;
	temp->left = NULL;


	struct node* y = NULL;
	struct node* x = root;

	while (x != NULL) {
		y = x;
		if (temp->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	temp->parent = y;

	if (y == NULL) {
		root = temp;
	}
	else if (temp->key < y->key)
		y->left = temp;
	else
		y->right = temp;
	
}

void Tree::inorder_traversal(struct node* x) {
	if (x != NULL) {
		inorder_traversal(x->left);
		std::cout << x->key<<" ";
		inorder_traversal(x->right);
	}
}
