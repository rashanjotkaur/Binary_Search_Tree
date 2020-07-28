// Method 1-O(n) space
unordered_map <int,bool> ump;
vector <int> v;
void traversal(struct Node *root){
    if(root==NULL)
        return ;
    if(root->left==NULL && root->right==NULL)
        v.push_back(root->data);
    ump[root->data]=true;
    traversal(root->left);
    traversal(root->right);
}
bool isDeadEnd(Node *root){
    if(root==NULL)
        return false;
    traversal(root);
    ump[0]=true;
    for(int i=0;i<v.size();i++){
        int x=v[i];
        if(ump[x+1] && ump[x-1])
            return true;
    }
    return  false;
}
