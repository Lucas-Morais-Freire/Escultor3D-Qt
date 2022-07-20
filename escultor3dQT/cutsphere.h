#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutSphere : public FiguraGeometrica {
    private:
        int xcenter, ycenter, zcenter, radius;
    public:
        CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius) {
            xcenter = _xcenter; ycenter = _ycenter; zcenter = _zcenter; radius = _radius;
        }
        void draw(Sculptor& t) {
            t.cutSphere(xcenter, ycenter, zcenter, radius);
        }
};

#endif //CUTSPHERE_H