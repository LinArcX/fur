#include "../include/nuboForm.h"

void
nubo_form(const char *title, float x, float y, float w, float h)
{
    float cornerRadius = 3.0f;
    NVGpaint shadowPaint;
    NVGpaint headerPaint;

    nvgSave(fBase.vg);
    //	nvgClearState(fBase.vg);

    // Window
    nvgBeginPath(fBase.vg);
    nvgRoundedRect(fBase.vg, x, y, w, h, cornerRadius);
    nvgFillColor(fBase.vg, nvgRGBA(28, 30, 34, 192));
    //	nvgFillColor(fBase.vg, nvgRGBA(0,0,0,128));
    nvgFill(fBase.vg);

    //// Drop shadow
    // shadowPaint = nvgBoxGradient(vg,
    //                             x,
    //                             y + 2,
    //                             w,
    //                             h,
    //                             cornerRadius * 2,
    //                             10,
    //                             nvgRGBA(0, 0, 0, 128),
    //                             nvgRGBA(0, 0, 0, 0));
    nvgBeginPath(fBase.vg);
    nvgRect(fBase.vg, x - 10, y - 10, w + 20, h + 30);
    nvgRoundedRect(fBase.vg, x, y, w, h, cornerRadius);
    nvgPathWinding(fBase.vg, NVG_HOLE);
    // nvgFillPaint(fBase.vg, shadowPaint);
    nvgFill(fBase.vg);

    // Header
    headerPaint = nvgLinearGradient(fBase.vg,
                                    x,
                                    y,
                                    x,
                                    y + 15,
                                    nvgRGBA(255, 255, 255, 8),
                                    nvgRGBA(0, 0, 0, 16));
    nvgBeginPath(fBase.vg);
    nvgRoundedRect(fBase.vg, x + 1, y + 1, w - 2, 30, cornerRadius - 1);
    nvgFillPaint(fBase.vg, headerPaint);
    nvgFill(fBase.vg);
    nvgBeginPath(fBase.vg);
    nvgMoveTo(fBase.vg, x + 0.5f, y + 0.5f + 30);
    nvgLineTo(fBase.vg, x + 0.5f + w - 1, y + 0.5f + 30);
    nvgStrokeColor(fBase.vg, nvgRGBA(0, 0, 0, 32));
    nvgStroke(fBase.vg);

    nvgFontSize(fBase.vg, 15.0f);
    nvgFontFace(fBase.vg, "FontBold");
    nvgTextAlign(fBase.vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

    nvgFontBlur(fBase.vg, 2);
    nvgFillColor(fBase.vg, nvgRGBA(0, 0, 0, 128));
    nvgText(fBase.vg, x + w / 2, y + 16 + 1, title, NULL);

    nvgFontBlur(fBase.vg, 0);
    nvgFillColor(fBase.vg, nvgRGBA(220, 220, 220, 160));
    nvgText(fBase.vg, x + w / 2, y + 16, title, NULL);

    nvgRestore(fBase.vg);
}
