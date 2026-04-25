// A more enhanced

#include <cstdint>
#include <string>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = nullptr;
static SDL_Renderer *renderer = nullptr;


//Initialize everything needed to run this program
SDL_AppResult SDL_AppInit(
    [[maybe_unused]] void **appstate, [[maybe_unused]] int argc, [[maybe_unused]] char **argv
) {
    SDL_SetAppMetadata("Name of app", "App version", "App identifier");

    if (not SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    std::string title {"project-3"};
    int width {400};
    int height {400};

    if (not SDL_CreateWindowAndRenderer(title.c_str(), width, height, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(renderer, width, height, SDL_LOGICAL_PRESENTATION_STRETCH);

    return SDL_APP_CONTINUE;
}

//Handle incoming events
SDL_AppResult SDL_AppEvent([[maybe_unused]] void *appstate, [[maybe_unused]] SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

//Run one frame of program
SDL_AppResult SDL_AppIterate([[maybe_unused]] void *appstate) {
    std::uint8_t red {33};
    std::uint8_t green {33};
    std::uint8_t blue {33};

    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    red = 0;
    green = 0;
    blue = 255;

    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_OPAQUE);
    SDL_FRect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = 100;
    rect.h = 50;
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

//Shut down
void SDL_AppQuit([[maybe_unused]] void *appstate, [[maybe_unused]] SDL_AppResult result) {}

