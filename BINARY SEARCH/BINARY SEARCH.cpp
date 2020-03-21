#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector <int>v;

int meet_value = 0;
void binary_search(int value,int left,int right) {
	int mid = (right + left) / 2;
	if( right < left  )  	{
		return;
	}
	cout<<v[mid]<<" ";
	if( v[mid] == value )	{
		meet_value = 1;
		return;
	}
	if( right == left  ) 	{
		return;
	}
	if( v[mid] < value ) {
		binary_search(value,mid+1,right);
	} else if( v[mid] > value ) {
		binary_search(value,left,mid-1);
	}
}

void bs(int value) {
	if( !v.empty() ) {
		sort (v.begin(), v.end());
		meet_value = 0;
		int min = 0;
		int max = v.size()-1;
		binary_search( value, min, max );
		if(meet_value == 1) {
			cout<<"Y"<<endl;
		} else {
			cout<<"N"<<endl;
		}
	}
}

int main() {
	string s;
	int    n;
	while(true) {
		cin>>s;
		if(s == "e") {
			break;
		} else if(s == "s") {
			cin>>n;
			bs(n);
		} else {
			const char * c = s.c_str();
			int t = atoi(c);
			v.push_back(t);
		}
	}
	return 0;
}

