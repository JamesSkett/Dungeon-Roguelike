#include "Renderer.h"
#include "Tile.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

ALLEGRO_DISPLAY* Renderer::disp;
ALLEGRO_TRANSFORM Renderer::camera;

Renderer::Renderer()
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();

    if (!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
    }

    disp = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

}

Renderer::~Renderer()
{
    al_destroy_display(disp);
}

void Renderer::CameraUpdate(float* cameraPosition, float x, float y, int width, int height, float endTileX, float endTileY)
{
    //follow the player when they get to the centre of the screen
    cameraPosition[0] = -(SCREEN_WIDTH / 2) + (x + width / 2);
    cameraPosition[1] = -(SCREEN_HEIGHT / 2) + (y + height / 2);

    //stop the camera if it hits 0 in x/y
    if (cameraPosition[0] < 0)
        cameraPosition[0] = 0;
    if (cameraPosition[0] + SCREEN_WIDTH > endTileX)
        cameraPosition[0] = endTileX - SCREEN_WIDTH;
    if (cameraPosition[1] < 0)
        cameraPosition[1] = 0;
    if (cameraPosition[1] + SCREEN_HEIGHT > endTileY)
        cameraPosition[1] = endTileY - SCREEN_HEIGHT;
}

float* Renderer::GetCameraPos()
{
    return cameraPosition;
}


