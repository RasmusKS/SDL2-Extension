#ifndef CAM_H
#define CAM_H

#include <World.hpp>
#include <Window.hpp>

class Cam{

public:

        Cam();
        Cam(World *world);
        ~Cam();

        void attachWorld(World *world);

        void joystickActivateButton(int button);

        void roll(double rad);
        void pitch(double rad);
        void yaw(double rad);

        void move(Vector mov);
        void move2D(Vector mov);

        void draw(Window &window);
        void draw(Window &window, Vector size);
        void draw(Window &window, Vector offset, Vector size);

        void setFov(double fovX, double fovY);
        void setFov(Vector fov);
        Vector getFov();

        void setPos(double posX, double posY, double posZ);
        void setPos(Vector dir);
        Vector getPos();

        void setDir(double roll, double pitch, double yaw);
        void setDir(Vector dir);
        Vector getDir();

        Vector fov;
        Vector pos;
        Vector dir;

        World *world;

        int renderedObjects;

//private:

        Vector pos3DToPos2D(Vector &pos, Vector &size);
        double pos3DToPosX(Vector pos);
        double pos3DToPosY(Vector pos);
};

#endif
