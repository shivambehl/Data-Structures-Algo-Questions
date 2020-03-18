#include<iostream>
#include<limits.h>
using namespace std;

// basic question - When to use segment tree instead of prefix sum?


int query(int *tree, int ss, int se, int qs, int qe, int index){
    // queries -
    // 1. Complete Overlap
    // 2. Partial Overlap
    // 3. No Overlap

    if(ss >= qs && se<=qe){
        return tree[index];
    }

    if(qe < ss || qs > se){
        return INT_MAX;
    }

    int mid = (ss+se)/2;
    int leftAns = query(tree, ss, mid, qs, qe, 2*index);
    int rightAns = query(tree, mid + 1, se, qs, qe, 2*index + 1);
    return min(leftAns, rightAns);
}

void updateNode(int *tree, int ss, int se, int i, int increment, int index){
    if(i > se || i < ss){
        return;
    }
    if(ss = se){
        tree[index] += increment;
        return;
    }
    int mid = (ss + se)/2;
    updateNode(tree, ss, mid, i, increment, 2*index);
    updateNode(tree, mid+1, se, i, increment, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
}


void buildTree(int *a, int s, int e, int *tree, int index){
    // bottom-up
    if(s == e){
        tree[index] = a[s];
        return;
    }
    int mid = (s + e)/2;
    buildTree(a, s, mid, tree, 2*index);
    buildTree(a, mid+1, e, tree, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}


void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index){
    //Out of bounds 
    if(l>se || r<ss){
        return;
    }
    
    // Leaf Node 
    if(ss==se){
        tree[index] += inc;
        return;
    }
    
    // Left and Right  Call Otherwise 
    int mid = (ss+se)/2;
    
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}


int main(){
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a)/sizeof(int);
    // tree array will have maximum size of 4*n + 1
    int *tree = new int[4*n + 1];

    buildTree(a, 0, n-1, tree, 1);

    for(int i = 1; i<=13; i++){
        cout<<tree[i]<<" ";
    }
    int l, r;
    cin>>l>>r;
    cout<<"\n"<<query(tree, 0, n-1, l, r, 1);
}