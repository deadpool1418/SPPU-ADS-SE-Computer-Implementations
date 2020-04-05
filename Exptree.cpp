#include<iostream>
#include<string.h>
using namespace std;
const int MAX=50;
class tree;
class node;
class stack
{

int top;
     node *info[50];
     public:
     stack()
     {
        top=-1;
     }
    int isempty()
       {
           if(top==-1)
              return 1;
            else 
               return 0;
       }
     void push(node *a)
       {
           top++;
           info[top]=a;
       }
    node *gettop()
       {
          
          return(info[top]);
       }
     node *pop()
       {
       	if(!isempty())
          return(info[top--]);
        return NULL;
          
   }

};
class node
{
     
     char data;
     node *l,*r;
     public:
     node()
       {
         l=r=NULL;
       }
      node (char ch)
       {
          l=r=NULL;
          data=ch;
       }
       friend class tree;
};
class tree
{
      
      node *root;
      public:
       tree()
         {
          root=NULL;
         }
     int priority(char a)
        {
            if(a=='+' || a=='-')
              return 0;
            else if(a=='/' || a=='*')
              return 1;
            else if(a=='^')
              return 2;
        }
    void generate(string a)
      {
         int i=0;
         stack s1,s2;
         char z;
         while(a[i]!='\0')
           {
               z=a[i];
              if(isalpha(z))
                {   
                    node *obj=new node(z);
                    s1.push(obj);
                } 
              else
                {
                  if(s2.isempty())
                     {
                         node *obj=new node(z);
                         s2.push(obj);
                     }
                  else if(priority(z)>priority(s2.gettop()->data))
                    {
                      node *obj=new node(z);
                         s2.push(obj);
                    }
              	else
		      	{
				while(!s2.isempty()&&priority(z)<=priority(s2.gettop()->data))
				{
					node *op=s2.pop();
					node *rchild=s1.pop();
					node *lchild=s1.pop();

					op->r=rchild;
					op->l=lchild;

					s1.push(op); //push on operand stack
				}
				s2.push(new node(z)); //push operand at last
			}
                }
                i++;
                }
                 while(!s2.isempty())
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
 
void post()
{
	postorder_rec(root);
}
void postorder_rec(node *rnode)
{
	if(rnode)
	{
		postorder_rec(rnode->l);
		postorder_rec(rnode->r);
		cout<<" "<<rnode->data;
	}
}
   
     
};
int main()
{
   
   string exp="a-b*c-d/e+f";
   tree t;
  t.generate(exp);
  t.post();
  
}
                       


