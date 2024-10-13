#include "3DLib.h"
#include <SDL2/SDL_timer.h>
#include <vector>



int main(){
    Screen screen;

    Figure cube = {
        {
            {100, 100, 100},
            {300, 100, 100},
            {300, 300, 100},
            {100, 300, 100},

            {100, 100, 300},
            {300, 100,300},
            {300, 300, 300},
            {100, 300, 300}
        },
        {
            {0,4},
            {1,5},
            {2,6},
            {3,7},

            {0,1},
            {1,2},
            {2,3},
            {3,0},

            {4,5},
            {5,6},
            {6,7},
            {7,4}
        },
        {0,0,0}
    };
    

    while(1){


        for (auto &p : cube.points)
        {
            p.x -= cube.center.x;
            p.y -= cube.center.y;
            p.z -= cube.center.z;
            rotate(p, 0.02*screen.xos, 0.02*screen.yos, 0.02*screen.zos);
            p.x += cube.center.x;
            p.y += cube.center.y;
            p.z += cube.center.z;
            screen.pixel(p.x, p.y);
        }

        for (auto &conn : cube.connections)
        {
            screen.line(cube.points[conn.a].x, cube.points[conn.a].y
                                    , cube.points[conn.b].x, cube.points[conn.b].y);
        }

        screen.display();
        screen.clear();
        screen.input();
        SDL_Delay(30);
    }

    return 0;
}