// Method 1-Using O(n) auxillary space
void inorder(struct Node *root,vector <int> &v){
    if(root==NULL)
        return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
bool isPairPresent(struct Node *root, int sum){
    if(root==NULL)
        return false;
    vector <int> v;
    inorder(root,v);
    
    int i=0,j=v.size()-1;
    while(i<j){
        int x=v[i]+v[j];
        if(x==sum)
            return true;
        if(x<sum)
            i++;
        else
            j--;
    }
    return false;
}

