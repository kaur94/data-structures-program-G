#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    node* next;
}*head=NULL;
 
 node *XOR (node *a, node *b)
{
   return (node*)((long long)(a)^(long long)(b));

}
 

void insert(node **head_ref, int data)
{
    node *new_node  = new  node;
    new_node->data = data;
    new_node->next = XOR (*head_ref, NULL);
    if (*head_ref != NULL)
    {
        node* next = XOR ((*head_ref)->next,  NULL);
        (*head_ref)->next = XOR (new_node, next);
    }
    *head_ref = new_node;
}
 
// Display List
void display (node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *next;
    cout<<"Elements of XOR Linked List: "<<endl;
    while (curr != NULL)
    {
        cout<<curr->data<<"--> ";
        next = XOR (prev, curr->next);
        prev = curr;
        curr = next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    
    int choice, item;
    while (1)
    {
        cout<<"\n-------------"<<endl;
        cout<<"Operations on XOR Linked List"<<endl;
        cout<<"\n-------------"<<endl;
        cout<<"1.Insert Element at First"<<endl;
        cout<<"2.Display List"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
          insert(&head, item);
            break;
        case 2:
            display (head);
            break;
        case 3:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
 


