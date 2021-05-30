#include <iostream>
#include <fstream>
using namespace std;
class student{


public:
int id;
char name[20];
float grade;
char dilim;



};




int main()
{

    char again;
    fstream file;
   file.open("student.txt",ios::in|ios::out|ios::app);
   fstream news("newStudent.txt",ios::in);
   if(!news.good()||!file.good()){

    cout<<"can't open file"<<endl;
   }
    student x;

    do{
cout<<"enter name"<<endl;
cin.getline(x.name ,20);
file << x.name <<',';
cout<<"enter id"<<endl;
cin>>x.id;
file << x.id <<',';
cout<<"enter grade"<<endl;
cin>>x.grade;
file <<x. grade <<'$';

   cout<<"want to add"<<endl;
          cin>>again;
          cin.ignore();
   }while(again=='y');

news.seekg(0,ios::end);
long size=news.tellg();
news.seekg(0);
char *buffer=new char[size];
news.read(buffer,size);
file.seekp(0,ios::end);
file.write(buffer,size);
news.close();
file.close();
//read from file
    string line;
    int count=0;
   ifstream infile;
   infile.open("student.txt");
   cout << "Reading from the file" << endl;
  while ( getline(infile, line,'$')) {
        count++;
        cout <<count<<":" <<line << endl;
    }
cout<<"number of student :"<<count<<endl;
infile.close();

   return 0;
}
