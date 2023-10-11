#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    uid_t uid = getuid();
    struct passwd *user_by_uid = getpwuid(uid);

    if (user_by_uid != NULL) {
        printf("Username by UID %d: %s\n", uid, user_by_uid->pw_name);
    } else {
        perror("Error getting information by UID");
    }

    const char *root_username = "root";
    struct passwd *user = getpwnam(root_username);

    if (user != NULL) {
        printf("Username by username '%s': %s\n", root_username, user->pw_name);
    } else {
        perror("Error getting information by username");
    }

    return 0;
}
