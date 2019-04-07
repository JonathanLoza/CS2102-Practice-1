#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string addceros(const string &a, int b, bool lado){
    string respuesta="";
    //si lado es 1 entonces agregara 0s a la derecha
    if(lado==1){
        respuesta=a;
        for(int i=0;i<b;++i)
            respuesta+='0';
    }//caso contrario agregara 0s a la izquierda
    else{
        for(int i=0;i<b;++i)
            respuesta+='0';
        respuesta+=a;
    }
    return respuesta;
}

//Classic
string operator*(const string &a, const string &b){
    string respuesta="";
    int sizea=a.size();
    int sizeb=b.size();
    vector<int> answer(sizea+sizeb,0);
    int puntero,i,j,out,multi,pos=0;
    for (i = sizea-1 ;  i>=0; --i) {
        puntero=pos;
        out=0;
        for(j=sizeb-1 ;j>=0;--j){
            multi=(b[j]-48)*(a[i]-48)+out+answer[puntero];
            if(multi>=10){
                out=multi/10;
                answer[puntero]=multi%10;
            }else{
                out=0;
                answer[puntero]=multi;
            }
            puntero++;
        }
        if(out>0){
            answer[puntero]+=out;
        }
        pos++;
    }
    bool x=true;
    for(int z=answer.size()-1;z>=0;--z){
        if(answer[z]==0 && x )
            continue;
        x=false;
        respuesta+=to_string(answer[z]);
    }
    if(x)
        return respuesta="0";
    return respuesta;
};

string operator-(const string &a,const string &b){
    string respuesta="";
    int sizea=a.size();
    int sizeb=b.size();
    int diferencia=sizea-sizeb;
    string newb=addceros(b,diferencia,0);
    sizeb=newb.size();
    vector<int> answer(sizea,0);
    int i,j,resta,pos=0,out=0;
    for(i=sizea-1;i>=0;--i){
        answer[pos]+=a[i]-48;
        pos++;
    }
    pos=0;
    for(j=sizeb-1;j>=0;--j){
        resta=answer[pos]-(newb[j]-48)-out;
        if(resta<0){
            out=1;
            answer[pos]=10+resta;
        }else{
            out=0;
            answer[pos]=resta;
        }
        pos++;
    }
    bool x=true;
    for(int z=answer.size()-1;z>=0;--z){
        if(answer[z]==0 && x )
            continue;
        x=false;
        respuesta+=to_string(answer[z]);
    }
    if(x)
        return respuesta="0";
    return respuesta;
};

string operator+(const string &a, const string &b){
    string respuesta="";
    int sizea=a.size();
    int sizeb=b.size();

    vector<int> answer(sizea > sizeb  ? sizea+1 : sizeb+1,0);
    int i,j,suma,pos=0,out=0;
    for(i=sizea-1;i>=0;--i){
        answer[pos]+=a[i]-48;
        pos++;
    }
    pos=0;
    for(j=sizeb-1;j>=0;--j){
        suma=(b[j]-48)+answer[pos]+out;
        if(suma>=10){
            out=suma/10;
            answer[pos]=suma%10;
        }else{
            out=0;
            answer[pos]=suma;
        }
        pos++;
    }
    if(out>0)
        answer[pos]+=out;
    bool x=true;
    for(int z=answer.size()-1;z>=0;--z){
        if(answer[z]==0 && x )
            continue;
        x=false;
        respuesta+=to_string(answer[z]);
    }
    if(x)
        return respuesta="0";
    return respuesta;
}

string karatsuba(const string &n1, const string &n2){
    string a,b,c,d,respuesta;
    if(n1.size()==1 || n2.size()==1){
        respuesta=n1*n2;
        return respuesta;
    }
    else{
        string ac,bd,ab,cd,suma,resta, m1,m2,N1,N2;
        int resto=0,size2=0;
        int size = max(n1.size(),n2.size());
        if (size % 2 == 1)
        {
            size = (size + 1) ;
        }
        size2=size/2;
        if(n1.size()<size){
            resto=size-n1.size();
            N1=addceros(n1,resto,0);
        }else{
            N1=n1;
        }
        if(n2.size()<size){
            resto=size-n2.size();
            N2=addceros(n2,resto,0);
        }
        else{
            N2=n2;
        }
        a=N1.substr(0,size2);
        b=N1.substr(size2, size2);
        c=N2.substr(0, size2);
        d=N2.substr(size2, size2);

        ac=karatsuba(a,c);
        bd=karatsuba(b,d);
        ab=a+b;
        cd=c+d;
        suma=karatsuba(ab,cd);
        resta=suma-bd;
        resta=resta-ac;

        m1=addceros(ac,size,1);
        m2=addceros(resta,size2,1);

        respuesta=m1+m2;
        respuesta=respuesta+bd;
    }
    return respuesta;

};

int main() {

    string a="36334570022123324633457902146334579021123161";
    string b="63345730142123324633457901246334579021123232";
    string a1="6351656156315631654514514651465467";
    string b1="6351656156315631621267124651465467";

    string a2="3001233451452561230";
    string b2="3001212332463345790";

    string a3="300221233246334579021";
    string b4="301421233246334579012";

    string a5="36334570022123324633457902146334579021123161";
    string b5="63345730142123324633457901246334579021123232";
    cout<<"Karatsuba"<<endl<<endl;
    clock_t start = clock();
    cout<<karatsuba(a,b)<<endl<<endl;
    cout<<karatsuba(a1,b1)<<endl<<endl;
    cout<<karatsuba(a2,b2)<<endl<<endl;
    cout<<karatsuba(a3,b4)<<endl<<endl;
    cout<<karatsuba(a5,b5)<<endl<<endl;
    clock_t time = clock() - start;
    cout << "Karatsuba time = " << static_cast<float>(time) / CLOCKS_PER_SEC<< endl;

    cout<<"Classic Multiplication"<<endl<<endl;
    start = clock();

    cout<<a*b<<endl<<endl;
    cout<<a1*b1<<endl<<endl;
    cout<<a2*b2<<endl<<endl;
    cout<<a3*b4<<endl<<endl;
    cout<<a5*b5<<endl<<endl;
    time = clock() - start;
    cout << "Third Grade time = " << static_cast<float>(time) / CLOCKS_PER_SEC<< endl;
    cout<<endl<<endl;
    cout<<"A*B Multiplication"<<endl;
    string Teachera="3141592653589793238462643383279502884197169399375105820974944592";
    string Teacherb="2718281828459045235360287471352662497757247093699959574966967627";
    cout<<Teachera*Teacherb<<endl;

    return 0;
}