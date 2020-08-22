#include "../include/nuboDropDown.h"

void
nubo_drop_down(const char *text, float x, float y, float w, float h)
{
    NVGpaint bg;
    char icon[8];
    float cornerRadius = 4.0f;

    bg = nvgLinearGradient(fBase.vg,
                           x,
                           y,
                           x,
                           y + h,
                           nvgRGBA(255, 255, 255, 16),
                           nvgRGBA(0, 0, 0, 16));
    nvgBeginPath(fBase.vg);
    nvgRoundedRect(fBase.vg, x + 1, y + 1, w - 2, h - 2, cornerRadius - 1);
    nvgFillPaint(fBase.vg, bg);
    nvgFill(fBase.vg);

    nvgBeginPath(fBase.vg);
    nvgRoundedRect(
      fBase.vg, x + 0.5f, y + 0.5f, w - 1, h - 1, cornerRadius - 0.5f);
    nvgStrokeColor(fBase.vg, nvgRGBA(0, 0, 0, 48));
    nvgStroke(fBase.vg);

    nvgFontSize(fBase.vg, 17.0f);
    nvgFontFace(fBase.vg, "FontNormal");
    nvgFillColor(fBase.vg, nvgRGBA(255, 255, 255, 160));
    nvgTextAlign(fBase.vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
    nvgText(fBase.vg, x + h * 0.3f, y + h * 0.5f, text, NULL);

    nvgFontSize(fBase.vg, h * 1.3f);
    nvgFontFace(fBase.vg, "FontIcons");
    nvgFillColor(fBase.vg, nvgRGBA(255, 255, 255, 64));
    nvgTextAlign(fBase.vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
    nvgText(fBase.vg,
            x + w - h * 0.5f,
            y + h * 0.5f,
            cpToUTF8(ICON_CHEVRON_RIGHT, icon),
            NULL);
}
