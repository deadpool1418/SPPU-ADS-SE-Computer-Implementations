#include<iostream>
#include<set>
#include<iterator>
using namespace std;
class sets
{
    set<int> s,s1;
    set<int>::iterator it;
    public:
     void create()
      {
         int n;
         cout<<"Enter the number to be inserted into set"<<endl;
         cin>>n;
         s.insert(n);
      }
      void search()
       {
           int n;
           cout<<"Enter the number to be searched in set"<<endl;
           cin>>n;
           for(it=s.begin();it!=s.end();it++)
            {
               if(*it==n)
                 cout<<"Number found"<<endl;
             }
        }
       void intersection()
        {
           int n,no;
           set<int>::iterator it1;
           cout<<"Enter the number of elements in set 2"<<endl;
           cin>>n;
           for(int i=0;i<n;i++)
             {cin>>no;s1.insert(no);}
           for(it=s.begin();it!=s.end();it++)
            {
              for(it1=s1.begin();it1!=s1.end();it1++)
                {
                   if(*it==*it1)
                     cout<<*it<<endl;
                 }
             }
         }
       void union_op()
         {
            int n,no;
           set<int>::iterator it1;
           cout<<"Enter the number of elements in set 2"<<endl;
           cin>>n;
           for(int i=0;i<n;i++)
             {cin>>no;s1.insert(no);}
           for(it=s.begin();it!=s.end();it++)
            {
              cout<<*it;
             }
          for(it1=s1.begin();it1!=s1.end();it1++)
            {
               cout<<*it1;
             }
           
         } 
     void display()
      {
         for(it=s.begin();it!=s.end();it++)
           cout<<*it<<" ";
      }
};
int main()
{
    sets S;
    S.create();
    S.create();
    S.create();
    S.display();
    //S.intersection();
    S.union_op();
}
