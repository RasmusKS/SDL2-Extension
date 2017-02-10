#include <Cam.hpp>

#include <cmath>

Cam::Cam(World *_world){
        fov = Vector(M_PI / 2, M_PI / 2, 0);
        pos = Vector(0, 0, 0);
        dir = Vector(0, 0, 3 * (-M_PI / 4));
        world = _world;
        renderedObjects = 0;
}

Cam::~Cam(){

}

void Cam::roll(double rad){
        dir.x += rad;
}

void Cam::pitch(double rad){
        dir.y += rad;
}

void Cam::yaw(double rad){
        dir.z += rad;
}

void Cam::move(Vector mov){
        mov.rotateX(dir.x);
        mov.rotateY(dir.y);
        mov.rotateZ(dir.z);

        pos += mov;
}

void Cam::move2D(Vector mov){
        mov.z = 0;
        mov.rotate(dir.z);
        pos += mov;
}

void Cam::draw(Window &window){
        draw(window, Vector(0, 0), *window.size);
}

void Cam::draw(Window &window, Vector size){
        draw(window, Vector(0, 0), size);
}

void Cam::draw(Window &window, Vector offset, Vector size){

        renderedObjects = 0;

        for (int i = 0; i < world->line.size(); i++){
                Vector startPos = pos3DToPos2D(*world->line[i].start, *window.size);
                Vector endPos = pos3DToPos2D(*world->line[i].end, *window.size);
                int sum = 0;
                if (
                        startPos.x < 0 ||
                        startPos.x > size.x ||
                        startPos.y < 0 ||
                        startPos.y > size.y ||
                        endPos.x < 0 ||
                        endPos.x > size.x ||
                        endPos.y < 0 ||
                        endPos.y > size.y
                ) continue;

                renderedObjects++;

                window.line(offset + startPos, offset + endPos, world->line[i].stroke);
        }
}

void Cam::setFov(double fovX, double fovY){
        fov = Vector(fovX, fovY);
}

void Cam::setFov(Vector _fov){
        fov = _fov;
}

Vector Cam::getFov(){
        return fov;
}

void Cam::setPos(double posX, double posY, double posZ){
        pos = Vector(posX, posY, posZ);
}

void Cam::setPos(Vector _pos){
        pos = _pos;
}

Vector Cam::getPos(){
        return pos;
}

void Cam::setDir(double roll, double pitch, double yaw){
        dir = Vector(roll, pitch, yaw);
}

void Cam::setDir(Vector _dir){
        dir = _dir;
}

Vector Cam::getDir(){
        return dir;
}

Vector Cam::pos3DToPos2D(Vector &_pos, Vector &size){
        Vector relPos(_pos - pos);
        relPos.rotateZ(-dir.z);
        relPos.rotateY(-dir.y);
        relPos.rotateX(-dir.x);
        double angleX = relPos.getAngleZ();
        if (angleX > M_PI) angleX -= 2 * M_PI;
        double angleY = M_PI / 2 - relPos.getAngleY();
        Vector temp((angleX + fov.x / 2) * size.x / fov.x, (-angleY + fov.y / 2) * size.y / fov.y);
        return temp;
}
