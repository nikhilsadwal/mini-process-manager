#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>

void list_processes() {
    DIR *dir;
    struct dirent *ent;
    FILE *fp;
    char path[256], line[256], name[256], state;
    int pid;
    long mem;

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        return;
    }

    printf("%-6s %-20s %-6s %-10s\n", "PID", "Name", "State", "Memory(KB)");
    while ((ent = readdir(dir)) != NULL) {
        if (isdigit(*ent->d_name)) {
            pid = atoi(ent->d_name);
            snprintf(path, sizeof(path), "/proc/%d/status", pid);
            fp = fopen(path, "r");
            if (fp) {
                char comm[256] = "";
                mem = 0;
                while (fgets(line, sizeof(line), fp)) {
                    if (sscanf(line, "Name:\t%s", comm) == 1) {}
                    else if (sscanf(line, "State:\t%c", &state) == 1) {}
                    else if (sscanf(line, "VmRSS:\t%ld", &mem) == 1) {}
                }
                printf("%-6d %-20s %-6c %-10ld\n", pid, comm, state, mem);
                fclose(fp);
            }
        }
    }
    closedir(dir);
}

int main() {
    int choice, pid;
    while (1) {
        printf("\n1. List processes\n2. Kill process\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) list_processes();
        else if (choice == 2) {
            printf("Enter PID to kill: ");
            scanf("%d", &pid);
            if (kill(pid, SIGTERM) == 0) printf("Process %d terminated.\n", pid);
            else perror("kill");
        }
        else break;
    }
    return 0;
}

