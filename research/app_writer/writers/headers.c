#include "./headers/DOS_header.c"

#include "./headers/PE_header.c"

#include "./headers/optional_header.c"

#include "./headers/data_directories.c"

void write_headers()
{
	write_DOS_header();

	write_PE_header();
}