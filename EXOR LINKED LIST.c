/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* npx;
    node(int val)
    {
        data=val;
        npx=NULL;
    }
};
node* head=NULL;

node* XOR(node* x,node* y)
{
    return (node*)((uintptr_t)(x)^(uintptr_t)(y));
}

void insert(int val)
{
    node* newNode=new node(val);
    newNode->npx=head;
    
    if(head!=NULL)
    {
        head->npx=XOR(newNode,head->npx);
    }
    head=newNode;
}

void insert_after_given_node(int k,int val)
{
    //insert after node k
    node* prev=NULL;
    node* next;
    
    node* curr=head;
    
    while(curr!=NULL)
    {
        // cout<<curr->data<<"->";
        if(curr->data==k)
        {
            next=XOR(prev,curr->npx);
            prev=curr;
            curr=next;
            node* newNode=new node(val);
            newNode->npx=XOR(curr,prev);
            prev->npx=XOR(newNode,XOR(prev->npx,curr));
            if(curr!=NULL)
            {
            curr->npx=XOR(newNode,XOR(curr->npx,prev));    
            }
            
            break;
        }
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
        
    }
}

void displayList()
{
    node* prev=NULL;
    node* next;
    
    node* curr=head;
    
    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
}

int main()
{
    int ch=1;
    cout<<"press 1 to insert begging\n2.to insert after key\n3.to display\n 4.exit";
    while(ch!=3)
    {
        
        switch(ch)
        {
            case 
        }
        
        
    }
    insert(10);
    insert(20);
    insert(30);
    insert_after_given_node(10,40);
    displayList();
    return 0;
}
