#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main()
{
	char	cmd[] = "/bin/ls";
	char	*argVec[] = {"ls", "-l", NULL};
	char	*envVec[] = {NULL};
	int		i;

	i = execve(cmd, argVec, envVec);
	printf("%d\n", i);
	return (0);
}
