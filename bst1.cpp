#include<iostream>
using namespace std;
class node
{
      
     int data;
     node *left;
     node *right;
       public:
          node()
            {
	left=NULL;
	right=NULL;
            }
         node(int x)
           {
           	   data=x;
           	   left=NULL;
           	   right=NULL;
	   }
 friend class bst;
};
class bst
{
     public:
     
       int flag;
       node *root;
         bst()
          {
            root=NULL;
         }
       void create(node *t,int z)
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
			
		}
void insert(node *t,int z)
{
         node *temp;
			    
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

       void pre(node *t)
          {
	if(t!=NULL)
	{
	pre(t->left);
	cout<<t->data<<" ";
	pre(t->right);
	}
        }
       void swap(node *t)
           {
	node *temp;
	node *temp1;
	temp=t;
	if(t!=NULL)
	{
		temp1=temp->left;
		temp->left=temp->right;
		temp->right=temp1;
		swap(t->left);
		swap(t->right);
	}
        
           
         }
      int search(node *t,int x)
          {
    	  
	  node *temp;
	  if(t!=NULL)
	    {
	        if(t->data==x)
	          {
		    flag=1;
		    
           	   }
	else if(t->data!=x && flag!=1)
	 {
	 	search(t->left,x);
	 	search(t->right,x);
	 	flag=0;
	 }
         }
	 
  }
   void min(node *t)
      {
          while(t->left!=NULL)
            {
                 t=t->left;
            }
         cout<<"Minimum data value in a tree is "<<t->data<<endl;
      }
	
};
int main()
{
	bst a;
	int x,n;
	int ch;
           
          while(1)
          {
              cout<<"Enter your choice\n :1)Creation of a tree\n  2)Insert a node\n  3)Minimum data value in a tree\n  4)Swap left and right nodes\n  5)Search\n  6)Display tree"<<endl;
 	       cin>>ch;
          switch(ch)
             { 
                 
                 case 1:
	         {
		cout<<"Enter the no of nodes in a tree"<<endl;
		cin>>n;
                        cout<<"Enter the nodes"<<endl;
                        while(n!=0)
                        {
                          cin>>x;
		a.create(a.root,x);
		n--;
		}
                      break;
	       }
                case 2:
                    {
                        cout<<"Enter the node to be inserted in a tree"<<endl;
                        cin>>x;
                        a.create(a.root,x);
                        break;
                    }
               case 3:
                    a.min(a.root);
                     break;
               case 4:
                   a.swap(a.root);
                    break;
               case 5:
                   cout<<"Enter the value to be search"<<endl;
                   cin>>x;
                   a.search(a.root,x);
                        if(a.flag==1)
                          cout<<"No Found"<<endl;
                       else
                           cout<<"No not found"<<endl;
                     break;
               case 6: 
                   a.pre(a.root);
                     break;
                      
          }
}

	
       
}
