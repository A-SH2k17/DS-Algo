#include <bits/stdc++.h>
/*
date done: sep 6 2022
author  ali el sharkawi
purpose of code: segmented sieve algorithm
code limitations:
    maximum amount of prime numbers it can find is between the ranges of 1 and 200,000,013

NOte to self: find a better algotithm that finds the number of prime numbres till 1 billion

algorithm:
    enter a and b
    generate prime numbers till 1,000,000 as a reference
    if a = 1:
        if b>1 mill:
             assign a to start and b to end:
            while(end less than b):
                call the solve function
                start  end + 1
                end = b - end if end = b add one
        if b<= 1 mill:
            loop through all the numbers in the generated sieve array till the end of the range:
                print the number if found true
    if a!=1 and b-a <= 1 mill:
        (put steps 1 to 5 in a function called solve)
        1)create a sieve array
        2)find all the prime numbers till the sqrt of the end of the range using the sieve array
        3)create a dummy array with the size of b-a
        4)loop through the prime numbers and mark their multiples as false
        5)loop through the dummy array and print the number if it is a prime number
    if a!=1 and b-a > 1 mill:
        assign a to start and b to end:
        while(end less than b):
            call the solve function
            start  end + 1
            if b-end > 1 mil:
                end += 1e6
            if b=end: end += 1
            else end += b-end
*/

unsigned long long Count =0;

using namespace std;

bool arr[1000001];

//find all the prime numbers till 1e6 using traditional sieve
void createsieve(){
    int root = sqrt(1e6);
    for(int i=2;i<=1e6;i++)
        arr[i]=true;
    for(int i = 2; i<=root;i++){
        if(arr[i]==false)
            continue;
        for(int j=i*i;j<=1e6;j+=i)
            arr[j]=false;
    }
}

//find all the prime numbers till the sqrt of the end part of the range
vector<int>primesGeneration(int n){
    vector<int>prime;
    for(int i=2;i<=n;i++){
        if(arr[i])
            prime.push_back(i);
    }
    return prime;
}

void solve(long long a, long long b){
   int root = sqrt(b);
    vector<int>primes = primesGeneration(root);

    //generate dummy array
    bool *arr = new bool[b-a+1];
    for(int i=0;i<=b-a;i++){
        arr[i]=true;
    }
    if(a==1){
        arr[0]=false;
    }
    //loop through the prime of the multiples
    for(auto p : primes){
       long long lcf =(a/p)*p;
       for(long long i = max((long long)p*p,lcf);i<=b;i+=p){
           arr[i-a]=false;
        }
     }
    for(int i=0;i<=b-a;i++){
        if(arr[i]){
            Count++;
        }
    }
}

void largegap(long long a,long long b){
    long long start =a, end =1e6;
    while(end<=b){
        solve(start,end);
        start = end+1;
        if(b-end>1e6){
            end+=1e6;
        }
        else if(b==end)
            end++;
        else
            end+=b-end;
        }
}
int main(){
    createsieve();
    long long a,b;
    cin>>a>>b;
    if(a==1){
        if(b<=1e6){
            for(int i=2;i<=b;i++){
            if(arr[i])
                Count++;
            }
        }
        else{
            largegap(a,b);
        }
    }
    else if(b-a<=1e6){
        solve(a,b);
    }
    else{
        largegap(a,b);
    }
    cout<<Count<<endl;
}