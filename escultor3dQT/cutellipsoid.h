#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica {
    private:
        int xcenter, ycenter, zcenter, rx, ry, rz;
    public:
        CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz) {
            xcenter = _xcenter; ycenter = _ycenter; zcenter = _zcenter; rx = _rx; ry = _ry; rz = _rz;
        }
        void draw(Sculptor& t) {
            t.cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
        }
};

#endif //CUTELLIPSOID_H