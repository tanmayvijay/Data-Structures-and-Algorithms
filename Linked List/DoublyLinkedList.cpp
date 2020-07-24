#include<iostream>
using namespace std;

template<class T>
class DLLNode{
	T data;
	DLLNode<T> *next = nullptr;
	DLLNode<T> *prev = nullptr;
	
	public:
		DLLNode(T& data, DLLNode<T>* prev=nullptr, DLLNode<T>* next=nullptr){
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		
		void add_next(DLLNode* new_node){
			if (this->next){
				new_node->next = this->next;
				if (new_node->next)
					new_node->next->prev = new_node;
				
				new_node->prev = this;
				this->next = new_node;
				
			}else{
				this->next = new_node;
				new_node->prev = this;
			}
		}
		
		void add_prev(DLLNode* new_node){
			if (this->prev){
				new_node->prev = this->prev;
				if (new_node->prev)
					new_node->prev->next = new_node;
				
				this->prev = new_node;
				new_node->next = this;
			}else{
				this->prev = new_node;
				new_node->next = this;
			}
		}
		
		void set_next(DLLNode* new_node){
			this->next = new_node;
			if (new_node)
				new_node->prev = this;
		}
		
		void set_prev(DLLNode* new_node){
			this->prev = new_node;
			if (new_node)
				new_node->next = this;
		}
		
		T get_data(){
			return this->data;
		}
		
		DLLNode* get_next(){
			return this->next;
		}
		
		DLLNode* get_prev(){
			return this->prev;
		}
};


template<class T>
class DoublyLinkedList{
	DLLNode<T> *head = nullptr;
	DLLNode<T> *tail = nullptr;
	int size = 0;
	public:
		void insert_back(T data){
			this->tail = new DLLNode<T>(data, this->tail);
			if (this->tail->get_prev())
				this->tail->get_prev()->set_next(this->tail);
			else
				this->head = this->tail;
			
			this->size ++;
		}
		
		void insert_front(T data){
			this->head = new DLLNode<T>(data, nullptr, this->head);
			if (this->head->get_next())
				this->head->get_next()->set_prev(this->head);
			else
				this->tail = this->head;
			
			this->size ++;
		}
		
		void insert(T data, int n=0){
			if (n > this->size){
				cout << n << " is not a valid index (n should be <= " << this->size <<  ")!" << endl;
				return;
			}
			
			DLLNode<T> *new_node = new DLLNode<T>(data);
			
			if (n == 0){
				new_node->add_next(this->head);
				this->head = new_node;
				
				if (! this->tail) this->tail = this->head;
			} else if (n == this->size){
				new_node->add_prev(this->tail);
				this->tail = new_node;
				
				if (! this->head) this->head = this->tail;
			} else{
				DLLNode<T> *t = this->head;
				while(--n){
					t = t->get_next();
				}
				t->add_next(new_node);
			}
			
			this->size ++;
		}

		T delete_node(int n=0){
			if (n >= this->size){
				cout << n << " is not a valid index (n should be < " << this->size <<  ")!" << endl;
				throw exception();
			}
			
			T data;
			
			if (n==0){
				DLLNode<T>* node = head;
				head = head->get_next();
				if (head)
					head->set_prev(nullptr);
				else
					tail = head;
				
				data = node->get_data();
				delete node;
			}else if (n == this->size - 1){
				DLLNode<T>* node = tail;
				tail = tail->get_prev();
				if (tail)
					tail->set_next(nullptr);
				else
					head = tail;
				
				data = node->get_data();
				delete node;
			} else{
				DLLNode<T>* t = this->head;
				while(--n){
					t = t->get_next();
				}
				DLLNode<T>* node = t->get_next();
				DLLNode<T>* next_node = node->get_next();
				t->set_next(next_node);
				// next_node->set_prev(t);
				data = node->get_data();
				delete node;
			}

			this->size --;
			
			return data;
		}
		
		DLLNode<T>* get_node(int n=0){
			if (n >= this->size){
				cout << n << " is not a valid index (n should be < " << this->size <<  ")!" << endl;
				throw exception();
			}
			
			DLLNode<T>* t = head;
			
			while(n--){
				t = t->get_next();
			}
			
			return t;
		}

		int get_size(){
			return this->size;
		}
		
		DLLNode<T>* get_head(){
			return this->head;
		}
		
		DLLNode<T>* get_tail(){
			return this->tail;
		}
		
		void print_list(){
			DLLNode<T> *t = this->head;
			while(t != NULL){
				cout << t->get_data() << " ";
				t = t->get_next();
			}
			cout << endl;
		}
};


//int main(){
//	DoublyLinkedList<int> dll;
//
//	for(int i=0; i<30; i++){
//		cout << "List: ";
//		dll.insert_front(i);
//		dll.print_list();
//		cout << dll.get_size() << endl;
//	}
	
//	dll.insert(100, 0);
//	dll.print_list();
//	cout << dll.get_size() << endl;
//	
//	dll.insert(100, dll.get_size());
//	dll.print_list();
//	cout << dll.get_size() << endl;
//	
//	dll.insert(100, dll.get_size()-1);
//	dll.print_list();
//	cout << dll.get_size() << endl;
//	
//	dll.insert(100, 20);
//	dll.print_list();
//	cout << dll.get_size() << endl;
	
//	dll.delete_node(0);
//	dll.print_list();
//	
//	cout << endl << dll.get_node(28)->get_data();
	
	
	
}
