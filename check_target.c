//check if there are any arguments
if(argc > 1)
  target = argv[1];
else
  {printf("No target specified.\n"); return;}

//check if the file exists
if(access(target, F_OK) == -1) return;

printf("Target is fine \n");
