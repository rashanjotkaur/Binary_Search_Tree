void inorder(struct Node *root,vector <int> &v){
    if(root==NULL)
        return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
vector<int> merge(Node *root1, Node *root2){
    vector <int> v;
    if(root1==NULL && root2==NULL)
        return v;

    vector <int> v1;
    inorder(root1,v1);
    
    vector <int> v2;
    inorder(root2,v2);
    
    if(root1 && root2==NULL)
        return v1;
    if(root1==NULL && root2)
        return v2;

    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        v.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v.push_back(v2[j]);
        j++;
    }
    return v;
}
