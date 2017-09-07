#include<iostream>
#include<cstdio>
#include<sstream>

using namespace std;
 

struct Node
{
    int data;
    Node *left;
    Node *right;
}*root= NULL;

int height(Node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
/*
 * Height Difference 
 */
int BF(Node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
/*
 * Right- Right Rotation
 */
Node *rr_rotation(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
Node *ll_rotation(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
/*
 * Left - Right Rotation
 */
Node *lr_rotation(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
/*
 * Right- Left Rotation
 */
Node *rl_rotation(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
/*
 * Balancing AVL Tree
 */
Node *balance(Node *temp)
{
    int bal_factor = BF(temp);
    if (bal_factor > 1)
    {
        if (BF (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (BF (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 
/*
 * Insert Element into the tree
 */
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
	    
        root->left =insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    { 
        
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
 
/*
 * Display AVL Tree
 */
void display(Node *p, int level)
{
    int i;
    if (p!=NULL)
    {
    	
        display(p->right, level + 1);
        cout<<endl;
        if (p == root)
		
        cout<<"Root ->";
        for (i = 0; i < level && p != root; i++)
            cout<<"           ";
        
        cout<<p->data;
       
        display(p->left, level + 1);
    
    }
}
 
int main()
{
    int choice, item,n,x;
  
    while (1)
    { 
        cout<<"\nAVL Tree Implementation"<<endl;
       cout<<"\n"<<endl;
         cout<<"1.Create Element into the tree"<<endl;
        cout<<"2.Insert Element into the tree"<<endl;
        cout<<"3.Display Balanced AVL Tree"<<endl;
      
        cout<<"4.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        	 case 1:
            cout<<"Enter no of values to be inserted: ";
            cin>>n;
            cout<<"enter tree data";
            for(int i=0;i<n;i++)
            {
			   cin>>x;
            root =insert(root, x);
            }
            break;
        case 2:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root =insert(root, item);
            break;
        case 3:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            display(root, item);
            break;
      
       
        
        case 4:
            exit(1);    
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
 
