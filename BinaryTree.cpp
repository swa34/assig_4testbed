//
// Created by scott on 10/27/2021.
//
#include<iostream>
#include <string>
#include "BinaryTree.h"
#include <queue>
using namespace std;

//creating a BinaryTree
template<class T>
BinaryTree<T>::BinaryTree() {
  root = nullptr;
  length = 0;
}

//destructor
template<class T>
BinaryTree<T>::~BinaryTree() {
  clear(root);
}

template<class T>
void BinaryTree<T>::clear(NodeType<T> *node) {
  if (node == nullptr)
	return;

  clear(node->left); // left subtree
  clear(node->right); // right subtree
  delete node;
}
template<class T>
NodeType<T> *BinaryTree<T>::initialize(T item) {
  NodeType<T> *node = new NodeType<T>;
  node->key = item;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}
//deleting a number/node from a BinaryTree
template<class T>
void BinaryTree<T>::deleteItem(T key) {
  searchAndDelete(root, key);
}

template<class T>
bool BinaryTree<T>::searchAndDelete(NodeType<T> *&node, T key) {
  if (node == nullptr) { // item does not exist
	cout << "\nItem not in tree." << endl;
	return false;
  }
	//found the node, now delete it
  else if (key == node->key) {
	deleteNode(node);
	return true;
  } else {
	if (key < node->key)
	  searchAndDelete(node->left, key);

	else if (key > node->key)
	  searchAndDelete(node->right, key);
  }
  return false;
}
template<class T>
void BinaryTree<T>::deleteNode(NodeType<T> *&targetNode) {
  NodeType<T> *temp = targetNode;

  // targetNode has two children
  if (targetNode->left != nullptr && targetNode->right != nullptr) {
	T predecessorItem = getPredecessor(targetNode->left);
	targetNode->key = predecessorItem;
	searchAndDelete(targetNode->left, predecessorItem);
  }

	// targetNode has one child
  else if (targetNode->left != nullptr) {
	targetNode = targetNode->left;

	delete temp;
  }

	// targetNode has one child
  else if (targetNode->right != nullptr) {
	targetNode = targetNode->right;

	delete temp;
  }

	// targetNode has no children
  else {
	targetNode = nullptr;

	delete temp;
  }
}

template<class T>
T BinaryTree<T>::getPredecessor(NodeType<T> *&node) const {
  // keep going right until we get to null
  if (node->right == nullptr)
	return node->key;
  else
	return getPredecessor(node->right);
}

//retrieving a node/number from a binaryTree
template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {
  struct NodeType<T> *node = new struct NodeType<T>;
  struct NodeType<T> *t = root;
  node->key = item;
  found = false;
  if (root == nullptr) {
	cout << "You can not retrieve from an empty tree.";
	return;
  } else {
	while (t != nullptr) {
	  if (node->key < t->key) {
		t = t->left;
	  } else if (node->key > t->key) {
		t = t->right;
	  } else {
		found = true;
		cout << "Item found in tree.";
		return;
	  }
	  //cout<<"Item found in tree";
	}
	if (t == nullptr) {
	  //key not in the tree
	  found = false;
	  cout << "Item not in tree.";
	  cout << endl;
	  return;
	}

  }
}

//traversing the tree preOrderly
template<class T>
void BinaryTree<T>::preOrderTraversal(NodeType<T> *node) const {
  if (node != NULL) {
	cout << node->key << " ";;
	preOrderTraversal(node->left);
	preOrderTraversal(node->right);
  }
}

//using the preOrderTraversal method to traverse the tree
template<class T>
void BinaryTree<T>::preOrder() const {
  preOrderTraversal(root);
}

//traversing the tree inOrderly
template<class T>
void BinaryTree<T>::inOrderTraversal(NodeType<T> *node) const {
  if (node != NULL) {
	inOrderTraversal(node->left);
	cout << node->key << " ";
	inOrderTraversal(node->right);
  }
}

//using the inOrderTraversal method to traverse the tree
template<class T>
void BinaryTree<T>::inOrder() const {
  inOrderTraversal(root);
  cout << endl;
}

//traversing the tree postOrderly
template<class T>
void BinaryTree<T>::postOrderTraversal(NodeType<T> *node) const {
  if (node != NULL) {
	postOrderTraversal(node->left);
	postOrderTraversal(node->right);
	cout << node->key << " ";
  }
}

//using the postOrderTraversal method to traverse the tree
template<class T>
void BinaryTree<T>::postOrder() const {
  postOrderTraversal(root);
  cout << endl;
}

template<class T>
int BinaryTree<T>::getLength() const {
  return calculateLength(root);
}

template<class T>
int BinaryTree<T>::calculateLength(NodeType<T> *node) const {
  if (node == nullptr) {
	return 0;
  }
  return calculateLength(node->left) + calculateLength(node->right) + 1;

}

//prints the number of leaf nodes in the tree
template<class T>
int BinaryTree<T>::getNumLeafNodes() {
  int lcount = 0;
  lcount = countLeaves(root);
  return lcount;
}
template<class T>
int BinaryTree<T>::countLeaves(NodeType<T> *node) {
  static int lcount = 0;
  if (node) {
	if (node->left == NULL && node->right == NULL) {
	  lcount++;
	}
	countLeaves(node->left);
	countLeaves(node->right);
  }
  return lcount;
}
template<class T>
int BinaryTree<T>::getNumSingleParent() {
  return getNumSingleParent(root);
}
template<class T>
int BinaryTree<T>::getNumSingleParent(NodeType<T> *node) {
  if (node == nullptr) {
	return 0;
  } else {
	return (((node->left == NULL && node->right != NULL) ||
		(node->left != NULL && node->right == NULL)) ? 1 : 0) + getNumSingleParent(node->left)
		+ getNumSingleParent(node->right);
  }

}

template<class T>
T BinaryTree<T>::getSumOfSubtrees(T &item) {
  NodeType<T> *node = ReturnNode(item);
  T sum = NULL;
  node->key = item;
  if (ReturnNode(item)) {
	sum = node->left->key + node->right->key;
	//cout << node->right->key<<endl;
	cout << "Sum of Subtrees: " << sum << endl;
	return sum;
  } else if (!(ReturnNode(item))) {
	cout << "Item not found in tree.";
	return 0;
  }

}

template<class T>
NodeType<T> *BinaryTree<T>::ReturnNode(T item) {
  return ReturnNodePrivate(item, root);

}
template<class T>
NodeType<T> *BinaryTree<T>::ReturnNodePrivate(T item, NodeType<T> *node) {
  if (item == node->key) {
	return node;
  } else if (item < node->key) {
	return ReturnNodePrivate(item, node->left);
  } else {
	return ReturnNodePrivate(item, node->right);
  }
}
//Helper to test by printing children of parent entered
template<class T>
void BinaryTree<T>::PrintChildren(T item) {
  NodeType<T> *node = ReturnNode(item);
  if (node->left) {
	cout << node->left->key << endl;
  }
  if (node->right) {
	cout << node->right->key << endl;
  }
}
template<class T>
void BinaryTree<T>::insert(T item) {
  insertsPrivate(item, root);
}
//inserting a number/node into a binary tree
template<class T>
void BinaryTree<T>::insertsPrivate(T item, NodeType<T> *node) {

  if (root == NULL) {
	root = initialize(item);

  } else if (item < node->key) {

	if (node->left != NULL) {
	  insertsPrivate(item, node->left);
	} else {
	  node->left = initialize(item);
	}
  } else if (item > node->key) {

	if (node->right != NULL) {
	  insertsPrivate(item, node->right);
	} else {
	  node->right = initialize(item);
	}
  } else {
	cout << "Item already in tree." << endl;
  }
}

template
class BinaryTree<int>;
template
class BinaryTree<float>;
template
class BinaryTree<string>;

