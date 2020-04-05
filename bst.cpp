#include<iostream>
using namespace std;
class node
{
    int data;
    node *l;
    node *r;
    public:
    node()
    {
      l=NULL;
      r=NULL;
    }
    node(int z)
     {
       l=NULL;
       r=NULL;
       data=z;
     }
    friend class bst;
};    
class bst
{

       public:
              node *root;
              bst()
               {
                  root=NULL;
               }
       void insert(node *temp,int a)
        {
            if(temp==NULL)
              {
                  temp=new node(a);
                  root=temp;
              }
            else
              {
                  if((temp->data)>a)
                   {
                     if(temp->l==NULL)
                       temp->l=new node(a);
                     else
                       insert(temp->l,a);
                   }
                  else
                   {
                       if(temp->r==NULL)
                       temp->r=new node(a);
                     else
                       insert(temp->r,a);
                   }
                }
          }
        void display(node *temp)
          {
             if(temp!=NULL)
               {
                  cout<<temp->data<<" ";
                  display(temp->l);
                  display(temp->r);
               }
          }
};
int main()
{
    bst x;
    x.insert(x.root,10);
    x.insert(x.root,5);
    x.insert(x.root,20);
    x.display(x.root);
}
