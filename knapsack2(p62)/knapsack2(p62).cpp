#include <iostream>
#include <vector>

using namespace std;

#define INF 0x8000

vector< vector<int> > dp;
vector<int> v, w;
int size_n, size_w, size_v;

void init(){
    int tmp_v, tmp_w;
    cout<<"n = ";
    cin>>size_n;
    
    for(int i=0;i<size_n;i++){
        cin>>tmp_w>>tmp_v;
        w.push_back(tmp_w);
        v.push_back(tmp_v);
        if(tmp_v>size_v) size_v = tmp_v;
    }
    
    cout<<"W = ";
    cin>>size_w;
    
    /*
    cout<<"size_n = "<<size_n<<endl;
    cout<<"size_v = "<<size_v<<endl;
    cout<<"size_w = "<<size_w<<endl;
    
    for(int i=0;i<size_n;i++){
        cout<<"i= "<<i<<endl;
        cout<<"w = "<<w[i]<<endl;
        cout<<"v = "<<v[i]<<endl;
    }
    */
    
    for(int i=0;i<=size_n;i++){
        dp.push_back(vector<int>());
        for(int j=0;j<=size_n*size_v;j++){
            //cout<<"(i,j) = "<<"("<<i<<","<<j<<")"<<endl;
            if(j==0) {
                dp[i].push_back(0);
            }else{
                dp[i].push_back(INF);
            }
        }
    }
    
}

int solve(){
    cout<<"======solve======="<<endl;
    
    for(int i=size_n-1;i>=0;i--){
        for(int j=0;j<=size_n*size_v;j++){
            if(j<v[i]){
                dp[i][j] = dp[i+1][j];
            }else{
                dp[i][j] = min(dp[i+1][j],dp[i+1][j-v[i]]+w[i]);
            }
        }
    }
    
    for(int j=size_n*size_v;j>=0;j--){
        if(dp[0][j]<=size_w) return j;
    }
    
}

int main(){
    init();
    cout<<solve();
    return 0;
}