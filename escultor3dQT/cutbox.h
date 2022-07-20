#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutBox : public FiguraGeometrica {
    private:
        int x0, x1, y0, y1, z0, z1;
    public:
        CutBox(int _x0, int  _x1, int  _y0, int  _y1, int  _z0, int _z1) {
            x0 = _x0; x1 = _x1; y0 = _y0; y1 = _y1; z0 = _z0; z1 = _z1;
        }
        void draw(Sculptor& t) {
            t.cutBox(x0, x1, y0, y1, z0, z1);
        }
};

#endif //CUTBOX_H