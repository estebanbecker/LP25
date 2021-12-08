#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MASK 0x7f // Index mask from 0 to 127, i.e. 128 elements
#define BUFFER_SIZE 128
unsigned char read_index = 0;
unsigned char write_index = 0;
char circular_buffer[BUFFER_SIZE];

int write_char(char c);
int read_char(char *c);

int main(int argc, char *argv[]) {
    char circular_buffer[BUFFER_SIZE];
    char str[BUFFER_SIZE];
    char c;
    int i=0;
    read_index = 0;
    write_index = 0;

    fgets(str, BUFFER_SIZE, stdin);
    do
    {
        if(str[i] != '\n')
            write_char(str[i]);
        i++;
    } while(str[i] != '\n');

    while(read_char(&c)){
        printf("%c", c);
    }
    

    return 0;
}

/*!
 * \brief function write_char writes c to circular buffer unless it is full
 * \param c the character to be appended to circular buffer
 * \return 1 if insertion is successful, 0 if buffer is full
 */
int write_char(char c) {
    /* Implement function here */
    if(write_index +1 == read_index) {
        return 0;
    }else {
        circular_buffer[write_index] = toupper(c);
        write_index = (write_index + 1) & MASK;
        return 1;
    }
}
/*!
 * \brief function read_char reads a character from circular
 * \param c a pointer to the character to be read
 * \return 1 if successful, 0 if buffer is empty
 */
int read_char(char *c) {
    /* Implement function here */
    if (read_index == write_index) {
        return 0;
    }
    else {
        *c = circular_buffer[read_index];
        read_index = (read_index + 1) & MASK;
        return 1;
    }
    return 1;
}