#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NANOVG_GLEW
#include <GL/glew.h>
#endif

#define GLFW_INCLUDE_GLEXT
#define NANOVG_GL3_IMPLEMENTATION

#include "../include/nuboBase.h"
#include "../include/ttf_roboto_regular.h"
#include "../include/ttf_roboto_bold.h"

int premult = 0;
NuboBase fBase;

const struct color RED = { .red = 0.2f,
                           .green = 0.3f,
                           .blue = 0.3f,
                           .alpha = 1.0f };

const struct color LIGHT_BLUE = { .red = 0.6f,
                                  .green = 0.6f,
                                  .blue = 1.0f,
                                  .alpha = 1.0f };

const struct color BLUE = { .red = 0.2f,
                            .green = 0.6f,
                            .blue = 1.0f,
                            .alpha = 1.0f };

const struct color BROWN = { .red = 153 / 255,
                             .green = 76 / 255,
                             .blue = 0 / 255,
                             .alpha = 1.0 };

const struct color LIGHT_GRAY = { .red = 0.75f,
                                  .green = 0.75f,
                                  .blue = 0.75f,
                                  .alpha = 1.0f };

const struct color GRAY = { .red = 0.62f,
                            .green = 0.62f,
                            .blue = 0.62f,
                            .alpha = 1.0f };

const struct color DARK_GRAY_2 = { .red = 0.37f,
                                   .green = 0.37f,
                                   .blue = 0.37f,
                                   .alpha = 1.0f };

const struct color DARK_GRAY = { .red = 0.3f,
                                 .green = 0.3f,
                                 .blue = 0.32f,
                                 .alpha = 1.0f };

int
loadFonts(NVGcontext *vg, Fonts *data)
{
    int i;

    if (vg == NULL)
        return -1;

    data->fontNormal = nvgCreateFontMem(
      vg, "sans", ttf_roboto_regular, ttf_roboto_regular_len, 0);
    if (data->fontNormal == -1) {
        printf("Could not add font italic.\n");
        return -1;
    }

    data->fontBold = nvgCreateFontMem(
      vg, "sans-bold", ttf_roboto_bold, ttf_roboto_bold_len, 0);
    if (data->fontBold == -1) {
        printf("Could not add font bold.\n");
        return -1;
    }
    return 0;
}

void
freeFonts(NVGcontext *vg, Fonts *data)
{
    int i;
    if (vg == NULL)
        return;
}

int8_t
nubo_init(char *title,
          uint16_t width,
          uint16_t height,
          void (*startup)(void),
          void (*render)(void),
          void (*shutdown)(void),
          void (*windows_changed)(void))
{
    fBase.title = title;
    fBase.width = width;
    fBase.height = height;
    fBase.startup = (*startup);
    fBase.render = (*render);
    fBase.shutdown = (*render);
    fBase.vg = NULL;
    fBase.windows_changed = (*windows_changed);
    fBase.current_time = glfwGetTime();

    Fonts data;
    // NVGcontext *vg = NULL;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* glfw window creation */
    fBase.window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (fBase.window == NULL) {
        fprintf(stderr, "Error creating window.\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(fBase.window);
    glfwSetFramebufferSizeCallback(fBase.window, windows_changed);

#ifdef DEMO_MSAA
    fBase.vg = nvgCreateGL3(NVG_STENCIL_STROKES | NVG_DEBUG);
#else
    fBase.vg = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
#endif
    if (fBase.vg == NULL) {
        printf("Could not init nanovg.\n");
        return -1;
    }

    if (loadFonts(fBase.vg, &data) == -1)
        return -1;

    (*startup)();

    /* render loop */
    while (!glfwWindowShouldClose(fBase.window)) {
        int winWidth, winHeight;
        int fbWidth, fbHeight;
        float pxRatio;

        fBase.current_time = glfwGetTime();

        glfwGetWindowSize(fBase.window, &winWidth, &winHeight);
        glfwGetFramebufferSize(fBase.window, &fbWidth, &fbHeight);

        // Calculate pixel ration for hi-dpi devices.
        pxRatio = (float)fbWidth / (float)winWidth;

        // Update and render
        glViewport(0, 0, fbWidth, fbHeight);
        if (premult)
            glClearColor(0, 0, 0, 0);
        else
            glClearColor(0.3f, 0.3f, 0.32f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |
                GL_STENCIL_BUFFER_BIT);

        nvgBeginFrame(fBase.vg, winWidth, winHeight, pxRatio);
        (*render)();
        nvgRestore(fBase.vg);
        nvgEndFrame(fBase.vg);

        glfwSwapBuffers(fBase.window);
        glfwPollEvents();
    }

    (*shutdown)();

    freeFonts(fBase.vg, &data);
    nvgDeleteGL3(fBase.vg);

    glfwTerminate();
    return 0;
}

void
set_background_color(const struct color col)
{
    GLfloat const color[] = { col.red, col.green, col.blue, col.alpha };
    glClearBufferfv(GL_COLOR, 0, color);
}

void
process_key(int key, int event, void (*process_key)())
{
    if (glfwGetKey(fBase.window, key) == event)
        (*process_key)();
}

uint16_t
nubo_base_get_width()
{
    return fBase.width;
}

uint16_t
nubo_base_get_height()
{
    return fBase.height;
}

void
nubo_base_set_width(uint16_t width)
{
    fBase.width = width;
}

void
nubo_base_set_height(uint16_t height)
{
    fBase.height = height;
}
