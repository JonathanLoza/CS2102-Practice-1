#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  string answer="";
  while(cin>>str){
    int x=str.size();
    for(int i=0;i<x;++i){
      answer+=str[i]-7;
    }
    cout<<answer<<endl;
    answer="";
  }
  return 0;
}
