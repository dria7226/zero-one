#define TARGET argv[1]

//check if there are any arguments
if(argc <= 1)
{
  printf("No target specified.\n");
  return;
}

printf("Checking target: %s ... ",TARGET);

//check if the file exists
if(access(&TARGET, F_OK) == -1)
{
    printf("/n Can't access target.");
    return;
}

printf("Done.\n");
