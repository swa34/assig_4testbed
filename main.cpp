#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
  BinaryTree<int> intList;
  BinaryTree<float> dbList;
  BinaryTree<string> stringList;
  char input;
  int fileInput;
  cout << "Enter list type (i - int, f - float, s - std::string):";
  cin >> input;
  // cout << "Test line " << input << endl;
  if (input == 'i') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\ass4testbed\int-input1)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	int n;
	while (fs >> n) {
	  //arr.push_back(n);
	  intList.insert(n);
	}
	//intList.print();
	fs.close();
	cout << "Commands: \n" << "insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
							  "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
	cout << endl;
	bool loop = true;
	char character; // character input when entering a command

	while (loop) {
	  cout << "\nEnter a command: ";
	  cin >> character;
	  //cout << "\n";

	  switch (character) {
		case 'i': {
		  cout << "Item to insert: ";
		  int number;
		  cin >> number;
		  intList.insert(number);
		  cout << endl;
		  cout << "In-Order: ";
		  intList.inOrder();
		  break;
		}
		case 'd': {
		  cout << "Item to delete: ";
		  int value;
		  cin >> value;
		  intList.deleteItem(value);
		  cout << "In-Order: ";
		  intList.inOrder();
		  cout << endl;
		  break;
		}
		case 'l': {
		  cout << "Tree length: " << intList.getLength();
		  cout << endl;
		  break;
		}
		case 'p': {
		  cout << "Pre-order: ";
		  intList.preOrder();
		  cout << endl;
		  break;
		}
		case 'n': {
		  cout << "In-Order: ";
		  intList.inOrder();
		  cout << endl;
		  break;
		}
		case 'r': {
		  cout << "Item to be retrieved: ";
		  int item;
		  cin >> item;
		  bool found = false;
		  intList.retrieve(item, found);
		  cout << endl;
		  break;

		}
		case 's': {
		  cout << "Number of single Parents: " << intList.getNumSingleParent();
		  cout << endl;
		  break;
		}

		case 'f': {

		  cout << "Number of leaf nodes: " << intList.getNumLeafNodes();

		  break;
		}
		case 't': {
		  cout << "Item to get sum of subtrees: ";
		  int num;
		  cin >> num;
//		 // intList.FindNode(num);
		  //  cout << "node there: " << intList.searchNode(num)<< endl;

		  intList.getSumOfSubtrees(num);
		  cout << endl;
		  break;
		}
		case 'o': {
		  cout << "Post-Order: ";
		  intList.postOrder();
		  break;
		}
		case 'q': { // quit command that stops the while loop and exits the program
		  cout << "Quitting program..." << endl;
		  loop = false;
		  break;
		}
		default: { // this will print when the command is invalid
		  cout << "Command not recognized. Try again" << endl;
		  break;
		}

	  }
	}
	///*** FLOAT START***//
  } else if (input == 'f') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\ass4testbed\float-input1)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file

	string input="";
	while (getline(fs, input)) {
	  //arr.push_back(n);
	  istringstream iss(input);
	  float n;
	  while(iss>>n){
		dbList.insert(n);
	  }
	}
	//dbList.print();
	fs.close();
	cout << "Commands: \n" << "insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
							  "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
	bool loop = true;
	char character; // character input when entering a command

	while (loop) {
	  cout << "\nEnter a command: ";
	  cin >> character;
	 // cout << "\n";

	  switch (character) {
		case 'i': {
		  cout << "Item to insert: ";
		  float number;
		  cin >> number;
		  dbList.insert(number);
		  cout << endl;
		  cout << "In-Order: ";
		  dbList.inOrder();
		  break;
		}
		case 'd': {
		  cout << "Item to delete: ";
		  float value;
		  cin >> value;
		  dbList.deleteItem(value);
		  cout << "In-Order: ";
		  dbList.inOrder();
		  cout << endl;
		  break;
		}
		case 'l': {
		  cout << "Tree length: " << dbList.getLength();
		  cout << endl;
		  break;
		}
		case 'p': {
		  cout << "Pre-order: ";
		  dbList.preOrder();
		  cout << endl;
		  break;
		}
		case 'n': {
		  cout << "In-Order: ";
		  dbList.inOrder();
		  cout << endl;
		  break;
		}
		case 'r': {
		  dbList.inOrder();
		  cout << "Item to be retrieved: ";
		  float item;
		  cin >> item;
		  bool found = false;
		  dbList.retrieve(item, found);
		  cout << endl;
		  break;

		}
		case 's': {
		  cout << "Number of single Parents: " << dbList.getNumSingleParent();
		  cout << endl;
		  break;
		}

		case 'f': {

		  cout << "Number of leaf nodes: " << dbList.getNumLeafNodes();

		  break;
		}
		case 't': {
		  cout << "Item to get sum of subtrees: ";
		  float num;
		  cin >> num;
//		 // dblist.FindNode(num);
		  //  cout << "node there: " << intList.searchNode(num)<< endl;

		  dbList.getSumOfSubtrees(num);
		  cout << endl;
		  break;
		}
		case 'o': {
		  dbList.postOrder();
		  cout << endl;
		  break;
		}
		case 'z': {
		  dbList.inOrder();
		  cout << "Item to do it: ";
		  cout << endl;

		  float number;
		  cin >> number;
		  dbList.PrintChildren(number);
		  break;
		}

		case 'q': { // quit command that stops the while loop and exits the program
		  cout << "Quitting program..." << endl;
		  loop = false;
		  break;
		}
		default: { // this will print when the command is invalid
		  cout << "Invalid command, try again!" << endl;
		  break;
		}

	  }
	}
	///*** STRING START***//
  } else if (input == 's') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\ass4testbed\string-input1)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file

	string input="";
	while (getline(fs, input)) {
	  //arr.push_back(n);
	  istringstream iss(input);
	  string n;
	  while(iss>>n){
		stringList.insert(n);
	  }
	}
	//stringlist.print();
	fs.close();
	cout << "Commands: \n" << "insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
							  "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
	bool loop = true;
	char character; // character input when entering a command

	while (loop) {
	  cout << "\nEnter a command: ";
	  cin >> character;
	  // cout << "\n";

	  switch (character) {
		case 'i': {
		  cout << "Item to insert: ";
		  string number;
		  cin >> number;
		  stringList.insert(number);
		  cout << endl;
		  cout << "In-Order: ";
		  stringList.inOrder();
		  break;
		}
		case 'd': {
		  cout << "Item to delete: ";
		  string value;
		  cin >> value;
		  stringList.deleteItem(value);
		  cout << "In-Order: ";
		  stringList.inOrder();
		  cout << endl;
		  break;
		}
		case 'l': {
		  cout << "Tree length: " << stringList.getLength();
		  cout << endl;
		  break;
		}
		case 'p': {
		  cout << "Pre-order: ";
		  stringList.preOrder();
		  cout << endl;
		  break;
		}
		case 'n': {
		  cout << "In-Order: ";
		  stringList.inOrder();
		  cout << endl;
		  break;
		}
		case 'r': {
		  stringList.inOrder();
		  cout << "Item to be retrieved: ";
		  string item;
		  cin >> item;
		  bool found = false;
		  stringList.retrieve(item, found);
		  cout << endl;
		  break;

		}
		case 's': {
		  cout << "Number of single Parents: " << stringList.getNumSingleParent();
		  cout << endl;
		  break;
		}

		case 'f': {

		  cout << "Number of leaf nodes: " << stringList.getNumLeafNodes();

		  break;
		}
		case 't': {
		  cout << "Item to get sum of subtrees: ";
		  string num;
		  cin >> num;
//		 // stringList.FindNode(num);
		  //  cout << "node there: " << intList.searchNode(num)<< endl;

		  stringList.getSumOfSubtrees(num);
		  cout << endl;
		  break;
		}
		case 'o': {
		  stringList.postOrder();
		  cout << endl;
		  break;
		}
		case 'z': {
		  stringList.inOrder();
		  cout << "Item to do it: ";
		  cout << endl;

		  string number;
		  cin >> number;
		  stringList.PrintChildren(number);
		  break;
		}

		case 'q': { // quit command that stops the while loop and exits the program
		  cout << "Quitting program..." << endl;
		  loop = false;
		  break;
		}
		default: { // this will print when the command is invalid
		  cout << "Invalid command, try again!" << endl;
		  break;
		}

	  }
	}

  } else {
	cout << "Invalid entry";
  }
}

