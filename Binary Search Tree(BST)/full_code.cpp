/**
 * Binary search tree :
 *  i.Has two childern
 *  ii.All nodes of the left subtree are less than root 
 *     & all nodes of right subtree are greater than root
 *  iii.Both Subtree of of each node are also subtree
 * 
 * Search ,Insert,Delete : T.C : O(log n)
 * 
 * Operation on code :  i.Node Struct        
 *                      ii.Insertion
 *                      iii.Search           
 *                      iv.Inorder Travarsal  
 *                      v.Deletion
 */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

Node* insert(Node*root,int val){
    if(root==nullptr)return new Node(val);
    if(val<root->data)root->left=insert(root->left,val);
    else if(val>root->data)root->right=insert(root->right,val);
    return root;
}

bool search(Node*root,int val){
    if(root==nullptr)return false;
    if(root->data==val)return true;
    else if(val<root->data)return search(root->left,val);
    else return search(root->right,val);
}

void inorder(Node*root){
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


Node*findMin(Node*root){
    while(root->left!=nullptr)root=root->left;
    return root;
}
Node* DeleteNode(Node*root,int val){
    if(root==nullptr)return nullptr;
    if(val<root->data)root->left=DeleteNode(root->left,val);
    else if(val>root->data)root->right=DeleteNode(root->right,val);
    else{
        Node*temp;
        if(root->left==nullptr){
            temp=root->right;
            delete root;
            return temp;
        }else if(root->right==nullptr){
            temp=root->left;
            delete root;
            return temp;
        }else{
            temp=findMin(root->right);
            root->data=temp->data;
            root->right=DeleteNode(root->right,temp->data);
        }
    }
    return root;
}

int main(){
    Node*root=nullptr;

    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,12);
    root=insert(root,2);
    root=insert(root,22);
    root=insert(root,4);

    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Delete Node 2 ";
    cout<<endl;
    root=DeleteNode(root,2);
    cout<<"After Deletion : ";
    inorder(root);
    cout<<endl;
    return 0;
}