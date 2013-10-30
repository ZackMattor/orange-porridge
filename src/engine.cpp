#include "engine.h"

engine::engine()
{
    qDebug() << "--Engine Constructing--" << endl;

    init();
}

int engine::init() {
    m_window = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "Orange Porridge");

    m_gameInstance = new gameManager();

    return 1;
}

void engine::run() {
    //event_queue = al_create_event_queue();
    //timer = al_create_timer(1.0 / FPS);
    //qsrand(QTime::currentTime().msec());

    //al_start_timer(timer);

    sf::Clock clock;

    static int WAIT_FOR_TICK = 1000 / TICS_PER_SEC;
    static int WAIT_FOR_DRAW = 1000 / FRAMES_PER_SEC;

    int lastTick = 0;
    int lastDraw = 0;
    int tick_count = 0;

    while(m_window->isOpen()) {
        int time =  clock.getElapsedTime().asMilliseconds();

        // clear the window with black color

        if(lastTick + WAIT_FOR_TICK < time) {
            //qDebug("--------------------UPDATE----------------");
            m_gameInstance->Update(m_window);
            tick_count++;
            lastTick = time;
        }

        if(lastDraw + WAIT_FOR_DRAW < time) {
            //qDebug("--------------------DRAW----------------");

            m_gameInstance->Draw(m_window);
            lastDraw = time;
        }

        sf::Event event;
        while (m_window->pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                m_window->close();
            }
        }

        // end the current frame
        m_window->display();
    }
}
