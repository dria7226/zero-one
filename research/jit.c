//------------------------------------------------------------------------------
// Simple JITing of code into memory.
//
// This example doesn't actually use libjit - it's much more basic.
//
// Eli Bendersky (eliben@gmail.com)
// This code is in the public domain
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#include "mman_abstract.c"

// Allocates RW memory of given size and returns a pointer to it. On failure,
// prints out the error and returns NULL. mmap is used to allocate, so
// deallocation has to be done with munmap, and the memory is allocated
// on a page boundary so it's suitable for calling mprotect.
ADDRESS_TYPE alloc_writable_memory(size_t size) {
  memory* m;
  ADDRESS_TYPE ptr = MAP(m, size, PAGE_READWRITE);
  if (ptr == (void*)-1) {
    perror("MAP");
    return NULL;
  }
  return ptr;
}

// Sets a RX permission on the given memory, which must be page-aligned. Returns
// 0 on success. On failure, prints out the error and returns -1.
int make_memory_executable(memory* m, size_t size) {
  if (PROTECT(m, PAGE_EXECUTE_READ) == -1) {
    perror("PROTECT");
    return -1;
  }
  return 0;
}

void emit_code_into_memory(unsigned char* m) {
  unsigned char code[] = {
    0x55,                      //push   %rbp
    0xe5, 0x89, 0x48,           //mov    %rsp,%rbp
    0x10, 0x4d, 0x89,           //mov    %ecx,0x10(%rbp)
    0x10, 0x45, 0x8b,            //mov    0x10(%rbp),%eax
    0x02, 0xc0, 0x83,          //add    $0x2,%eax
    0xc9,                      //leaveq
    0xc3,                      //retq
    0x90                       //nop

    // 0x48, 0x89, 0xf8,                   // mov %rdi, %rax
    // 0x48, 0x83, 0xc0, 0x04,             // add $4, %rax
    // 0xc3                                // ret
  };
  memcpy(m, code, sizeof(code));
}

#define SIZE 1024
typedef long (*JittedFunc)(long);

// Allocates RW memory, emits the code into it and sets it to RX before
// executing.
int main(int argc, char** argv) {
  printf("Starting jit\n");

  ADDRESS_TYPE m = alloc_writable_memory(SIZE);
  emit_code_into_memory(m);
  make_memory_executable(m, SIZE);

  JittedFunc func = m;
  long int answer = func(2);
  printf("result = %li\n", answer);
  UNMAP(m);

  return 0;
}
