
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*knight,*wiz,*moon;
SDL_Rect rect_background,rect_knight, rect_wiz, rect_moon;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 10, 30, 1280/*WIDTH*/, 720/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"background.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    knight = IMG_LoadTexture(renderer, "knight.png");
    SDL_QueryTexture(knight, NULL, NULL, &w, &h);
    rect_knight.x = 0; rect_knight.y = 360; rect_knight.w = w; rect_knight.h = h;

    wiz = IMG_LoadTexture(renderer, "wizzard.png");
    SDL_QueryTexture(wiz, NULL, NULL, &w, &h);
    rect_wiz.x = 1150; rect_wiz.y = 360; rect_wiz.w = w; rect_wiz.h = h;

    moon = IMG_LoadTexture(renderer, "moon_overlay.png");
    SDL_QueryTexture(moon, NULL, NULL, &w, &h);
    rect_moon.x = 656; rect_moon.y = 0; rect_moon.w = w; rect_moon.h = h;

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_knight.x+=3;

                else if(Event.key.keysym.sym == SDLK_a)
                    rect_knight.x-=3;

                else if(Event.key.keysym.sym == SDLK_w)
                    rect_knight.y-=3;

                else if(Event.key.keysym.sym == SDLK_s)
                    rect_knight.y+=3;

                else if(Event.key.keysym.sym == SDLK_UP)
                    rect_wiz.y-=3;

                else if(Event.key.keysym.sym == SDLK_DOWN)
                    rect_wiz.y+=3;

                else if(Event.key.keysym.sym == SDLK_RIGHT)
                    rect_wiz.x+=3;

                else if(Event.key.keysym.sym == SDLK_LEFT)
                    rect_wiz.x-=3;
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, moon, NULL, &rect_moon);
        SDL_RenderCopy(renderer, knight, NULL, &rect_knight);
        SDL_RenderCopy(renderer, wiz, NULL, &rect_wiz);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
