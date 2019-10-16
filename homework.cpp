#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define next nxt

int next[1003];

void get(char *p, int len)
{
    next[0] = -1;
    int j = 0, k = -1;
    while(j < len)
    {
        if(k == -1 || p[j] == p[k])
        {
            ++j;
            ++k;
            if(p[j] == p[k]) next[j] = k;
            else next[j] = next[k];
        }
        else k = next[k];
    }
}

int kmp(char *s, char *p)
{
    int ans = 0;
    int lens = strlen(s), lenp = strlen(p);
    get(p, lenp);
    int i = 0, j = 0;
    while(i < lens)
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else j = next[j];
        if(j == lenp)
        {
            ++ans;
            j = 0;
        }
    }
    return ans;
}

int main()
{
    char s[1003], p[1003];
    while(scanf("%s", s))
    {
        if(s[0] == '#')break;
        scanf("%s", p);
        printf("%d\n", kmp(s, p));
    }
    return 0;
}
