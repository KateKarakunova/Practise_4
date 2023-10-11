#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256];
    struct utsname uname_data;

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Ім'я комп'ютера: %s\n", hostname);
    } else {
        perror("Помилка отримання імені хоста");
    }

    if (uname(&uname_data) == 0) {
        printf("Операційна система: %s\n", uname_data.sysname);
        printf("Ім'я вузла: %s\n", uname_data.nodename);
        printf("Версія ОС: %s\n", uname_data.release);
        printf("Версія ОС: %s\n", uname_data.version);
        printf("Архітектура: %s\n", uname_data.machine);
    } else {
        perror("Помилка отримання інформації про комп'ютер");
    }

    return 0;
}
