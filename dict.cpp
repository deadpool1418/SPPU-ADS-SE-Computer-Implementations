#include<iostream>
#include<string.h>
using namespace std;
class dictionary
{
   string dict[10][2];
   string key,value;
   public:
     dictionary()
      {
         for(int i=0;i<10;i++)
           {
             for(int j=0;j<2;j++)
                dict[i][j]="--";
            }
      }
      int asci(string s)
       {
          int ascii=0;
          for(int i=0;i<s.length();i++)
            ascii=ascii+s[i];
          return ascii;
       }
     int hash(int a)
      {
          int h=a%10;
          return h;
      }
      void insert()
       {
          int index,a;
          cout<<"Enter the key,value pair to be inserted into Dictionary"<<endl;
          cin>>key;
          cin>>value;
          a=asci(key);
          index=hash(a);
          if(dict[index][0]=="--")
          {
            dict[index][0]=key;
            dict[index][1]=value;
          }
          else if(dict[index][0]!="--")
           {
               for(int i=1;i<10;i++)
                {
                 index=hash(a+i);
                if(dict[index][0]=="--")
                 {
                  dict[index][0]=key;
                  dict[index][1]=value;
                  break;
                 }
                else if(dict[index][0]!="--")
                 {
                    index=hash(a-i);
                 if(dict[index][0]=="--")
                 {
                  dict[index][0]=key;
                  dict[index][1]=value;
                  break;
                 }
               }
              }
            }
          }
          void delete_value()
          {
              cout<<"Enter the key whose value is to be deleted"<<endl;
              cin>>key;
              int a=asci(key);
              int ind=hash(a);
              dict[ind][0]="--";
              dict[ind][1]="--";
          }
     void display()
      {
         cout<<"\nDICTIONARY:\n"<<endl;
         cout<<"   Index  "<<" Key   "<<"Value"<<endl; 
         for(int i=0;i<10;i++)
          {
          cout<<"    "<<i<<" \t   ";
            for(int j=0;j<2;j++)
              cout<<dict[i][j]<<"\t  ";
            cout<<endl;
          }
      }
};
int main()
{
    dictionary d;
    int ch;
    while(1)
    {
       cout<<"\n   1)Create Dictionary\n   2)Insert Value\n   3)Delete Value\n   4)Display\n";
       cin>>ch;
       switch(ch)
       {
          case 1:
             int n;
             cout<<"  Enter the number of elements of Dictionary"<<endl;
             cin>>n;
             for(int i=0;i<n;i++)
               d.insert();
             break;
          case 2:
            d.insert();
            break;
          case 3:
            d.delete_value();
            break;
          case 4:
            d.display();
        }
     }
} 

    
