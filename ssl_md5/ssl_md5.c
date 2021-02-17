#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_chunk
{
    uint8_t block[64];
}t_chunk;


size_t ft_strlen(char *str){
    char *s = str;
    while(*s)
        ++s;
    return (size_t)(s - str);
}


void encrypt_md5(char *str) {

    /* precomputed tables of sinus values */
    uint32_t K[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
                        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
                        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

    /* MD5 work upon 4 'words' of 64 bits which all start at specific constant */
    const int a0 = 0x67452301;   // A
    const int b0 = 0xefcdab89;   // B
    const int c0 = 0x98badcfe;   // C
    const int d0 = 0x10325476;   // D

    size_t message_len = ft_strlen(str) * 8;
    uint16_t blockNb = 1 + (message_len / 512);
    blockNb += (message_len % 512 >= 448) ? 1 : 0;
    uint16_t lastBlockLength = message_len % 512;
    printf("[%s] : msg_len = %d, LastBlockLenght = %d, There will be %d block \n",str,lastBlockLength,message_len, blockNb);


}


int main(void){
    encrypt_md5("");
    encrypt_md5("a");
    encrypt_md5("abc");
    encrypt_md5("message digest");
    encrypt_md5("abcdefghijklmnopqrstuvwxyz");
    encrypt_md5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    encrypt_md5("12345678901234567890123456789012345678901234567890123456789012345678901234567890");
}