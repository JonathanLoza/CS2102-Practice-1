#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <random>
#include <limits>
using namespace std;
void merge(vector<int>& a,int begin, int medio, int end){

    int n1=medio-begin+1;
    int n2=end-medio;
    vector<int> left;
    vector<int> right;
    for(int i=0;i<n1;++i){
        left.push_back(a[i+begin]);
    }
    for(int j=0;j<n2;++j){
        right.push_back(a[j+medio+1]);
    }
    left.push_back(std::numeric_limits<int>::max());
    right.push_back(std::numeric_limits<int>::max());
    int i=0;
    int j=0;
    for(int k=begin;k<=end;++k){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
        }
    }
}

void mergesort(vector<int>& a, int begin, int end){
    if(begin<end){
        int q=(begin+(end-1))/2;
        mergesort(a,begin,q);
        mergesort(a,q+1,end);
        merge(a,begin,q,end);
    }
}


vector<int> insertionsort(vector<int>& a){
    for(int j=1;j<a.size() ;++j){
        int key=a[j];
        int i=j-1;
        while(i>=0 and a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    return a;

}

int main() {
    int average;
    ofstream file("data.dat");
    float timeinsert,timemerge;
    int n=600;
    int veces=0;
    vector<int> num;
    vector<int> num1;
    vector<int> num2;
    while(veces<100) {
        srand((unsigned) time(0));
        int randint;
        for (int index = 0; index < n; index++) {
            randint = (rand() % 1000) + 1;
            num.push_back(randint);
        }
        num1 = num;
        num2 = num;
        clock_t start = clock();
        mergesort(num1, 0, num1.size() - 1);
        clock_t time = clock() - start;
        timemerge=static_cast<float>(time) / CLOCKS_PER_SEC;
        cout << "Mergesort = " << timemerge<< endl;
        start = clock();
        num2 = insertionsort(num2);

        time = clock() - start;
        timeinsert=static_cast<float>(time) / CLOCKS_PER_SEC;
        cout << "Insertionsort = " << timeinsert << endl;
        cout<<"Merge"<<endl;
        for (auto item:num1) {
            cout << item << " ";
        }
        cout<<endl<<"Insertion"<<endl;
        for (auto item:num2) {
            cout << item << " ";
        }
        cout << endl<<endl;
        if(timemerge<timeinsert){
            veces++;
        }else{
            average=n;
        }
        num.clear();
        n+=50;
        file<<n<<" "<<timeinsert<<" "<<timemerge<<endl;
    }
    cout<<"Average: "<<average<<endl;
    return 0;
    file.close();
}