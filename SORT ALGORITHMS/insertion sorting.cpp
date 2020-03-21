#include <iostream>
using namespace std;
int main(){
	int array[10000];
	int a, count , size;
	cin>>size;
	for(int i= 0 ; i < size ; i++){
		cin >> a;
		array[i] = a;
	}
	int temp = 0;
	for(int i = 1 ; i < size ; i++){
		for(int j = 0 ; j < i ; j++){
			if(array[j]>array[i]){
				temp = array[i];
				for(int k = i ; k > j ; k--){
					array[k]  = array[k-1];
					
				}
				array[j] = temp;
				count ++;
				for(int k = 0 ; k < size; k++){
					cout << array[l] <<" ";
				}
				cout << endl;
			}
		}
	}
	cout << count << endl;
}
