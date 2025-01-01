#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "draw_utils_interface.h"

void draw_carpet_knuth(struct Surface *surface, void* data){
	Surface_color_t backcolor = {		
		.r = 0xC1,
		.g = 0xBD,
		.b = 0xB4,
		.a = 0x00,
	};

	Surface_color_t pate = {
		.r = 0xF5,
		.g = 0x89,
		.b = 0x02,
		.a = 0x00,
	};
	surface_fillwith(surface, pate);
	for(int y = 0; y < 2000; ++y) {
		for(int x = 0; x < 2000; ++x) {
			if(((x^y)*(x^y) >> 17) & 1) surface_putpixel(surface, backcolor, x, y);
		}
	}
}

int main() {
	struct Viewport *viewport = create_viewport(draw_carpet_knuth, 1000, 1000, NULL);
	struct Surface *surface = create_surface(viewport);
	while(viewport_poll(viewport, surface) == PROCESS){}
	destroy_surface(surface);
	destroy_viewport(viewport);
}
