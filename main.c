#include <stdio.h>
#include <allegro5/allegro5.h>
#define  ALEATOIRE al_map_rgb(rand()%256, rand()%256, rand()%256)

int main() {
    // seed
    srand(time(0));

    // Declaration des variables (type ALLEGRO_* )
    ALLEGRO_DISPLAY * fenetre= NULL;
    ALLEGRO_EVENT_QUEUE* fifo = NULL;
    ALLEGRO_COLOR aleatoire= {0};
    ALLEGRO_EVENT event= {0};
    ALLEGRO_TIMER * timer = NULL;

    // initialisation des fonctions Allegro
    assert(al_init());

    // flags
    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    // allocation
    fenetre = al_create_display(800, 600);
    fifo = al_create_event_queue();
    timer = al_create_timer(1.0/2.0); // deux tics par seconde

    // sources
    al_register_event_source(fifo, al_get_display_event_source(fenetre));
    al_register_event_source(fifo, al_get_timer_event_source(timer));

    bool fini = true;
    al_start_timer(timer);
    while(fini) {
        al_wait_for_event(fifo, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                printf("Tu as cliqué sur fermer\n");
                fini= false;
                break;
            case ALLEGRO_EVENT_DISPLAY_RESIZE:
                printf("Tu as changé la taille de la fenetre\n");
                break;
            case ALLEGRO_EVENT_TIMER:
                // ou 
                //aleatoire = al_map_rgb(rand()%256, rand()%256, rand()%256);
                al_clear_to_color(ALEATOIRE);
                al_flip_display();
                break;
            default:
                printf("Event inconnu\n");
        }
    }

    // liberation memoire
    al_destroy_display(fenetre);
    al_destroy_event_queue(fifo);
    al_destroy_timer(timer);
    return 0;
}
