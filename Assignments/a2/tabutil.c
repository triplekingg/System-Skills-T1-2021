/* Name: Manit Gandhi
 * ID: 6280004
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *inputString(FILE *fp, size_t size) {
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str) * size);//size is start size
    if (!str)return str;
    while (EOF != (ch = fgetc(fp)) && ch != '\n') {
        str[len++] = ch;
        if (len == size) {
            str = realloc(str, sizeof(*str) * (size += 16));
            if (!str)return str;
        }
    }
    str[len++] = '\0';
    return realloc(str, sizeof(*str) * len);
}

void replaceTabs(char *c, int numSpaces) {
    char space = ' ';
    int i = 0;
    while (c[i] != '\0') {
        if (c[i] != '\t') {
            printf("%c", c[i]);
        } else {
            for (int i = 0; i < numSpaces; i++) {
                printf("%c", space);
            }

        }
        i++;
    }
}

void replaceSpace(char *c, int numSpaces) {
    char tab = '\t';
    int i = 0;
    int count = 0;
    while (c[i] != '\0') {
        if (c[i] == ' ') {
            count += 1;
            if (count == numSpaces) {
                printf("%c", tab);
                count = 0;
            }
        } else {
            if (count > 0) {
                for (int j = 0; j < count; j++) {
                    printf(" ");
                }
            }
            count = 0;
            printf("%c", c[i]);
        }
        i++;
    }
}


int main(int argc, char *argv[]) {
    char *m;
    if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "-e") == 0) {
        int num = atoi(argv[2]);
        m = inputString(stdin, 10);
        if (strcmp(argv[1], "-d") == 0) {
            replaceTabs(m, num);
        } else {
            replaceSpace(m, num);
        }
        free(m);
    } else {
        printf("error");
    }
    return 0;
}
