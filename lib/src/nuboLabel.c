#include "../include/nuboLabel.h"

void
nubo_label(const char *text, float x, float y, float w, float h)
{
    NVG_NOTUSED(w);

    nvgFontSize(fBase.vg, 15.0f);
    nvgFontFace(fBase.vg, "FontNormal");
    nvgFillColor(fBase.vg, nvgRGBA(255, 255, 255, 128));

    nvgTextAlign(fBase.vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
    nvgText(fBase.vg, x, y + h * 0.5f, text, NULL);
}
