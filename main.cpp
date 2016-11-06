#include "Binary_Search_Tree.hpp"

int main(){
	BinarySearchTree<double> bst(1.2);
	Node<double> node1(0.8);
	Node<double> node2(1.9);
	Node<double> node3(0.7);
	Node<double> node4(1.0);
	Node<double> node5(1.8);
	bst.Insert(&node1);
	bst.Insert(&node2);
	bst.Insert(&node3);
	bst.Insert(&node4);
	bst.Insert(&node5);
	bst.Print();
	bst.Delete();
	bst.Delete();
	std::cout<<"\nPrint out Again\n";
	bst.Print();
	return 0;
}