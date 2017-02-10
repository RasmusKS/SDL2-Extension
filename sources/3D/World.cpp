#include <World.hpp>

World::World(){

}

World::~World(){

}

void World::addAxis(int l){
        line.push_back(LineData(new Vector(0, 0, 0), new Vector(1 * l, 0, 0), new Color(255, 0, 0)));
        line.push_back(LineData(new Vector(0, 0, 0), new Vector(0, 1 * l, 0), new Color(0, 255, 0)));
        line.push_back(LineData(new Vector(0, 0, 0), new Vector(0, 0, 1 * l), new Color(0, 0, 255)));
}

int World::getObjectCount(){
        return line.size() + circle.size();
}

void World::addLine(Vector start, Vector end, Color color){
        addLine(new Vector(start), new Vector(end), new Color(color));
}

void World::addLine(Vector *start, Vector *end, Color *color){
        line.push_back(LineData(start, end, color));
}

void World::addCircle(Vector pos, double r, Color fill, Color stroke){
       addCircle(new Vector(pos), new double(r), new Color(fill), new Color(stroke));
}

void World::addCircle(Vector *pos, double *r, Color *fill, Color *stroke){
        circle.push_back(CircleData(pos, r, fill, stroke));
}

void World::addBox(Vector pos, Vector size, Color color){
        Vector point[8];
        point[0] = pos + Vector(     0,      0,      0);
        point[1] = pos + Vector(size.x,      0,      0);
        point[2] = pos + Vector(     0, size.y,      0);
        point[3] = pos + Vector(size.x, size.y,      0);
        point[4] = pos + Vector(     0,      0, size.z);
        point[5] = pos + Vector(size.x,      0, size.z);
        point[6] = pos + Vector(     0, size.y, size.z);
        point[7] = pos + Vector(size.x, size.y, size.z);

        addLine(point[0], point[1], color);
        addLine(point[1], point[3], color);
        addLine(point[3], point[2], color);
        addLine(point[2], point[0], color);
        addLine(point[0], point[4], color);
        addLine(point[1], point[5], color);
        addLine(point[2], point[6], color);
        addLine(point[3], point[7], color);
        addLine(point[4], point[5], color);
        addLine(point[5], point[7], color);
        addLine(point[7], point[6], color);
        addLine(point[6], point[4], color);
}

void World::clear(){
        line.clear();
        circle.clear();

}
