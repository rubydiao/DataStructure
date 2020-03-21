#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Node {
	public:
		Node *next;
		int value;
		Node(int value) {
			this->value = value;
		}
};
class Link {
	public:
		Node *head;
		int size = 0 ;
		Link() {
			head = NULL;
		}
		void insertFirst(int value) {
			if(head == NULL) {
				Node *h = new Node(value);
				h->next = NULL;
				head = h;
				size = 1;
				return;
			}
			Node *h = new Node(value);
			h->next = head;
			head = h;
			size ++;
		}
		void insertLast(int value) {
			if(head == NULL) {
				Node * h= new Node(value);
				h->next = NULL;
				head =h;
				size=1;
				return ;
			}
			for(Node *h = head ; h!= NULL  ; h=  h->next) {
				if(h->next == NULL) {
					h->next = new Node(value);
					h->next->next = NULL;
					break;
				}
			}
			size++;
		}
		void insertAfter(int index,int value) {
			int m = 1;//m=1-1;=0
			int i = 1;
			if(head == NULL) {
				Node * h= new Node(value);
				h->next = NULL;
				head =h;
				size=1;
				return ;
			}
			for(Node *h = head ; h != NULL ; h = h->next) {
				if(m == index && index == size) {
					h->next = new Node(value);
					h->next->next = NULL;
					size++;
					break;
				} else if(index == m) {
					Node *n = new Node(value);
					n->next = h->next;
					h->next = n;
					size++;
					break;
				} else if(index > size) {
					insertLast(value);
					size++;
					break;
				}
				m++;
			}

		}
		void insertbefore(int index,int value) {
			int m = 2;///m = 1+1; default = 1;
			int i = 1;
			if(head == NULL) {
				Node *h= new Node(value);
				h->next = NULL;
				head =h;
				size=1;
				return ;
			}
			for(Node *h = head ; h != NULL ; h = h->next) {
				if(index == i) {
					Node *h = new Node(value);
					h->next = head;
					head = h;
					size++;
					break;
				} else if(m - 1 ==index && index  == size) {
					h->next = new Node(value);
					h->next->next = NULL;
					size++;
					break;
				} else if(index == m) {
					Node *n = new Node(value);
					n->next = h->next;
					h->next = n;
					size++;
					break;
				} else if(index > size) {
					insertLast(value);
					size++;
					break;
				}
				m++;
			}

		}
		void remove(int value) { //remove by value
			bool a= false;
			if(size == 0) {
				cout << "EMPTY SIZE"<<endl;
				return ;
			}
			for(Node *h = head ; h!= NULL ; h= h->next) {
				if(head->value == value) {
					head = head->next;
					a=true;
					size--;
					break;
				} else if(h->next == NULL) {

					break;
				}  else if(h->value == value) {
					h->next = NULL;
					a=true;
					size--;
					break;
				} else if(h->next->value==value) {
					h->next = h->next->next;
					a=true;
					size--;
					break;
				}
			}

			if(a == false) {
				cout << "NOT FOUND THAT VALUE : "<<value<<endl;
			}
		}

		void removein(int index) { //remove by index
			int m=2;//if index=1 ,m+1;
			int i = 1;
			if(size == 0) {
				cout << "EMPTY SIZE"<<endl;
				return ;
			}
			for(Node *h= head ; h!= NULL ; h = h->next) {
				if(index == i) {
					head= head->next;
					size--;
					break;
				} else if(m  == index && index == size - 1) {
					h->next = NULL;
					size--;
					break;
				} else if(index == m) {
					h->next = h->next->next;
					size--;
					break;
				} else if(index >size) {

					break;
				}
				m++;
			}

		}
		void print() {
			while(true) {
				if(size != 0) {
					for(Node *h = head ; h!= NULL ; h = h->next) {

						cout<<h->value<<" ";
					}
					break;
				} else {
					cout<<"EMPTY SIZE"<<endl;
					break;
				}
			}
		}
};
int main() {

	Link *l = new Link();
	int a;
	int c;
	char b;

	while(true) {
		cin>>b;
		if(b=='A'|| b== 'a') { // input tail
			cin>>a;
			l->insertLast(a);
		} else if(b == 'F'|| b == 'f') { //input head
			cin>>a;
			l->insertFirst(a);
		} else if(b=='P' || b== 'p') { //print_all
			l->print();
			cout<<endl;
		} else if(b == 'I'|| b== 'i') { //insert index before
			cin>>c>>a;
			l->insertbefore(c,a);
		} else if(b == 'J'|| b== 'j') { //insert index after
			cin>>c>>a;
			l->insertAfter(c,a);
		} else if(b== 'D'|| b == 'd') { // delete by value
			cin>>a;
			l->remove(a);
		} else if(b== 'q'|| b == 'Q') { // delete by index
			cin>>a;
			l->removein(a);
		} else if(b == '0') { // end-program
			cout<<endl;
			break;
		} else if(b == 's'|| b == 'S') { // print_size
			cout<<l->size<<endl;
		} else {	//else
			cout<<"ERROR"<<endl;
			break;
		}
	}
	return 0;
}

