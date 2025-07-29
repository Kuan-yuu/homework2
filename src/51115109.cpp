//問題一//
#include<iostream>
using namespace std;

class T
{
    friend class P;
private:
    float c;
    int e;
};

class P
{
private:
    T *ta;
    int c;
    int t;
public:
    P()
    {
        c=10;
        ta=new T[c];
        t=0;
    }
    ~P()
    {
        delete[]ta;
    }
};

//問題二//
#include<iostream>
using namespace std;

class T
{
    friend class P;
private:
    float c;
    int e;
};

class P
{
private:
    T* ta;
    int c;
    int t;
public:
    P()
    {
        c=10;
        ta=new T[c];
        t=0;
    }
    ~P()
    {
        delete[]ta;
    }
    friend istream& operator>>(istream& in,P& p)
    {
        cout<<"Enter number of terms: ";
        in>>p.t;
        if(p.t>p.c)p.t=p.c;
        for(int i=0;i<p.t;i++)
        {
            cout<<"Enter coefficient and exponent for term "<<i+1<<": ";
            in>>p.ta[i].c>>p.ta[i].e;
        }
        return in;
    }
    friend ostream& operator<<(ostream& out,const P& p)
    {
        for(int i=0;i<p.t;i++)
        {
            if(i>0&&p.ta[i].c>=0)out<<"+";
            out<<p.ta[i].c;
            if(p.ta[i].e>0)out<<"x^"<<p.ta[i].e;
        }
        if(p.t==0)out<<"0";
        out<<endl;
        return out;
    }
};

int main()
{
    P p;
    cout<<"Input polynomial:"<<endl;
    cin>>p;
    cout<<"Polynomial: "<<p;
    return 0;
}
