struct Viewport;
struct Surface;


typedef void (*callback_t)(struct Surface* surface, void* data);
struct Viewport* create_viewport(callback_t print_callback, int width, int height, void* data);
void destroy_viewport(struct Viewport* viewport);


struct Surface* create_surface(struct Viewport *viewport);
void destroy_surface(struct Surface *surface);


enum pollres {PROCESS, STOP};
enum pollres viewport_poll(struct Viewport* viewport, struct Surface *surface);


typedef struct Surface_color{
	unsigned r: 8;
	unsigned g: 8;
	unsigned b: 8;
	unsigned a: 8;
} Surface_color_t;


void surface_fillwith(struct Surface *surface, Surface_color_t color);
void surface_putpixel(struct Surface *surface, Surface_color_t color, int x, int y);



