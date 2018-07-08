#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

void Xoa(char s[MAX], int n, int i){
    char *p;
    p= (char*)malloc (MAX * sizeof (char));
    strncpy(p, s, i); // copy phan tu truoc chuoi s1
    int len = strlen(s);
    strcpy(p + i, s + i + n); // copy phan tu sau chuoi s1
    p[len - n] = '\0';
    strcpy(s,p);
}
//Them ch vao vi tri thu i cua s
void Them(char s[MAX], int i, char s2[MAX]){
    int len = strlen(s);
    int lens2 = strlen(s2);
    int j;
    for ( j = len; j >= i; j--)
        s[j + lens2] = s[j];
    for ( j = 0; j < lens2; j++)
        s[i + j] = s2[j]; //chen chuoi s2 vao giua
}

void ThayThe(char s[MAX], char s1[MAX], char s2[MAX]){
    int len = strlen(s);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *p;
    p= (char*)malloc (MAX * sizeof (char));
    int i;
    while ((p = strstr(s,s1)) != NULL)
    {
           i = p - s;
           Xoa(s,len1,i);
           Them(s,i,s2);
    }
}
int main(int argc,char* argv[]){
    while(argc!=4){
        printf("argc must be 4!");
        exit(1);
    }
    char s[MAX]="";
    char s1[MAX]="";
    char s2[MAX]="";
    strcat(s,argv[1]);
    strcat(s1,argv[2]);
    strcat(s2,argv[3]);
    // khai bao doi so
    ThayThe(s, s1, s2);
    // thay the s1 bang s2
    printf("The string after replaced is: %s\n",s);
    return 0;
}
