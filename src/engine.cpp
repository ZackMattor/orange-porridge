#include "engine.h"

engine::engine()
{
    qDebug() << "--Engine Constructing--" << endl;

    init();
}

int engine::init() {
    //Allegro Setup
    if(!al_init())
    {
        qDebug() << "Allegro Init is failing!";
        return -1;
    }

    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    m_display = al_create_display(ScreenWidth, ScreenHeight);
    al_set_window_title(m_display, "Triangles in Space");

    if(!m_display)
    {
        qDebug() << "Display is failing!";
        return -1;
    }

    al_install_keyboard();
    al_install_mouse();

    m_gameInstance = new game();

    return 1;
}

void engine::run() {
    //primitive variable
    bool redraw = true;
    const int FPS = 60;

    //Allegro variables
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);
    qsrand(QTime::currentTime().msec());

    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_keyboard_event_source());
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_mouse_event_source());
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_timer_event_source(timer));
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_display_event_source(m_display));
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)m_display);

    al_start_timer(timer);

    while(m_gameInstance->getGameState() != CLOSE)
    {
        QCoreApplication::processEvents();
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        switch(ev.type)
        {
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                //Update();
            break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                m_gameInstance->setGameState(CLOSE);
            break;

            case ALLEGRO_EVENT_KEY_DOWN:
                m_keys[ev.keyboard.keycode] = true;
            break;

            case ALLEGRO_EVENT_KEY_UP:
                m_keys[ev.keyboard.keycode] = false;
            break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            case ALLEGRO_EVENT_MOUSE_AXES:
                m_mouse = ev.mouse;
            break;
        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {
            //cout << "Drawing";
            redraw = false;
           //draw();

            //FLIP BUFFERS
            al_flip_display();

            if(m_gameInstance->getGameState() != GAME) //game takes care of it's own background
            {
                if(m_background != NULL)
                {
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(m_background, 0, 0, 0);
                }
                else
                {
                    al_clear_to_color(al_map_rgb(0, 191, 255));
                }
            }
        }
    }
}
