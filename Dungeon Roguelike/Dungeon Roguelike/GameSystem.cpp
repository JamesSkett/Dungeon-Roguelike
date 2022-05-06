#include "GameSystem.h"
#include "Renderer.h"
#include "Tile.h"
#include "Player.h"
#include "Level.h"
#include "MainMenu.h"
#include "Image.h"

//#include <conio.h>

//Constructor sets up the game
GameSystem::GameSystem(const char* levelFileName)
	: renderer(new Renderer()), m_level(new Level())
{
	m_timer = al_create_timer(1.0 / 60.0);
	m_queue = al_create_event_queue();
	m_level->Load(levelFileName, m_vTiles, m_player);
}

GameSystem::~GameSystem()
{
	al_destroy_timer(m_timer);
	al_destroy_event_queue(m_queue);

	delete renderer;
	delete m_player;

	//for (int i = 0; i < m_vTiles.size(); i++)
	//{
	//	delete m_vTiles[i];
	//}

	m_vTiles.clear();

	if (m_level != nullptr) 	
	{
		delete m_level;		
		m_level = nullptr;	
	}

}

//---------------------------------------------------------------------------
//main game loop
void GameSystem::playGame()
{
    al_register_event_source(m_queue, al_get_keyboard_event_source());
    al_register_event_source(m_queue, al_get_display_event_source(Renderer::disp));
    al_register_event_source(m_queue, al_get_timer_event_source(m_timer));

	bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_KEYBOARD_STATE keyState;

    al_start_timer(m_timer);
    while (!done)
    {
        al_wait_for_event(m_queue, &event);


		if ((event.type == ALLEGRO_EVENT_KEY_UP))
		{
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			}
		}

		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			al_get_keyboard_state(&keyState);

			if (al_key_down(&keyState, ALLEGRO_KEY_A))
				m_player->UpdatePosition(-5, 0, m_vTiles);
			else if (al_key_down(&keyState, ALLEGRO_KEY_D))
				m_player->UpdatePosition(5, 0, m_vTiles);
			else if (al_key_down(&keyState, ALLEGRO_KEY_W))
				m_player->UpdatePosition(0, -5, m_vTiles);
			else if (al_key_down(&keyState, ALLEGRO_KEY_S))
				m_player->UpdatePosition(0, 5, m_vTiles);
			
			renderer->CameraUpdate(renderer->GetCameraPos(), m_player->GetImage()->GetPos().x, m_player->GetImage()->GetPos().y, m_player->GetImage()->GetWidth(), m_player->GetImage()->GetHeight(), m_vTiles.back()->GetImage()->GetPos().x + 64, m_vTiles.back()->GetImage()->GetPos().y + 64);

			al_identity_transform(&Renderer::camera);
			al_translate_transform(&Renderer::camera, -renderer->GetCameraPos()[0], -renderer->GetCameraPos()[1]);
			al_use_transform(&Renderer::camera);

			redraw = true;
		}


        if (redraw && al_is_event_queue_empty(m_queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));

			for (int i = 0; i < m_vTiles.size(); i++)
			{
				m_vTiles[i]->Draw();
			}

			al_draw_textf(font, al_map_rgb(44, 117, 255), 1920 / 2, 1080 / 2, ALLEGRO_ALIGN_CENTER, "X pos: %f", m_player->GetImage()->GetPos().x);
			m_player->Draw();

            al_flip_display();
			
            redraw = false;
        }
    }

	al_destroy_font(font);
	//tells the player they are dead after all lives lost.
	//deathScreen();
	//returns to main function and game ends
}

//---------------------------------------------------------------------------
//gets user input
//void GameSystem::playerMove()
//{
//	char input;
//	printf("\n\nEnter a move command (W/A/S/D), press 'E' to dig hole or Press 'Q' to quit: ");
//	input = _getch();
//
//	m_level->movePlayer(input, m_player);
//}

//-----------------------------------------------------------------------------
//tells the player they died and prints out the player properties
//void GameSystem::deathScreen()
//{
//	system("CLS");
//	printf("           YOU DIED!\n\n");
//
//	//_player.printProperties();
//	_getch();
//}


