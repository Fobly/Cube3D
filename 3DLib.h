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

    rad = x;
    point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
    point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

    rad = y;
    point.x = std::cos(rad) * point.x - std::sin(rad) * point.z;
    point.z = std::sin(rad) * point.x + std::cos(rad) * point.z;

    rad = z;
    point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
    point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;
}