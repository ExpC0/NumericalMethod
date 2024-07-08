#include<bits/stdc++.h>
using namespace std;

double findX(double y,double z){
   
    return (1.0/27.0)*(85-6*y+z);
}

double findY(double x,double z){
    return (1.0/15.0)*(72-6*x-2*z);
}

double findZ(double x,double y){
    return (1.0/54.0)*(110-x-y);
}

int main(){
    /*
    fstream inputf;
    
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    
    inputf.open("input1.txt",ios::out);
 
    inputf << s1<<endl;
    inputf << s2<<endl;
    inputf << s3<<endl;
    

    
    inputf.close();
    
    */
    
    double y=0.0,z=0.0,x;
    
    
    for(int i=1;i<=10;i++){
        cout<<"< Iteration "<<i<<" > ";
       x = findX(y,z);
       cout<<"x = "<<x<<" ";
       y = findY(x,z);
       cout<<"y = "<<y<<" ";

       z = findZ(x,y);
       cout<<"z = "<<z<<" ";
       
       cout<<endl<<endl;
       
  

    }
  
    
    cout<<"x = "<<x<<" y = "<<y<<" z = "<<z<<endl;
    
    
    
}
