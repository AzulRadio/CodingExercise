#include "queue.h"

#ifndef AVLTREE_H
#define AVLTREE_H

using std::string;
using std::cout;
using std::endl;

template <class K, class V> 
struct treeNode {
	K key;
	V value;
	int height;
	treeNode * left;
	treeNode * right;
};

template <class K, class V>
class AvlTree {
	public:
	AvlTree();
	void printTree();
	void insert(const K &, const V &);
	treeNode<K,V> search(K);
	private:
	treeNode<K,V> * root;
	void leftRotate(treeNode<K,V> *&);
	void rightRotate(treeNode<K,V> *&);
	void printTree(treeNode<K,V> *, Queue<treeNode<K,V> *> &);
	void insert(treeNode<K,V>* &, const K &, const V &);
	int balanceFactor(treeNode<K,V> * &);
	void updateHeight (treeNode<K, V> * &);
};

template <class K, class V>
AvlTree<K,V>::AvlTree(){
	root = NULL;
}

template <class K, class V>
void AvlTree<K,V>::printTree(){
	Queue<treeNode<K,V>*> q = Queue<treeNode<K,V>*>();
	printTree(root, q);
}

template <class K, class V>
void AvlTree<K,V>::printTree(treeNode<K,V> * curr, Queue<treeNode<K,V> *> & q){
	if (curr == NULL) {
		return;	
	}
	cout << "key: " << curr->key <<" -> value: "<< curr->value << " (height = " << curr->height << ") ";
	cout << endl;
	if(curr->left != NULL) {
		q.enqueue(curr->left);
	}
	if(curr->right != NULL) {
		q.enqueue(curr->right);
	}
	printTree(q.dequeue(), q);
}

template <class K, class V>
void AvlTree<K,V>::insert(const K & key, const V & value){
	insert(root, key, value);
}

template <class K, class V>
void AvlTree<K,V>::insert(treeNode<K,V>* & curr, const K & k, const V & v){
	if (curr == NULL) {
		curr = new treeNode<K,V>;
		curr->key = k;
		curr->value = v;
		curr->height = 0;
	} else if (k < curr->key) {
		insert(curr->left, k, v);	
	} else if (k > curr->key) {
		insert(curr->right, k ,v);	
	} else if (k == curr->key) {
		curr->value = v;
	}

	updateHeight(curr);

	if (balanceFactor(curr) >= 2 && balanceFactor(curr->right) > 0) {
		leftRotate(curr);
		return;
	}
	if (balanceFactor(curr) <= -2 && balanceFactor(curr->left) < 0) {
		rightRotate(curr);
		return;
	}
	if (balanceFactor(curr) >= 2 && balanceFactor(curr->right) < 0) {
		rightRotate(curr->right);
		leftRotate(curr);
		return;
	}
	if (balanceFactor(curr) <= -2 && balanceFactor(curr->left) > 0) {
		leftRotate(curr->left);
		rightRotate(curr);
		return;
	}
}

template <class K, class V>
int AvlTree<K,V>::balanceFactor(treeNode<K,V>* & curr) {
	int balanceFactor;
	if (curr == NULL || (curr->left == NULL && curr->right == NULL) ) {
		return 0;	
	}
	if (curr->left == NULL && curr-> right != NULL) {
		return curr->right->height + 1;
	}
	if (curr->left != NULL && curr-> right == NULL) {
		return 0 - (curr->left->height + 1);
	}
	return curr->right->height - curr->left->height;
}

template <class K, class V>
void AvlTree<K,V>::updateHeight (treeNode<K, V> * & curr) {
	if (curr->left == NULL && curr->right == NULL) {
		curr->height = 0;
		return;
	}
	if (curr->left == NULL && curr->right != NULL) {
		curr->height = curr->right->height + 1;
		return;
	}
	if (curr->left != NULL && curr->right == NULL) {
		curr->height = curr->left->height + 1;	
		return;
	}
	if (curr->left->height > curr->right->height) {
		curr->height = curr->left->height + 1;
		return;
	}  
	curr->height = curr->right->height + 1;
}

template <class K, class V>
void AvlTree<K,V>::leftRotate(treeNode<K,V> * & curr) {
	treeNode<K,V> * temp = curr->right;
	curr->right = temp->left;
	temp->left = curr;
	curr = temp;

	updateHeight(curr->left);
	updateHeight(curr->right);
	updateHeight(curr);
}

template <class K, class V>
void AvlTree<K,V>::rightRotate(treeNode<K,V> * & curr) {
	treeNode<K,V> * temp = curr->left;
	curr->left = temp->right;
	temp->right = curr;
	curr = temp;
	updateHeight(curr->left);
	updateHeight(curr->right);
	updateHeight(curr);
}

#endif

