#include <stdio.h>
#include <stdlib.h>

int main() {
    char* env_var;
    int i = 0;

    while ((env_var = environ[i]) != NULL) {
        printf("%s\n", env_var);
        i++;
    }
    return 0;
}
