#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

template <class T> class BinaryTree {
	private:

		struct node {
			node *left, *right;
			T data;

			node () : left(NULL), right(NULL) {}
			node (T x) : left(NULL), right(NULL), data(x) {}

		};

		node *root;
		size_t size = 0;		
	
		void p_add (node*& cur, T x);		
		bool p_find (node* cur, T x);

	public:
		
		void add (T x);
		bool find (T x);
		size_t getSize () { return size; }

};

template <class T> void BinaryTree <T> :: p_add (node*& cur, T x) {
	if (!cur) {
		cur = new node (x);
		return;
	}	
	if (x < cur->data) {
		if (!cur->left)
			cur->left = new node (x);
		else
			p_add (cur->left, x);	
	} 
	else if (x > cur->data) {
		if (!cur->right)
			cur->right = new node (x);
		else
			p_add (cur->right, x);
	}
}

template <class T> bool BinaryTree <T> :: p_find (node* cur, T x) {
	if (!cur)
		return false;
	if (x < cur->data) {
		if (!cur->left)
			return false;
		return p_find (cur->left, x);	
	} 
	else if (x > cur->data) {
		if (!cur->right)
			return false;
		return p_find (cur->right, x);
	}
	return true;
}

template <class T> void BinaryTree <T> :: add (T x) {
	size++;
	p_add (root, x);
}

template <class T> bool BinaryTree <T> :: find (T x) {
	return p_find (root, x);
}



int main () {

	srand ((unsigned long long)time(0));
	
	BinaryTree <int> myTree;

	int n = 100;

	for (int i = 0; i < n; i++)
		myTree.add (rand());	
	
	return 0;
}

