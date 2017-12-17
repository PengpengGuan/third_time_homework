#include <iostream>
#include <stdio.h>  
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <omp.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
FILE *file2;
file2=fopen("sushu_output_bing.txt","w");
//fstream file2("sushu_output_bing.txt",ios::in);
//FILE* file2=open("sushu_output_bing.txt","w");
int flag=1;
int count=0;
int a,i;
omp_set_num_threads(8);
#pragma omp parallel for private(a,i,flag) reduction(+:count)
for(int a=2;a<100000;a++){
 if(a==2){
  //cout << a << "\t";
  //file2 << a << "\n";
  fprintf(file2,"2");
  count++;
  }
  else{
  for(int i=2;i<(a/2+1);i++){
   if(a%i==0)
   {flag=0;}
   }
  if(flag==1)
   {
   //cout << a <<"\n";
   count++;
   fprintf(file2,"%d\n",a);
   //file2 << a << "\n";
   //cout.write(file2,a);
   }
   flag=1;
  }
 }
cout << count<< endl;
//file2.close();
}
