#ifndef NUBO_EDITBOX_H
#define NUBO_EDITBOX_H

#include "nuboBase.h"

void
nubo_edit_box(const char *text, float x, float y, float w, float h);

void
nubo_edit_box_num(const char *text,
                  const char *units,
                  float x,
                  float y,
                  float w,
                  float h);

#endif /* NUBO_EDITBOX_H */
