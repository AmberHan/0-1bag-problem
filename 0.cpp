#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
//0-1 背包问题变形
//时间O（volume*n）,空间O（volume*n）
bool canPutbag(vector<int>& weights,int volume) {
        int len = weights.size();
        //二维数组,i表示weights索引，j表示volume可表达值
        vector<vector<int>> dp(len,vector<int>(volume+1,0));
        //初始化，二维表置false
        for(int i=0;i<len;i++){
            for(int j=0;j<=volume;j++){
                dp[i][j] = false;
            }
        }
        dp[0][weights[0]] = true;
        //第0列置为True
        for(int i=0;i<len;i++){
            dp[i][0] = true;
        }
        for(int i=1;i<len;i++){
            int weight = weights[i];
            for(int j=0;j<=volume;j++){
                //动态规划
                // j < weights[i]  （不放）dp[i][j]=dp[i-1][j]
                // j = weights[i]    dp[i][j] = true,可合并到上一个情况，
                // j > weights[i]   (放)dp[i][j]= dp[i-1][j-weights[i]]                
                if (j >= weight) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - weight];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len-1][volume];
    }
int main(){
    vector<int>weights={1,3,11,7};
    if(canPutbag(weights,11)){
        cout << "I can"<<endl;
    }
    else{
        cout << "I can't"<<endl;
    }
    return 0;
}