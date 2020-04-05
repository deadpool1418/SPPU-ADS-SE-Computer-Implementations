#include<iostream>
#include<fstream>
using namespace std;
class student
{
    public:
        int roll;
        char name[20];
        char div;
        fstream file;
        void put()
           {
                cin>>roll;
                cin>>name;
                cin>>div;
                file.open("student.txt",ios::app | ios::binary);
                file.write((char*)&roll,sizeof(roll));
                file.write((char*)&name,sizeof(name));
                file.write((char*)&div,sizeof(div));
                file.close();
            }
            void display()
               {
                    file.open("student.txt",ios::in | ios::binary);
                    cout<<"Records of Students: "<<endl;
                    cout<<"\n\t\tRoll  \tName  \tDiv"<<endl;
                    while(1)
                      {
                           if(!file.read((char*)&roll,sizeof(roll)))
                                 break;
                           file.read((char*)&name,sizeof(name));
                           file.read((char*)&div,sizeof(div));
                           cout<<"\t\t "<<roll;
                           cout<<"\t"<<name;
                           cout<<"\t "<<div<<endl;
                      }
                      file.close();
                }
                void search(int r)
                  {
                       int flag;
                     // cin>>r;
                      file.open("student.txt",ios::in | ios::binary);
                       //file.seekg(0);
                      while(!file.eof())
                      {
                       //if(!file.read((char*)&roll,sizeof(roll)))
                         //  break;
                          file.read((char*)&roll,sizeof(roll));
                          file.read((char*)&name,sizeof(name));
                           file.read((char*)&div,sizeof(div));
                      //cout<<roll;
                          if(roll==r)
                          {
                             cout<<"\n  Record found!!!\n";
                             flag=1;
                            cout<<"\n\tRoll no :"<<roll<<endl;
                             cout<<"\tName :"<<name<<endl;
                             cout<<"\tDivison :"<<div<<endl;
                             break;
                        }
                          else
                              flag=0;
                      }
                      if(flag==0)
                         cout<<"\nRecord not found\n";
                   file.close();
                }
                void del_data(int r)
                {
                    int flag=0;
                    ofstream file1;
                    file.open("student.txt",ios::in | ios::binary);
                    file1.open("student1.txt",ios::out | ios::binary);
                   while(1)
                      {
                           if(!file.read((char*)&roll,sizeof(roll)))
                                 break;
                           file.read((char*)&name,sizeof(name));
                           file.read((char*)&div,sizeof(div));
                           if(roll==r)
                              flag=1;
                           if(roll!=r)
                              {
                               file1.write((char*)&roll,sizeof(roll));
                          file1.write((char*)&name,sizeof(name));
                           file1.write((char*)&div,sizeof(div));
                           }
                    }
                    if(flag==0)
                       cout<<"\nError while deleting record,data not found!!!\n"<<endl;
                       else
                         cout<<"\nRecord deleted successfully"<<endl;
                   remove("student.txt");
                    rename("student1.txt","student.txt");
                    file.close();
                    file1.close();
                 }
};
int main()
{
   student s;
   int ch,r;
   while(1)
   {
       cout<<"\n\t\t****SEQUENTIAL FILE ORGANIZATION****\n"<<endl;
       cout<<"\t\t  1)Write data into the file"<<endl;
       cout<<"\t\t  2)Display data from a file"<<endl;
       cout<<"\t\t  3)Search data in file"<<endl;
       cout<<"\t\t  4)Delete a record from a file"<<endl;
       cout<<"\t\t  5)Exit\n"<<endl;
       cin>>ch;
       switch(ch)
       {
           case 1:
                s.put();
                break;
           case 2:
                s.display();
                break;
           case 3:
                cout<<"\nEnter the Roll number of student whose record is to be searched\n"<<endl;
                cin>>r;
                s.search(r);
                break;
           case 4:
                cout<<"\nEnter the roll number whose record is to be deleted\n"<<endl;
                cin>>r;
                s.del_data(r);
                break;
           case 5:
                return 0;
        }
     }
     
                
}
