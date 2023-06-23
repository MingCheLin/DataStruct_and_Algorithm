#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class TreeNode{
public:
      int val;
      TreeNode *left=NULL, *right=NULL;
      TreeNode(int val){
            this->val = val;
      }
};


class Tree{
public:
      TreeNode *root;
      Tree(vector<int> &arr){
            if (arr.size()==0){
                return;
            }
            root = new TreeNode(arr[0]);
            int n = arr.size(), m, idx = 1;
            queue<TreeNode*> bfs;
            bfs.push(root);
            while (bfs.size()){
                  m = bfs.size();
                  for (int i=0; i<m; i++){
                        TreeNode *cur = bfs.front();
                        bfs.pop();
                        if (idx < n && arr[idx]){
                              TreeNode* left = new TreeNode(arr[idx]);
                              cur->left = left;
                              bfs.push(left);
                        }
                        else{
                              bfs.push(NULL);
                        }
                        idx++;
                        if (i < n && arr[idx]){
                              TreeNode* right = new TreeNode(arr[idx]);
                              cur->right = right;
                              bfs.push(right);
                        }
                        else{
                              bfs.push(NULL);
                        }
                        idx++;
                  }
                  if (idx>=n){
                        break;
                  }
            }
      }
};
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,NULL,NULL, 10, 11};
    Tree x = Tree(arr);
    cout<<x.root->val<<endl;
    cout<<x.root->left->val<<endl;
    cout<<x.root->right->val<<endl;
    cout<<x.root->right->right->val<<endl;
    cout<<x.root->left->right->right->val<<endl;
    return 0;
}
