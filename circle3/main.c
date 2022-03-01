#include <dirent.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	DIR *dirp;

	dirp = opendir("test_dir");
	if (!dirp)
	{
		printf("error");
		return (1);
	}
	return 0;
}
