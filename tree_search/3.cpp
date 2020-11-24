#include<iostream>
#include<cstdlib>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x,TreeNode *l,TreeNode *r) : val(x), left(l), right(r){}
};
class Solution {
public: 
    bool exit(int index,TreeNode* root,int level){
        //level=3,k子树的层数对应 100，按位取&计算index，往左还是往右
        int k = 1<<(level-1);
        while(root && k>0){
            //1右移
            if(index & k){
                root = root->right;
            }
            //0右移
            else{
                root = root->left;
            }
            k>>=1;
        }
        return root!=NULL;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int level = -1;
        TreeNode* root1 = root;
        while(root){
            root=root->left;
            level++;
        }
        int low = (1<<level);
        int high = (1<<(level+1))-1;
        int mid = 0;
        while(low < high){
            //mid存在，往右侧找
            //因为high = mid-1，缩小的右边;需要向上取整
            mid = (high - low + 1) / 2 + low;
            // mid = low+((high-low+1)>>1);
            if(exit(mid,root1,level)){
                low = mid;
            }
            //mid不存在，左侧找
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
int main(){
    TreeNode node4(4);   
    TreeNode node5(5);
    TreeNode node2(2,&node4,&node5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node3(3,&node6,&node7);
    TreeNode root(1,&node2,&node3);
    Solution a;
    int count = a.countNodes(&root);
    cout << count <<endl;
    return 0;
}