#include <iostream>
 
using namespace std;
 
int max(int a, int b) {
    if(a>b){
        return a;
    }else {
        return b;
    }
}
 
int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0){
        return 0;
    }
    if (wt[n-1] > W){
        return knapSack(W, wt, val, n-1);
    }
    else{
        return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),knapSack(W, wt, val, n-1) );
    }
}
 
int main() {
    int n,x,y,w;
    cin >> n;
    int val[n];
    int wt[n];
    for(int i = 0;i<n;i++){
        cin >> x >> y;
        val[i] = x;
        wt[i] = y;
    }
    cin >> w;
//    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(w, wt, val, n);
    return 0;
}

 
