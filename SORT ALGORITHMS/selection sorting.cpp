#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<int> v;
int main(){
	string a;
	while(true){
		cin>>a;
		if(a == "e"){
			for(int i = 0 ; i < v.size() ; i++){
				int t = i;
				for(int j = i ; j < v.size() ; j++){
					if(v[t] > v[j]){
						t =j;
					}
				}
				int tt = v[i];
				v[i] = v[t];
				v[t] = tt;
				for(int i = 0 ; i < v.size()  ; i++){
					cout << v[i] << " ";
				}
				cout << endl;
			}
			break;
		}else{
			v.push_back(atoi(a.c_str()));
		}
	}
}
