#include "stdio.h"
#include "stdlib.h"
#include "ncurses.h"
#include "string.h"

#include "../config.h"


int main(int argc, char *argv[]) {

  initscr();
  noecho();
  keypad(stdscr, TRUE);
  if(has_colors() == FALSE) {
    endwin();
    printf("Colors are not supported by your terminal.\n");
exit(1);
  }

start_color();
init_pair(1, COLOR_WHITE, COLOR_BLUE);
attron(COLOR_PAIR(1));

int row, col;
getmaxyx(stdscr, row, col);
mvprintw(row / 2, (col - strlen(PACKAGE_STRING)) / 2, "%s", PACKAGE_STRING);
  refresh();
  getch();
  endwin();

  return 0;
}
