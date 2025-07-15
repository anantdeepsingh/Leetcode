#include<bits/stdc++.h>
using namespace std;
class Complex{
    int a,b;
    public:
    void set(int n1,int n2){
        a=n1;
        b=n2;
    }
    void get(){
        cout<<a<<" + "<<b<<"i"<<endl;
    }
    friend Complex sumComplex(Complex &ob1,Complex &ob2);
};
Complex sumComplex(Complex &ob1,Complex &ob2){
    Complex ob3;
    ob3.a=ob1.a+ob2.a;
    ob3.b=ob1.b+ob2.b;
    ob3.get();
    return ob3;
}
int main(){
    Complex ob1,ob2;
    ob1.set(4,5);
    ob2.set(5,8);
    Complex ob3=sumComplex(ob1,ob2);
}

