#ifndef HELPER_H
#define HELPER_H

#include "types.h"

struct hndrte_timer *
schedule_work(void *context, void *data, void *mainfn, int ms, int periodic);

void *
skb_push(sk_buff *p, unsigned int len);

void *
skb_pull(sk_buff *p, unsigned int len);

void
hexdump(char *desc, void *addr, int len);

unsigned short
bcm_qdbm_to_mw(unsigned char qdbm);

unsigned char
bcm_mw_to_qdbm(unsigned short mw);

#define HTONS(A) ((((uint16)(A) & 0xff00) >> 8) | (((uint16)(A) & 0x00ff) << 8))

inline uint16
htons(uint16 a)
{
    return (a & 0xff00) >> 8 | (a & 0xff) << 8;
}

inline uint32
htonl(uint32 a)
{
	return (a & 0xff000000) >> 24 | (a & 0xff0000) >> 8 | (a & 0xff00) << 8 | (a & 0xff) << 24;
}

inline uint16
ntohs(uint16 a)
{
	return htons(a);
}

inline uint32
ntohl(uint32 a)
{
	return htonl(a);
}

inline void *
get_stack_ptr() {
    void *stack = 0x0;
    __asm("mov %0, sp" : "=r" (stack));
    return stack;
}

/*
inline int
get_register(int reg_nr) {
    int reg_content = 0;
    switch(reg_nr) {
        case 0:
            __asm("mov %0, r0" : "=r" (reg_content));
            break;
        case 1:
            __asm("mov %0, r1" : "=r" (reg_content));
            break;
        case 2:
            __asm("mov %0, r2" : "=r" (reg_content));
            break;
        case 3:
            __asm("mov %0, r3" : "=r" (reg_content));
            break;
        case 10:
            __asm("mov %0, r10" : "=r" (reg_content));
            break;
        default:
            // not impl. do nothing
            break;
    }
    return reg_content;
}

inline void
copy_stack(void *dest, int copy_size) {
    printf("copy_stack: %d\n", copy_size);
    if(copy_size > 0) {
        memcpy( (void *) (dest), get_stack_ptr(), copy_size);
    }
    return;
}
*/

#endif /* HELPER_H */
