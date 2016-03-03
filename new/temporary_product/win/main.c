/*
   - setup
   - load ide.segment and main.segment
   - get handle for MAIN function
   - run it
*/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
   #include "../common/setup.c"

   #include "../load_standard_segments.c"

   #include "../run_segments.c"
}
