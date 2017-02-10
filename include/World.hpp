#ifndef WORLD_H
#define WORLD_H

#include <Vector.hpp>
#include <Color.hpp>
#include <vector>

struct CircleData{

        CircleData(Vector *_pos, double *_radius, Color *_fill, Color *_stroke){
                pos = _pos;
                radius = _radius;
                fill = _fill;
                stroke = _stroke;
        }

        Vector *pos;
        double *radius;
        Color *fill;
        Color *stroke;
};

struct LineData{

        LineData(Vector *_start, Vector *_end, Color *_stroke){
                start = _start;
                end = _end;
                stroke = _stroke;
        }

        Vector *start;
        Vector *end;
        Color *stroke;
};

class World{

public:

        World();
        ~World();

        void addAxis(int l);

        int getObjectCount();

        void addLine(Vector start, Vector end, Color color);
        void addLine(Vector *start, Vector *end, Color *color);
        void addCircle(Vector pos, double r, Color fill, Color stroke);
        void addCircle(Vector *pos, double *r, Color *fill, Color *stroke);
        void addBox(Vector pos, Vector size, Color color);

        void clear();

        std::vector<CircleData> circle;
        std::vector<LineData> line;
};

#endif
