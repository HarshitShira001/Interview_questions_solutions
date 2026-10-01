/*Company  A  is discarding product numbers that contain few specific digits a specific number of time or more than that.
You are given a range and you need to find product numbers that are possible. 
Example- Range: 24 to 12943 Numbers that should not come: 1, 3, 5 Number of times these number should not occur: 3 or more  
In above case all two digit numbers are valid. In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid. In four digit:
All the numbers containing above 3 digit numbers are not valid.   
Eg: 11223 is not valid, 11222 is valid. */

#include <iostream>
using namespace std;

int solve(int a,int b,int k,int n,int *invalid){
    int count = 0;
    for(int i = a;i <= b;i++){
        int num = i;
        int digits[10] = {0};
        while(num != 0){
            int digit = num%10;
            digits[digit]++;
            num = num/10;
        }
        int dcount = 0;
        for(int i = 0;i < n;i++){
            dcount += digits[invalid[i]];
        }
        if(dcount < k){
            count++;
        }
    }
    return count;
}
int main() 
{
    int a,b,k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    int *invalid = new int[n];
    for(int i = 0;i < n;i++){
        cin >> invalid[i];
    }
    cout << solve(a,b,k,n,invalid);
    return 0;
}
