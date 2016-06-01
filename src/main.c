#include "stdio.h"
#include "stdlib.h"
#include "ncurses.h"
#include "string.h"
#include "unistd.h"

#include "../config.h"


int main(int argc, char *argv[]) {

initscr();
noecho();
keypad(stdscr, TRUE);

WINDOW *top_win;
WINDOW *win;
WINDOW *bottom_win;
int wy, wx, y, x, width, height;
width = 100;
height = 30;
y = (LINES - height) / 2;
x = (COLS - width) / 2;
getmaxyx(win, wy, wx);

top_win = newwin(3, width, 1, x);
box(top_win, 0, 0);
win = newwin(height, width, y, x);
box(win, 0, 0);
bottom_win = newwin(6, width, LINES - 7, x);
box(bottom_win, 0, 0);

mvwprintw(top_win, 1, (100 - strlen(PACKAGE_STRING)) / 2 , "%s", PACKAGE_STRING);
curs_set(0);

refresh();
wrefresh(win);
wrefresh(top_win);
wrefresh(bottom_win);

sleep(60);

delwin(win);
endwin();

return 0;
}
