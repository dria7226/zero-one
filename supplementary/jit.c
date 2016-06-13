/* http://redd.it/2z68di */
#define _BSD_SOURCE  // MAP_ANONYMOUS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <windows.h>

#define PAGE_SIZE 4096

struct asmbuf {
    uint8_t code[PAGE_SIZE - sizeof(uint64_t)];
    uint64_t count;
};

struct asmbuf *
asmbuf_create(void)
{
    // int prot = PROT_READ | PROT_WRITE;
    // int flags = MAP_ANONYMOUS | MAP_PRIVATE;
    // return mmap(NULL, PAGE_SIZE, prot, flags, -1, 0);
    return VirtualAlloc(NULL, PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
}

void
asmbuf_free(struct asmbuf *buf)
{
    // munmap(buf, PAGE_SIZE);
    VirtualFree(buf, PAGE_SIZE, MEM_RELEASE);
}

void
asmbuf_finalize(struct asmbuf *buf)
{
    // mprotect(buf, PAGE_SIZE, PROT_READ | PROT_EXEC);

    DWORD old;
    VirtualProtect(buf, PAGE_SIZE, PAGE_EXECUTE_READ, &old);
}

void
asmbuf_ins(struct asmbuf *buf, int size, uint64_t ins)
{
    int i;
    for (i = size - 1; i >= 0; i--)
        buf->code[buf->count++] = (ins >> (i * 8)) & 0xff;
}

void
asmbuf_immediate(struct asmbuf *buf, int size, const void *value)
{
    memcpy(buf->code + buf->count, value, size);
    buf->count += size;
}

int main(void)
{
    /* Compile input program */
    struct asmbuf *buf = asmbuf_create();
    // asmbuf_ins(buf, 3, 0x4889f8); // mov   %rdi, %rax
    asmbuf_ins(buf, 3, 0x4889c8); // mov %rcx, %rax
    int c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF) {
        if (c == ' ')
            continue;
        char operator = c;
        long operand;
        scanf("%ld", &operand);
        asmbuf_ins(buf, 2, 0x48bf);         // mov   operand, %rdi
        asmbuf_immediate(buf, 8, &operand);
        switch (operator) {
        case '+':
            asmbuf_ins(buf, 3, 0x4801f8);   // add   %rdi, %rax
            break;
        case '-':
            asmbuf_ins(buf, 3, 0x4829f8);   // sub   %rdi, %rax
            break;
        case '*':
            asmbuf_ins(buf, 4, 0x480fafc7); // imul  %rdi, %rax
            break;
        case '/':
            asmbuf_ins(buf, 3, 0x4831d2);   // xor   %rdx, %rdx
            asmbuf_ins(buf, 3, 0x48f7ff);   // idiv  %rdi
            break;
        }
    }
    asmbuf_ins(buf,  1, 0xc3); // ret
    asmbuf_finalize(buf);

    long init;
    unsigned long term;
    scanf("%ld %lu", &init, &term);
    long (*recurrence)(long) = (void *)buf->code;
    unsigned long i, x;
    for (i = 0, x = init; i <= term; i++, x = recurrence(x))
        fprintf(stderr, "Term %lu: %ld\n", i, x);

    asmbuf_free(buf);
    return 0;
}
