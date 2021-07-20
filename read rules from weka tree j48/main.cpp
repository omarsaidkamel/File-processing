#include <bits/stdc++.h>
using namespace std;
bool comp(string l,string o,string r){
     stringstream ss1,ss2;int x,y;
      ss1<<l;ss2<<r; ss1>>x;ss2>>y;
      if(o[0]=='>'){
        if(o[1]=='=') {
            if(x>=y)return true;
            else return false;
        }
        else {
            if(x>y)return true;
            else return false;
        }
      }
      else if(o[0]=='<'){
        if(o[1]=='='){
            if(x<=y)return true;
            else return false;
        }
        else {
            if(x<y)return true;
            else return false;
        }
      }
      else{
         if(l==r)return true;
         else return false;
      }
}
int main()
{
    /////////////////////Take input////////////////////////////////
    ifstream newfile;string S="",xx[1005];int att=0,hi=0;
    bool f=1,g=1;
   vector<pair<string,pair<string,pair<string,string>>>>ABC;
    newfile.open("weka.txt");
    while(getline(newfile, S)){
         S.erase(remove(S.begin(), S.end(), ' '), S.end());
         int n=S.size();string s="";
         if(!g){
           for(int i=0;i<n;i++){
            while(S[i]=='|')i++;
            s+=S[i];bool yy=0;
            for(int j=0;j<att;j++){
                if(s==xx[j]){yy=1;break;}
            }
            if(yy){
                string a = s,b="",c="",d="";i++;
                    if(S[i]=='='||S[i]=='>'||S[i]=='<'){b+=S[i];i++;}
                    if(S[i]=='='){b+=S[i];i++;}
                       int u=0;
                       for(int h=i;h<n;h++) {
                            if(S[h]==':'){u=h+1;break;}
                            c+=S[h];
                       }
                       if(u){
                          for(int h=u;h<n;h++){
                            if(S[h]=='(')break;
                            d+=S[h];
                          }
                       }
                    ABC.push_back(make_pair(a,make_pair(b,make_pair(c,d))));
            }
           }
         }
         if(!f&&g){
           if(att>hi) xx[hi++]=S;
         }
         if(att==hi&&att!=0)g=0;
         if(f){
           for(int i=0;i<n;i++){
            s+=S[i];
            if(s == "Attributes:"){
                if(S[n-2]>'0'&&S[n-2]<'9')att=10*(S[n-2]-'0');
                att+=S[n-1]-'0';f=0;
            }
           }
         }
        // cout << S << "\n";
    }
    /////////////////////get the result////////////////////////////////
    int Rules = ABC.size();
    for(int i=0;i<Rules;i++){
        cout<<ABC[i].first<<" "<<ABC[i].second.first<<" "<<ABC[i].second.second.first<<" "<<ABC[i].second.second.second<<"\n";
       puts("///");
    }
    puts("\nGet Input\n");
    map<string,string>input;
    for(int i=0;i<att-1;i++){
        cout<<xx[i]<<":";
        cin>>input[xx[i]];
    }
    puts("");
    for(int i=0;i<Rules;i++){
        if(ABC[i].second.second.second==""){
            if(!comp(input[ABC[i].first],ABC[i].second.first,ABC[i].second.second.first)){
                string Copy = ABC[i].first;
                i++;
                while(ABC[i].first != Copy && i < Rules)i++;
                i--;
            }
        }
        else {
            if(comp(input[ABC[i].first],ABC[i].second.first,ABC[i].second.second.first)){cout<<xx[att-1]<<" : "<<ABC[i].second.second.second;return 0;}
            else{
                string Copy = ABC[i].first;
                i++;
                while(ABC[i].first != Copy && i < Rules)i++;
                i--;
            }
        }
    }
    puts("Invalid input");
    return 0;
}
