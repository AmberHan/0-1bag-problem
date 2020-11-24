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
    //计算子树层数
    int countlevel(TreeNode* root){
        int level = 0;
        while(root!=NULL){
            root = root->left;
            level++;
        }
        return level;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int leftlevel = countlevel(root->left);
        int rightlevel = 0;
        int count = 0;
        while(root){
            rightlevel = countlevel(root->right);
            //左边子树是满二叉树
            if(leftlevel == rightlevel){
                count += (1<<leftlevel);
                root = root->right;
            }
            //右边子树是满二叉树
            else{
                count += (1<<rightlevel);
                root = root->left;
            }
            leftlevel--;    
        }
        return count;
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