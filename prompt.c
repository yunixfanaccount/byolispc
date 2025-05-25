#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>
static char buffer[2048];
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {
  printf("Lispy Ver 0.0.1\n");
  printf("Press Ctrl+c to Exit\n\n");

  while(true) {
    char* input = readline("lispy> ");
    add_history(input);
    printf("we can be %s... t-together... >w<\n", input);
    free(input);
  }
  return 0;
}
