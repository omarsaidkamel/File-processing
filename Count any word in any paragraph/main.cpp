#include <iostream>
#include<fstream>
using namespace std;
int main()
{int c=0;string word,in;ofstream outf;ifstream inf;
outf.open("outf.txt");inf.open("inf.txt");
cout<<"Enter The Word Do You Want To count From The File.\n";
cin>>in;
while(!inf.eof())
    {inf>>word;
     if(in==word){c++;}}
     cout<<in<<" Is Found "<<c<<" Times ";
outf.close();inf.close();
    return 0;
}

