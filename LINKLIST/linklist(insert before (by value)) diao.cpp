#include <iostream>
using namespace std;
class node{
	public:
		node *next;
		int value;
		node(int value){
			this->value = value;
		}
};
class link{
	public:
		node *head=NULL;
		int size = 0;
		link(){
			
		}
		void a(int value,int a){
			if(s(value)){
				return ;
			}
			if(head == NULL){
				head = new node(value);
				head->next = NULL;
				size++;
				p();
				return ;
			}
			node *n = new node(value);
			for(node *h= head ; h!= NULL ; h=h->next){
				if(head->value == a){
					n->next = head;
					head = n;
					size++;
					p();
					return ;
				}
				else if(h->next == NULL){
					n->next = h->next;
					h->next = n;
					size++;
					p();
					return ;
				}
				else if(h->next->value == a){
					n->next = h->next;
					h->next = n;
					size++;
					p();
					return ;
				}
			
			}
		}
		void d(int value){
			if(size == 1 || size == 0){
				return ;
			}
			for(node *h=head ;h!=NULL; h=h->next)
			{
				if(head->value == value){
					head=head->next;
					size--;
					p();
					return ;
				}
				else if(h->next == NULL){
					break;
				}
//				else if(h->value == value){
//					h->next = NULL;
//					size--;
//					p();
//					return ;
//				}
				else if(h->next->value == value){
					h->next = h->next->next;
					size--;
					p();
					return ;
				}
			}
		}
		bool s(int value){
			for(node *h =head ; h!= NULL ; h=h->next)
			{
				if(h->value == value){
					return true;
				}
			}
			return false;
		}
		void p(){
			for(node *h=head ; h!= NULL ;h=h->next)
			{
				cout << h->value <<" ";
			}
			cout <<endl;
		}
};
int main(){
	link *l  = new link();
	int a,b,c;
	while(true){
		cin>>c;
		if(c == 1){
			cin>>a>>b;
			l->a(a,b);
			
		}
		else if(c == 0){
			cin>>a;
			l->d(a);
		}
		else if(c == 3){
			break;
		}
	}
	return 0;
}
