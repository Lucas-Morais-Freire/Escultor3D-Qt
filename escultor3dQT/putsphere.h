#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica {
    private:
        int xcenter, ycenter, zcenter, radius;
    public:
        PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a) {
            xcenter = _xcenter; ycenter = _ycenter; zcenter = _zcenter; radius = _radius;   r = _r; g = _g; b = _b; a = _a;
        }
        void draw(Sculptor& t) {
            t.setColor(r, g, b, a);
            t.putSphere(xcenter, ycenter, zcenter, radius);
        }
};

#endif //PUTSPHERE_H