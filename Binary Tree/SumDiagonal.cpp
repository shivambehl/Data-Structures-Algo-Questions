// GeeksForGeeks - Diagonal Sum In Binary Tree
// https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

int mx = 0;
int a[100001];

void fill_array(Node* root, int dist){
    if(root == NULL)
        return;
    mx = max(dist, mx); // to keep track of maximum dist ever achieved
    a[dist] += root->data;
    fill_array(root->right, dist);
    fill_array(root->left, dist + 1);
    return;
}


void diagonalSum(Node* root) {
    memset(a, 0, sizeof(a));
    mx = 0;
    
    fill_array(root, 0);
    for(int i = 0; i<=mx; i++){
        cout<<a[i]<<" ";
    }
}
