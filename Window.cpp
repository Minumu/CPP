//#include "Ship.hpp"
//#include <unistd.h>
//
//// int readGetch(char sym, int y, int x) {
//// 	Ship ship = Ship(1, 5, "}");
//// 	if (sym == 'w') {
//// 		ship.shipMoved(y - 10, x);
//// 		y = (y - 10);
//// 	} else if (sym == 'q') {
//// 		endwin();
//// 		std::cout << "Game Over" << std::endl;
//// 	}
//// 	return 1;
//// }
//
//int main(void)
//{
//	int y = 10;
//	int x = 20;
//	int ch;
//	Ship ship = Ship(1, 5, "}");
//
//	srand(time(NULL));
//	initscr();
//	noecho();
//	// mvprintw(y, x, "}");
//	refresh();
//	ch = 0;
//	while(1)
//	{
//		 sleep(100);
//		mvprintw(y, x, " ");
//		y = std::rand() % 6;
//		ship.shipMoved(y, x, "*");
//	}
//	 while (ch != 'q') {
//	 	ch = getch();
//	 	mvprintw(y, x, " ");
//	 	if (ch == 'a') {
//	 		ship.shipMoved(y, x - 1);
//	 		x = (x - 1);
//	 	} else if (ch == 'd') {
//	 		ship.shipMoved(y, x + 1);
//	 		x = (x + 1);
//	 	} else if (ch == 'w') {
//	 		ship.shipMoved(y - 1, x);
//	 		y = (y - 1);
//	 	} else if (ch == 's') {
//	 		ship.shipMoved(y + 1, x);
//	 		y = (y + 1);
//	 	}
//	 }
//	endwin();
//	return 0;
//}