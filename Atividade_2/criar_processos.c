// criador_processos.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <número de processos>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        fprintf(stderr, "Erro: número de processos deve ser maior que zero.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            // Processo filho executa ./hello
            execl("./hello", "hello", NULL);
            // Se execl falhar
            perror("execl");
            exit(1);
        }
    }

    // Processo pai espera todos os filhos
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}
