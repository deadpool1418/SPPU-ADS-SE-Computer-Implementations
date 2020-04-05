#include<iostream>
using namespace std;
class heap
{
   int a[20],b[20],n;
   public:
       void read()
           {
               cout<<"Enter the number of students"<<endl;
               cin>>n;
               cout<<"Enter the marks scored by students"<<endl;
               for(int i=0;i<n;i++)
                   cin>>a[i];
           }
       void max_heap()
          {
               int root,temp;
               for(int i=n-1;i>=0;i--)
                  {
                      root=(i-1)/2;cout<<root;
                      if(a[root]<a[i])
                        {
                            temp=a[i];
                            a[root]=temp;
                            a[i]=a[root];
                        }
                   }
           }
          void display()
           {
               for(int i=0;i<n;i++)
                  cout<<a[i]<<" ";
           }
};
int main()
{
    heap z;
    z.read();
    z.max_heap();
  //  z.display();
}
