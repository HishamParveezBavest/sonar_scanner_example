#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <cerrno>


int access(const char* file, const char* status) {
    return -1;
}

/*void fopen_with_toctou(const char* file)
{
    FILE* f = fopen(file, "w"); // NonCompliant
    if (NULL == f) {

    }
    if (fclose(f) == EOF) {
    }
}*/


void open_without_toctou(const char* file) {
    FILE* f = fopen(file, "wx"); // Compliant
    if (NULL == f) {
        /* Handle error */
    }
    /* Write to file */
    if (fclose(f) == EOF) {
        /* Handle error */
    }
}

