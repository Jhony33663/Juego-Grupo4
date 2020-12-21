# include <allegro.h>
BITMAP *lienzo;
# include <iostream>
using namespace std;
#include <unistd.h>
# include <list>
# include <math.h>
# include "Alarm.h"
# include "Bala.h"
# include "Objetos.h"
# include "Enemigo.h"
# include "Background.h"
# include "Menu.h"
Alarm *Timer = new Alarm(); 
void mensaje ();



void init();
void deinit();
void crear();
void Enemigo_action();



void inicio(); /// creacion de la funcion menu

void final();



int main (){
	init();
	
SAMPLE* sample = load_sample("navidad.wav");
	play_sample(sample, 255, 128, 1000, 1);

	inicio();  ////// --------> MENU
	

	
/////////////////////////// Juego Naves  ////////////////////////////
lienzo = create_bitmap(1300,450);

	
	lienzo = create_bitmap(900,640);
	Nave *nave = new Nave();
	Background* background = new Background("fondo_juego.bmp");
	Menu* menu = new Menu(900,0);
	
	
	srand(time(NULL)); // hace que los numeros sean aleatorios
	
	
	
	while (!key[KEY_ESC]) 
	{
		background->action(); // mostrar el fondo
		crear();
		menu->action(nave->vida);
		Enemigo_action();
		if (nave->vida > 0) 	nave->mov(); // mover la nave si su vida es mayor a 0
		draw_sprite(screen,lienzo,0,0);
		clear_to_color(lienzo,0x000000);
		if (nave ->vida <0 and key[KEY_SPACE] ){
		
			final();
		}
	}

	deinit();
	return 0;
}
END_OF_MAIN()


void crear(){
	static int cont = 0; // cuenta los enemigos que se crean
	static int type = rand()%3; // crea un numero aleatorio entre el 0 y 2
	
	if(cont < 5){
		if(Timer->alarm(180)){
			Enemigos.push_back(new Enemigo(-80,15,type)); // crear un enemigo random
			cont++;	
		}
	}else{
		if(Timer->alarm(320))		{
			cont = 0; //reinicia el contador
			type = rand()%3;
		}
	}
	
}


void Enemigo_action(){
	for(list<Enemigo*>::iterator it = Enemigos.begin(); it != Enemigos.end(); it++){
		Enemigo *b = *it;
		b->action();
		
	}
}

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1300, 450, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT  ,MIDI_AUTODETECT, NULL);
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}	




void inicio(){   /////// funcion menu 
	
	install_keyboard();
	install_mouse();
	lienzo = create_bitmap(1300,450);
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1300, 450, 0, 0);
	
	//define variables utilizadas en el programa
	
	BITMAP *fondo;
	BITMAP *fondo2;
	BITMAP *fondo3;
	BITMAP *cursor;
	BITMAP *borrar = create_bitmap(1300, 450);	
	BITMAP *inicio_1;  
	// inicializa las variables 
	
	fondo = load_bitmap("FONDOI1.bmp",NULL);
	fondo2 = load_bitmap("FONDOI2.bmp",NULL);
    fondo3 = load_bitmap("FONDOI3.bmp",NULL);
	cursor = load_bitmap("cursor.bmp",NULL);

    bool salida = false;



	 // primer menu simple
	while ( !salida )	
	{
         // posicion del boton 
         if ( mouse_x > 500 && mouse_x < 800 &&
              mouse_y > 250 && mouse_y < 320) 
         {  
            blit(fondo2, lienzo, 0, 0, 0, 0, 1300, 450); 
            
            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                  salida = true;
            }
         }else if ( mouse_x > 570 && mouse_x < 730 &&
              mouse_y > 360 && mouse_y < 420) {
		
			blit(fondo3, lienzo, 0, 0, 0, 0, 1300, 450); 

					if(mouse_b & 1){
				    exit(-1); 
		          
		          
		          
				   	}
		}
		 
		 else{
         	
         	
         	
            blit(fondo, lienzo, 0, 0, 0, 0, 1300, 450);    
         }

         // pinta el cursor
         masked_blit(cursor, lienzo, 0, 0, mouse_x, mouse_y, 13,22); 
         
         // se muestra todo por pantalla 
	     blit(lienzo, screen, 0, 0, 0, 0, 1300, 450);
	     
          if ( key[KEY_ESC] )
          {
               salida = true;
          } 
	     
    } 
    
    
    ///////////////  portada 
    
    ///////////// instruciciones 
    
    // inicializa las variables con el nuevo menu 
    salida = false;
	destroy_bitmap(fondo);
	destroy_bitmap(fondo2);
	blit(borrar,screen,0,0,0,0,1300, 450);
	fondo  = load_bitmap("simple2f.bmp",NULL);
         blit(borrar,screen,0,0,0,0,1300, 450);	
	fondo2 = load_bitmap("simple2n.bmp",NULL);
         blit(borrar,screen,0,0,0,0,1300, 450);	
	
	// menu simple 2, igual que el anterior
	while ( !salida )
	{
         if ( mouse_x > 460 && mouse_x < 820 &&
              mouse_y > 390 && mouse_y < 440) 
         {  
            blit(fondo2, lienzo, 0, 0, 0, 0, 1300, 450); 
            
            if ( mouse_b & 1 )
            {
                  salida = true;
            }
         }else{
            blit(fondo, lienzo, 0, 0, 0, 0, 1300, 450);    
         }
         
         masked_blit(cursor, lienzo, 0, 0, mouse_x, mouse_y, 13,22); 
          
	     blit(lienzo, screen, 0, 0, 0, 0, 1300, 450);
	     
	     // se cambia la tecla de salida
          if ( key[KEY_ENTER] )
          {
               salida = true;
          } 
	     
    }	
     

    // libera memoria quitando las imagenes 	
	destroy_bitmap(lienzo);
	destroy_bitmap(fondo);
	destroy_bitmap(fondo2);
	destroy_bitmap(cursor);	
	
}


void final (){
	
	
		install_keyboard();
	install_mouse();
	lienzo = create_bitmap(1300,450);
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1300, 450, 0, 0);
	
	//define variables utilizadas en el programa
	
	BITMAP *final;
	BITMAP *final2;
	BITMAP *cursor;
	BITMAP *borrar = create_bitmap(1300, 450);	
	BITMAP *inicio_1;  
	// inicializa las variables 
	
	final = load_bitmap("fin.bmp",NULL);
	final2 = load_bitmap("fin2.bmp",NULL);
    cursor = load_bitmap("cursor.bmp",NULL);

    bool salida = false;



	 // primer menu simple
	while ( !salida )	
	{
         // posicion del boton 
         if ( mouse_x > 400 && mouse_x < 1000 &&
              mouse_y > 240 && mouse_y < 390) 
         {  
            blit(final2, lienzo, 0, 0, 0, 0, 1300, 450); 
            
            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                  salida = true;
                   exit(-1); 
            }
         }
		 
		 else{
         	
         	
            blit(final, lienzo, 0, 0, 0, 0, 1300, 450);    
         }

         // pinta el cursor
         masked_blit(cursor, lienzo, 0, 0, mouse_x, mouse_y, 13,22); 
         
         // se muestra todo por pantalla 
	     blit(lienzo, screen, 0, 0, 0, 0, 1300, 450);
	     
          if ( key[KEY_ESC] )
          {
               salida = true;
          } 
	     
    } 
	
	
}


