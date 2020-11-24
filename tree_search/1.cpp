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
    int countNodes(TreeNode* root) {
        return root == NULL? 0:countNodes(root->left)+countNodes(root->right)+1;
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
