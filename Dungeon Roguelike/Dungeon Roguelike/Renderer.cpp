#include "Renderer.h"
#include "Tile.h"

Renderer::Renderer()
{
    al_init();
    al_install_keyboard();

    timer = al_create_timer(1.0 / 30.0);
    queue = al_create_event_queue();
    disp = al_create_display(1920, 1080);
    font = al_create_builtin_font();

    if (!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
    }

    tile = new Tile(0, 0, "turtle.jpg");

}

void Renderer::Init()
{
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if ((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            tile->Draw();

            al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");


            al_flip_display();

            redraw = false;
        }
    }

}

Renderer::~Renderer()
{

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}
