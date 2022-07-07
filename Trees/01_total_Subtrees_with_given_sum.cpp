#include<bits/stdc++.h>
using namespace std;
char a[1000];
vector<int> nums;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            data = d;
            left = right = NULL;
        }
};

void stringToInt(){
    char *ans = strtok(a, " ");
    while(ans != NULL){
        nums.push_back(stoi(ans));
        ans = strtok(NULL, " ");
    }
}

node* CreateTree(){
    if(strlen(a) == 0 || nums.size() == 0){
        return NULL;
    }
    int no = nums[0];
    node* root = new node(no);
    int i = 1;
    queue<node*>q;
    q.push(root);

    while(!q.empty() && i < nums.size()){
        node* temp = q.front();
        q.pop();
        no = nums[i++];
        temp->left = new node(no);
        q.push(temp->left);
        if(i >= nums.size()){
            break;
        }

        no = nums[i++];
        temp->right = new node(no);
        q.push(temp->right);
        if(i >= nums.size()){
            break;
        }
    }
    return root;
}

int Sum(node* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);
    return root->data + leftSum + rightSum;
}

int countSubtrees(node* root, int x){
    if(root == NULL){
        return 0;
    }
    int ans = 0;
    if(Sum(root) == x){
        ans = 1;
    }
    int leftSubtrees = countSubtrees(root->left, x);
    int rightSubtrees = countSubtrees(root->right, x);
    return ans + leftSubtrees + rightSubtrees;
}
int main(){
    cin.ignore();
    cin.getline(a, 1000);
    stringToInt();
    int x;
    cin >> x;
    node* root = CreateTree();
    cout << countSubtrees(root, x);
    return 0;
}