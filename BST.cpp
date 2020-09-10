#include<iostream>
#include<stack>

using namespace std;

template<class T>
class BSTNode{
	public:
		T data;
		BSTNode *left, *right;
		
		BSTNode(T data){
			this->data = data;
			left = right = nullptr;
		}
};


template<class T>
class BST{
	BSTNode<T>* root = nullptr;
	
	public:
		void insert_node(T data){
			if (!root){
				root = new BSTNode<T> (data);
				return;
			}
			
			BSTNode<T>* node = root;
			
			while(node){
				if (data < node->data){
					if (node->left) node = node->left;
					else node->left = new BSTNode<T>(data);
				}
				else if (data > node->data){
					if (node->right) node = node->right;
					else node->right = new BSTNode<T>(data);
				}
				else break;
			}
			
		}
		
		void delete_node(T data){
			if (!root) {
				cout << "Empty!" << endl;
			}
			
			BSTNode<T> *node = root, *parent = nullptr;
			bool lr = false; // f == l and t == r
			
			while(node){
				if (node->data == data){
					BSTNode<T>* temp = node;
					BSTNode<T>* repl = node->right;
					if (!repl) repl = node->left;
					
					if (node->right && node->left){
						BSTNode<T>* repl_left = repl->left;
						repl->left = node->left;
						node = node->left;
						while(node->right) node = node->right;
						node->right = repl_left;
					}
					
					if (parent){
						if (lr) parent->right = repl;
						else parent->left = repl;
					}else{
						root = repl;
					}
					
					delete temp;
					
					return;
				}
				else if (data < node->data){
					if(node->left){
						parent = node;
						node = node->left;
						lr = false;
					} 
					else {
						cout << data << " is not in BST!" << endl;
						return;
					}
				}
				else{
					if (node->right){
						parent = node;
						node = node->right;
						lr = true;
					} 
					else{
						cout << data << " is not in BST!" << endl;
						return;
					}
				}
			}
		}
		
		
		void _inorder(BSTNode<T>* root){
			if (!root) return;
			_inorder(root->left);
			cout << root->data << " ";
			_inorder(root->right);
		}
		
		void print_inorder(){
			if (!root){
				cout << "Empty!" << endl;
				return;
			}
			_inorder(this->root);
			cout << endl;
		}
};


//int main(){
//	int arr[] = {6,21,4,32423,235,7,65,1,245,1924,586,9887,69,9327,3,98238,475,8,2,4356,987,68};
//	BST<int> bst;
//	
//	bst.print_inorder();
//	
//	for (int a: arr){
//		bst.insert_node(a);
////		bst.print_inorder();
//	}
//	
//	bst.print_inorder();
//	cout << endl << endl;
//	
//	for (int a: arr){
//		bst.delete_node(a);
//		bst.print_inorder();
//	}
//}
