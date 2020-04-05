#include<iostream>
#include<string.h>
using namespace std;
class node
{
   char data[20];
   int weight;
   node *next;
   node()
    {
         next=NULL;
    }
    node(char c[])
    {
         strcpy(data,c);
         next=NULL;
    }
     node(int c)
    {
         weight=c;
         next=NULL;
    }
   friend class graph;
};
class graph
{
    node *x[10],*root;
    node *z[10];
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
for(int i=1;i<v;i++)
  x[i]=NULL;
}
      void matrix()
      {
	       int w;
		   char city[20];
		   char src[20],des[20];
		   char ch='y';
           cout<<"Enter the number of vertices"<<endl;
           cin>>v;
           for(int p=1;p<=v;p++)
           {
           	   cout<<"Enter city name";
           	   cin>>city;
           	   z[p]=new node(city);
           
		   }
           cout<<"Enter the connectivity between the vertices(Source-Destination) and cost"<<endl;
           while(ch=='y')
            {
                cin>>src;
                cin>>des;
                cin>>w;
                for(int p=1;p<=v;p++)
                   {
                   	if(strcmp(z[p]->data,src)==0)
                   	   i=p;
                   	else if(strcmp(z[p]->data,des)==0)
                   	   j=p;
				   }
				   cout<<i<<j;
                if(a[i][j]==w)
                  cout<<"Edge already exist"<<endl;
                else
                 {
                  a[i][j]=w;
                  a[j][i]=w;
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
        int no;
         for(int i=1;i<=v;i++)
            {
              for(int j=1;j<=v;j++)
                  {
                    if(a[i][j]!=0)
                        {
                             if(x[i]==NULL)
                               { 
                                  no=a[i][j];
                                  x[i]=new node(no);
                                  strcpy(x[i]->data,z[j]->data);
                                  temp=x[i];
                               }
                             else
                               {
                               	   no=a[i][j];
                                   node *temp1;
                                   temp1=new node(no);
                                   strcpy(temp1->data,z[j]->data);
                                   temp->next=temp1;
                                   temp=temp1;
                               }
                      }
                 }
         }
 }
void display_adjc()
 {cout<<"Adjacency list Representation - Source->Destination(Cost)"<<endl;
       for(int i=1;i<=v;i++)
         {
            node *temp=x[i];
            
            cout<<z[i]->data<<"->";
            while(temp!=NULL)
             {
               cout<<temp->data;
               cout<<"("<<temp->weight<<")"<<"->";
               temp=temp->next;
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
