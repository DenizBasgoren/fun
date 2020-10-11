
#include <stdio.h>
#include "deniz.h"



void setCursorPosition( int x, int y) {
	printf("\x1b[%d;%dH", y, x);
}





void saveCursorPosition() {
	printf("\x1b" "7");
}



void restoreCursorPosition() {
	printf("\x1b" "8");
}



void makeCursorInvisible() {
	printf("\x1b[?%dl", 25);
}



void makeCursorVisible() {
	printf("\x1b[?%dh", 25);
}



void setCursorColor( enum Color color ) {
	if (color == 0) {
		printf("\x1b[%dm", 39);
	}
	else if (color >= 1 && color <= 8) {
		printf("\x1b[%dm", color + 29);
	}
}




void setBackgroundColor( enum Color color ) {
	if (color == 0) {
		printf("\x1b[%dm", 49);
	}
	else if (color >= 1 && color <= 8) {
		printf("\x1b[%dm", color + 39);
	}
}



void setCursorStyle( enum Style style) {
	if (style == 0) {
		printf("\x1b[%dm", 22);
		printf("\x1b[%dm", 23);
		printf("\x1b[%dm", 24);
	}
	else if (style >= 1 && style <= 4) {
		printf("\x1b[%dm", style);
	}
}



void enterAlternateScreen() {
	saveCursorPosition();
	printf("\x1b[?%dh", 47);
}




void leaveAlternateScreen() {
	printf("\x1b[?%dl", 47);
	restoreCursorPosition();
}



void clearScreen() {
	printf("\x1b[%dJ", 2);
	printf("\x1b[%dJ", 3);
	setCursorPosition(1,1);
}
