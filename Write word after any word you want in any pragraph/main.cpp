#include <iostream>
#include<fstream>
using namespace std;
int main()
{string ward,name,man;int i=0;char d,a; fstream file;
file.open("input_file.txt",ios::out|ios::in);
cout<<"Inter The Word That You Want To Write After It\n";
cin>>ward;
file<<ward;file.seekg(ios::beg);
cout<<"What Do You Want To Write\n";
cin>>d;
while(!file.eof())
    {
        a=file.get();
     if(d==a)
        {cout<<"found";
        return 0;
        }
    }
 cout<<"not found";
file.close();
    return 0;
}
