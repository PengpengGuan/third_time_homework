#include <iostream>
#include <omp.h>

using namespace std;
int main(){
double sum=0.0;
const int d=1000000;
double a[d],b[d];
 for(int i=0;i<d;i++){
 a[i]=2.0;
 b[i]=2.0;
 }
omp_set_num_threads(8); 
//#pragma omp parallel for reduction(+:sum)
//#pragma acc parallel
//#pragma acc loop//parallel for reduction(+:sum)
 for(int i=0;i<d;i++){
// cout<< omp_get_thread_num() <<endl;
 sum=sum+a[i]*b[i];
 }
 cout << sum <<endl;
}
