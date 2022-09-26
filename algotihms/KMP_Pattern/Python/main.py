


def kmpalgo(string,substring):
    m,n = len(string),len(substring)
    lps = [0]*n
    lps_create_pattern(substring,lps,n)
    i,j=0,0
    print(m-n+1)
    while (m-i)>=(n-j):
        if string[i]==substring[j]:
            i+=1
            j+=1
        else:
            if j!=0:
                j = lps[j-1]
            else:
                i+=1
        if j==n:
            print("found at ",i-j)
            j = lps[j-1]

def lps_create_pattern(substring,lps,n):
    len,i=0,1
    while i < n:
        if substring[i]==substring[len]:
            len+=1
            lps[i]=len
            i+=1
        else:
            if len != 0:
                len = lps[len-1]
            else:
                lps[i]=0
                i+=1

string = input()
substring = input()
kmpalgo(string,substring)