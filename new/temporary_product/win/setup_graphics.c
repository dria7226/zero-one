BOOL bQuit = 0;
/* program main loop */
while (!bQuit)
{
    /* check for messages */
    if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
    {
        /* handle or dispatch messages */
        if (msg.message == WM_QUIT)
        {
            bQuit = TRUE;
        }
        else
        {
            TranslateMessage (&msg);
            DispatchMessage (&msg);
        }
    }
    else
    {
        /* OpenGL animation code goes here */

        glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
        glClear (GL_COLOR_BUFFER_BIT);

        glPushMatrix ();
        glBegin (GL_TRIANGLES);
        glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (0.0f, 1.0f);
        glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.87f, -0.5f);
        glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (-0.87f, -0.5f);
        glEnd ();
        glPopMatrix ();

        SwapBuffers (hDC);
        Sleep (1);
    }
}
