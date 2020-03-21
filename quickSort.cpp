#include <vector>
#include <iostream>
using namespace std;
vector<int> v;
void qs(int li , int hi){
	int i = li;
	int j = hi;
	int pivot = v[li+(hi - li)/2];
	while(i <= j){
		while(v[i] < pivot){
			i++;
		}
		while(v[j] > pivot){
			j--;
		}
		if(i <= j){
			int t= v[i];
			v[i] = v[j];
			v[j] = t;
			i++;
			j--;
		}
	}
	if(li < j){
		qs(li,j);
	}
	if(i < hi){
		qs(i,hi);
	}
}
int main(){
	int a; int size;
	cin>>size;
	for(int i = 0 ; i< size ; i++){
		cin>>a;
		v.push_back(a);
	} 
	qs(0,v.size()-1);
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << " ";
	} 
	cout << endl;
	return 0;
	
}
