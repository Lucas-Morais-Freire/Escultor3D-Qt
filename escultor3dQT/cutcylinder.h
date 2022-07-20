#ifndef CUTCYLINDER_H
#define CUTCYLINDER_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutCylinder : public FiguraGeometrica {
    private:
        float xa, ya, za, xb, yb, zb, rad;
    public:
        CutCylinder(float _xa, float _ya, float _za, float _xb, float _yb, float _zb, float _rad) {
            xa = _xa, ya = _ya, za = _za, xb = _xb, yb = _yb, zb = _zb, rad = _rad;
        }
        void draw(Sculptor& t) {
            t.cutCylinder(xa, ya, za, xb, yb, zb, rad);
        }
};

#endif //CUTCYLINDER_H