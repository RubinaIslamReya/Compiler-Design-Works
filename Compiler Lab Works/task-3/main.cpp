#include<iostream>
#include<fstream>
using namespace std;

bool isUpperCase(char s)
{
    if((s>='A'&&s<='Z'))
    {
        return true;
    }
    return false;
}
bool isLowerCase(char s)
{
    if((s>='a'&&s<='z'))
    {
        return true;
    }
    return false;
}
void grammer_check(string sentence,int size)
{
    int flag1=0;

    string error1="";
    string error2="";
    string error3="";
    string error4="";
    string error5="";
    string error6="";

    for(int i=0; i<size; i++)
    {
        if(!isUpperCase(sentence[0]))
        {
            flag1++;
            error1="Enter Capital Letter";
        }
        if(sentence[size-1]!='.')
        {
            flag1++;
            error2="Enter Fullstop";
        }
        if(isUpperCase(sentence[i])&& isUpperCase(sentence[i+1]))
        {
            flag1++;
            error3="Two Capital Letter are not Acceptable";
        }
        if(sentence[i]==' '&& sentence[i+1]==' ')
        {
            flag1++;
            error4="Two Space are not Acceptable";
        }
         if(isLowerCase(sentence[i])&& isUpperCase(sentence[i+1]))
        {
            flag1++;
            error5="No Capital Letter After Small Letter";
        }
        if(sentence[size-2]==' ')
        {
            flag1++;
            error6="No Space Before Fullstop";
        }
    }
    if(flag1==0)
    {
        cout<<"Sentence is CORRECT !!"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Sentence is INCORRECT !!"<<endl;
        cout<<"The Mistakes in Details!"<<endl;
        cout<<endl;
        cout<<error1<<endl;
        cout<<error2<<endl;
        cout<<error3<<endl;
        cout<<error4<<endl;
        cout<<error5<<endl;
        cout<<error6<<endl;
    }

}
int main()
{

fstream f("sentence.txt",fstream::in);
string se;
getline(f,se,'\0');
f.close();
cout<<"The sentence : "<<se<<endl;
grammer_check(se,se.length());
return 0;
}
