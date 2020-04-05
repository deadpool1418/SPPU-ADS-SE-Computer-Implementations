#include<iostream>
using namespace std;
class hashing
{
    //int key;
   long int hash[10],i,index,count,col[10],k;
    public:
       hashing()
       {
         k=-1;i=0;count=0;
         for(int j=0;j<10;j++)
             hash[j]=0;
       }
       int hashFun(long int k)
         {
             int h;
             h=k%10;
             return h;
         }
       void insert(long int no)
        {
            int flag,p;
            index=hashFun(no);//cout<<index<<" ";
            if(hash[index]==0)
                hash[index]=no;
            else if(hash[index]!=0)
              {
                 for(int i=0;col[i]!='\0';i++)
                   {
                      if(hash[index]==col[i] && index!=col[i]%10)
                        {p=col[i];hash[index]=no;insert(p);flag=1;break;}
                   }         
                  for(int j=1;j<10 && flag!=1;j++)
                   {
                      index=hashFun(no+j);
                      if(hash[index]==0)
                         {
                           hash[index]=no;
                           col[++k]=no;
                           count++;
                           cout<<"\nCollision occured at index "<<(index-j)%10<<" collision number is "<<count<<endl;
                           break;
                          }
                      else
                       {
                         index=hashFun(no-j);
                         if(hash[index]==0)
                           {
                              hash[index]=no;
                              col[++k]=no;
                              count++;
                           cout<<"\nCollision occured at index: "<<(index+j)%10<<" collision number is"<<count<<endl;
                              break;
                           }
                       }
                   }
               
               }
            }
         
         void display()
           {
                cout<<"  INDEX"<<"    "<<"KEY"<<endl;
               for(int j=0;j<10;j++)
                  cout<<"   "<<j<<"   \t   "<<hash[j]<<endl;
            }
};
int main()
{
  int ch;long int n;
  hashing H;
  while(1)
  {
     cout<<"\n\tMenu:\n\t1)Insert\n\t2)Display Table\n\t3)Exit\n";
     cin>>ch;
     switch(ch)
       {
            case 1:
              cout<<"Enter the key to be inserted into hash table"<<endl;
              cin>>n;
              H.insert(n);
              break;
            case 2:
              cout<<"\nHash Table:\n"<<endl;
              H.display();
              break;
            case 3:
               return 0;
        }
   }
}
