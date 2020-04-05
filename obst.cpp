#include<iostream>
using namespace std;
class obst
{
    int p[10],q[10],w[10][10],c[10][10],r[10][10];
    int n,a;
    public:
    obst()
    {
       for(int i=0;i<10;i++)
         {
            for(int j=0;j<10;j++)
              {w[i][j]=0;c[i][j]=0;r[i][j]=0;}
         }
    }
   void read()
    {
       cout<<"Enter the no of keys"<<endl;
       cin>>n;
       cout<<"Enter the successfull probabilities"<<endl;
       for(int i=1;i<=n;i++)
         cin>>p[i];
       cout<<"Enter the unsuccessful probabilities"<<endl;
       for(int i=0;i<=n;i++)
         cin>>q[i];
    }
   int cal_min(int i,int j)
    {  
       
       int root;
       int d=j-i;
       int min=10000;
       int m[10][2];
       a=j;
       for(int t=0;t<d;t++)
        {
           m[t][0]=c[i][a-1]+c[a][j];
           m[t][1]=a;
           a=a-1;
        }
       for(int t=0;t<d;t++)
        {
          if(m[t][0]<min)
           {
             min=m[t][0];
             root=m[t][1];
           }
         }
        r[i][j]=root;
      return min;
      }
     int cal()
      {
         int i,j,z;
        for(i=0,j=0;i<=n,j<=n;i++,j++)
         {
           w[i][j]=q[i];
           c[i][j]=0;
          }
         for(i=1;i<=n;i++)
          {
            for(j=0;j<=n;j++)
              {
                int x;
                int k=i+j;
                w[j][k]=w[j][k-1]+q[k]+p[k];
                x=cal_min(j,k);
                c[j][k]=w[j][k]+x;
               }
            }
         }
       void display()
        {
           for(int i=0;i<=n;i++)
            {
              for(int j=0;j<=n;j++)
                {
                
                   cout<<r[i][j]<<"/"<<c[i][j]<<"/"<<w[i][j]<<" ";
                 }
               cout<<endl;
            }
         }
};
int main()
{
  obst o;
  o.read();
  o.cal();
  o.display();
}
       
         
