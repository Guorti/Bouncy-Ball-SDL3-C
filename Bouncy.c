#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

struct Circle
{
    int x;
    int y;
    int radius;
};

void FillSurfaceCircle(SDL_Surface *surface, struct Circle circle) {

};

int main(int argc, char *argv[])
{

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("No se inicio bien: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if (!SDL_CreateWindowAndRenderer("Buen dia", 900, 600, SDL_WINDOW_RESIZABLE, &window, &renderer))
    {
        SDL_Log("No se inicio bien: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_Rect rect = (SDL_Rect){200, 200, 200, 200};
    SDL_FillSurfaceRect(surface, &rect, 0xffffffff);
    SDL_UpdateWindowSurface(window);

    bool done = false;

    while (!done)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                done = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    return SDL_APP_SUCCESS;
}
