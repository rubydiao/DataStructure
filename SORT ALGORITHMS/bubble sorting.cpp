#include <iostream>
using namespace std;
int main(){
	int array[10000];
	int a , size , count;
	cin>>size;
	for(int i = 0 ; i < size ; i++){
		cin>>a;
		array[i] = a;
	}
	for(int i = 0 ; i < size - 1 ; i++){
		for(int j = 0 ; j < size - i - 1 ; j++){
			if(array[j]>array[j+1]){
				int temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
		count++;
		for(int k = 0 ; k < size; k++){
			cout << array[k] <<" ";
		}
		cout << endl;
	}
	cout << count <<endl;
}
