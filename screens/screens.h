#include <stdbool.h>

// INTRO
void draw_intro(void);

// GAMEPLAY
void init_gameplay(void);
void update_gameplay(void);
void draw_gameplay(void);
void reset_gameplay(void);
void unload_gameplay(void);
bool gameplay_should_end(void);

// ENDING
void draw_ending(void);
