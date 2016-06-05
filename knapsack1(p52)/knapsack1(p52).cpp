#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> P;

vector< P > wv;
vector< vector<int> > dp;
int size_n, size_w;

void init(){
    int w, v;
    cout<<"n = ";
    cin>>size_n;
    
    for(int i=0; i<size_n;i++){
        cin>>w;
        cout<<",";
        cin>>v;
        wv.push_back(P(w,v));
        cout<<endl;
    }
    
    cout<<"W = ";
    cin>>size_w;
    
    for(int i=0; i<size_n; i++){
        cout<<"("<<wv[i].first<<","<<wv[i].second<<")"<<endl;
    }
    
    for(int i=0; i<=size_n;i++){
        dp.push_back(vector<int>());
        for(int j=0;j<=size_w; j++){
            dp[i].push_back(0);
        }
    }
    
}

void solve1(){
    
    for(int i= size_n-1;i>=0;i--){
        for(int j=0; j<=size_w;j++){
            if(j<wv[i].first){
                dp[i][j] = dp[i+1][j];
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i+1][j-wv[i].first]+wv[i].second);
            }
        }
    }
    
    cout<<dp[0][size_w];
}

int main(){
    init();
    solve1();
    return 0;
}