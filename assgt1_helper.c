#include <unistd.h>
int main()
{
	char buf[100];
	write(STDOUT_FILENO, "Enter something: ", 17);
	
	int n = read(STDIN_FILENO, buf, 100);  // n contains the acutal number of characters entered

	write(STDOUT_FILENO, "You entered: ", 13);
	write(STDOUT_FILENO, buf, n);
	return 0;
}
