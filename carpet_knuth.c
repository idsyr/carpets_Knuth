#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "draw_utils_interface.h"

void draw_carpet_knuth(struct Surface *surface, void* data){
	Surface_color_t backcolor = {
		.r = 0xFF,
		.g = 0xFF,
		.b = 0xFF,
		.a = 0x00,
	};
	surface_fillwith(surface, backcolor);

	Surface_color_t pate = {
		.r = 0x42,
		.g = 0x13,
		.b = 0x77,
		.a = 0x00,
	};
	for(int y = 0; y < 1000; ++y){
		for(int x = 0; x < 1000; ++x){
			if(((x^y)*(x^y) >> 17) & 1) surface_putpixel(surface, pate, x, y);
		}
	}
}

int main(){
	struct Viewport *viewport = create_viewport(draw_carpet_knuth, 1000, 1000, NULL);
	struct Surface *surface = create_surface(viewport);
	while(viewport_poll(viewport, surface) == PROCESS){}
	destroy_surface(surface);
	destroy_viewport(viewport);
}

// gcc carpet_knuth.c draw_utils_sdl.c -lSDL2 -lSDL2_image -o carpet_knuth.x -O2
