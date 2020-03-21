#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
vector<int> a;
void merge(vector<int>& a,int left , int right , int rightEnd) {
	int tmp[10000];
	int startL = left;
	int EndL = right - 1;
	int startR = right;
	int EndR = rightEnd;
	int index = startL;
	int indL = startL;
	int indR = startR;
	
	while(indL <= EndL && indR <= EndR) {
		if(a[indL] < a[indR]) {
			tmp[index] = a[indL];
			indL++;
			index++;
		} else {
			tmp[index] = a[indR];
			indR++;
			index++;
		}
	}
	while(indL <= EndL) {
		tmp[index] = a[indL];
		indL++;
		index++;
	}
	while(indR <= EndR) {
		tmp[index] = a[indR];
		indR++;
		index++;
	}
	for(int i = startL ; i <= EndR ; i++) {
		a[i] = tmp[i];
	}
}
void mergesort(vector<int>& a, int left,int right) {
	if(left < right) {
		int c = (left + right ) / 2 ;
		mergesort(a , left ,c);
		mergesort(a ,c+ 1 , right);
		merge(a, left ,c+1,right);
	}
}
int main() {
//	int a[10000];
	 int b;
	int size;
	cin>>size;
	
	for(int i = 0 ; i < size; i++){
		cin>>b;
		a.push_back(b);
	}
	mergesort(a , 0 , a.size() - 1 );
	
	for(int i = 0 ; i < a.size() ; i++){
		cout << a[i] <<" ";
	}
	cout << endl;
	return 0 ;

}
