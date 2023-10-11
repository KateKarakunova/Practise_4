#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        if (clearenv() == 0) {
            printf("Усі змінні середовища було видалено.\n");
        } else {
            perror("Помилка очищення середовища");
            return -1;
        }
    } else if (argc == 2) {
        if (unsetenv(argv[1]) == 0) {
            printf("Змінну %s було видалено.\n", argv[1]);
        } else {
            perror("Помилка видалення змінної середовища");
            return -1;
        }
    } else {
        printf("Неправильне використання програми. Використання: %s [ІМ'Я_ЗМІННОЇ]\n", argv[0]);
        return -1;
    }

    extern char **environment;
    if (environment == NULL) {
        printf("Середовище порожнє.\n");
    } else {
        char **env_var = environment;
        while (*env_var) {
            printf("%s\n", *env_var);
            env_var++;
        }
    }

    return 0;
}
