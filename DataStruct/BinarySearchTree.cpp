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

class BinarySearchTree{
private:
public:
      int size = 0;
      TreeNode *root=NULL;
      BinarySearchTree(vector<int> &arr){
            if (arr.size() == 0){
                  return;
            }
            root = new TreeNode(arr[0]);
            for (auto it=arr.begin()+1; it!=arr.end(); it++){
                  push(*it);
            }
      }

      void push(int val){
            TreeNode *cur = root;
            while (true){
                  if (val >= cur->val){
                        if (cur->right == NULL){
                              cur->right = new TreeNode(val);
                              break;
                        }
                        else{
                              cur = cur->right;
                        }
                  }
                  else{
                        if (cur->left == NULL){
                              cur->left = new TreeNode(val);
                              break;
                        }
                        else{
                              cur = cur->left;
                        }
                  }
            }
      }

      bool search(int target){
            if (root==NULL)
                  return false;
            TreeNode *cur = root;
            while (true){
                  if (target > cur->val){
                        if (cur->right == NULL){
                              return false;
                        }
                        else{
                              cur = cur->right;
                        }
                  }
                  else if (target < cur->val){
                        if (cur->left == NULL){
                              return false;
                        }
                        else{
                              cur = cur->left;
                        }
                  }
                  else{
                        return true;
                  }
            }
      }
};

int main()
{
    vector<int> arr={50, 60, 40, 30, 35, 45, 55, 70, 65};               //50
    BinarySearchTree x = BinarySearchTree(arr);                    //40        60
    x.push(75);                                                //30    45    55   70
    x.push(37);                                              //    35         65    75
    cout<<x.root->right->val<<endl;                         //      37
    cout<<x.root->right->right->val<<endl;
    cout<<x.root->right->right->right->val<<endl;
    cout<<x.root->left->left->right->right->val<<endl;
    return 0;
}
