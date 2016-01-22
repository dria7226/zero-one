int draw_main_menu()
{
	clear_screen();
	draw_title("App Writer");

	unsigned char i;
	for(i = 1; i < item_list_length; i++)
	{
		printf(item_list[i],i,item_variables[i]);
	}

	int command;

	scanf("%d",&command);

	switch(command)
	{
		case p_path:
		{
			clear_screen();
			draw_title(" Enter Product Path ");
			set_product_path();
		}
		break;

		case c_name:
		{
			clear_screen();
			draw_title(" Enter Product Name ");
			set_product_name();
		}
		break;

		case t_os:
		{
			clear_screen();
			draw_title(" Enter Target OS ");
			set_target_OS();
		}
		break;

		case rite:
		{
			clear_screen();
			draw_title(" Writing App ");
			write_app();
		}
		break;

		case xit:
		{
			return 0;
		}
		break;
	}

	return 1;
}