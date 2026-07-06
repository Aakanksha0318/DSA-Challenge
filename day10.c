/* Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/

#include <stdio.h>
#include <string.h>

int main(){
    char s[50];
    scanf("%49s ", s);
    char str[50];
    strcpy(str ,s);

    int j=strlen(str)-1;
    int i=0;
    char temp;
    while(i<j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;j--;
    }

    if (strcmp(s, str) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}