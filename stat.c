#include "split.h"
/**
 * main - Entry point for the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, otherwise error code
 */
int main(int argc, char *argv[])
{
	struct stat inf;
	mode_t mode;
	char c;
	stat(argv[1], &inf);
	mode = inf.st_mode;
	if (S_ISDIR(mode))
	{
		char c = 'd';
		printf("%s est un repertoire \n", argv[1]);
	}
	else if (S_ISREG(mode))
	{
		char c = '-';
		printf("%s est un fichier régulier \n", argv[1]);
	}
	else if (S_ISFIFO(mode))
	{
		char c = 'p';
		printf("%s est un fichier First In First Out \n", argv[1]);
	}
	else
		printf("%s est un autre type \n", argv[1]);
	printf("Droit d'accès : ");
	printf("%c", c);
	printf("%c", mode & S_IRUSR ? 'r' : '-');
	printf("%c", mode & S_IWUSR ? 'w' : '-');
	printf("%c", mode & S_IXUSR ? 'x' : '-');
	printf("%c", mode & S_IRGRP ? 'r' : '-');
	printf("%c", mode & S_IWGRP ? 'w' : '-');
	printf("%c", mode & S_IXGRP ? 'x' : '-');
	printf("%c", mode & S_IROTH ? 'r' : '-');
	printf("%c", mode & S_IWOTH ? 'w' : '-');
	printf("%c", mode & S_IXOTH ? 'x' : '-');
	printf("\n");
	printf("Numero de l'inode       :%ld \n", inf.st_ino);
	printf("Nombre de lien physique :%ld \n", inf.st_nlink);
	printf("Numero de proprietaire  :%d \n", inf.st_uid);
	printf("Numero de groupe        :%d \n", inf.st_gid);
	printf("Taille du fichier       :%ld \n", inf.st_size);
	return (0);
}
