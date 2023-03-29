
/*for cmd in cmds
if there is a next cmd
pipe(new_fds)
fork
if child
if there is a previous cmd
dup2(old_fds[0], 0)
close(old_fds[0])
close(old_fds[1])
if there is a next cmd
close(new_fds[0])
dup2(new_fds[1], 1)
close(new_fds[1])
exec cmd || die
else
if there is a previous cmd
close(old_fds[0])
close(old_fds[1])
if there is a next cmd
    old_fds = new_fds
if there are multiple cmds
close(old_fds[0])
close(old_fds[1])
*/
#include "../mysh.h"

int pipe_count = 2;
int I = 0;

void close_(int pipes[2][2])
{
    if (pipe_count)
    {
        if (I == pipe_count || I != 0)
            close(pipes[1][0]);
        if (I == 0 || I != pipe_count)
            close(pipes[0][1]);
    }
}


void alternate(int **pipes)
{
    int *pipe_current;

    pipe_current = pipes[0];
    pipes[0] = pipes[1];
    pipes[1] = pipe_current;
}

int connect(int pipes[2][2])
{
    if (pipe_count)
    {
        if (I == pipe_count || I != 0)
            dup2(pipes[1][0], STDIN_FILENO);
        if (I == 0 || (I != pipe_count))
            dup2(pipes[0][1], STDOUT_FILENO);
    }
    return (true);
}

void execute(char **command)
{
    static int pipe_fd[2][2];

    if (pipe_count && pipe(pipe_fd[0]) == -1)
        return;
    if (fork() == 0 && connect(pipe_fd))
    {
        execvp(command[0], command);
        _exit(EXIT_FAILURE);
    }
    while (wait(NULL) >= 0);
    close_(pipe_fd);
    alternate((int **)pipe_fd);
}

void run()
{
    char ***commands = (char **[]) {
        (char *[]) {"ls", "-l", NULL},
        (char *[]) {"grep", "a", NULL},
        (char *[]) {"grep", "b", NULL},
        NULL
    };
    printf("here\n");
    for (I = 0; commands[I]; ++I){
        printf("%d\n", I);
        execute(commands[I]);
    }
}
