#include <ncurses.h>
#include <sstream>
#include <map>
#include <cstdlib>

#include "Controller.h"
#include "ControllerBuilder.h"

// From http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/windows.html
WINDOW *create_newwin(int height, int width, int starty, int startx){
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);	/* 0, 0 gives default characters 
							 * for the vertical and horizontal
							 * lines			*/
	wrefresh(local_win);	/* Show that box 		*/
	return local_win;
}

int main(int argc, char *argv[]){
	WINDOW *sensors;
	WINDOW *actuators;

	initscr();	// Start curses mode
	cbreak();	// Line buffering disabled, Pass on everything to me

	refresh();
	actuators = create_newwin(10, COLS/2, 1, 1);
	sensors = create_newwin(20, COLS/2, 1, COLS/2);

	Controller* controller = ControllerBuilder::GetController();

	std::map<std::string, int> actuatorValues;
	actuatorValues["fan1"] = 0;
	actuatorValues["fan2"] = 0;
	actuatorValues["heating1"] = 0;
	actuatorValues["heating2"] = 0;
	actuatorValues["cooling"] = 0;
	actuatorValues["vent1"] = 0;
	actuatorValues["vent2"] = 0;
	actuatorValues["vent3"] = 0;
	actuatorValues["vent4"] = 0;



	while(true){
		int ch = getch();
		char str[10] = {0};
		int val = -1;
		if(ch == 'q')
			break;

		if(ch >= '0' && ch <= '9'){
			int row, col;
			getmaxyx(stdscr, row, col);
			mvprintw(row, 0, "Enter a value: ");
			getstr(str);
			val = atoi(str);
		}

		int i=0;
		for(std::map<std::string, int>::iterator it=actuatorValues.begin();
		it != actuatorValues.end();
		it++, i++){
			if(ch == (i + '0')){
				controller->SetActuatorValue(it->first, val);
				it->second = val;
			}
			std::stringstream ss;
			ss << i << ": " << it->first << "\t @ " << it->second;
			wprintw(actuators, ss.str().c_str());
		}

		std::map<std::string, double> sensorValues = controller->GetSensorValue();
		for(std::map<std::string, double>::const_iterator i = sensorValues.begin();
		i != sensorValues.end();
		i++){
			std::stringstream ss;
			ss << i->first << ":\t" << i->second;
			wprintw(sensors, ss.str().c_str());
		}
		wrefresh(sensors);

	}

	endwin();			/* End curses mode		  */
	return 0;
}


