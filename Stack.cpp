#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack{
	vector<T> data;
	int size = 0;
	int top = -1;
	
	public:
		
		Stack(){
			this->size = 0;
			this->top = -1;
		}
		
		Stack(T* arr, int size){
			this->size = size;
			for(int i=0; i<size; i++){
				this->data.push_back(arr[i]);
				this->size++;
				this->top++;
			}
		}
		
		void push(T element){
			this->data.push_back(element);
			this->size++;
			this->top++;
		}
		
		T pop(){
			if (size){
				T element = this->data[top];
				this->data.pop_back();
				this->top --;
				this->size --;
				return element;
			}else {
				cout << "Nothing to pop!" << endl;
				throw exception();
			}	
		}
		
		T get_top(){
			if (!this->size){
				cout << "Nothing at top!" << endl;
				throw exception();
			}
			
			return this->data[top];
		}
		
		int get_size(){
			return this->size;
		}
		
		bool is_empty(){
			if (this->size) return false;
			return true;
		}
		
		void print_stack(){
			if (!this->size){
				cout << "Empty" << endl;
				return;
			}
			for (int i=0; i<size; i++){
				cout << this->data[i] <<" ";
			}
			cout << endl <<  "size: " << this->size << endl;
		}
};


//int main(){
//	Stack<int> s;
//	
//	cout << "1: push\n2:pop\n3: size\n4: empty\n5: print stack\n6: top\n";
//
//	int ch;
//	while(true){
//		cout << ">> ";
//		cin >> ch;
//		switch(ch){
//			case 1:
//				int x;
//				cin >> x;
//				s.push(x);
//				s.print_stack();
//				break;
//			case 2:
//				s.pop();
//				s.print_stack();
//				break;
//			case 3:
//				cout << "size: " << s.get_size()<< endl;
//				break;
//			case 4:
//				cout << "empty: " << (s.is_empty()?"true":"false") << endl;
//				break;
//			case 5:
//				s.print_stack();
//				break;
//			case 6:
//				cout << "top: " << s.get_top() << endl;
//				break;
//			default:
//				break;
//		}
//	}
//}
