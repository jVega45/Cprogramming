#include <stdio.h>

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
    return dest;
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
        printf(">>>invalid ptr!<<<");
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

int main (int argc, char* argv[])
{
    int arr1[2] = {1, 2};
    int arr2[2] = {3, 4};
    char* nullPtr = NULL;
    sp_memcpy(arr1, nullPtr, 2 * sizeof(int));
    printf("\n%08x %08x\n", arr1[0], arr1[1]);
    sp_memset(arr2, 1, 2 * sizeof(int));
    printf("\n%08x %08x\n", arr1[0], arr1[1]);
    return 0;
}