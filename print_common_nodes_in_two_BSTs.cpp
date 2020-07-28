void traverse(struct Node *root,unordered_map <int,bool> &ump){
    if(root==NULL)
        return ;
    ump[root->data]=true;
    traverse(root->left,ump);
    traverse(root->right,ump);
}
void inorder(struct Node *root,vector <int> &vec,unordered_map <int,bool> ump){
    if(root==NULL)
        return ;
    inorder(root->left,vec,ump);
    if(ump[root->data]==true)
        vec.push_back(root->data);
    inorder(root->right,vec,ump);
}
vector <int> printCommon(Node *r1, Node *r2){
    unordered_map <int,bool> ump;
    vector <int> vec;
    if(r1==NULL || r2==NULL)
        return vec;
    traverse(r1,ump);
    inorder(r2,vec,ump); 
    return vec;
}


