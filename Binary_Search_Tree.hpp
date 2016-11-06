//implement Binary_Search_Tree
#include <queue>
#include <iostream>

template<typename T>
class Node{
public:
	T data;
	Node<T>* leftChild;
	Node<T>* rightChild;
	Node(T value): data(value), leftChild(NULL), rightChild(NULL){}
};
template<typename T>
class BinarySearchTree{
private:
	int size;
	Node<T>* root;
public:
	BinarySearchTree(T value):size(1),root(new Node<T>(value)){}
	void Insert(Node<T>* node1){
		T val=node1->data;
		Node<T>* current(root);
		bool has_kid;
		do{
			if(current->data>=val){
				if(current->leftChild) current=current->leftChild;
				else{
					node1->leftChild= NULL;
					node1->rightChild=NULL;
					current->leftChild=node1;
					break;
				}
			}
			else{
				if(current->rightChild) current=current->rightChild;
				else{
					node1->leftChild=NULL;
					node1->rightChild=NULL;
					current->rightChild=node1;
					break;
				}
			}
		} while(true);
	}
	Node<T> Top(){
      return *root;
	}
	void Delete(){
       RecursiveDelete(root);
	}
	Node<T>* RecursiveDelete(Node<T>* currentRoot){
		if(!currentRoot) return NULL;
		if(!currentRoot->leftChild && !currentRoot->rightChild) return NULL;
		if(currentRoot->leftChild){
			currentRoot->data=currentRoot->leftChild->data;
			currentRoot->leftChild=RecursiveDelete(currentRoot->leftChild);
			return currentRoot;
		}	
		currentRoot->data=currentRoot->rightChild->data;
		currentRoot->rightChild=RecursiveDelete(currentRoot->rightChild);
		return currentRoot;
	}
	void Print() const{
       std::queue<Node<T>* > tree_Queue;
       tree_Queue.push(root);
       while(!tree_Queue.empty()){
       	  Node<T>* current=tree_Queue.front();
       	  tree_Queue.pop();
          std::cout<<current->data<<", ";
          if(current->leftChild) tree_Queue.push(current->leftChild);
          if(current->rightChild) tree_Queue.push(current->rightChild);
       }
	}

};