class Menu{
	public:
		// Variables
		int x;
		int y;
		BITMAP* sprite;
		BITMAP* visor;
		BITMAP* b_vida;
		BITMAP* img;
		//Funciones
		Menu(int x, int y);
		~Menu();
		void action(int &vida);
};

Menu::Menu(int x, int y){
	this->x = x;
	this->y = y;
	sprite = create_bitmap(1300,640);
	 img = load_bitmap("fon_vida.bmp",NULL);
	visor = load_bitmap("visor.bmp",NULL);
	this->b_vida = load_bitmap("b_vida.bmp",NULL);
    

}

void Menu::action(int &vida){
	draw_sprite(sprite,img,0,0); // imagen de fondo
	draw_sprite(sprite,visor,30,50); // dibuja el visor 
	//-----------------------------------
	float b_tam = (104.0/100.0) * vida; // tamaño de la barra de vida
	stretch_sprite(sprite,b_vida,102,56,b_tam,12); // crea una barra de vida estirando una imagen
	//-----------------------------------


	draw_sprite(screen,sprite,x,y);	
	
}

Menu::~Menu(){

}

