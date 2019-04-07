#include <iostream>
#include <vector>
#include <string>

using namespace std;

int operation(int a, int b){
  int x;
  int ciclomax=0;
  int ciclo;
  if(a>b){
    x=a;
    a=b;
    b=x;
  }
  for(a;a<=b;a++){
    ciclo=1;
    x=a;
    while(x!=1){
      if(x%2!=0){
        x=3*x+1;
      }
      else{
        x=x/2;
      }
      ciclo+=1;
    }
    if(ciclo>ciclomax){
      ciclomax=ciclo;
    }

  }
  return ciclomax;
}


int main(){
  int x,y;
  while(cin>>x>>y){
    cout<<x<<" "<<y<<" "<<operation(x,y)<<endl;
  }

  return 0;
}
