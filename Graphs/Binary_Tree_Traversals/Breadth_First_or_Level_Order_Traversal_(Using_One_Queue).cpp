/*
Sonali Singh
Time complexity: O(n)
*/

#include <bits/stdc++.h> 
using namespace std; 

/* Structure for a node */
struct node{ 
	int data; 
	struct node *left;
	struct node *right; 
}; 

/* Function to create a new node */
struct node *newNode(int data){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
};

/* Function to insert a node in the tree */
void insert_node(struct node *root, int n1, int n2, char lr){
    if(root == NULL)
    return;
    if(root -> data == n1){
        switch(lr){
            case 'l' : root -> left = newNode(n2);
            break;
            case 'r' : root -> right = newNode(n2);
            break;
        }
    }
    else{
        insert_node(root -> left, n1, n2, lr);
        insert_node(root -> right, n1, n2, lr);
    }
}

/* Function to print the level order traversal of the tree */
void LevelOrder(node *root){ 
	// Base Case 
	if (root == NULL) 
	    return; 

	// Create an empty queue for level order traversal 
	queue<node *> q; 
	
	// to store front element of queue 
	node *curr;
	
	// enqueue Root 
	q.push(root); 

	while (!q.empty()){ 
	    
		// Print front of queue and remove it from queue 
		curr = q.front(); 
		cout << curr->data << " "; 
		q.pop(); 

		// enqueue left child 
		if (curr->left != NULL) 
			q.push(curr->left); 

		// enqueue right child 
		if (curr->right != NULL) 
			q.push(curr->right); 
	} 
} 

int main() { 
	struct node *root = NULL;
    int n;
    cout<<"Enter the number of edges : ";
    cin>>n;
    cout<<n<<"\n";
    cout<<"Input the nodes of the binary tree in order \nparent-child-left(or)right-\n";
    while(n--){
        char lr;
        int n1,n2;
        cin>>n1>>n2>>lr;
        cout<<n1<<" "<<n2<<" "<<lr<<"\n";
        if(root == NULL){
            root = newNode(n1);
            switch(lr){
                case 'l' :root -> left = newNode(n2);
                break;
                case 'r' : root -> right = newNode(n2);
                break;
            }
        }
        else{
            insert_node(root,n1,n2,lr);
        }
    }

	cout << "\nLevel Order traversal: \n"; 
	LevelOrder(root); 
	return 0; 
} 


/*                               
Enter the number of edges : 8                                                                        1
Input the nodes of the binary tree in order                                                         / \
parent-child-left(or)right-                                                                        2   3
1 2 l                                                                                             / \   \
2 4 l                                                                                            4   5   6
4 7 l                                                                                           /         \
7 9 r                                                                                          7           8
2 5 r                                                                                           \
1 3 r                                                                                            9
3 6 r
6 8 r

Level Order traversal: 
1 2 3 4 5 6 7 8 9  
*/
