class Nave{
	public:
		//varibles
		int x;
		int y;
		BITMAP* sprite;
		float vel;
		int vida;
		//Funciones
		void mov();
		Nave();
		~Nave();
};

Nave::Nave(){
	x = 200;
	y = 400;
	sprite = load_bitmap("nave.bmp",NULL);
	
	vel = 2;
	vida = 100;
	
}

void Nave::mov(){
	//Dibujo en el lienzo
	draw_sprite(lienzo,sprite,x,y);
	
	
	if(key[KEY_SPACE] and alarm(5))		
		balas.push_back(new Bala(x+(sprite->w/2)-3,y,0)); // agrega una bala a la lista

	
	
	for(list<Bala*>::iterator it = balas.begin(); it != balas.end(); it++){
		Bala *b = *it;
		b->mov();
	}
	
	//colision
	for(list<Bala*>::iterator it = balas.begin(); it != balas.end(); it++){
		Bala *b = *it;
		if(b->type == 1){ // si la bala es de tipo 1 (creada por el enemigo)
			if(b->x >= x and b->x <= x+sprite->w and b->y >= y and b->y <= y+sprite->h)
			{
				delete b;
				this->vida-=3;	
			}	
		}
	}
	
	
	
	
	if(key[KEY_RIGHT] and x + sprite->w < lienzo->w){
		x+=vel;
	}
	if(key[KEY_LEFT] and x > 0){
		x-=vel;
	}
	if(key[KEY_UP] and y > 0){
		y-=vel;
	}
	if(key[KEY_DOWN] and y + sprite->h < lienzo->h){
		y+=vel;
	}
	
	
}


Nave::~Nave(){
	
}
