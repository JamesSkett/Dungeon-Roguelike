#include "Renderer.h"
#include "Tile.h"

ALLEGRO_DISPLAY* Renderer::disp;

Renderer::Renderer()
{
    al_init();
    al_install_keyboard();

    if (!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
    }

    disp = al_create_display(1920, 1080);

}

Renderer::~Renderer()
{
    al_destroy_display(disp);
}
