#include <iostream>

using namespace std;

void Hanoi(int diskNum, int initPeg, int targetPeg, int tempPeg){
    if(diskNum == 1){
        cout<<initPeg<<"->"<<targetPeg<<endl;
        return;
    }
    
    Hanoi(diskNum-1,initPeg,tempPeg,targetPeg);
    cout<<initPeg << "->" << targetPeg<<endl;
    Hanoi(diskNum-1,tempPeg,targetPeg,initPeg);
}

int main(){
    int diskNum;
    cout<<"enter disk number:"<<endl;
    cin >> diskNum;
    
    Hanoi(diskNum,1,3,2);
    
    return 0;
}