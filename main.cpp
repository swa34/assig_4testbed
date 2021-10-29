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
	  cout << "\n";

	  switch (character) {
		case 'i': {
		  intList.inOrder();
		  cout << "Item to insert: ";
		  cout << endl;

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

		  cout<< "Number of leaf nodes: " << intList.getNumLeafNodes();

		  break;
		}
		case 't': {
		  cout << "Item to get sum of subtrees: ";
		  cout << endl;

		  int num;
		  cin >> num;
		  cout << "Sum of Subtrees: " << intList.getSumOfSubtrees(num);

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
  } else if (input == 'f') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\Allen_assignment3\float-input)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	float n;
	while (fs >> n) {
	  //arr.push_back(n);
	  dbList.initialize(n);
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
	  cout << "\n";

	  switch (character) {
		case 'i': {
		  dbList.inOrder();
		  cout << "Item to insert: ";
		  cout << endl;

		  float number;
		  cin >> number;
		  dbList.insert(number);

		  cout << "Tree elements: ";
		  cout << endl;
		  dbList.inOrder();
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
		  cout << "Number of single Parents: ";
		  cout << endl;
		  dbList.getNumSingleParent();
		  cout << endl;
		  break;
		}

		case 'f': {

		  dbList.getNumLeafNodes();

		  break;
		}
		case 't': {
		  cout << "Item to get sum of subtrees: ";
		  cout << endl;

		  float num;
		  cin >> num;
		  cout << "Sum of Subtrees: ";
		  //dbList.getSumOfSubtrees(num);
		  cout << endl;
		  break;
		}
		case 'o': {
		  dbList.postOrder();
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
  } else if (input == 's') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\Allen_assignment3\string-input)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	string str;
	while (getline(fs, str)) {
	  //arr.push_back(n);
	  stringList.initialize(str);
	}
	//stringList.print();
	fs.close();
	cout << "Commands: \n" << "insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
							  "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
	bool loop = true;
	char character; // character input when entering a command

	while (loop) {
	  cout << "\nEnter a command: ";
	  cin >> character;
	  cout << "\n";

	  switch (character) {
		case 'i': {
		  dbList.inOrder();
		  cout << "Item to insert: ";
		  cout << endl;

		  float number;
		  cin >> number;
		  dbList.insert(number);

		  cout << "Tree elements: ";
		  cout << endl;
		  dbList.inOrder();
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
		  cout << "Number of single Parents: ";
		  cout << endl;
		  dbList.getNumSingleParent();
		  cout << endl;
		  break;
		}

		case 'f': {

		  dbList.getNumLeafNodes();

		  break;
		}
		case 't': {
		  cout << "Item to get sum of subtrees: ";
		  cout << endl;

		  float num;
		  cin >> num;
		  cout << "Sum of Subtrees: ";
		//  dbList.getSumOfSubtrees(num);
		  cout << endl;
		  break;
		}
		case 'o': {
		  dbList.postOrder();
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

