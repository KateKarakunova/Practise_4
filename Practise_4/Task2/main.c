#include <stdio.h>
#include <stdlib.h>

void printEnvironmentVariable(const char *envVarName) {
    char *envVarValue = getenv(envVarName);

    if (envVarValue) {
        printf("Value of %s: %s\n", envVarName, envVarValue);
    } else {
        printf("Environment variable '%s' is not set.\n", envVarName);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <environment_variable_name>\n", argv[0]);
        return 1;
    }

    const char *envVarName = argv[1];
    printEnvironmentVariable(envVarName);

    return 0;
}
