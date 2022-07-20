#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutVoxel : public FiguraGeometrica {
    private:
        int x, y, z;
    public:
        CutVoxel(int _x, int _y, int _z) {
            x = _x; y = _y; z = _z;
        }
        void draw(Sculptor& t) {
            t.cutVoxel(x, y, z);
        }
};

#endif //CUTVOXEL_H