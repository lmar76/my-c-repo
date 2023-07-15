#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void usage()
{
    fprintf(stderr, "Usage: main min_value [max_value]\n");
}

int main(int argc, char **argv)
{
    int min_value, max_value;

    if (argc < 2) {
        usage();
        exit(1);
    } else if (argc < 3) {
        min_value = atoi(argv[1]);
        printf("%d: %s\n", min_value, strerror(min_value));
        exit(0);
    } else {
        min_value = atoi(argv[1]);
        max_value = atoi(argv[2]);
        for (int i = min_value ; i < max_value + 1 ; i++) {
            printf("%d: %s\n", i, strerror(i));
        }
        exit(0);
    }

    return 0;
}
