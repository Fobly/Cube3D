#include "graphic.h"

struct vec3{
    float x, y, z;
};
struct connection
{
    int a, b;
};

class Figure {
    public:
    std::vector<vec3> points;
    std::vector<connection> connections;
    vec3 center;

    Figure(std::vector<vec3> points, std::vector<connection> connections, vec3 center)
    {
        this->center = center;
        this->points = points;
        this->connections = connections;
        for (auto &p : points)
        {
            this->center.x += p.x;
            this->center.y += p.y;
            this->center.z += p.z;
        }
        this->center.x /= points.size();
        this->center.y /= points.size();
        this->center.z /= points.size();
    }
};

void rotate(vec3 &point, float x = 1, float y = 1, float z = 1){

    float rad = 0;
    vec3 OGpoint = point; //add this

    rad = x;
    point.y = cos(rad) * OGpoint.y - sin(rad) * OGpoint.z;
    point.z = sin(rad) * OGpoint.y + cos(rad) * OGpoint.z;
    OGpoint = point; // add this

    rad = y;
    point.x = cos(rad) * OGpoint.x + sin(rad) * OGpoint.z;
    point.z = -sin(rad) * OGpoint.x + cos(rad) * OGpoint.z;
    OGpoint = point; //add this

    rad = z;
    point.x = cos(rad) * OGpoint.x - sin(rad) * OGpoint.y;
    point.y = sin(rad) * OGpoint.x + cos(rad) * OGpoint.y;

}