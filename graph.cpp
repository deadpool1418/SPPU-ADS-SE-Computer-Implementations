#include<iostream>
using namespace std;
class node
{
   int data;
   node *left,*right;
   node()
    {
         left=NULL;
         right=NULL;
    }
    node(int c)
    {
         data=c;
         left=NULL;
         right=NULL;
    }
   friend class graph;
};
class graph
{
    node *x[10],*root;
    int i,j,v;
      int a[10][10];
        public:
     graph()
     {
           root=NULL;
       i=j=1;
      for(int i=1;i<10;i++)
        {
            for(int j=1;j<10;j++)
                a[i][j]=0;
     }
for(int i=1;i<10;i++)
  x[i]=NULL;
}
      void matrix()
      {
           
           char ch='y';
           cout<<"Enter the number of vertices"<<endl;
           cin>>v;
           cout<<"Enter the connectivity between the vertices(Source-Destination)"<<endl;
           while(ch=='y')
            {
                cin>>i>>j;
                if(a[i][j]==1)
                  cout<<"Edge already exist"<<endl;
                else
                 {
                  a[i][j]=1;
                  a[j][i]=1;
                  }
                 cout<<"Do you want to continue(y/n)"<<endl;
                cin>>ch;
               
           }
     }
 void display_matrix()
     {
          cout<<"Matrix Representation"<<endl;
          for(int m=1;m<=v;m++)
             { 
                 for(int n=1;n<=v;n++)
                    cout<<a[m][n]<<" ";
                 cout<<endl;
              }
    }
  void adjc()
     {
        node *temp;
         for(int i=1;i<=v;i++)
            {
              for(int j=1;j<=v;j++)
                  {
                    if(a[i][j]==1)
                        {
                             if(x[i]==NULL)
                               { 
                                  x[i]=new node(j);
                                  temp=x[i];
                               }
                             else
                               {
                                   node *temp1;
                                   temp1=new node(j);
                                   temp->right=temp1;
                                   temp=temp1;
                               }
                      }
                 }
         }
 }
void display_adjc()
 {cout<<"Adjacency list Representation"<<endl;
       for(int i=1;i<=v;i++)
         {
            node *temp=x[i];
            cout<<i<<"->";
            while(temp!=NULL)
             {
               cout<<temp->data<<"->";
               temp=temp->right;
                }
            cout<<endl;
}
 }
}; 
int main()
{   
  graph z;
  z.matrix();
  z.display_matrix();
  z.adjc();
  z.display_adjc();
}
