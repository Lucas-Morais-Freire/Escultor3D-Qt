#ifndef PUTCYLINDER_H
#define PUTCYLINDER_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutCylinder : public FiguraGeometrica {
    private:
        float xa, ya, za, xb, yb, zb, rad;
    public:
        PutCylinder(float _xa, float _ya, float _za, float _xb, float _yb, float _zb, float _rad, float _r, float _g, float _b, float _a) {
            xa = _xa; ya = _ya; za = _za; xb = _xb; yb = _yb; zb = _zb; rad = _rad;
            r = _r; g = _g; b = _b; a = _a;
        }
        void draw(Sculptor& t) {
            t.setColor(r, g, b, a);
            t.putCylinder(xa, ya, za, xb, yb, zb, rad);
        }
};

#endif //PUTCYLINDER_H