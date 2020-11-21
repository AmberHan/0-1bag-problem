#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
//0-1 背包问题变形
//输出遍历
//表填写0，1，2，3
//res记录包放的所有情况，put记录当前情况包放置情况，dp二维表，weights包物品重量
void dfs(vector<vector<int>> &res, vector<int> put,int i,int j,vector<vector<int>> dp,vector<int> weights){
    if(j == 0){
        res.emplace_back(put);
    }else{
        vector<int> a(put);
        a.emplace_back(weights[i]);
        //==3代表2种情况，weights[i]放和不放都行，产生分支
        if(dp[i][j]==3){
            dfs(res,put,i-1,j,dp,weights);
            dfs(res,a,i-1,j-weights[i],dp,weights);
        }
        //==1代表，weights[i]放
        else if(dp[i][j]==1){
            dfs(res,a,i-1,j-weights[i],dp,weights);
        }
        //==2代表，只有不放，才满足情况
        else if(dp[i][j]==2){
            dfs(res,put,i-1,j,dp,weights);
        }
    }
}

//记录位置0123
int canPutbag(vector<int>& weights,int volume) {
        int len = weights.size();
        //二维数组,i表示weights索引，j表示volume可表达值
        vector<vector<int>> dp(len,vector<int>(volume+1,0));
        //初始化，二维表置0
        for(int i=0;i<len;i++){
            for(int j=0;j<=volume;j++){
                dp[i][j] = 0;
            }
        }
        dp[0][weights[0]] = 1;
        //第0列置为2
        for(int i=0;i<len;i++){
            dp[i][0] = 2;
        }
        for(int i=1;i<len;i++){
            int weight = weights[i];
            for(int j=0;j<=volume;j++){
                //动态规划             
                if (j >= weight) {
                    dp[i][j] = dp[i - 1][j]<<1 | (dp[i - 1][j - weight]==0?0:1);
                } else {
                    dp[i][j] = dp[i - 1][j]<<1;
                }
            }
        }
        if(dp[len-1][volume]){
            vector<vector<int>> res;
            dfs(res, {}, len-1, volume, dp, weights);
            for(auto &ch:res){
                for(auto &ch1:ch){
                    cout << ch1;
                }
                cout << '\n';
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