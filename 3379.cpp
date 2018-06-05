#include <bits/stdc++.h>

using namespace std;
int i,j;
vector<int> a;
int memo[1001][1001];

int f(int i, int j){
    if(memo[i][j]!= 0) return memo[i][j];
    if(i>j) return 0;
    else{
        int opc1=a[i];
        if(a[i+1]>=a[j]){
            opc1+=f(i+2,j);
        }
        else{
            opc1+=f(i+1,j-1);
        }
        int opc2=a[j];
        if(a[1]>=a[j-1]){
            opc2+=f(i+1,j-1);
        }
        else{
            opc2+=f(i,j-2);
        }
        memo[i][j]=max(opc1,opc2);
        return memo[i][j];
    }
}

int main(){
    int game=1;
    int n,h,s=0;
    cin>>n;
    while(n!=0){
        memset(memo,0,sizeof(memo));
        for(int i=0;i<n;i++){
            cin>>h;
            s+=h;
            a.push_back(h);
        }
        cout<<"In game "<<game<<","<<" the greedy strategy might lose by as many as "<<2*f(0,n-1)-s<<" points."<<endl;
        s=0;
        a.clear();
        game++;
        cin>>n;
    }
    return 0;
}
