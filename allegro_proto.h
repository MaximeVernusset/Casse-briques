#ifndef ALLEGRO_PROTO_H_INCLUDED
#define ALLEGRO_PROTO_H_INCLUDED

int install_allegro(int system_id, int *errno_ptr, int (*atexit_ptr)());
int allegro_init();
void allegro_exit();
void allegro_message(const char *text_format, ...);
void set_window_title(const char *name);
int set_close_button_callback(void (*proc)(void));
int desktop_color_depth();
int get_desktop_resolution(int *width, int *height);
void check_cpu();


void set_uformat(int type);
int get_uformat(void);
void register_uformat(int type, int (*u_getc)(const char *s), int (*u_getx)(char **s), int (*u_setc)(char *s, int c), int (*u_width)(const char *s), int (*u_cwidth)(int c), int (*u_isok)(int c));
void set_ucodepage(const unsigned short *table, const unsigned short *extras);
int need_uconvert(const char *s, int type, int newtype);
int uconvert_size(const char *s, int type, int newtype);
void do_uconvert(const char *s, int type, char *buf, int newtype, int size);
char *uconvert(const char *s, int type, char *buf, int newtype, int size);
char *uconvert_ascii(const char *s, char buf[]);
char *uconvert_toascii(const char *s, char buf[]);
int ugetc(const char *s);
int ugetx(char **s);
int ugetxc(const char **s);
int usetc(char *s, int c);
int uwidth(const char *s);
int ucwidth(int c);
int uisok(int c);
int uoffset(const char *s, int index);
int ugetat(const char *s, int index);
int usetat(char *s, int index, int c);
int uinsert(char *s, int index, int c);
int uremove(char *s, int index);
int ustrsize(const char *s);
int ustrsizez(const char *s);
int uwidth_max(int type);
int utolower(int c);
int utoupper(int c);
int uisspace(int c);
int uisdigit(int c);
char *ustrdup(const char *src)
char *_ustrdup(const char *src, void* (*malloc_func)(size_t))
char *ustrcpy(char *dest, const char *src);
char *ustrzcpy(char *dest, int size, const char *src);
char *ustrcat(char *dest, const char *src);
char *ustrzcat(char *dest, int size, const char *src);
int ustrlen(const char *s);
int ustrcmp(const char *s1, const char *s2);
char *ustrncpy(char *dest, const char *src, int n);
char *ustrzncpy(char *dest, int size, const char *src, int n);
char *ustrncat(char *dest, const char *src, int n);
char *ustrzncat(char *dest, int size, const char *src, int n);
int ustrncmp(const char *s1, const char *s2, int n);
int ustricmp(const char *s1, const char *s2);
int ustrnicmp(const char *s1, const char *s2, int n);
char *ustrlwr(char *s);
char *ustrupr(char *s);
char *ustrchr(const char *s, int c);
char *ustrrchr(const char *s, int c);
char *ustrstr(const char *s1, const char *s2);
char *ustrpbrk(const char *s, const char *set);
char *ustrtok(char *s, const char *set);
char *ustrtok_r(char *s, const char *set, char **last);
double uatof(const char *s);
long ustrtol(const char *s, char **endp, int base);
double ustrtod(const char *s, char **endp);
const char *ustrerror(int err);
int usprintf(char *buf, const char *format, ...);
int uszprintf(char *buf, int size, const char *format, ...);
int uvsprintf(char *buf, const char *format, va_list args);
int uvszprintf(char *buf, int size, const char *format, va_list args);


void set_uformat(int type);
int get_uformat(void);
void register_uformat(int type, int (*u_getc)(const char *s), int (*u_getx)(char **s), int (*u_setc)(char *s, int c), int (*u_width)(const char *s), int (*u_cwidth)(int c), int (*u_isok)(int c));
void set_ucodepage(const unsigned short *table, const unsigned short *extras);
int need_uconvert(const char *s, int type, int newtype);
int uconvert_size(const char *s, int type, int newtype);
void do_uconvert(const char *s, int type, char *buf, int newtype, int size);
char *uconvert(const char *s, int type, char *buf, int newtype, int size);
char *uconvert_ascii(const char *s, char buf[]);
char *uconvert_toascii(const char *s, char buf[]);
int ugetc(const char *s);
int ugetx(char **s);
int ugetxc(const char **s);
int usetc(char *s, int c);
int uwidth(const char *s);
int ucwidth(int c);
int uisok(int c);
int uoffset(const char *s, int index);
int ugetat(const char *s, int index);
int usetat(char *s, int index, int c);
int uinsert(char *s, int index, int c);
int uremove(char *s, int index);
int ustrsize(const char *s);
int ustrsizez(const char *s);
int uwidth_max(int type);
int utolower(int c);
int utoupper(int c);
int uisspace(int c);
int uisdigit(int c);
char *ustrdup(const char *src)
char *_ustrdup(const char *src, void* (*malloc_func)(size_t))
char *ustrcpy(char *dest, const char *src);
char *ustrzcpy(char *dest, int size, const char *src);
char *ustrcat(char *dest, const char *src);
char *ustrzcat(char *dest, int size, const char *src);
int ustrlen(const char *s);
int ustrcmp(const char *s1, const char *s2);
char *ustrncpy(char *dest, const char *src, int n);
char *ustrzncpy(char *dest, int size, const char *src, int n);
char *ustrncat(char *dest, const char *src, int n);
char *ustrzncat(char *dest, int size, const char *src, int n);
int ustrncmp(const char *s1, const char *s2, int n);
int ustricmp(const char *s1, const char *s2);
int ustrnicmp(const char *s1, const char *s2, int n);
char *ustrlwr(char *s);
char *ustrupr(char *s);
char *ustrchr(const char *s, int c);
char *ustrrchr(const char *s, int c);
char *ustrstr(const char *s1, const char *s2);
char *ustrpbrk(const char *s, const char *set);
char *ustrtok(char *s, const char *set);
char *ustrtok_r(char *s, const char *set, char **last);
double uatof(const char *s);
long ustrtol(const char *s, char **endp, int base);
double ustrtod(const char *s, char **endp);
const char *ustrerror(int err);
int usprintf(char *buf, const char *format, ...);
int uszprintf(char *buf, int size, const char *format, ...);
int uvsprintf(char *buf, const char *format, va_list args);
int uvszprintf(char *buf, int size, const char *format, va_list args);


void set_config_file(const char *filename);
void set_config_data(const char *data, int length);
void override_config_file(const char *filename);
void override_config_data(const char *data, int length);
void push_config_state();
void pop_config_state();
void flush_config_file();
void reload_config_texts(const char *new_language);
void hook_config_section(const char *section, int (*intgetter)(const char *name, int def), const char *(*stringgetter)(const char *name, const char *def), void (*stringsetter)(const char *name, const char *value));
int config_is_hooked(const char *section);
const char *get_config_string(const char *section, const char *name, const char *def);
int get_config_int(const char *section, const char *name, int def);
int get_config_hex(const char *section, const char *name, int def);
float get_config_float(const char *section, const char *name, float def);
int get_config_id(const char *section, const char *name, int def);
char **get_config_argv(const char *section, const char *name, int *argc);
const char *get_config_text(const char *msg);
void set_config_string(const char *section, const char *name, const char *val);
void set_config_int(const char *section, const char *name, int val);
void set_config_hex(const char *section, const char *name, int val);
void set_config_float(const char *section, const char *name, float val);
void set_config_id(const char *section, const char *name, int val);
int list_config_entries(const char *section, const char ***names);
int list_config_sections(const char ***names);
int free_config_entries(const char ***names);


// Mouse routines
int install_mouse();
void remove_mouse();
int poll_mouse();
int mouse_needs_poll();
void enable_hardware_cursor(void);
void disable_hardware_cursor(void);
void select_mouse_cursor(int cursor);
void set_mouse_cursor_bitmap(int cursor, BITMAP *bmp);
void show_mouse(BITMAP *bmp);
void scare_mouse();
void scare_mouse_area(int x, int y, int w, int h);
void unscare_mouse();
int show_os_cursor(int cursor);
void position_mouse(int x, int y);
void position_mouse_z(int z);
void set_mouse_range(int x1, int y1, int x2, int y2);
void set_mouse_speed(int xspeed, int yspeed);
void set_mouse_sprite(BITMAP *sprite);
void set_mouse_sprite_focus(int x, int y);
void get_mouse_mickeys(int *mickeyx, int *mickeyy);


// Timer routine
int install_timer();
void remove_timer();
int install_int(void (*proc)(), int speed);
int install_int_ex(void (*proc)(), int speed);
void remove_int(void (*proc)());
int install_param_int(void (*proc)(void *), void *param, int speed);
int install_param_int_ex(void (*proc)(void *), void *param, int speed);
void remove_param_int(void (*proc)(void *), void *param);
void rest(unsigned int time);
void rest_callback(long time, void (*callback)())


// Keyboard routines
int install_keyboard();
void remove_keyboard();
void install_keyboard_hooks(int (*keypressed)(), int (*readkey)());
int poll_keyboard();
int keyboard_needs_poll();
int keypressed();
int readkey();
int ureadkey(int *scancode);
int scancode_to_ascii(int scancode);
void simulate_keypress(int key);
void simulate_ukeypress(int key, int scancode);
void set_leds(int leds);
void set_keyboard_rate(int delay, int repeat);
void clear_keybuf();


// Joystick routines
int install_joystick(int type);
void remove_joystick();
int poll_joystick();
int calibrate_joystick(int n);
int save_joystick_data(const char *filename);
int load_joystick_data(const char *filename);
int initialise_joystick();


// Graphic modes
void set_color_depth(int depth);
int get_color_depth(void);
void request_refresh_rate(int rate);
int get_refresh_rate(void);
GFX_MODE_LIST *get_gfx_mode_list(int card);
void destroy_gfx_mode_list(GFX_MODE_LIST *mode_list);
int set_gfx_mode(int card, int w, int h, int v_w, int v_h);
int set_display_switch_mode(int mode);
int set_display_switch_callback(int dir, void (*cb)());
void remove_display_switch_callback(void (*cb)());
int get_display_switch_mode();
int is_windowed_mode(void);
int enable_triple_buffer();
int scroll_screen(int x, int y);
int request_scroll(int x, int y);
int poll_scroll();
int show_video_bitmap(BITMAP *bitmap);
int request_video_bitmap(BITMAP *bitmap);
void vsync();

// Bitmap objects
BITMAP *create_bitmap(int width, int height);
BITMAP *create_bitmap_ex(int color_depth, int width, int height);
BITMAP *create_sub_bitmap(BITMAP *parent, int x, y, width, height);
BITMAP *create_video_bitmap(int width, int height);
BITMAP *create_system_bitmap(int width, int height);
void destroy_bitmap(BITMAP *bitmap);
void lock_bitmap(BITMAP *bitmap);
int bitmap_color_depth(BITMAP *bmp);
int bitmap_mask_color(BITMAP *bmp);
int is_same_bitmap(BITMAP *bmp1, BITMAP *bmp2);
int is_planar_bitmap(BITMAP *bmp);
int is_linear_bitmap(BITMAP *bmp);
int is_memory_bitmap(BITMAP *bmp);
int is_screen_bitmap(BITMAP *bmp);
int is_video_bitmap(BITMAP *bmp);
int is_system_bitmap(BITMAP *bmp);
int is_sub_bitmap(BITMAP *bmp);
void acquire_bitmap(BITMAP *bmp);
void release_bitmap(BITMAP *bmp);
void acquire_screen();
void release_screen();
void set_clip_rect(BITMAP *bitmap, int x1, int y1, int x2, int y2);
void get_clip_rect(BITMAP *bitmap, int *x1, int *y1, int *x2, int *y2);
void add_clip_rect(BITMAP *bitmap, int x1, int y1, int x2, int y2);
void set_clip_state(BITMAP *bitmap, int state);
int get_clip_state(BITMAP *bitmap);
int is_inside_bitmap(BITMAP *bmp, int x, int y, int clip);


// Loading image file
BITMAP *load_bitmap(const char *filename, RGB *pal);
BITMAP *load_bmp(const char *filename, RGB *pal);
BITMAP *load_bmp_pf(PACKFILE *f, RGB *pal);
BITMAP *load_lbm(const char *filename, RGB *pal);
BITMAP *load_pcx(const char *filename, RGB *pal);
BITMAP *load_pcx_pf(PACKFILE *f, RGB *pal);
BITMAP *load_tga(const char *filename, RGB *pal);
BITMAP *load_tga_pf(PACKFILE *f, RGB *pal);
int save_bitmap(const char *filename, BITMAP *bmp, const RGB *pal);
int save_bmp(const char *filename, BITMAP *bmp, const RGB *pal);
int save_bmp_pf(PACKFILE *f, BITMAP *bmp, RGB *pal);
int save_pcx(const char *filename, BITMAP *bmp, const RGB *pal);
int save_pcx_pf(PACKFILE *f, BITMAP *bmp, RGB *pal);
int save_tga(const char *filename, BITMAP *bmp, const RGB *pal);
int save_tga_pf(PACKFILE *f, BITMAP *bmp, RGB *pal);
void register_bitmap_file_type(const char *ext, BITMAP *(*load)(const char *filename, RGB *pal), int (*save)(const char *filename, BITMAP *bmp, const RGB *pal));
void set_color_conversion(int mode);
int get_color_conversion();


// Pqlette routines
void set_color(int index, const RGB *p);
void _set_color(int index, const RGB *p);
void set_palette(const PALETTE p);
void set_palette_range(const PALETTE p, int from, int to, int vsync);
void get_color(int index, RGB *p);
void get_palette(PALETTE p);
void get_palette_range(PALETTE p, int from, int to);
void fade_interpolate(const PALETTE source, const PALETTE dest, PALETTE output, int pos, int from, int to);
void fade_from_range(const PALETTE source, const PALETTE dest, int speed, int from, int to);
void fade_in_range(const PALETTE p, int speed, int from, int to);
void fade_out_range(int speed, int from, int to);
void fade_from(const PALETTE source, const PALETTE dest, int speed);
void fade_in(const PALETTE p, int speed);
void fade_out(int speed);
void select_palette(const PALETTE p);
void unselect_palette();
void generate_332_palette(PALETTE pal);
int generate_optimized_palette(BITMAP *bmp, PALETTE pal, const char rsvd[PAL_SIZE]);


// Truecolor pixel formats
int makecol8(int r, int g, int b);
int makecol15(int r, int g, int b);
int makecol16(int r, int g, int b);
int makecol24(int r, int g, int b);
int makecol32(int r, int g, int b);
int makeacol32(int r, int g, int b, int a);
int makecol(int r, int g, int b);
int makecol_depth(int color_depth, int r, int g, int b);
int makeacol(int r, int g, int b, int a);
int makeacol_depth(int color_depth, int r, int g, int b, int a);
int makecol15_dither(int r, int g, int b, int x, int y);
int makecol16_dither(int r, int g, int b, int x, int y);
int getr8(int c);
int getg8(int c);
int getb8(int c);
int getr15(int c);
int getg15(int c);
int getb15(int c);
int getr16(int c);
int getg16(int c);
int getb16(int c);
int getr24(int c);
int getg24(int c);
int getb24(int c);
int getr32(int c);
int getg32(int c);
int getb32(int c);
int geta32(int c);
int getr(int c);
int getg(int c);
int getb(int c);
int geta(int c);
int getr_depth(int color_depth, int c);
int getg_depth(int color_depth, int c);
int getb_depth(int color_depth, int c);
int geta_depth(int color_depth, int c);


// Drawing primitives
void clear_bitmap(BITMAP *bitmap);
void clear_to_color(BITMAP *bitmap, int color);
void putpixel(BITMAP *bmp, int x, int y, int color);
void _putpixel(BITMAP *bmp, int x, int y, int color);
void _putpixel15(BITMAP *bmp, int x, int y, int color);
void _putpixel16(BITMAP *bmp, int x, int y, int color);
void _putpixel24(BITMAP *bmp, int x, int y, int color);
void _putpixel32(BITMAP *bmp, int x, int y, int color);
int getpixel(BITMAP *bmp, int x, int y);
int _getpixel(BITMAP *bmp, int x, int y);
int _getpixel15(BITMAP *bmp, int x, int y);
int _getpixel16(BITMAP *bmp, int x, int y);
int _getpixel24(BITMAP *bmp, int x, int y);
int _getpixel32(BITMAP *bmp, int x, int y);
void vline(BITMAP *bmp, int x, int y1, int y2, int color);
void hline(BITMAP *bmp, int x1, int y, int x2, int color);
void do_line(BITMAP *bmp, int x1, y1, x2, y2, int d, void (*proc)(BITMAP *bmp, int x, int y, int d));
void line(BITMAP *bmp, int x1, int y1, int x2, int y2, int color);
void fastline(BITMAP *bmp, int x1, int y1, int x2, int y2, int color);
void triangle(BITMAP *bmp, int x1, y1, x2, y2, x3, y3, int color);
void polygon(BITMAP *bmp, int vertices, const int *points, int color);
void rect(BITMAP *bmp, int x1, int y1, int x2, int y2, int color);
void rectfill(BITMAP *bmp, int x1, int y1, int x2, int y2, int color);
void do_circle(BITMAP *bmp, int x, int y, int radius, int d, void (*proc)(BITMAP *bmp, int x, int y, int d));
void circle(BITMAP *bmp, int x, int y, int radius, int color);
void circlefill(BITMAP *bmp, int x, int y, int radius, int color);
void do_ellipse(BITMAP *bmp, int x, int y, int rx, ry, int d, void (*proc)(BITMAP *bmp, int x, int y, int d));
void ellipse(BITMAP *bmp, int x, int y, int rx, int ry, int color);
void ellipsefill(BITMAP *bmp, int x, int y, int rx, int ry, int color);
void do_arc(BITMAP *bmp, int x, int y, fixed a1, fixed a2, int r, int d, void (*proc)(BITMAP *bmp, int x, int y, int d));
void arc(BITMAP *bmp, int x, y, fixed ang1, ang2, int r, int color);
void calc_spline(const int points[8], int npts, int *x, int *y);
void spline(BITMAP *bmp, const int points[8], int color);
void floodfill(BITMAP *bmp, int x, int y, int color);


//Blitting and sprites
void blit(BITMAP *source, BITMAP *dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
void stretch_blit(BITMAP *source, BITMAP *dest, int source_x, source_y, source_width, source_height, int dest_x, dest_y, dest_width, dest_height);
void masked_blit(BITMAP *source, BITMAP *dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
void masked_stretch_blit(BITMAP *source, BITMAP *dest, int source_x, source_y, source_w, source_h, int dest_x, dest_y, dest_w, dest_h);
void draw_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y);
void stretch_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, int w, int h);
void draw_sprite_v_flip(BITMAP *bmp, BITMAP *sprite, int x, int y);
void draw_sprite_h_flip(BITMAP *bmp, BITMAP *sprite, int x, int y);
void draw_sprite_vh_flip(BITMAP *bmp, BITMAP *sprite, int x, int y);
void draw_trans_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y);
void draw_lit_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, int color);
void draw_gouraud_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, int c1, int c2, int c3, int c4);
void draw_character_ex(BITMAP *bmp, BITMAP *sprite, int x, int y, color, bg);
void rotate_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, fixed angle);
void rotate_sprite_v_flip(BITMAP *bmp, BITMAP *sprite, int x, int y, fixed angle);
void rotate_scaled_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, fixed angle, fixed scale);
void rotate_scaled_sprite_v_flip(BITMAP *bmp, BITMAP *sprite, int x, int y, fixed angle, fixed scale);
void pivot_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, int cx, int cy, fixed angle);
void pivot_sprite_v_flip(BITMAP *bmp, BITMAP *sprite, int x, int y, int cx, int cy, fixed angle);
void pivot_scaled_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, int cx, int cy, fixed angle, fixed scale);
void pivot_scaled_sprite_v_flip(BITMAP *bmp, BITMAP *sprite, int x, int y, int cx, int cy, fixed angle, fixed scale);


//RLE sprites
RLE_SPRITE *get_rle_sprite(BITMAP *bitmap);
void destroy_rle_sprite(RLE_SPRITE *sprite); void draw_rle_sprite(BITMAP *bmp, const RLE_SPRITE *sprite, int x, int y);
void draw_rle_sprite(BITMAP *bmp, const RLE_SPRITE *sprite, int x, int y);
void draw_trans_rle_sprite(BITMAP *bmp, const RLE_SPRITE *sprite, int x, int y);
void draw_lit_rle_sprite(BITMAP *bmp, const RLE_SPRITE *sprite, int x, y, color);

// Compiled sprites
COMPILED_SPRITE *get_compiled_sprite(BITMAP *bitmap, int planar);
void destroy_compiled_sprite(COMPILED_SPRITE *sprite);
void draw_compiled_sprite(BITMAP *bmp, const COMPILED_SPRITE *sprite, int x, int y);


// Fonts
void register_font_file_type(const char *ext, FONT *(*load)(const char *filename, RGB *pal, void *param));
FONT *load_font(const char *filename, RGB *pal, void *param);
void destroy_font(FONT *f);
void make_trans_font(FONT *f);
int is_color_font(FONT *f);
int is_mono_font(FONT *f);
FONT *is_compatible_font(FONT *f1, FONT *f2);
int get_font_ranges(FONT *f);
int get_font_range_begin(FONT *f, int range);
int get_font_range_end(FONT *f, int range);
FONT *extract_font_range(FONT *f, int begin, int end);
int transpose_font(FONT *f, int drange);
FONT *merge_fonts(FONT *f1, FONT *f2);
FONT *load_dat_font(const char *filename, RGB *pal, void *param);
FONT *load_bios_font(const char *filename, RGB *pal, void *param);
FONT *load_grx_font(const char *filename, RGB *pal, void *param);
FONT *load_grx_or_bios_font(const char *filename, RGB *pal, void *param);
FONT *load_bitmap_font(const char *filename, RGB *pal, void *param);
FONT *grab_font_from_bitmap(BITMAP *bmp);
FONT *load_txt_font(const char *filename, RGB *pal, void *param);


// Text output
int text_length(const FONT *f, const char *str);
int text_height(const FONT *f);
void textout_ex(BITMAP *bmp, const FONT *f, const char *s, int x, int y, int color, int bg);
void textout_centre_ex(BITMAP *bmp, const FONT *f, const char *s, int x, y, int color, int bg);
void textout_right_ex(BITMAP *bmp, const FONT *f, const char *s, int x, int y, int color, int bg);
void textout_justify_ex(BITMAP *bmp, const FONT *f, const char *s, int x1, int x2, int y, int diff, int color, int bg);
void textprintf_ex(BITMAP *bmp, const FONT *f, int x, int y, int color, int bg, const char *fmt, ...);
void textprintf_centre_ex(BITMAP *bmp, const FONT *f, int x, int y, int color, int bg, const char *fmt, ...);
void textprintf_right_ex(BITMAP *bmp, const FONT *f, int x, y, color, bg, const char *fmt, ...);
void textprintf_justify_ex(BITMAP *bmp, const FONT *f, int x1, x2, y, diff, color, bg, const char *fmt, ...);


// Polygon rendering
void polygon3d(BITMAP *bmp, int type, BITMAP *texture, int vc, V3D *vtx[]);
void polygon3d_f(BITMAP *bmp, int type, BITMAP *texture, int vc, V3D_f *vtx[]);
void triangle3d(BITMAP *bmp, int type, BITMAP *tex, V3D *v1, *v2, *v3);
void triangle3d_f(BITMAP *bmp, int type, BITMAP *tex, V3D_f *v1, *v2, *v3);
void quad3d(BITMAP *bmp, int type, BITMAP *tex, V3D *v1, *v2, *v3, *v4);
void quad3d_f(BITMAP *bmp, int type, BITMAP *tex, V3D_f *v1, *v2, *v3, *v4);
int clip3d_f(int type, float min_z, float max_z, int vc, const V3D_f *vtx[], V3D_f *vout[], V3D_f *vtmp[], int out[]);
int clip3d(int type, fixed min_z, fixed max_z, int vc, const V3D *vtx[], V3D *vout[], V3D *vtmp[], int out[]);
ZBUFFER *create_zbuffer(BITMAP *bmp);
ZBUFFER *create_sub_zbuffer(ZBUFFER *parent, int x, int y, int width, int height);
void set_zbuffer(ZBUFFER *zbuf);
void clear_zbuffer(ZBUFFER *zbuf, float z);
void destroy_zbuffer(ZBUFFER *zbuf);
int create_scene(int nedge, int npoly);
void clear_scene(BITMAP *bmp);
void destroy_scene();
int scene_polygon3d(int type, BITMAP *texture, int vc, V3D *vtx[]);
int scene_polygon3d_f(int type, BITMAP *texture, int vc, V3D_f *vtx[]);
void render_scene();

// Transparency and patterned drawing
void drawing_mode(int mode, BITMAP *pattern, int x_anchor, int y_anchor);
void xor_mode(int on);
void solid_mode();
void create_trans_table(COLOR_MAP *table, const PALETTE pal, int r, g, b, void (*callback)(int pos));
void create_light_table(COLOR_MAP *table, const PALETTE pal, int r, g, b, void (*callback)(int pos));
void create_color_table(COLOR_MAP *table, const PALETTE pal, void (*blend)(PALETTE pal, int x, int y, RGB *rgb), void (*callback)(int pos));
void create_blender_table(COLOR_MAP *table, const PALETTE pal, void (*callback)(int pos));
void set_trans_blender(int r, int g, int b, int a);
void set_alpha_blender();
void set_write_alpha_blender();
void set_add_blender(int r, int g, int b, int a);
void set_burn_blender(int r, int g, int b, int a);
void set_color_blender(int r, int g, int b, int a);
void set_difference_blender(int r, int g, int b, int a);
void set_dissolve_blender(int r, int g, int b, int a);
void set_dodge_blender(int r, int g, int b, int a);
void set_hue_blender(int r, int g, int b, int a);
void set_invert_blender(int r, int g, int b, int a);
void set_luminance_blender(int r, int g, int b, int a);
void set_multiply_blender(int r, int g, int b, int a);
void set_saturation_blender(int r, int g, int b, int a);
void set_screen_blender(int r, int g, int b, int a);
void set_blender_mode(BLENDER_FUNC b15, b16, b24, int r, g, b, a);
void set_blender_mode_ex(BLENDER_FUNC b15, b16, b24, b32, b15x, b16x, b24x, int r, g, b, a);


//Converting between color formats
int bestfit_color(const PALETTE pal, int r, int g, int b);
void create_rgb_table(RGB_MAP *table, const PALETTE pal, void (*callback)(int pos));
void hsv_to_rgb(float h, float s, float v, int *r, int *g, int *b);
void rgb_to_hsv(int r, int g, int b, float *h, float *s, float *v);


// Direct access to video memory
unsigned long bmp_write_line(BITMAP *bmp, int line);
unsigned long bmp_read_line(BITMAP *bmp, int line);
void bmp_unwrite_line(BITMAP *bmp);


//FLIC routines
int play_fli(const char *filename, BITMAP *bmp, int loop, int (*callback)());
int play_memory_fli(const void *fli_data, BITMAP *bmp, int loop, int (*callback)());
int open_fli(const char *filename);
int open_memory_fli(const void *fli_data);
void close_fli();
int next_fli_frame(int loop);
void reset_fli_variables();














#endif // ALLEGRO_PROTO_H_INCLUDED
