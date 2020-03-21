#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>
#include <vector> 
#include <algorithm> 
using namespace std;

class Stack
{
    public:
	vector<string> v;	
    void Push(string data)
    {
		v.push_back(data);
    }
    void Top()
    {
    	if(!v.empty())
    	{
    		cout<<v[ v.size()-1 ]<<endl;
    	}
	}
    void Pop()
    {
    	if(!v.empty())
    	{
    		Top();
    		v.pop_back();
		}
    }
    void Print()
    {	
		if(!v.empty())
    	{
			for (int i = 0 ; i < v.size() ; i++)			
			{ 
	 			cout << v[i] << " ";
			}
			cout<<endl;
		}
    }
};

int main() 
{
	Stack s;
	string t;
	string t1;
	while(true)
	{
		cin>>t;
		if(t=="U")
		{
			cin>>t1;
			s.Push(t1); 
		}
		else if(t=="O")
		{
			s.Pop(); 
		}
		else if(t=="P")
		{
			s.Print();
		}
		else if(t=="N")
		{
			cout<<s.v.size()<<endl;
		}		
		else if(t=="T" )
		{
			s.Top();
		}
		else if(t=="X")
		{
			break;
		}
		
	}
  	return 0;
}
