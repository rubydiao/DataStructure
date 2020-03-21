#include <iostream>
#include <math.h>
using namespace std;
class node {
	public:
		node *left;
		node *right;
		int value = 0;

		node(int value) {
			this->value = value;
			left = NULL;
			right = NULL;
		}
};
class tree {
	public:
		node *n = NULL;
		tree() {

		}
		void add(int value) {
			if(n == NULL) {
				n = new node(value);
				return ;
			}
			node *i =n;
			while(true) {
				if(i->value > value && i->left != NULL) {
					i=i->left;
				} else if(i->value < value&& i->right !=NULL) {
					i=i->right;
				} else if(i->value > value && i->left==NULL) {
					i->left= new node(value);
					break;
				} else if(i->value < value && i->right==NULL) {
					i->right= new node(value);
					break;
				} else {
					break;
				}
			}
		}
		bool search(int value) {
			if(n!=NULL) {
				node *i = n;
				while(true) {
					if(i->value > value && i->left!= NULL) {
						i = i->left;
					} else if(i->value < value && i->right!=NULL) {
						i = i->right;

					} else if(i->value == value) {
						return true;
					} else {
						return false;
					}
				}
			}
		}
		void d(int value) {
		
			if(!search(value) || value == -1) {
				cout << value << endl;
			}
			if(n!=NULL) {
				node *parrent = n;
				node *current = n;
				if( n->value == value ) 
            {		    
            	if( n->right == NULL && n->left == NULL  )
            	{
            		n = NULL;
            		return;
				}
				if( n->right != NULL && n->left == NULL )
				{
					n = n->right;
					return;
				} 
				if( n->right == NULL && n->left != NULL )
				{
					n = n->left;
					return;
				}
			}
				

				while(true) {
					parrent = current;
					if(current->value==value) {
						if(current->left==NULL && current->right==NULL) {
							n = NULL;
							return ;
						} else if(current->left!=NULL) {
							sl(current);
						} else if(current->right!=NULL) {
							sr(current);
						}
						return ;
					} else if(current->value >value) {
						if(current->left!=NULL) {
							current = current->left;
						} else {
							return ;
						}
						if(current->value==value) {
							if(current->left == NULL && current->right == NULL) {
								parrent->left = NULL;
							} else if(current->left == NULL && current->right != NULL) {
								parrent->left = current->right;
							} else if(current->left != NULL && current->right == NULL) {
								parrent->left = current->left;
							} else if(current->left != NULL && current->right != NULL) {
								sl(current);
							}
							return;
						}
					} else if(current->value < value) {
						if(current->right!=NULL) {
							current = current->right;
						} else {
							return ;
						}
						if(current->value==value) {
							if(current->left == NULL && current->right == NULL) {
								parrent->right = NULL;
							} else if(current->left == NULL && current->right != NULL) {
								parrent->right = current->right;
							} else if(current->left != NULL && current->right == NULL) {
								parrent->right = current->left;
							} else if(current->left != NULL && current->right != NULL) {
								sl(current);
							}
							return;
						}
					}
				}
			}
		}
		void sl(node *current) {
			node *pmin;
			node *min = current->left;
			while(true) {
				pmin = min;
				if(min->right==NULL) {
					current->value = min->value;
					current->left = min->left;
					return ;
				} else {
					min = min->right;
					if(min->right == NULL && min->left == NULL) {
						current->value = min->value;
						pmin->right = NULL;
						return ;
					}
					if(min->right == NULL && min->left != NULL) {
						current->value = min->value;
						pmin->right = min->left;
						return ;
					}
				}
			}
		}
		void sr(node *current) {
			node *pmin;
			node *min = current->right;
			while(true) {
				pmin = min;
				if(min->left == NULL) {
					current->value = min->value;
					current->right = min->right;
					return ;
				} else {
					min = min->left;
					if(min->left == NULL && min->right==NULL) {
						current->value = min->value;
						pmin->left = NULL;
						return ;
					}
					if(min->left == NULL && min->right!=NULL) {
						current->value = min->value;
						pmin->left = min->right;
						return ;
					}
				}
			}
		}
		int maxh = 0;
		int temph = 0;
		void height(node *m) {
			if(m!=NULL) {
				temph++;
				height(m->left);
				if(temph>maxh) {
					maxh = temph;
				}
				height(m->right);
				temph--;
			}
		}
		bool bfs(node *m,int level) {
			if(level == 0) {
				cout << m->value <<" ";
			} else {
				if(m->left!=NULL) {
					bfs(m->left,level-1);
				}
				if(m->right!=NULL) {
					bfs(m->right,level-1);
				}
			}
		}
		void bfs() {
			if(n!=NULL) {
				maxh= 0;
				temph= 0;
				height(n);
				for(int i=0 ; i <maxh ; i++) {
					bfs(n,i);
					cout << "| ";
				}
				cout << endl;
			}
		}
		
};
int main() {
	tree *t = new tree();
	string a;
	float b;
	while(true) {
		cin>>a;
		if(a == "i") {
			cin>>b;
			if(b>0 && t->search(b)) {
				cout << b << endl;
			}
			else if(b > 0 && ceil(b)!=floor(b)){
				continue;
			} 
			else if(b>0) {

				t->add(b);
			}
		} else if(a == "p") {
			t->bfs();
		} else if(a == "d") {
			cin>>b;
			if(ceil(b)!=floor(b)) {
				continue;
			}
			else if(b == -1 || !t->search(b)){
				cout << b << endl;
			}
			else{
				t->d(b);
			}
			
		} else if(a == "x") {
			break;
		} else {
			break;
		}
	}
	return 0;
}
