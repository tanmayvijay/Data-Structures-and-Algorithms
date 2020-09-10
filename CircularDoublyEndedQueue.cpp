#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Node{
  public:
	T data;
	struct Node* next=NULL, *prev=NULL;
	Node(){
		
	}
	Node(T& data){
		this->data = data;
	}
};

template<class T>
class CircularDoublyEndedQueue{
	Node<T>* front=NULL, *rear;
	int size;
	
	public:
		CircularDoublyEndedQueue(){
			this->size = 0;
			this->front=NULL;
			this->rear=NULL;
		}
		
		void enqueue_front(T data){ // read enk
			if (!front){
				front = new Node<T>(data);
				rear = front;
			}else{
				Node<T>* new_node = new Node<T>(data);
				new_node->next = front;
				front->prev = new_node;
				front = new_node;
			}
			size ++;
			front->prev = rear;
			rear->next = front;			
		}
		
		
		void enqueue_rear(T data){ // read enck
			if (!rear){
				rear = new Node<T>(data);
				front = rear;
			}else{
				Node<T>* new_node = new Node<T>(data);
				rear->next = new_node;
				new_node->prev = rear;
				rear = new_node;
			}
			size++;
			
			front->prev = rear;
			rear->next = front;
		}
		
		T dequeue_front(){  // read deck
			if (!size){
				cout << "Empty Queue" << endl;
				throw exception();
			}
			
			Node<T>* temp = front;
			
			if (size == 1){
				front = NULL;
				rear = NULL;
			}else{
				front = front->next;
				front->prev = rear;
				rear->next = front;
			}
			
			T ret = temp->data;
			delete temp;
			
			size--;
			
			return ret;
			
		}
		
		T dequeue_rear(){ // read deck
			if (!size){
				cout << "Empty Queue" << endl;
				throw exception();
			}
			
			Node<T>* temp = rear;
			
			if (size == 1){
				rear = NULL;
				front = NULL;
			}else{
				rear = rear->prev;
				rear->next = front;
				front->prev = rear;
				
			}
			
			T ret = temp->data;
			delete temp;
			
			size--;
			
			return ret;
		}
		
		T get_front(){
			if (front) return front->data;
			
			cout << "Empty Queue" << endl;
			throw exception();
		}
		
		T get_rear(){
			if (rear) return rear->data;
			
			cout << "Empty Queue" << endl;
			throw exception();
		}
		int get_size(){
			return this->size;
		}
		
		void print_queue(){
			if (!front){
				cout << "empty\n";
				return;
			}
			Node<T>* t = front;
			do{
				cout << t->data << " ";
				t = t->next;
			}while(t != front);
			cout << endl << "Size: " << this->size << endl;
		}
};


int main(){
	CircularDoublyEndedQueue<int> cdeq;
	for(int i: {1,2, 3,4 ,5 ,6,}) {
		cdeq.enqueue_front(i);
//		cdeq.print_queue();
//		cout << cdeq.get_rear() << endl;
//		cout << cdeq.get_front() << endl;
	}
	
	cdeq.print_queue();
	int i=0;
	while(i<7) {
		cdeq.dequeue_rear();
		cdeq.print_queue();
//		cout << cdeq.get_rear() << endl;
//		cout << cdeq.get_front() << endl;
	}
}
