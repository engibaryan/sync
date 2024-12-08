#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY); // Open file for reading
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[10];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);

    if(bytesRead == -1) {
	perror("Error reading file");
	close(fd);
	return 1;
    }

    buffer[bytesRead] = '\0';
    printf("Read content: %s\n", buffer);

    // File opened successfully, you can now use low-level file I/O
    close(fd); // Don't forget to close the file

    return 0;
}
