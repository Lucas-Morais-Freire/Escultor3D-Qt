#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutVoxel : public FiguraGeometrica {
    private:
        int x, y, z;
    public:
        PutVoxel(int _x,int  _y,int _z, float _r, float _g, float _b, float _a) {
            x = _x; y = _y; z = _z; r = _r; g = _g; b = _b; a = _a;
        }
        void draw(Sculptor& t) {
            t.setColor(r, g, b, a);
            t.putVoxel(x, y, z);
        }
};

#endif //PUTVOXEL_H