// Simple test. I'm kind of following Mike Shah's tutorial series

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_AppResult SDL_AppInit(
    [[maybe_unused]] void **appstate, [[maybe_unused]] int argc, [[maybe_unused]] char **argv
) {
    if (not SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate([[maybe_unused]] void *appstate) {
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent([[maybe_unused]] void *appstate, [[maybe_unused]] SDL_Event *event) {
    // if (event->type == SDL_EVENT_QUIT) {
    //     return SDL_APP_SUCCESS;
    // }
    
    SDL_Log("Running the program");
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit([[maybe_unused]] void *appstate, [[maybe_unused]] SDL_AppResult result) {}
