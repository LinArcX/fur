#include "../include/nuboEditBox.h"

void
nubo_edit_box_base(float x, float y, float w, float h)
{
    NVGpaint bg;
    // Edit
    bg = nvgBoxGradient(fBase.vg,
                        x + 1,
                        y + 1 + 1.5f,
                        w - 2,
                        h - 2,
                        3,
                        4,
                        nvgRGBA(255, 255, 255, 32),
                        nvgRGBA(32, 32, 32, 32));
    nvgBeginPath(fBase.vg);
    nvgRoundedRect(fBase.vg, x + 1, y + 1, w - 2, h - 2, 4 - 1);
    nvgFillPaint(fBase.vg, bg);
    nvgFill(fBase.vg);

    nvgBeginPath(fBase.vg);
    nvgRoundedRect(fBase.vg, x + 0.5f, y + 0.5f, w - 1, h - 1, 4 - 0.5f);
    nvgStrokeColor(fBase.vg, nvgRGBA(0, 0, 0, 48));
    nvgStroke(fBase.vg);
}

void
nubo_edit_box(const char *text, float x, float y, float w, float h)
{

    nubo_edit_box_base(x, y, w, h);

    nvgFontSize(fBase.vg, 17.0f);
    nvgFontFace(fBase.vg, "FontNormal");
    nvgFillColor(fBase.vg, nvgRGBA(255, 255, 255, 64));
    nvgTextAlign(fBase.vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
    nvgText(fBase.vg, x + h * 0.3f, y + h * 0.5f, text, NULL);
}

void
nubo_edit_box_num(const char *text,
                  const char *units,
                  float x,
                  float y,
                  float w,
                  float h)
{
    float uw;

    nubo_edit_box_base(x, y, w, h);

    uw = nvgTextBounds(fBase.vg, 0, 0, units, NULL, NULL);

    nvgFontSize(fBase.vg, 15.0f);
    nvgFontFace(fBase.vg, "FontNormal");
    nvgFillColor(fBase.vg, nvgRGBA(255, 255, 255, 64));
    nvgTextAlign(fBase.vg, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
    nvgText(fBase.vg, x + w - h * 0.3f, y + h * 0.5f, units, NULL);

    nvgFontSize(fBase.vg, 17.0f);
    nvgFontFace(fBase.vg, "FontNormal");
    nvgFillColor(fBase.vg, nvgRGBA(255, 255, 255, 128));
    nvgTextAlign(fBase.vg, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
    nvgText(fBase.vg, x + w - uw - h * 0.5f, y + h * 0.5f, text, NULL);
}
