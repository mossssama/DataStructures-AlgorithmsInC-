#include <iostream>
using namespace std;

struct binaryNode { int data;    binaryNode* left;    binaryNode* right; };

class BST {
private:    binaryNode* root;
public:
	BST() { root = NULL; }

	binaryNode* makeNewNode(int val){
		binaryNode* temp = new binaryNode;
		temp->data = val;   temp->left = NULL;   temp->right = NULL;
		return temp;
	}

	void recInsert(binaryNode* ptr,int val){
		if (val < ptr->data) {
			if (ptr->left == NULL) { ptr->left = makeNewNode(val); }
			else { recInsert(ptr->left, val); }
		}
		else if (val>ptr->data){
			if (ptr->right == NULL) { ptr->right = makeNewNode(val); }
			else { recInsert(ptr->right, val); }
		}
	}
	void insert(int val){
		if (root == NULL) { root = makeNewNode(val); }
		else recInsert(root, val);
	}

	int recSearch(binaryNode* ptr, int val) {
		if (val==ptr->data) { return 1; }
		else if (val<ptr->data){
			if (ptr->left == NULL)    {return 0; }
			else                     { recSearch(ptr->left, val); }
			}
		else if (val>ptr->data){
			if (ptr->right == NULL)  { return 0; }
			else                     { recSearch(ptr->right, val); }
		}
	}
	int search(int val){
		if (root == NULL) { return -1; }
		recSearch(root, val);
	}

	binaryNode* minValueNode(binaryNode* ptr){
		while (ptr && ptr->left != NULL) { ptr = ptr->left; }
		return ptr;
	}
	binaryNode* deleteNode(binaryNode* ptr, int val) {
		if (ptr == NULL) return NULL;

		else if (val < ptr->data)      { ptr->left = deleteNode(ptr->left, val); }
		else if (val > ptr->data) { ptr->right = deleteNode(ptr->right, val); }
		else {
			if (ptr->left == NULL && ptr->right == NULL)  return NULL;
			else if (ptr->left == NULL) { binaryNode* temp = ptr->right; delete ptr; return temp; }
			else if (ptr->right == NULL) { binaryNode* temp = ptr->left; delete ptr; return temp; }
			binaryNode* temp = minValueNode(ptr->right);
			ptr->data = temp->data;
			ptr->right= deleteNode(ptr->right, temp->data);
		}
		return ptr;
	}

	void recBFS(binaryNode* ptr,int line) {
		if (ptr == NULL) return;
	    else if (line == 0) { cout << ptr->data<<" "; }
		else { recBFS(ptr->left, line - 1);  recBFS(ptr->right, line - 1); }
	}
	void printBFS(binaryNode* ptr) {
		for (int i = 0; i <= treeHeight(ptr); i++) { recBFS(ptr, i); }
	}

	int treeHeight(binaryNode* ptr){
		if (ptr == NULL)  return -1;
		else {
			int lheight = treeHeight(ptr->left);    int rheight = treeHeight(ptr->right);
			if (lheight > rheight) { return (lheight + 1); }
			else  { return (rheight + 1); }
		}
	}
	void getTreeHeight(binaryNode* ptr) {
		int height = treeHeight(ptr)+1;
		cout << "BST height is: "<<height<<endl;
	}
	void printPreOrder(binaryNode* ptr) { if (ptr == NULL) return; cout << ptr->data << " ";         printPreOrder(ptr->left);      printPreOrder(ptr->right); }
	void printInOrder(binaryNode* ptr)  { if (ptr == NULL) return; printInOrder(ptr->left);          cout << ptr->data << " ";      printInOrder(ptr->right);  }
	void printPostOrder(binaryNode* ptr){ if (ptr == NULL) return; printPostOrder(ptr->left);        printPostOrder(ptr->right);    cout << ptr->data << " "; }

	binaryNode* getRoot() { return root; }
};
int main() {
	BST b1;

	b1.insert(1);   b1.insert(18);   b1.insert(20);  b1.insert(22);
	b1.insert(13);  b1.insert(12);   b1.insert(99);  b1.insert(0);


	cout << "DFS(preorder):[ ";  b1.printPreOrder(b1.getRoot());    cout << "]\n";
	cout << "DFS(inorder):[ ";   b1.printInOrder(b1.getRoot());     cout <<"]\n";
	cout << "DFS(postorder):[ "; b1.printPostOrder(b1.getRoot());   cout << "]\n";
	cout << "BFS:[ "; b1.printBFS(b1.getRoot());   cout << "]\n";

	b1.deleteNode(b1.getRoot(), 18);
	b1.getTreeHeight(b1.getRoot());

	cout << "\t**********18 is deleted***********\n";

	cout << "DFS(preorder):[ ";  b1.printPreOrder(b1.getRoot());    cout << "]\n";
	cout << "DFS(inorder):[ ";   b1.printInOrder(b1.getRoot());     cout << "]\n";
	cout << "DFS(postorder):[ "; b1.printPostOrder(b1.getRoot());   cout << "]\n";
	cout << "BFS:[ "; b1.printBFS(b1.getRoot());   cout << "]\n";

	b1.getTreeHeight(b1.getRoot());
}