/********************************************
 KODAY 04: menu simple
 Web: http://devcpp-allegro.blogspot.com/
*********************************************
  muestra dos menus simples
*********************************************/

#include <allegro.h>


int main() 
{	
    // inicializacion del allegro    
	allegro_init();
	install_keyboard();
	install_mouse();
	
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1300, 450, 0, 0);
	
	//define variables utilizadas en el programa
	BITMAP *buffer = create_bitmap(1300, 450);
	BITMAP *fondo;
	BITMAP *fondo2;
	BITMAP *fondo3;
	BITMAP *cursor;
	
	BITMAP *inicio_1;  
	// inicializa las variables 
	clear_to_color(buffer, 0x333333);		
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
            blit(fondo2, buffer, 0, 0, 0, 0, 1300, 450); 
            
            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                  salida = true;
            }
         }else if ( mouse_x > 570 && mouse_x < 730 &&
              mouse_y > 360 && mouse_y < 420) {
		
			blit(fondo3, buffer, 0, 0, 0, 0, 1300, 450); 
			
					if(mouse_b & 1){
				    salida = true; 
		          return 0;
				   	}
		}
		 
		 else{
         	
         	
         	
            blit(fondo, buffer, 0, 0, 0, 0, 1300, 450);    
         }

         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22); 
         
         // se muestra todo por pantalla 
	     blit(buffer, screen, 0, 0, 0, 0, 1300, 450);
	     
          if ( key[KEY_ESC] )
          {
               salida = true;
          } 
	     
    }
    
    // inicializa las variables con el nuevo menu 
    salida = false;
	destroy_bitmap(fondo);
	destroy_bitmap(fondo2);
	fondo  = load_bitmap("simple2f.bmp",NULL);
	fondo2 = load_bitmap("simple2n.bmp",NULL);
	
	// menu simple 2, igual que el anterior
	while ( !salida )
	{
         if ( mouse_x > 230 && mouse_x < 410 &&
              mouse_y > 390 && mouse_y < 440) 
         {  
            blit(fondo2, buffer, 0, 0, 0, 0, 1300, 450); 
            
            if ( mouse_b & 1 )
            {
                  salida = true;
            }
         }else{
            blit(fondo, buffer, 0, 0, 0, 0, 1300, 450);    
         }
         
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22); 
          
	     blit(buffer, screen, 0, 0, 0, 0, 1300, 450);
	     
	     // se cambia la tecla de salida
          if ( key[KEY_ENTER] )
          {
               salida = true;
          } 
	     
    }	
     

    // libera memoria quitando las imagenes 	
	destroy_bitmap(buffer);
	destroy_bitmap(fondo);
	destroy_bitmap(fondo2);
	destroy_bitmap(cursor);
	
	return 0;
}
END_OF_MAIN();
