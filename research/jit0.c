#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char** argv) {

  printf("Loading code\n");

  LPVOID m = VirtualAlloc(NULL, 16, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  unsigned char code[] = {
    //return x+2;
    0x55,                      //push   %rbp
    0xe5, 0x89, 0x48,          //mov    %rsp,%rbp
    0xc8, 0x89,                //mov    %ecx,%eax
    0x02, 0xc0, 0x83,          //add    $0x2,%eax
    0xc9,                      //leaveq
    0xc3,                      //retq
    0x90                       //nop
  };
  memcpy(m, code, sizeof(code));

  PDWORD trash;
  VirtualProtect(m, 16, PAGE_EXECUTE_READ, trash);

  long int (*addTwo)(long int) = m;
  long int answer = addTwo(2);
  printf("result = %li\n", answer);

  VirtualFree(m, 0, MEM_RELEASE);
  return 0;
}
