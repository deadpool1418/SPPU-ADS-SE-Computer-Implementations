#include<iostream>
using namespace std;
class heap
{
     int a[50],s[50],n,no;
     public:
        void read()
          {
               cout<<"Enter the number of students"<<endl;
               cin>>n;
               cout<<"Enter the marks scored by studennts"<<endl;
               for(int i=0;i<n;i++)
                  {
                     
                       cin>>a[i];
                      
                  }
           }
         void heap_tree(int m)
           {
                int temp,root;
                for(int i=m-1;i>=0;i--)
                  {
                       root=(i-1)/2;
                       if(a[root]<a[i])
                         { 
                        
                              temp=a[root];
                              a[root]=a[i];
                              a[i]=temp;
                         }
                   }
             }
             void heap_sort()
                {
                     int j=0;
                     no=n;
                     heap_tree(no);
                     for(int i=0;i<n;i++)
                        {
                             s[j]=a[0];//cout<<s[j]<<" ";
                             a[0]=a[no-1];//cout<<a[0]<<"  ";
                             no--;j++;
                             heap_tree(no);
                        }
                 }
                             
         void max_min()
             {
                   cout<<"Maximum marks obtained : "<<s[0]<<endl;
                   cout<<"Minimum marks obtained : "<<s[n-1]<<endl;
              }
     };
  int main()
     {
            heap z;
            z.read();
            z.heap_sort();
            z.max_min();
       }
            
