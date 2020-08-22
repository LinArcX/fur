#ifndef NUBO_BASE_H
#define NUBO_BASE_H

#include <stdint.h>
#include <GLFW/glfw3.h>
#include "../include/nanovg.h"
#include "../include/nanovg_gl.h"

struct fonts
{
    int fontNormal, fontBold, fontIcons, fontEmoji;
};
typedef struct fonts Fonts;

const struct color
{
    float red;
    float green;
    float blue;
    float alpha;
};

extern const struct color RED;
extern const struct color BLUE;
extern const struct color LIGHT_BLUE;
extern const struct color BROWN;
extern const struct color LIGHT_GRAY;
extern const struct color GRAY;
extern const struct color DARK_GRAY;

typedef struct
{
    char *title;
    uint16_t width;
    uint16_t height;
    GLFWwindow *window;
    double current_time;
    NVGcontext *vg;
    void (*startup)(void);
    void (*render)(void);
    void (*shutdown)(void);
    void (*windows_changed)(void);
} NuboBase;

extern NuboBase fBase;

int8_t
nubo_init(char *title,
          uint16_t width,
          uint16_t height,
          void (*startup)(void),
          void (*render)(void),
          void (*shutdown)(void),
          void (*windows_changed)(void));

void
set_background_color(const struct color col);

void
process_key(int key, int event, void (*process_key)(void));

uint16_t
nubo_base_get_width();

uint16_t
nubo_base_get_height();

void
nubo_base_set_width(uint16_t width);

void
nubo_base_set_height(uint16_t height);

#endif /* NUBO_BASE_H */
