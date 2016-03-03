int test(int x)
{
   return x + 42;
}

/********************
   Window Procedure
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}

/**************
Graphics Helpers
***************/
void WIN_CreateGraphics(HINSTANCE hInstance)
{
   WNDCLASS wc;
   HWND hWnd;
   HDC hDC;
   HGLRC hRC;
   MSG msg;

   /* register window class */
   wc.style = CS_OWNDC;
   wc.lpfnWndProc = WndProc;
   wc.cbClsExtra = 0;
   wc.cbWndExtra = 0;
   wc.hInstance = hInstance;
   wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
   wc.hCursor = LoadCursor (NULL, IDC_ARROW);
   wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
   wc.lpszMenuName = NULL;
   wc.lpszClassName = "GLSample";
   RegisterClass (&wc);

   /* create main window */
   hWnd = CreateWindow (
     "GLSample", "OpenGL Sample",
     WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
     0, 0, 256, 256,
     NULL, NULL, hInstance, NULL);

   /* enable OpenGL for the window */
   PIXELFORMATDESCRIPTOR pfd;
   int iFormat;

   /* get the device context (DC) */
   hDC = GetDC (hWnd);

   /* set the pixel format for the DC */
   ZeroMemory (&pfd, sizeof (pfd));
   pfd.nSize = sizeof (pfd);
   pfd.nVersion = 1;
   pfd.dwFlags = PFD_DRAW_TO_WINDOW |
     PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
   pfd.iPixelType = PFD_TYPE_RGBA;
   pfd.cColorBits = 24;
   pfd.cDepthBits = 16;
   pfd.iLayerType = PFD_MAIN_PLANE;
   iFormat = ChoosePixelFormat (hDC, &pfd);
   SetPixelFormat (hDC, iFormat, &pfd);

   /* create and enable the render context (RC) */
   hRC = wglCreateContext( hDC );
   wglMakeCurrent( hDC, hRC );
}

void WIN_DestroyGraphics(HWND hWnd, HDC hDC, HGLRC hRC)
{
   /* shutdown OpenGL */
   wglMakeCurrent (NULL, NULL);
   wglDeleteContext (hRC);
   ReleaseDC (hWnd, hDC);

   /* destroy the window explicitly */
   DestroyWindow (hWnd);
}
