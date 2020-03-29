// GeeksforGeeks - Maximum Node Level
// https://practice.geeksforgeeks.org/problems/maximum-node-level/1

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/


int a[100001];
int mx = 0;

void fun(Node *root, int level){
    if(root == NULL)
        return;
    a[level]++;
    mx = max(mx, level);
    fun(root->left,  level + 1);
    fun(root->right, level + 1);
}
int maxNodeLevel(Node *root)
{
    mx = 0;
    int mxlev = 0;
    memset(a, 0, sizeof(a));
    fun(root, 0);
    int maxx  = 0;
    for(int i = 0; i<=mx; i++){
        if(maxx < a[i]){
            maxx = a[i];
            mxlev = i;
        }
    }
 
