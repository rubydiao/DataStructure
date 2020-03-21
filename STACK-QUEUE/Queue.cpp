#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>
#include <vector> 
#include <algorithm> 
using namespace std;

class Queue
{
	public:
    vector<string> v;
     
    void Enqueue(string data)
    {
        v.push_back(data);
    }
    
    string Dequeue() 
    {
    	string s = "";
    	if(!v.empty())
    	{
        	s = v.at(0); 
        	v.erase( v.begin() );	          
        }
        return s;
    }
    
    void Print()
    {
		if(!v.empty())
    	{    	
			for (int i = 0; i < v.size(); i++)				
			{ 
	 			cout << v[i] << " ";
			}
			cout<<endl;
		}
    }
};

int main() 
{
	Queue s;
	string t;
	string t1;
	while(true)
	{
		cin>>t;
		if(t=="E")
		{
			cin>>t1;
			s.Enqueue(t1); 
		}
		else if(t=="D")
		{
			s.Dequeue(); 
		}
		else if(t=="P")
		{
			s.Print();
		}
		else if(t=="N")
		{
			cout<<s.v.size()<<endl;
		}		
		else if(t=="X")
		{
			break;
		}
	}
  	return 0;
}
