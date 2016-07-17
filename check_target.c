#define TARGET argv[1]

//check if there are any arguments
if(argc <= 1)
{
  printf( ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET " No target specified.\n");
  return;
}

printf(ANSI_COLOR_GREEN "Checking target:" ANSI_COLOR_RESET " %s " ANSI_COLOR_GREEN " ... " ANSI_COLOR_RESET,TARGET);

//check if the file exists
if(access(TARGET, F_OK) == -1)
{
    printf("\n" ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET " Can't access target.");
    return;
}

printf(ANSI_COLOR_BLUE "Done.\n" ANSI_COLOR_RESET);
