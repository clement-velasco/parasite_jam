/*
** EPITECH PROJECT, 2021
** start
** File description:
** open_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int calc_size(char *filname)
{
    int fd = open(filname, O_RDONLY);
    char *buf = malloc(sizeof(char));
    int size = 0;

    for (; read(fd, buf, 1) != 0; size++);
    free(buf);
    close(fd);
    return size;
}

char *open_file(char *filname)
{
    struct stat buf;
    char *file = NULL;
    int size = calc_size(filname);
    int fd = open(filname, O_RDONLY);
    int len = 0;

    file = malloc(sizeof(char) * (size));
    if (file == NULL) {
        free(file);
        return NULL;
    }
    len = read(fd, file, size);
    if (len <= 0) {
        free(file);
        return NULL;
    }
    file[len - 1] = '\0';
    return file;
}