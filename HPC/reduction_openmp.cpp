#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }

    int max_val= INT_MIN;
    int min_val= INT_MAX;
    long long sum=0;

    double start= omp_get_wtime();

    #pragma omp parallel for reduction(max:max_val) reduction(min:min_val) reduction(+:sum)
    for (int i=0; i<n; i++){
        if(arr[i]> max_val) 
            max_val=arr[i];
        if(arr[i]< min_val)
            min_val= arr[i];
        sum+=arr[i];
    }

    double end= omp_get_wtime();
    double avg= double(sum)/n;

    cout<<"minimum: "<<min_val<<"\n";
    cout<<"max: "<<max_val<< "\n";
    cout<<"sum is: "<< sum << "\n";
    cout<<"avg: "<<avg<< "\n";
    cout<<"Execution time: "<< (end-start)<<" seconds \n";

    return 0;
}