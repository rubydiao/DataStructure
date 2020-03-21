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
class link {
	public:
		Node *head = NULL;
		int size = 0 ;
		link() {

		}
		void last_add(int value, int a) {
			if(search(value)) {
				return ;
			}
			if(head == NULL) {
				head = new Node(value);
				head->next = NULL;
				size++;
				print();
				return ;
			}
			Node *n = new Node(value);
			for(Node *h =head ; h!=NULL ; h=h->next) {
				if(h->value == a) {
					n->next = h->next;
					h->next = n;
					size++;
					print();
					return ;
				} else if(h->next == NULL) {
					break;
				}
			}
			n->next = head;
			head =n;
			size++;
			print();
		}
		bool search(int value) {
			for(Node *h = head ; h!= NULL ; h=h->next) {
				if(h->value == value) {
					return true;
				}
			}
			return false;
		}
		void print() {
			for(Node *h = head ; h!= NULL ; h = h->next) {

				cout<<h->value<<" ";
			}
			cout<<endl;
		}
		void remove(int value) {
			if(size == 1 || size == 0) {
				return ;
			}
			for(Node *h = head ; h!=NULL ; h=h->next ) {
				if(head->value == value) {
					head = head->next;
					size--;
					print();
					return ;
				} else if(h->next == NULL) {
					return ;
				} else if(h->next->value == value) {
					h->next = h->next->next;
					size--;
					print();
					return ;
				}
			}
		}
};
int main() {
	link *l = new link();
	string a;
	int x,y;
	while(true) {
		cin>>a;
		if(a == "1") {
			cin>>x>>y;
			l->last_add(x,y);
		} else if(a == "0") {
			cin>>x;
			l->remove(x);
		} else if(a == "3") {
			break;
		}
	}
	return 0;
}
