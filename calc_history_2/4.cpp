#include<iostream>
using namespace std;
struct node{
	int key;
	node *right;
	node *left;
	
};

node* add_new(int key){
	node *new_node = new node;
	new_node->key = key;
	new_node->right = NULL;
	new_node->left = NULL;
	return new_node;
}

node* traverse(node *node1){
	if(node1->right == NULL && node1->left == NULL){
		cout<<node1->key<<endl;
		return NULL;
	}else if(node1->right == NULL){
	cout<<node1->key<<endl;
		return node1->left;
}else if(node1->left == NULL){
	cout<<node1->key<<endl;
		return node1->right;
}
traverse()
}

int main(){
	node *head = add_new(10);
	head->left = add_new(20);
	
}
