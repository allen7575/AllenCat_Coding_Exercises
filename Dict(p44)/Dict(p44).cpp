#include <iostream>
#include <string>
#include <vector>

using namespace std;

int length;
vector<char> S,T;

void init(){
    char ch;
    cout<<"========== init ======="<<endl;
    cout<<"N = ";
    cin>>length;
    cout<<length<<endl;
    cout<<"S = ";
    for(int i=0;i<length;i++){
        cin>>ch;
        S.push_back(ch);
    }
    
    for(int i=0; i<S.size(); i++){
        cout<<S[i];
    }
    cout<<endl;
    
}

void solve(){
    int front=0, end=length-1;
    cout<<"=========== solve ==========="<<endl;
    while(front <= end){
        bool left = false;
        cout<<"front = "<<front<<endl;
        cout<<"end = "<<end<<endl;
        
        for(int i=0; front+i<end; i++){
            cout<<"S[front+i] = "<<S[front+i]<<endl;
            cout<<"S[end-i] = "<<S[end-i]<<endl;
            if(S[front+i] < S[end-i]){
                left = true;
                break;
            }else if(S[front+i] > S[end-i]){
                left = false;
                break;
            }
        }
        
        if(left){
            T.push_back(S[front++]);
            cout<<"front++ = "<<front<<endl;
        }else{
            T.push_back(S[end--]);
            cout<<"end++ = "<<end<<endl;
        }
        
        //cout<<T<<endl;
        cout<<"S = ";
        for(int i=0; front+i<=end; i++){
            cout<<S[front+i];
        }
        cout<<endl;
        cout<<"T = ";
        for(int i=0; i<T.size(); i++){
            cout<<T[i];
        }
        cout<<endl;
        cout<<"==============="<<endl;
    }
    
}



int main(){
    init();
    solve();
    return 0;
}