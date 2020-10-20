#ifndef FUN_H
#define FUN_H


/*
	HOW TO USE THIS LIBRARY

	Include this header at the top of the files, in which you use this library.
	DO NOT include the actual library (fun.c)
	NEVER change the filenames in any library.
	Also note that we use " " instead of < > because the header is not in the system include folder.

	Example:
		#include <stdio.h>
		#include "fun.h"

		int main() {
			setCursorColor(GREEN);
			puts("Yay, green text");
			return 0;
		}
*/




// These are the colors you can pick from.
// Note that yellow is more of an orange color in Replit. The actual colors depend on the terminal.
enum Color {DEFAULT_COLOR, BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, LIGHTBLUE, WHITE};


// These are the styles you can pick from.
// Note that the Replit terminal (which uses Xterm.js) doesn't support all applicable styles.
enum Style {DEFAULT_STYLE, BOLD, FAINT, ITALIC, UNDERLINED};





void setCursorPosition( int x, int y);
/*
	Set cursor position to x and y.
	Top-left corner is (1,1).
	From there x grows as you go rightwards.
	y grows as you go downwards. (known as inverted Y axis)

	Example:
		setCursorPosition(4,5); // set using literals
	
	Example:
		int row = 6;
		int column = 7;
		setCursorPosition(column, row); // set using variables
*/




void saveCursorPosition();
/*
	Before moving the cursor somewhere, save its position.
	This way you'll be able to restore the position to where it was.

	Example:
		saveCursorPosition();
		setCursorPosition(4,5); // move somewhere
		puts("Some text"); // write something
		restoreCursorPosition(); // continue where you left off
*/




void restoreCursorPosition();
/*
	Use this in conjunction with saveCursorPosition (see above)
*/




void makeCursorInvisible();
/*
	Make the cursor (the white rectangle) invisible.
	Use it in conjunction with makeCursorVisible.
*/




void makeCursorVisible();
/*
	See makeCursorInvisible function above.
*/




void setCursorColor( enum Color color );
/*
	After calling this function, everything that is printed will be	in the new color.
	Only certain colors are allowed, see above for the list.
	You can use DEFAULT_COLOR to reset color.

	Example:
		setCursorColor( GREEN ); // set using constants
	
	Example:
		enum Color x = GREEN;
		setCursorColor(x); // set using variables
*/




void setBackgroundColor( enum Color color );
/*
	After calling this function, everything that is printed will have the new background color.
	Only certain colors are allowed, see above for the list.
	You can use DEFAULT_COLOR to reset color.

	Example:
		setBackgroundColor( WHITE ); // set using constants
	
	Example:
		enum Color x = WHITE;
		setBackgroundColor(x); // set using variables
*/




void setCursorStyle( enum Style style);
/*
	After calling this function, everything that is printed will have the new text style.
	You can use DEFAULT_STYLE to reset the style.

	Example:
		setCursorStyle(BOLD); // using constants
		puts("Some text"); // prints in bold
	
	Example:
		enum Style x = ITALIC;
		setCursorStyle(x); // using variables
		puts("Some text"); // prints in bold
*/




void enterAlternateScreen();
/*
	After calling this function, you will be taken to a cleared screen.
	There you can do whatever you want.
	When you're done, call leaveAlternateScreen function (see below).
	When you leave, you will return to the state that you were in before.
	The point is that your program won't litter the screen if you use this.
	Note that cursor color and style resets upon entering.

	Example:
		enterAlternateScreen();
		puts("Some text");
		leaveAlternateScreen();
		// "Some text" will disappear.
*/




void leaveAlternateScreen();
/*
	Use this in conjunction with enterAlternateScreen (see above).
	Note that cursor color and style resets upon leaving.
*/




void clearScreen();
/*
	Clear the screen (all the text on the screen will be removed).
	Note that this function clears with the current background color, not the default one.
	You might want to set background color to DEFAULT_COLOR before using this.

	Example:
		// assume you have
		setBackgroundColor(BLUE);
		clearScreen(); // now the whole screen is in blue
	
	Example:
		// assume you have
		setBackgroundColor(BLUE);
		// before clearing, reset the color
		setBackgroundColor(DEFAULT_COLOR);
		clearScreen(); // now the whole screen is in default color
*/



/*
	IMPORTANT LINKS:

	Xterm.js documentation (the one used at Replit)
	https://xtermjs.org/docs/api/vtfeatures/

	Xterm documentation
	https://www.xfree86.org/current/ctlseqs.html

	This explains how coloring and styling works in general
	https://en.wikipedia.org/wiki/ANSI_escape_code#Escape_sequences
*/




#endif // FUN_H