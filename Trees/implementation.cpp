#include<iostream>
#include<queue>



using namespace std;

class TreeNode{
public: 
	int data;
	TreeNode* left;
	TreeNode * right;

	TreeNode(int data){
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};


TreeNode* buildTrees(TreeNode* root){
	int data;
	cout << "enter data:-";
	cin>> data;
	root = new TreeNode(data);
	if(data==-1) return nullptr;

	cout << "enter left val of: " << data;
	cout << endl;
	root->left = buildTrees(root->left);
	cout << "Enter right val of: " << data;
	cout << endl;
	root->right = buildTrees(root->right);

	return root;
}
void LevelOrderTransversal(TreeNode* root){
	TreeNode * temp = root;

	queue<TreeNode*> q;
	q.push(temp);

	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();

		if(temp->left) q.push(temp);
		if(temp->right) q.push(temp);
	}
}

int main(){

	TreeNode* root = nullptr;

	root = buildTrees(root);

	cout << root->right->data;

	// LevelOrderTransversal(root);
}