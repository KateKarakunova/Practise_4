#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void print_environment() {
    char **env = environ;
    if (env == NULL || *env == NULL) {
        printf("Середовище пусте.\n");
    } else {
        while (*env) {
            printf("%s\n", *env);
            env++;
        }
    }
}

void print_help() {
    printf("Довідка:\n");
    printf("-h, --help\t\tПоказати це повідомлення про довідку\n");
    printf("-i, --info <змінна>\tПоказати значення змінної середовища\n");
    printf("-s, --set <змінна=значення>\tВстановити значення змінної середовища\n");
    printf("-a -v <змінна> [значення]\tВстановити нове значення змінної середовища\n");
    printf("-d, --del <змінна>\tВидалити змінну середовища\n");
    printf("-c, --clear\t\tОчистити всі середовище\n");
}

void print_variable(const char *variable_name) {
    char *value = getenv(variable_name);
    if (value != NULL) {
        printf("%s=%s\n", variable_name, value);
    } else {
        printf("Змінна %s відсутня в середовищі.\n", variable_name);
    }
}

void set_variable(const char *variable_name, const char *value) {
    setenv(variable_name, value, 1);
    printf("%s=%s\n", variable_name, value);
}

void assign_variable(const char *variable_name, const char *value) {
    if (value != NULL) {
        setenv(variable_name, value, 1);
        printf("%s=%s\n", variable_name, value);
    } else {
        unsetenv(variable_name);
        printf("Змінну %s видалено з середовища.\n", variable_name);
    }
}

void delete_variable(const char *variable_name) {
    unsetenv(variable_name);
    printf("Змінну %s видалено з середовища.\n", variable_name);
}

void clear_environment() {
    clearenv();
    printf("\nСередовище очищено!\n");
}

int check_arguments(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        return 1;
    } else if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0) {
        return (argc == 3) ? 2 : -2;
    } else if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0) {
        return (argc == 4) ? 3 : -3;
    } else if (strcmp(argv[1], "-a") == 0 && strcmp(argv[3], "-v") == 0) {
        if (argc == 4 || argc == 5) {
            return 4;
        }
        return -4;
    } else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--del") == 0) {
        return (argc == 3) ? 5 : -5;
    } else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--clear") == 0) {
        return 6;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    int arg_check = check_arguments(argc, argv);
    if (arg_check < 0) {
        printf("Помилка: Невідома опція. Використовуйте -h або --help для довідки.\n");
        return 1;
    }

    if (arg_check == 0) {
        print_environment();
    } else if (arg_check == 1) {
        print_help();
    } else if (arg_check == 2) {
        print_variable(argv[2]);
    } else if (arg_check == 3) {
        set_variable(argv[2], argv[3]);
        print_environment();
    } else if (arg_check == 4) {
        assign_variable(argv[2], (argc == 5) ? argv[4] : NULL);
        print_environment();
    } else if (arg_check == 5) {
        delete_variable(argv[2]);
        print_environment();
    } else if (arg_check == 6) {
        clear_environment();
        print_environment();
    }

    return 0;
}
