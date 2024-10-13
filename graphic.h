#include <SDL2/SDL.h>
#include <vector>
#include <numeric>

class Screen{
    
    SDL_Event e;
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::vector<SDL_FPoint> points;

    public:
    Screen(){
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
        // SDL_RendererSetScale(renderer, 2, 2);
    }

    void pixel(float x, float y){
         points.emplace_back(SDL_FPoint{ x, y });
    }

    void line(float x1, float y1, float x2, float y2){
        float dx = x2 - x1;
        float dy = y2 - y1;

        float len = std::sqrt(dx*dx + dy*dy);
        float angle = std::atan2(dy, dx);
        for (float i=0; i<len; i++){
            pixel(x1 + std::cos(angle)*i, y1 + std::sin(angle)*i);
        }
    }

    void display(){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (auto &point : points){
            SDL_RenderDrawPointF(renderer, point.x, point.y);
        }

        SDL_RenderPresent(renderer);
    }

    void clear(){
        points.clear();
    }

    void input(){
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT){
                SDL_Quit();
                exit(0);
            }
        }
    }
};