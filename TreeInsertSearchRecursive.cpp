#include <iostream>
using namespace std;

// Structure of Tree
struct TreeNode{
	int data;
	TreeNode* tNodeLft;
	TreeNode* tNodeRt;
};

// Create new Node of Tree
TreeNode* getNewNode(int data){
	TreeNode* newNode = new TreeNode();
	newNode->data = data;
	newNode->tNodeLft = NULL;
	newNode->tNodeRt = NULL;
	return newNode;
}

// insertNode New node in tree
TreeNode* insertNode(TreeNode* rootNode, int data){
	TreeNode* newNode = getNewNode(data);
	if(rootNode == NULL){
		rootNode = newNode;
		return rootNode;
	}
	else if(data<=rootNode->data){
		rootNode->tNodeLft = insertNode(rootNode->tNodeLft, data);
		return rootNode;
	}
	else{
		rootNode->tNodeRt = insertNode(rootNode->tNodeRt, data);
		return rootNode;
	}

}

// Search node in tree
bool searchNode(TreeNode* root, int data){
	
	if(root == NULL){
	    return false;
	}

	if(data == root->data)
		return true;
	else if(data<=root->data)
		return searchNode(root->tNodeLft, data);
	else
		return searchNode(root->tNodeRt, data);

}


int main() {
    
	TreeNode* root = NULL;
	root = insertNode(root, 15);
	root = insertNode(root, 10);
	root = insertNode(root, 5);
	root = insertNode(root, 25);
	root = insertNode(root, 30);
	root = insertNode(root, 13);
	root = insertNode(root, 22);

	cout<<searchNode(root, 23)<<endl;
	cout<<searchNode(root, 5)<<endl;

	return 0;
}
