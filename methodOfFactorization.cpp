

#include<bits/stdc++.h>
using namespace std;

#define N 3
#define M 4
#define iteration 5

int A[3][3];

bool isDigit(char c)
{
    if(c>='0' && c<='9') return 1;
    else return 0;
}
int isOperator(char c)
{
    if(c=='+') return 1;
    else if(c=='-') return 2;
    else return 0;
}
void file_read()
{
    ifstream in;
    in.open("input1.txt");
    fstream out("output.txt");
    int i,j;
    string s;
    int count=0;
    while(in>>s)
    {
        char c;
        int number=0,a[4]={0};
        bool sign=0;
        for(i=0;i<s.size();i++)
        {
            if(isDigit(s[i]))
            {
                if(number==0) number=s[i]-48;
                else number*=10,number+=s[i]-48;
            }
            else if(isOperator(s[i]))
            {
                sign=((isOperator(s[i])==1)?0:1);
            }
            else if(s[i]=='=')
            {
                sign=0;
            }
            else
            {
                int index;
                if(number==0) number=1;
                if(sign) number*=-1;
                if(s[i]=='x') index=0;
                else if(s[i]=='y') index=1;
                else if(s[i]=='z') index=2;
                a[index]=number;
                sign=0;
                number=0;
            }
        }
        if(sign) number*=-1;
        a[3]=number;
        for(i=0;i<M;i++)
        {
            cout<<a[i]<<" ",out<<a[i]<<" ";
            if(i<M-1) A[count][i]=a[i];
        }
        cout<<endl,out<<endl;
        count++;
    }
}
void solution()
{
    int i,j;
    float U[3][3]={0},L[3][3]={0};
    L[0][0]=L[1][1]=L[2][2]=1;

    U[0][0]=A[0][0];
    L[1][0]=A[1][0]/U[0][0];
    L[2][0]=A[2][0]/U[0][0];

    U[0][1]=A[0][1];
    U[1][1]=A[1][1]-L[1][0]*U[0][1];
    L[2][1]=(A[2][1]-L[2][0]*U[0][1])/U[1][1];

    U[0][2]=A[0][2];
    U[1][2]=A[1][2]-L[1][0]*U[0][2];
    U[2][2]=A[2][2]-L[2][0]*U[0][2]-L[2][1]*U[1][2];

    cout<<"Upper Matrix:"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) printf("%10f ",U[i][j]);
        cout<<endl;
    }
    cout<<"Lower Matrix:"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) printf("%10f ",L[i][j]);
        cout<<endl;
    }
    
    
}

int main()
{
    int i,j;
    file_read();
    solution();
}
