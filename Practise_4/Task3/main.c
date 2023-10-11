#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Використання: %s <new_variable> <new_value>\n", argv[0]);
        return 1;
    }

    const char *new_variable = argv[1];
    const char *new_value = argv[2];

    if (setenv(new_variable, new_value, 1) != 0) {
        perror("Помилка встановлення змінної середовища");
        return 1;
    }

    char *environment_value = getenv(new_variable);
    if (environment_value == NULL) {
        printf("Не вдалося отримати змінну середовища %s.\n", new_variable);
        return 1;
    } else {
        printf("Змінна середовища: %s\nЗначення: %s\n", new_variable, environment_value);
    }

    return 0;
}
