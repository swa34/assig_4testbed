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

 public:
  BinaryTree();
  ~BinaryTree();
  void clear(NodeType<T> *node);
  void insert(T &key);

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
  void initialize(T number);
  int getNumSingleParent();
  int getNumSingleParent(NodeType<T> *node);
  int getNumLeafNodes();
  int countLeaves(NodeType<T>* node);
  T getSumOfSubtrees( T &key);

 private:
  int length;
  T value;

};
#endif //ASS4TESTBED_BINARYTREE_H
