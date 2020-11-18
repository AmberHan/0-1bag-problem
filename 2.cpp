#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
//0-1 背包问题
//暴力求解
bool canPutbag(int volume,vector<int> lst){
    if(volume==0)return true;
    else if(volume<0)return false;
    if(lst.size()==0)return false;
    else{
        vector<int>lst1(lst.begin()+1,lst.end());
        if(canPutbag(volume-lst[0],lst1) || canPutbag(volume,lst1)){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int>weights={1,3,11,7};
    if(canPutbag(15,weights)){
        cout << "I can"<<endl;
    }
    else{
        cout << "I can't"<<endl;
    }
    return 0;
}