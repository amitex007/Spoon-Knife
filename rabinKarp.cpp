#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include<fstream>
using namespace std;
int value(char);
long long int hash1(char *, int);

int main()
{

    char *s1=new char[20];
    char *s2=new char[5];
    ofstream mk;
    mk.open("input.txt");
    for(int i=0;i<20;i++)
    {
        if(i<10)
            mk<<"a";
        else if(i>15)
            mk<<"a";
        else mk<<"b";
    }
    mk<<"\n";
    for(int i=0;i<5;i++)
        mk<<"b";
    mk.close();
    ifstream mf;
    mf.open("input.txt");
    //string s1,s2;
    cout<<"Enter first string"<<endl;
    mf>>s1;
    cout<<"Enter string to be searched"<<endl;
    mf>>s2;
    int l=strlen(s2);
    long long int hs=hash1(s2,l);
    long long int ht=hash1(s1,l);



    for(int i=0;i<=strlen(s1)-l;i++)
    {
        //cout<<"This is check "<<i<<" "<<hs<<" "<<ht<<endl;

        if(hs==ht)
        {
            if(strncmp(s2,s1+i,l)==0)
            {
                cout<<"string fount at "<<i+1<<endl;
            }
        }
       // cout<<value(s1[i])<<endl;
        ht=(ht- value(s1[i])*pow(101,l-1))*101 + value(s1[i+l]);
    }
    mf.close();
    return 0;

}
long long int hash1(char *x,int l)
{
    long long int z=0;
    for(int i=0;i<l;i++)
    {
        z=z*101 + value(x[i]);
    }
    return z;
}
int value(char m)
{
    return m;

}
