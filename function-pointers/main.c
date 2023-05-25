#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f1 (int arg1, int arg2)
{
    return arg1 + arg2;
}

char *f2 (char *arg1, char *arg2)
{
    char *result = calloc(strlen(arg1) + strlen(arg2), sizeof(char));
    strcat(result, arg1);
    strcat(result, arg2);
    return result;
}

int main()
{
    int (*ifp) (int, int) = f1;
    int n1 = 2;
    int n2 = 3;
    
    printf("f(%d, %d) = %d\n\n", n1, n2, ifp(n1, n2));

    char *(*cfp) (char *, char *) = f2;
    char *s1 = "Hello";
    char *s2 = "World!";

    printf("f('%s', '%s') = '%s'\n\n", s1, s2, cfp(s1, s2));

    return 0;
}
