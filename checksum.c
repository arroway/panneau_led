/**
 * @file checksum.c
 * @brief Calcul du checksum 
 *
 * @author Mathieu Cassard
 *
 */

#include <stdio.h>
#include <stdlib.h>

static unsigned char checksum(const char *str, unsigned char init)
{
    unsigned char i = init;

    while (*str != '\0') {
    i ^= *str;
    str++;
    }

return (i);
}

int main(int argc, char *argv[])
{
    unsigned char csum = 0x0;
    char* msg;

    //printf("ff\n");
    if (argc != 2)
        exit(-1);
    else
        msg = argv[1];

    csum = checksum(msg, csum);
    printf("%02X\n",csum);

    return (csum);
}

