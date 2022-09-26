#include<bits/stdc++.h>

using namespace std;



void createLPS(string substring,int m, int*arr){
    int len = 0, i=1;
    while (i<m){
        if(substring[i]==substring[len]){
            len++;
            arr[i]=len;
            i++;
        }
        else{
            if(len !=0 ){
                len = arr[len-1];
            }
            else{
                arr[i]=0;
                i++;
            }
        }
    }
}

void KMP(string word, string substring){
    int m = substring.size();
    int n = word.size();
    int* lps = new int [m];
    createLPS(substring,m,lps);
    int i=0,j=0;
    while((n-i)>=(m-j)){
        cout<<i<<endl;
        if(word[i]==substring[j]){
            i++;
            j++;
        }
        else{
            if(j!=0)
                j = lps[j-1];
            else{
                i++;
            }
        }
        if(j==m){
            cout<<"found at "<<i-j<<endl;
            j =lps[j-1];
        }
    }
}

int main(){
    string word, substring;
    cin>>word>>substring;
    KMP(word,substring);
}