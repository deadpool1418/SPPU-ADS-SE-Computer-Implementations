#include<iostream>
using namespace std;
struct node
{
      
     int data;
     node *left;
     node *right;
 }*root;

class avl
{
     public:
     
       int flag;
         avl()
          {
            root=NULL;
         }
      /* void create(node *t,int z)
	{
	node *temp;
	if(t==NULL)
	  {
	  	t=new node(z);
	    root=t;
	  }
	  else
	    {
	    	temp=t;
	    	if((temp->data)>z)
	    	  {
                       	       if(temp->left!=NULL)
   	  	     create(temp->left,z);
  	  	 else
	  	 {
						  
  	  	   temp->left=new node(z);
		  }
		  }
	        if((temp->data)<=z)
	            {
	    	  if(temp->right!=NULL)
	                create(temp->right,z);
  	  	 else
                    	  {
                             temp->right=new node(z);
		 }
		  }
		}
			
		}*/
       node *create(node *t,int z)
	{
	    if(root==NULL)
	       {
	          root=new node;
	          root->data=z;
	          root->left=NULL;
	          root->right=NULL;
	          return root;
	       }
	    else if(z<(root->data))
	      {
	          root->left=create(root->left,z);
	          root=balance(root);
	      }
	  else if(z>=(root->data))
	     {
 	          root->right=create(root->right,z);
	          root=balance(root);
	      }
	   return root;
	}
       int height(node *temp)
       {
           int rh=0,lh=0,h=0;
           if(temp!=NULL)
           {
           rh=height(temp->right);
           lh=height(temp->left);
           if(rh>lh)
               h=rh+1;
           else
               h=lh+1;
           }
           return h;
        }
      int bfactor(node *temp)
        {
           int r_h=height(temp->right);
           int l_h=height(temp->left);
           int bf=l_h-r_h;
           return bf;
        }
     node *RR(node *parent)
        {
               node *temp;
               temp = parent->right;
               parent->right = temp->left;
               temp->left = parent;
               return temp;
        }
      node *LL(node *parent)
        {
            node *temp;
            temp=parent->left;
            parent->left=temp->right;
            temp->right=parent;
            return temp;
        }
      node *RL(node *parent)
        {
            node *temp;
            temp=parent->right;
            parent->right=LL(temp); 
            return RR(parent);
        }
       node *LR(node *parent)
        {
            node *temp;
            temp=parent->left;
            parent->left=RR(temp); 
            return LL(parent);
        }
     node *balance(node *temp)
        {
            int b=bfactor(temp);
            if(b>1)
              {
                  if(bfactor(temp->left)>0)
                      temp=LL(temp);
                  else
                      temp=LR(temp);
               }
             else if(b<-1)
                {
                     if(bfactor(temp->right)>0)
                         temp=RL(temp);
                     else
                         temp=RR(temp);
                }
             return temp;
         }
       void pre(node *t)
          {
	if(t!=NULL)
	{cout<<t->data<<" ";
	pre(t->left);
	pre(t->right);
	}
        }
};
int main()
{
   avl z;
   root=z.create(root,1);
   root=z.create(root,2);
   root=z.create(root,3);
   root=z.create(root,4);
   z.pre(root);
  

}
