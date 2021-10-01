// Code to draw a line using DDA Algorithm


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800

float x_point1, x_point2, y_point1, y_point2;
using namespace std;

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // take the input for the values (x1, y1) and (x2,y2)
   
   cout << "Enter the value of x1" << endl;
   cin >> x_point1;

   cout << "Enter the value of y1" << endl;
   cin >> y_point1;

   cout << "Enter the value of x2" << endl;
   cin >> x_point2;

   cout << "Enter the value of y2" << endl;
   cin >> y_point2;

  
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "DDA Line Drawing Algorithm implemented by Shubham Khandelwal", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);


    float vertices[2000] = { 0.0 };
    GLfloat colour[2000] = { 0.0 };


    //########## code for main Algorithm ################


    float dy, dx, step, x, y, k, Xin, Yin;
    dx = x_point2 - x_point1;
    dy = y_point2 - y_point1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;

    x = x_point1;
    y = y_point1;

    vertices[0] = x;
    vertices[1] = y;
    vertices[2] = 0.0;

    colour[0] = 0;
    colour[1] = 255;
    colour[2] = 0;


    int i = 3;
    int j = 3;

    for (k = 1; k <= step; k++)
    {

        x = x + Xin;
        y = y + Yin;

        vertices[i++] = x;
        vertices[i++] = y;
        vertices[i++] = 0.0;

        colour[j++] = 0;
        colour[j++] = 255;
        colour[j++] = 0;

    }


    //####################################################################


    
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

    glMatrixMode(GL_PROJECTION);

    
    glLoadIdentity();

    // essentially set coordinate system
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity(); 

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);


        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices); // point to the vertices to be used
        glColorPointer(3, GL_FLOAT, 0, colour);
        glDrawArrays(GL_POINTS, 0, step); // draw the vertixes
        glDisableClientState(GL_COLOR_ARRAY);

        // tell OpenGL that you're finished using the vertex arrayattribute
        glDisableClientState(GL_VERTEX_ARRAY);


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
