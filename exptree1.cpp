#include<iostream>
#include<string.h>
using namespace std;
class node{
    char data;
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
       friend class tree;
};
class stack{
    int top;
    node *info[50];
    public:
    stack()
      {
         top=-1;
      }
    void push(node *temp)
    {
        top++;
        info[top]=temp;
    }
   int isEmpty()
    {
        if(top==-1)
           return 1;
        else 
            return 0;
    }
    node *pop()
       {
          if(!isEmpty())
            return(info[top--]);
          else
            return NULL;;
        }
      node *getTop()
        {
            return(info[top]);
         }
};
class tree{
   public:
   node *root;
   tree()
     {
        root=NULL;
     }
      int priority(char z)
       {
          if(z=='+' || z=='-')
             return 0;
          else if(z=='*' || z=='/')
             return 1;
          else if(z=='^')
             return 2;
        }
      void create(string a)
        {
           int i=0;
           stack s1,s2;
           char z;
           while(a[i]!='\0')
            {
               z=a[i];
               if(isalpha(z))
                 {
                     node *newnode=new node(z);
                     s1.push(newnode);
                 }
               else
                 {
                     if(s2.isEmpty())
                       {
                           node *newnode=new node(z);
                           s2.push(newnode);
                       }
                      else if(priority(z)>priority(s2.getTop()->data))
                        {
                             node *newnode=new node(z);
                             s2.push(newnode);
                        }
                      else if(priority(z)<=priority(s2.getTop()->data))
                        {
                             while(!s2.isEmpty() && priority(z)<=priority(s2.getTop()->data))
                               {
                                   node *op=s2.pop();
                                   node *op1=s1.pop();
                                   node *op2=s1.pop();
                                   op->r=op1;
                                   op->l=op2;
                                   s1.push(op);
                               }
                               s2.push(new node(z));
                          }
                       }
                        i++;
                    }
                   while(!s2.isEmpty())
                   {
                              node *o=s2.pop();
                              node *obj1=s1.pop();
                              node *obj2=s1.pop();
                              o->l=obj2;
                              o->r=obj1;
                              s1.push(o);
                    }
                      root=s1.pop();
                }
             void post(node *temp)
               {
                   if(temp!=NULL)
                     {
                        post(temp->l);
                        post(temp->r);
                        cout<<temp->data<<" ";
                     }
                 }
                  void postOrder(node *temp)
                   {
                       stack s1,s2;
                       node *t;
                       s1.push(temp);
                       while(!s1.isEmpty())
                        {
                           t=s1.pop();
                           s2.push(t);
                           if(t->l)
                            s1.push(t->l);
                           if(t->r)
                             s1.push(t->r);
                        }
                        while(!s2.isEmpty())
                         {
                            cout<<s2.pop()->data;
                            
                         }
                    }
                            
                   
            
};
int main()
{
   string s="a-b*c-d/e+f";
   tree t;
   t.create(s);
   t.postOrder(t.root);
}                 
