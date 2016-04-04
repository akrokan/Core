#ifndef CBOUNDINGBOX_H
#define CBOUNDINGBOX_H

#include "CORE/component.h"

class CBoundingBox : public Component
{
    int height {0}, width {0};

public:
    // Constructors
    CBoundingBox();
    CBoundingBox(int height, int width);

    int getBoundHeight() const;
    int getBoundWidth() const;

    void setBoundHeight(int height);
    void setBoundWidth(int width);
};

#endif // CBOUNDINGBOX_H
