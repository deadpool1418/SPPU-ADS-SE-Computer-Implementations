#include<iostream>
using namespace std;
class node
{
    public:
    node *l,*r;
    int data;
    friend class node;
};
class avl
{
    public:  
      node *root;
      avl()
      {
           root=NULL;
       }
    int data;
     int height(node *temp)
     {     
    int h = 0;
    if(temp==NULL)
       h=0;
    else
    {
        int lh = height (temp->l);
        int rh = height (temp->r);
          if(rh>lh)
             h=rh+1;
          else
             h=lh+1;
    }
    return h;
   } 
node *balance(node *temp)    
     {
    int bf = bfactor(temp);
    if (bf> 1)
    {
        if (bfactor(temp->l) > 0)
            temp =LL(temp);
        else
            temp = LR(temp);
    }
    else if (bf < -1)
    {
        if (bfactor(temp->r) > 0)
            temp = RL(temp);
        else
            temp = RR(temp);
    }
    return temp;
   }
         int bfactor(node *temp)
           {
              int bf;
              bf=height(temp->l)-height(temp->r);
              return bf;
           }  
       node *RR(node *parent)
            {
                   node *temp;
                   temp=parent->r;
                   parent->r=temp->l;
                   temp->l=parent;
                   return temp;
              
            }
     node *LL(node *parent)
            {
                  node *temp;
                   temp=parent->l;
                   parent->l=temp->r;
                   temp->r=parent;
                   return temp;
            }
          node *RL(node *parent)
             {
                   parent->r = LL (parent->r);
                  return RR(parent);
              }
            node *LR(node *parent)
             {
                   parent->l = LL (parent->l);
                  return RR(parent);
              }
       node *insert(node *root,int x)
             {
                    if(root==NULL)
                       {
                            root=new node;
                            root->data=x;
                            root->l=NULL;
                            root->r=NULL;
                            return root;
                       }
                else if (x< root->data)
                      {     
                            root->l= insert(root->l,x);
                             root = balance (root);
                      }
                else if (x>= root->data)
                    {
                             root->r = insert(root->r,x);
                            root = balance (root);
                  }
                     return root;  
               
              }
              void pre(node *temp)
                {
                       if(temp!=NULL)
                          {
                                cout<<temp->data<<" ";
                                pre(temp->l);
                                pre(temp->r);
                           }
                      }
void  display(node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->r, level + 1);
        cout<<endl;
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->l, level + 1);
    }
}
       };

int main()
{
    avl z;
    z.root= z.insert(z.root,1);
   z.root= z.insert(z.root,2);
    z.root=z.insert(z.root,3);
    z.root=z.insert(z.root,4);
    z.root=z.insert(z.root,8);
    z.root=z.insert(z.root,7);
    z.root=z.insert(z.root,6);
   z.display(z.root,1);
}    
