#include <stdio.h>
#include <math.h>

#include <base.h>
#include <window.h>
#include <editBox.h>

void
process_key_escape(void)
{
    glfwSetWindowShouldClose(fBase.window, 1);
}

void
process_key_q(void)
{
    glfwSetWindowShouldClose(fBase.window, 1);
}

void
custom_background()
{
    const GLfloat color[] = { (float)sin(fBase.current_time) * 0.5f + 0.5f,
                              (float)cos(fBase.current_time) * 0.5f + 0.5f,
                              0.0f,
                              1.0f };
    glClearBufferfv(GL_COLOR, 0, color);
}

void
key_manager()
{
    process_key(GLFW_KEY_ESCAPE, GLFW_PRESS, process_key_escape);
    process_key(GLFW_KEY_Q, GLFW_PRESS, process_key_q);
}

void
windows_changed(void)
{
    printf("window's size changed.\n");
    glViewport(0, 0, fBase.width, fBase.height);
}

void
startup(void)
{
    printf("App started.\n");
    nubo_make_point();
}

void
render()
{
    // printf("current time: %f\n", fBase.current_time);
    key_manager();
    set_background_color(DARK_GRAY);

    drawWindow("Form", 0, 0, fBase.width, fBase.height);
    drawEditBox("Email", 40, 40, 300, 30);
    drawEditBox("Name", 40, 80, 300, 30);

    // drawSearchBox(fBase.vg, "Search", 10, 10, 280, 25);

    // y += 35;
    // drawEditBox(vg, "Password", x,y, 280,28);
    // y += 38;
    // drawCheckBox(vg, "Remember me", x,y, 140,28);
    // drawButton(vg, ICON_LOGIN, "Sign in", x+138, y, 140, 28,
    // nvgRGBA(0,96,128,255)); y += 45;

    //// Slider
    // drawLabel(vg, "Diameter", x,y, 280,20);
    // y += 25;
    // drawEditBoxNum(vg, "123.00", "px", x+180,y, 100,28);
    // drawSlider(vg, 0.4f, x,y, 170,28);
    // y += 55;
}

void
shutdown(void)
{
    printf("App finished.\n");
    nubo_del_point();
}

int
main(int argc, char *argv[])
{
    nubo_init(
      "Hello opengl", 800, 600, startup, render, shutdown, windows_changed);
    return 0;
}
