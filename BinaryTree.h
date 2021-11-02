//
// Created by scott on 10/27/2021.
//

#ifndef ASS4TESTBED_BINARYTREE_H
#define ASS4TESTBED_BINARYTREE_H
using namespace std;

template<class T>
struct NodeType {
  T key;
  T data;
  NodeType<T> *left;
  NodeType<T> *right;

};

template<class T>
class BinaryTree {
  struct NodeType<T> *root;
  NodeType<T> *root2;

 public:
  BinaryTree();
  ~BinaryTree();
  void clear(NodeType<T> *node);
  NodeType<T>*  initialize(T number);
  void deleteItem(T key);
  void deleteNode(NodeType<T> *&targetNode);
  T getPredecessor(NodeType<T> *&node) const;
  bool searchAndDelete(NodeType<T> *&node, T key);
  void retrieve(T &item, bool &found) const;
  void preOrderTraversal(NodeType<T> *node) const;
  void preOrder() const;
  void inOrderTraversal(NodeType<T> *node) const;
  void inOrder() const;
  void postOrderTraversal(NodeType<T> *node) const;
  void postOrder() const;
  int getLength() const;
  int calculateLength(NodeType<T> *node) const;
  int getNumSingleParent();
  int getNumSingleParent(NodeType<T> *node);
  int getNumLeafNodes();
  int countLeaves(NodeType<T>* node);
  T getSumOfSubtrees( T &item);
  T getSumOfSubtree();
  NodeType<T>* ReturnNode(T item);
  void PrintChildren(T item);
  void inserts(T &key);
void insert(T item);

 bool searchNode(T item);

 private:
  int length;
  T value;
  NodeType<T>* ReturnNodePrivate(T item,NodeType<T>* node);
  void insertsPrivate(T item,NodeType<T>* node);
};
#endif //ASS4TESTBED_BINARYTREE_H
