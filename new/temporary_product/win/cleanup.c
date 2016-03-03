/* shutdown OpenGL */
wglMakeCurrent (NULL, NULL);
wglDeleteContext (hRC);
ReleaseDC (hWnd, hDC);

/* destroy the window explicitly */
DestroyWindow (hWnd);

return msg.wParam;
