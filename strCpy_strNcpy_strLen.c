#include <stdio.h>

/**
 * CPE/CSC 159 - Operating System Pragmatics
 * California State University, Sacramento
 * Spring 2021
 *
 * String Utilities
 */
//#define NULL ((void*)0)

/**
 * Sets the first n bytes pointed to by str to the value specified by c
 *
 * @param   dest - pointer the block of memory to set
 * @param   c    - value to set; passed as an integer but converted to unsigned
 * char when set
 * @param   n    - number of bytes to set
 * @return  pointer to the memory region being set; NULL on error
 */
void *sp_memset(void *dest, int c, size_t n) 
{
    if(dest == NULL)
    {
        printf(">>>invalid ptr!<<<");
        return (void*)-1;
    }
    unsigned char* ptr = dest; // convert the void ptr to a ptr to an unsigned char
    while(n > 0)
    {
        *ptr = (unsigned char)c; // cannot dereference a void pointer, therefore use the ptr variable
        ptr++;
        n--;
    }    
    return ptr;
}

/**
 * Copies n bytes from the block of memory pointed to by src to dest
 *
 * @param   dest - pointer to the destination block of memory
 * @param   src  - pointer to the source block of memory
 * @param   n    - number of bytes to read/set
 * @return  pointer to the destination memory region; NULL on error
 */
void *sp_memcpy(void *dest, const void *src, size_t n) 
{
    if((dest == NULL) || (src == NULL))
    {
        (">>>invalid ptr!<<<");
        return (void*)-1;
    }
    // typecast src and dest addresses to pointers to chars
    char* cpySrc = (char*)src;
    char* cpyDest = (char*)dest;
    int i; // i don't like declaring variables inside header of loops

    for(i = 0; i < n; i++)
    {
        cpyDest[i] = cpySrc[i]; // copy src to dest
    }     
    return dest;
}

/**
 * Copies the string pointed to by src to the destination dest
 *
 * @param  dest - pointer to the destination string
 * @param  src  - pointer to the source string
 * @return pointer to the destination string
 */
char *sp_strcpy(char *dest, const char *src)
{
    // check for NULL ptr
    if((dest == NULL) || (src == NULL))
    {
        return NULL;
    }
    char* ptr = dest; // ptr variable to point to destination

    // copy C-string from src to dest
    while(*src != '\0') 
    {
        *dest = *src;
        dest++;
        src++;
    }
   *dest = '\0';  // add the null terminating character to end of dest

   return ptr;
}

/**
 * Copies up to n characters from the source string src to the destination
 * string dest. If the length of src is less than that of n, the remainder
 * of dest up to n will be filled with NULL characters.
 *
 * @param  dest - pointer to the destination string
 * @param  src  - pointer to the source string
 * @param  n    - maximum number of characters to be copied
 * @return pointer to the destination string
 */
char *sp_strncpy(char *dest, const char *src, size_t n)
{
    //  check for NULL ptrs
    if((dest == NULL) || (src == NULL))
    {
        return NULL;
    }
    char* ptr = dest;

    // copy src until NULL character is reached in src then concat NULL to dest for rest of n
    while(*src != '\0' && n--)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return ptr;
}

/**
 * Computes the length of the string str up to, but not including the null
 * terminating character
 *
 * @param  str - pointer to the string
 * @return length of the string
 */
size_t sp_strlen(const char *str)
{
    size_t strLength = 0;

    while(*str != '\0')
    {
        strLength++;
        str++;
    }
    return strLength;
}

int main()
{
    char name1[8] = {'C', 'h', 'a', 'r', 'l', 'e', 's', '\0'};
    char name2[10];
    size_t len = 12;
    printf("\nName #1: %s\n", name1);

    sp_strncpy(name2, name1, len);
    printf("\nName #2: %s\n", name2);
    printf("\nlength of name1: %zu\n", sp_strlen(name1));
    sp_strcpy(name2, name1);
    printf("After strcpy --> Name #1: %s Name #2: %s\n", name1, name2);

    int i;
    printf("\nPrinting Name #2:\n");
    for(i = 0; i <= sp_strlen(name2); i++)
    {
        printf("\n%c\n", name2[i]);    
    }

    return 0;
}

// can we assume that all strings passed to strlen will have a null terminator character?