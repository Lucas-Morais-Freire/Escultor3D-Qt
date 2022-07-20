#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutBox : public FiguraGeometrica {
    private:
        int x0, x1, y0, y1, z0, z1;
    public:
        PutBox(int _x0, int  _x1, int  _y0, int  _y1, int  _z0, int  _z1, float _r, float _g, float _b, float _a) {
            x0 = _x0; x1 = _x1; y0 = _y0; y1 = _y1; z0 = _z0; z1 = _z1;
            r = _r; g = _g; b = _b; a = _a;
        }
        void draw(Sculptor& t) {
            t.setColor(r, g, b, a);
            t.putBox(x0, x1, y0, y1, z0, z1);
        }
};

#endif //PUTBOX_H