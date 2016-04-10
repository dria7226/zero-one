void assemble_path()
{
	sprintf(extension,"%s",".exe");

	sprintf(path,"%s%s%s",relative_product_path,product_name,extension);
}

//state setters
void set_product_path()
{	
	printf("Please enter relative path: ");

	scanf("%s",relative_product_path);

	assemble_path();
}

void set_product_name()
{
	printf("Please enter product name: ");

	scanf("%s",product_name);

	assemble_path();
}

void set_target_OS()
{
	printf("Please choose OS: \n");

	int i;
	for(i = 1; i < os_length; i++)
		printf("[%d]%s \n",i,os_names[i]);

	scanf("%d",&OS);

	if(OS >= os_length) OS = os_length-1;

	item_variables[t_os] = os_names[OS];
}

int open_file()
{
	if(access( path, F_OK ) != -1 ) 
	{
		printf("A file with the same name already exists. Would you like to: \n");
		printf("[1]Overwrite\n");
		printf("[2]Cancel and go back to the main menu\n");

		int answer;
		scanf("%d",&answer);
		if(answer != 1) return 0;

		remove(path);
		
		clear_screen();
		draw_title(" Writing App ");
	}

	app = fopen(path,"a+b");

	if(!app)
	{
		printf("Can't open or create app at %s \n",path); 
		return 0;
	}

	printf("%s opened.\n",path);
}