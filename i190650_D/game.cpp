//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<sstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 string s5,s6,s8;
 void help()//function for help.
 {
 glClearColor(.5/*Red Component*/, .5,	//148.0/255/*Green Component*/,
			.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawString( 200, 300, "press 'p' for pause the game.    ", colors[MISTY_ROSE]);//manues
 DrawString( 200, 400, "press 'excape' for exit the game.  ", colors[MISTY_ROSE]);
 DrawString( 200, 500, "press 'space' for speed douple the game.  ", colors[MISTY_ROSE]);
 DrawString( 200, 600, "press 'right click' for select  the maue ption.  ", colors[MISTY_ROSE]);
 DrawString( 200, 700, "All these options are used in game  ", colors[MISTY_ROSE]);
  DrawString( 200, 200, "arrow keys for controls:left for left movement and right for right.", colors[MISTY_ROSE]);
   DrawString( 200, 150, "down for down and up for up movement ", colors[MISTY_ROSE]);
 DrawString( 200, 100, "Back  ", colors[MISTY_ROSE]);
 glutSwapBuffers();
 }
 
 void high()//function for high score.
 {
 glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

 DrawString( 200, 700, "HIGH SCORE;  ", colors[BLUE]);
 DrawString( 200, 100, "Back to menu  ", colors[BLUE]);
 DrawString( 420, 700, s5, colors[BLUE]);
 glutSwapBuffers();
 }
 void winning()//function for winning messsage.
 {
 glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

 DrawString( 200, 700, "YOU WON CONRATULATIONS!  ", colors[BLUE]);
  DrawString( 400, 500, "reward points are  ", colors[BLUE]);
   DrawString( 600, 500,s8, colors[BLUE]);
 DrawString( 200, 100, "Back to menu  ", colors[BLUE]);
 
 glutSwapBuffers();
 }
 
 void gameover()//function for high score.
 {
 glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

 DrawString( 200, 700, "GAME OVER  ", colors[MISTY_ROSE]);
 DrawString( 200, 100, "Back to menu  ", colors[MISTY_ROSE]);
  DrawString( 200, 500, "YOUR SCORE OF LAST LAIF  ", colors[MISTY_ROSE]);
 DrawString( 660, 500, s6, colors[MISTY_ROSE]);
 glutSwapBuffers();
 }
 void Timer3(int);
 void Timer1(int);
 void Timer(int);
 static float e=350,f=20,g=20,d=450,g1=620,d1=380;//e=x-axis of player /-f=y-axis of player/-d=x-axis of opponant /- g=y-axis of opponant
 static int arry[100];static int s=1;static int reward_p=0,l=380,z=1,x=1,o=3,k=0,paus=0,lavel=1,sap=0,h=0,s7;static char key;
 string score,s2,s4;
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
string displying(int j)      						//function for displaying score,lavel and life of screen
	{ostringstream convert;
	convert<<j;
	string score=convert.str();
	return score;}
/*
 * Main Canvas drawing function.
 * */
//Board *b;
void manu(){
glClearColor(1/*Red Component*/, 0.627450980392157,	//148.0/255/*Green Component*/,
			0.478431372549020/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors						//function of manues
DrawString( 200, 800, "START  ", colors[RED]);
DrawString( 200, 700, "NEW GAME ", colors[RED]);
DrawString( 200, 600, "SEE HIGH SCORE  ", colors[RED]);
DrawString( 200, 500, "HELP  ", colors[RED]);
DrawString( 200, 400, "EXIT  ", colors[RED]);
//glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	//		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glClear (GL_COLOR_BUFFER_BIT); //Update the colors
glutSwapBuffers();
}
/*void file(char fname[],int store[],int &b)
{
ifstream st (fname);
st>>store[0];*/


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1, 0.854901960784314, 0.725490196078431,0); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students
if(s)
	{
	for(int i=0;i<100;i++)				//loop to filled array that draw coins.
	{arry[i]=1;
	}s=0;}
	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	DrawString( 50, 800, "Score=", colors[GREEN]);
	
	/*int displing(l)
	ostringstream convert;
	convert<<l;
	score=convert.str();*/
	score=displying(l);					//calling the displying function that display score.
	DrawString( 120, 800, score, colors[BLUE]);
	
	
	
	
	s2=displying(o);					// for displaying life
	s4=displying(lavel);
	s8=displying(reward_p);					//for displaying  lavels
						
	DrawString( 600, 800, "Life  ", colors[GREEN]);	
	DrawString( 660, 800,s2, colors[BLUE]);
	DrawString( 400, 800, "LEVEL  ", colors[GREEN]);
	DrawString( 520, 800,s4, colors[BLUE]);
	DrawString( 200, 800, "reward points  ", colors[GREEN]);
	DrawString( 350, 800,s8, colors[BLUE]);
	// Drawing opponent car
	/*float x = 100; 
	float y = 100; 
	float width = 20; 
	float height = 15;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

	// Drawing Arena
	int gap_turn = 30;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
*/float width = 10; 		// 1st opponant car
	float height = 10;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 5.0;
	DrawRoundRect(d,g,width,height,color,radius); // bottom left tyre
	DrawRoundRect(d+width*3,g,width,height,color,radius); // bottom right tyre
	DrawRoundRect(d+width*3,g+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(d,g+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(d, g+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(d+width, g+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(d+width*3, g+height*2, width, height, color, radius/2); // body right rect
	
	//Draw a car2
	
	//e = 600; 
	//f = 100; 
	 width = 10; 									//player car.
	 height = 10;
	float* colour = colors[RED]; 
	 radius = 5.0;
	DrawRoundRect(e,f,width,height,colour,radius); // bottom left tyre
	DrawRoundRect(e+width*3,f,width,height,colour,radius); // bottom right tyre
	DrawRoundRect(e+width*3,f+height*4,width,height,colour,radius); // top right tyre
	DrawRoundRect(e,f+height*4,width,height,colour,radius); // top left tyre
	DrawRoundRect(e, f+height*2, width, height, colour, radius/2); // body left rect
	DrawRoundRect(e+width, f+height, width*2, height*3, colour, radius/2); // body center rect
	DrawRoundRect(e+width*3, f+height*2, width, height, colour, radius/2); // body right rect

if(lavel==4)
{width = 10; 									//second apponsnt  car.
	 height = 10;
	 colour = colors[BLUE_VIOLET]; 
	 radius = 5.0;
	DrawRoundRect(d1,g1,width,height,colour,radius); // bottom left tyre
	DrawRoundRect(d1+width*3,g1,width,height,colour,radius); // bottom right tyre
	DrawRoundRect(d1+width*3,g1+height*4,width,height,colour,radius); // top right tyre
	DrawRoundRect(d1,g1+height*4,width,height,colour,radius); // top left tyre
	DrawRoundRect(d1, g1+height*2, width, height, colour, radius/2); // body left rect
	DrawRoundRect(d1+width, g1+height, width*2, height*3, colour, radius/2); // body center rect
	DrawRoundRect(d1+width*3, g1+height*2, width, height, colour, radius/2); // body right rect
}
	// Drawing Arena
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx-20, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight, swidth-50, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn-20, sheight, swidth-50, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+740, swidth, sheight, scolor); // top left
	DrawRectangle(sx-20, sy+740, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn-20, sheight, swidth-50, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight, swidth-50, scolor); // left down

//drawing arena
DrawRectangle(sx+50, sy+70, swidth-70, sheight, scolor); // bottom left
DrawRectangle(sx+120, sy+140, swidth-140, sheight, scolor); // bottom left
DrawRectangle(sx+190, sy+210, swidth-210, sheight, scolor); // bottom left
DrawRectangle(sx+260, sy+280, swidth-180, sheight, scolor); // bottom left
DrawRectangle(sx + swidth + gap_turn, sy+70, swidth-60, sheight, scolor); // bottom right
DrawRectangle(sx + swidth + gap_turn, sy+140, swidth-130, sheight, scolor); // bottom right
DrawRectangle(sx + swidth + gap_turn, sy+210, swidth-200, sheight, scolor); // bottom right
DrawRectangle(sx + swidth + gap_turn, sy+280, swidth-270, sheight, scolor); // bottom right
DrawRectangle(sx+swidth*2-70+gap_turn, sy+sheight+70, sheight, swidth-120, scolor); // right down
DrawRectangle(sx+swidth*2-140+gap_turn, sy+sheight+140, sheight, swidth-190, scolor); // right down
DrawRectangle(sx+swidth*2-210+gap_turn, sy+sheight+210, sheight, swidth-260, scolor); // right down
DrawRectangle(sx+swidth*2-280+gap_turn, sy+sheight+280, sheight, swidth-230, scolor); // right down
DrawRectangle(sx + swidth + gap_turn, sy+670, swidth-70, sheight, scolor); // top left
DrawRectangle(sx + swidth + gap_turn, sy+600, swidth-140, sheight, scolor); // top left
DrawRectangle(sx + swidth + gap_turn, sy+530, swidth-210, sheight, scolor); // top left
DrawRectangle(sx + swidth + gap_turn, sy+460, swidth-280, sheight, scolor); // top left
DrawRectangle(sx-sheight*2+70, sy+sheight+70, sheight, swidth-120, scolor); // left down
DrawRectangle(sx-sheight*2+140, sy+sheight+140, sheight, swidth-190, scolor); // left down
DrawRectangle(sx-sheight*2+210, sy+sheight+210, sheight, swidth-260, scolor); // left down
DrawRectangle(sx-sheight*2+280, sy+sheight+280, sheight, swidth-230, scolor); // left down
DrawRectangle(sx+swidth+300+gap_turn, sy+sheight+swidth+gap_turn-20, sheight, swidth-110, scolor); // right up
DrawRectangle(sx+swidth+230+gap_turn, sy+sheight+swidth+gap_turn-20, sheight, swidth-180, scolor); // right up
DrawRectangle(sx+swidth+160+gap_turn, sy+sheight+swidth+gap_turn-20, sheight, swidth-250, scolor); // right up
DrawRectangle(sx+swidth+90+gap_turn, sy+sheight+swidth+gap_turn-20, sheight, swidth-320, scolor); // right up
DrawRectangle(sx-sheight+60, sy+sheight+swidth+gap_turn-20, sheight, swidth-110, scolor); // left up
DrawRectangle(sx-sheight+130, sy+sheight+swidth+gap_turn-20, sheight, swidth-180, scolor); // left up
DrawRectangle(sx-sheight+200, sy+sheight+swidth+gap_turn-20, sheight, swidth-250, scolor); // left up
DrawRectangle(sx-sheight+270, sy+sheight+swidth+gap_turn-20, sheight, swidth-320, scolor); // left up
DrawRectangle(sx+60, sy+670, swidth-80, sheight, scolor); // top right
DrawRectangle(sx+130, sy+600, swidth-150, sheight, scolor); // top right
DrawRectangle(sx+200, sy+530, swidth-220, sheight, scolor); // top right
DrawRectangle(sx+270, sy+460, swidth-190, sheight, scolor); // top right

//drawing cins.colum 1
if(arry[0]){DrawSquare( 40 , 50 ,10,colors[RED]);
}if(arry[1]){DrawSquare( 40 , 120 ,10,colors[RED]);
 }if(arry[2]){DrawSquare( 40 , 190 ,10,colors[RED]);
}if(arry[3]){DrawSquare( 40 , 260 ,10,colors[RED]);
}if(arry[4]){DrawSquare( 40 , 330 ,10,colors[RED]);
}if(arry[5]){DrawSquare( 40 , 430 ,10,colors[RED]);
}if(arry[6]){DrawSquare( 40 , 500 ,10,colors[RED]);
}if(arry[7]){DrawSquare( 40 , 580 ,10,colors[RED]);
 }if(arry[8]){DrawSquare( 40 , 640 ,10,colors[RED]);
 }if(arry[9]){DrawSquare( 40 , 720 ,10,colors[RED]);
//drawing cins.colum 2
 }if(arry[10]){DrawSquare( 100 , 50 ,10,colors[RED]);
 }if(arry[11]){DrawSquare( 100 , 120 ,10,colors[RED]);
 }if(arry[12]){DrawSquare( 100 , 190 ,10,colors[RED]);
 }if(arry[13]){DrawSquare( 100 , 260 ,10,colors[RED]);
 }if(arry[14]){DrawSquare( 100 , 330 ,10,colors[RED]);
 }if(arry[15]){DrawSquare( 100 , 430 ,10,colors[RED]);
 }if(arry[16]){DrawSquare( 100 , 500 ,10,colors[RED]);
 }if(arry[17]){DrawSquare( 100 , 580 ,10,colors[RED]);
 }if(arry[18]){DrawSquare( 100 , 640 ,10,colors[RED]);
 }if(arry[19]){DrawSquare( 100 , 720 ,10,colors[RED]);
//drawing cins.colum 3
 }if(arry[20]){DrawSquare( 180 , 50 ,10,colors[RED]);
 }if(arry[21]){DrawSquare( 180 , 120 ,10,colors[RED]);
 }if(arry[22]){DrawSquare( 180 , 190 ,10,colors[RED]);
 }if(arry[23]){DrawSquare( 180 , 260 ,10,colors[RED]);
 }if(arry[24]){DrawSquare( 180 , 330 ,10,colors[RED]);
 }if(arry[25]){DrawSquare( 180 , 430 ,10,colors[RED]);
 }if(arry[26]){DrawSquare( 180 , 500 ,10,colors[RED]);
 }if(arry[27]){DrawSquare( 180 , 580 ,10,colors[RED]);
 }if(arry[28]){DrawSquare( 180 , 640 ,10,colors[RED]);
 }if(arry[29]){DrawSquare( 180 , 720 ,10,colors[RED]);
//drawing cins.colum 4
 }if(arry[30]){DrawSquare( 250 , 50 ,10,colors[RED]);
 }if(arry[31]){DrawSquare( 250 , 120 ,10,colors[RED]);
 }if(arry[32]){DrawSquare( 250 , 190 ,10,colors[RED]);
 }if(arry[33]){DrawSquare( 250 , 260 ,10,colors[RED]);
 }if(arry[34]){DrawSquare( 250 , 330 ,10,colors[RED]);
 }if(arry[35]){DrawSquare( 250 , 430 ,10,colors[RED]);
 }if(arry[36]){DrawSquare( 250 , 500 ,10,colors[RED]);
 }if(arry[37]){DrawSquare( 250 , 580 ,10,colors[RED]);
 }if(arry[38]){DrawSquare( 250 , 640 ,10,colors[RED]);
 }if(arry[39]){DrawSquare( 250 , 720 ,10,colors[RED]);
//drawing cins.colum 5
 }if(arry[40]){DrawSquare( 360 , 50 ,10,colors[RED]);
 }if(arry[41]){DrawSquare( 360 , 120 ,10,colors[RED]);
 }if(arry[42]){DrawSquare( 360 , 190 ,10,colors[RED]);
 }if(arry[43]){DrawSquare( 360 , 260 ,10,colors[RED]);

 }if(arry[44]){DrawSquare( 360 , 500 ,10,colors[RED]);
 }if(arry[45]){DrawSquare( 360 , 580 ,10,colors[RED]);
 }if(arry[46]){DrawSquare( 360 , 640 ,10,colors[RED]);
 }if(arry[47]){DrawSquare( 360 , 720 ,10,colors[RED]);
//drawing cins.colum 6
 }if(arry[48]){DrawSquare( 450 , 50 ,10,colors[RED]);
 }if(arry[49
 ]){DrawSquare( 450, 120 ,10,colors[RED]);
 }if(arry[50]){DrawSquare( 450 , 190 ,10,colors[RED]);
 }if(arry[51]){DrawSquare( 450 , 260 ,10,colors[RED]);

 }if(arry[52]){DrawSquare( 450 , 500 ,10,colors[RED]);
 }if(arry[53]){DrawSquare( 450 , 580 ,10,colors[RED]);
 }if(arry[54]){DrawSquare( 450 , 640 ,10,colors[RED]);
 }if(arry[55]){DrawSquare( 450 , 720 ,10,colors[RED]);
//drawing cins.colum 7
 }if(arry[56]){DrawSquare( 570 , 50 ,10,colors[RED]);
 }if(arry[57]){DrawSquare( 570, 120 ,10,colors[RED]);
 }if(arry[58]){DrawSquare( 570 , 190 ,10,colors[RED]);
 }if(arry[59]){DrawSquare( 570 , 260 ,10,colors[RED]);
 }if(arry[60]){DrawSquare( 570 , 330 ,10,colors[RED]);
 }if(arry[61]){DrawSquare( 570 , 430 ,10,colors[RED]);
 }if(arry[62]){DrawSquare( 570 , 500 ,10,colors[RED]);
 }if(arry[63]){DrawSquare( 570 , 580 ,10,colors[RED]);
 }if(arry[64]){DrawSquare( 570 , 640 ,10,colors[RED]);
 }if(arry[65]){DrawSquare( 570 , 720 ,10,colors[RED]);
//drawing cins.colum 8
 }if(arry[66]){DrawSquare( 650 , 50 ,10,colors[RED]);
 }if(arry[67]){DrawSquare( 650, 120 ,10,colors[RED]);
 }if(arry[68]){DrawSquare( 650 , 190 ,10,colors[RED]);
 }if(arry[69]){DrawSquare( 650 , 260 ,10,colors[RED]);
 }if(arry[70]){DrawSquare( 650 , 330 ,10,colors[RED]);
 }if(arry[71]){DrawSquare( 650 , 430 ,10,colors[RED]);
 }if(arry[72]){DrawSquare( 650 , 500 ,10,colors[RED]);
 }if(arry[73]){DrawSquare( 650 , 580 ,10,colors[RED]);
 }if(arry[74]){DrawSquare( 650 , 640 ,10,colors[RED]);
 }if(arry[75]){DrawSquare( 650 , 720 ,10,colors[RED]);
//drawing cins.colum 9
 }if(arry[76]){DrawSquare( 720 , 50 ,10,colors[RED]);
 }if(arry[77]){DrawSquare( 720, 120 ,10,colors[RED]);
 }if(arry[78]){DrawSquare( 720 , 190 ,10,colors[RED]);
 }if(arry[79]){DrawSquare( 720 , 260 ,10,colors[RED]);
 }if(arry[80]){DrawSquare( 720 , 330 ,10,colors[RED]);
 }if(arry[81]){DrawSquare( 720 , 430 ,10,colors[RED]);
 }if(arry[82]){DrawSquare( 720 , 500 ,10,colors[RED]);
 }if(arry[83]){DrawSquare( 720 , 580 ,10,colors[RED]);
 }if(arry[84]){DrawSquare( 720 , 640 ,10,colors[RED]);
 }if(arry[85]){DrawSquare( 720 , 720 ,10,colors[RED]);
//drawing cins.colum 10
 }if(arry[86]){DrawSquare( 780 , 50 ,10,colors[RED]);
 }if(arry[87]){DrawSquare( 780, 120 ,10,colors[RED]);
 }if(arry[88]){DrawSquare( 780 , 190 ,10,colors[RED]);
 }if(arry[89]){DrawSquare( 780 , 260 ,10,colors[RED]);
 }if(arry[90]){DrawSquare( 780 , 330 ,10,colors[RED]);
 }if(arry[91]){DrawSquare( 780 , 430 ,10,colors[RED]);
 }if(arry[92]){DrawSquare( 780 , 500 ,10,colors[RED]);
 }if(arry[93]){DrawSquare( 780 , 580 ,10,colors[RED]);
 }if(arry[94]){DrawSquare( 780 , 640 ,10,colors[RED]);
 }if(arry[95]){DrawSquare( 780 , 720 ,10,colors[RED]);
}
if(l==96)					//condition for changing lavels
{lavel=2;
glutDisplayFunc(GameDisplay);
e=350,f=20,g=90,d=450,g1=620,d1=380;
s=1;
reward_p=100;
}
if(l==193)
{lavel=3;
glutDisplayFunc(GameDisplay);
e=350,f=20,g=690,d=450,g1=620,d1=380;
s=1;
reward_p=200;
}
if(l==288)
{lavel=4;
glutDisplayFunc(GameDisplay);
e=350,f=20,g=20,d=450,g1=620,d1=380;
s=1;
reward_p=300;}
if(l==384)
 {
 reward_p=400;
 s8=displying(reward_p);
		glutDisplayFunc(winning);
		e=350,f=20,g=20,d=450,g1=620,d1=380;
		s=1;l=0;lavel=1,o=3;
		}
s7=l;
if(((e-5)==d||(e+5)==d||(e==d))&&((f-5)==g||(f+5)==g||(f==g)))				//condition for colllision between cars.
{ s=1;
 o--;
 if(l>h)
 {h=l;}
 l=0;
 if(o==0)
 {
 
 
 
 
 o=3;
 l=1;
  glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (WHITE); //Update the colors
	s6=displying(s7);
 glutDisplayFunc(gameover);}
for(int k=0;k<1000;k++)				//loop for sound and setting initial values of the axises of cars.
cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
e=350,f=20,g=20,d=450,d1=380,g1=620;
}

if(lavel==4)
{if(((e-5)==d1||(e+5)==d1||(e==d1))&&((f-5)==g1||(f+5)==g1||(f==g1)))				//condition for colllision between cars.
{ s=1;
 o--;
 if(l>h)
 {h=l;}
 l=0;
 if(o==0)
{
 
 
 
 
 o=3;
 l=1;
  glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (WHITE);
	
	s6=displying(s7);
	 //Update the colors
 glutDisplayFunc(gameover);}
 
for(int k=0;k<1000;k++)				//loop for sound and setting initial values of the axises of cars.
cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
e=350,f=20,g=20,d=380,d1=380,g1=620;
}}
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
cout<<"                   e"<<e<<"   f"<<f<<"    d"<<d<<"    g"<<g<<"        d1"<<d1<<"    g1"<<g1<<endl;
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
			if(lavel==1)
			{
			if((d>370&&d<450)&&g<740&&g>450)		//condition for up movement.		
g=g-70;

	//if((d>370&&d<460)&&g<740)			
//g=g-70;
if((d>370&&d<460)&&g>0&&g<250)
g=g+70;
}
if(lavel>1)			//condition for left movement.
{if((g>350&&g<450)&&d>0&&d<260)
d=d+70;
if(d==300&&g>230&&g<480)
d=d-70;
if(d==370&&g>230&&g<480)		//condition for down movement.	
d=d-70;
if((g>350&&g<400)&&d<=770&&d>540)
d=d-70;
if((d>370&&d<450)&&g<=740&&g>450)		//condition for up movement.		
g=g-70;
if((d>370&&d<460)&&g>0&&g<250)		//condition for down movement.	
g=g+70;}
if(lavel==4)
{if((d1>350&&d1<400)&&d1<=770&&d1>540)
d1=d1-70;
if((d1>370&&d1<450)&&g1<=740&&g1>450)		//condition for up movement.		
g1=g1-70;
if((d1>370&&d<460)&&g1>0&&g1<250)		//condition for down movement.	
g1=g1+70;
if((g1>350&&g1<450)&&d1>0&&d1<260)
d1=d1+70;
}

if(f>350&&f<450)
{
e=e-70;
}
if(d1==-50)				// these conditions for opponant two for ristection to go outside the arena
d1=d1+70;

if(d1==-120)
d1=d1+140;
if(d1==910)
d1=d1-140;

if(d1==840)
d1=d1-70;
if(g1==760)
g1=g1-70;
if(g1==-50)
g1=g1+70;
if(g1==830)
g1=g1-140;
if(g1==-120)
g1=g1+140;

if(d==-50)			// these conditions for opponant one for ristection to go outside the arena
d=d+70;

if(d==-120)
d=d+140;
if(d1==910)
d=d-140;

if(d==840)
d=d-70;
if(g==760)
g=g-70;
if(g==-50)
g=g+70;
if(g==830)
g=g-140;
if(g==-120)
g=g+140;


if(e==-50)			// these conditions for player for ristection to go outside the arena
e=e+70;

if(e==-120)
e=e+140;
if(e==910)
e=e-140;

if(e==840)
e=e-70;
if(f==760)
f=f-70;
if(f==-50)
f=f+70;
if(f==830)
f=f-140;
if(f==-120)
f=f+140;

//these conditions are used to restict the cars to go in the most inner part of arena

if(d==490&&g>230&&g<480)
d=d+70;
if(d==420&&g>230&&g<480)			
d=d+140;
if(e==490&&f>230&&f<480)
e=e+70;
if(e==420&&f>230&&f<480)	
e=e+140;
if(d1==490&&g1>230&&g1<480)
d1=d1+70;
if(d1==420&&g1>230&&g1<480)		
d1=d1+140;
		
if(d==300&&g>230&&g<480)
d=d-70;
if(d==370&&g>230&&g<480)		
d=d-140;
if(e==300&&f>230&&f<480)
e=e-70;
if(e==370&&f>230&&f<480)			
e=e-140;
if(d1==300&&g1>230&&g1<480)
d1=d1-70;
if(d1==370&&g1>230&&g1<480)			
d1=d1-140;

if(f==300&&e>230&&e<560)
f=f-70;
if(f==370&&e>230&&e<560)			
f=f-140;
if(g==300&&d>230&&d<560)
g=g-70;
if(g==370&&d>230&&d<560)		
g=g-140;
if(g1==300&&d1>230&&d1<560)
g1=g1-70;
if(g1==370&&d1>230&&d1<560)			
g1=g1-140;

if(f==410&&e>230&&e<560)
f=f+70;
if(f==340&&e>230&&e<560)		
f=f+140;
if(g==410&&d>230&&d<560)
g=g+70;
if(g==340&&d>230&&d<460)			
g=g+140;
if(g1==410&&d1>230&&d1<560)
g1=g1+70;
if(g1==340&&d1>230&&d1<560)		
g1=g1+140;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
if(lavel==1)
{
if((d>370&&d<450)&&g<=740&&g>450&&g!=410&&g!=340)		//condition for up movement.		
g=g-70;
if((d>370&&d<460)&&g>0&&g<250&&g!=300&&g!=370)		//condition for down movement.	
g=g+70;}
if(lavel>1)				//condition for right movement.
{if((g>350&&g<450)&&d<=770&&d>540&&d!=490&&d!=420)
d=d-70;
if((d>370&&d<450)&&g<=740&&g>450&&g!=410&&g!=340)		//condition for up movement.		
g=g-70;
if((d>370&&d<460)&&g>0&&g<250&&g!=300&&g!=370)		//condition for down movement.	
g=g+70;
if((g>350&&g<450)&&d>0&&d<260&&d!=300&&d!=370)
d=d+70;}
if(lavel==4)
{if((d1>350&&d1<450)&&d1>0&&d1<260&&d1!=300&&d1!=370)
d1=d1+70;
if((d1>370&&d1<450)&&g1<=740&&g1>450&&g1!=410&&g1!=340)		//condition for up movement.		
g1=g1-70;
if((d1>370&&d<460)&&g1>0&&g1<250&&g1!=300&&g1!=370)		//condition for down movement.	
g1=g1+70;
if((g1>350&&g1<450)&&d1<=770&&d>540&&d!=490&&d!=420)
d1=d1-70;}

if(f>350&&f<400)
e=e+70;


if(d1==-50)				// these conditions for opponant two for ristection to go outside the arena
d1=d1+70;

if(d1==-120)
d1=d1+140;
if(d1==910)
d1=d1-140;

if(d1==840)
d1=d1-70;
if(g1==760)
g1=g1-70;
if(g1==-50)
g1=g1+70;
if(g1==830)
g1=g1-140;
if(g1==-120)
g1=g1+140;

if(d==-50)			// these conditions for opponant one for ristection to go outside the arena
d=d+70;

if(d==-120)
d=d+140;
if(d1==910)
d=d-140;

if(d==840)
d=d-70;
if(g==760)
g=g-70;
if(g==-50)
g=g+70;
if(g==830)
g=g-140;
if(g==-120)
g=g+140;


if(e==-50)			// these conditions for player for ristection to go outside the arena
e=e+70;

if(e==-120)
e=e+140;
if(e==910)
e=e-140;

if(e==840)
e=e-70;
if(f==760)
f=f-70;
if(f==-50)
f=f+70;
if(f==830)
f=f-140;
if(f==-120)
f=f+140;	


//these conditions are used to restict the cars to go in the most inner part of arena

if(d==490&&g>230&&g<480)
d=d+70;
else if(d==420&&g>230&&g<480)			
d=d+140;
else if(e==490&&f>230&&f<480)
e=e+70;
else if(e==420&&f>230&&f<480)	
e=e+140;
else if(d1==490&&g1>230&&g1<480)
d1=d1+70;
else if(d1==420&&g1>230&&g1<480)		
d1=d1+140;
		
else if(d==300&&g>230&&g<480)
d=d-70;
else if(d==370&&f>230&&f<480)		
d=d-140;
else if(e==300&&f>230&&f<480)
e=e-70;
else if(e==370&&f>230&&f<480)			
e=e-140;
else if(d1==300&&g1>230&&g1<480)
d1=d1-70;
else if(d1==370&&g1>230&&g1<480)			
d1=d1-140;

else if(f==300&&e>230&&e<560)
f=f-70;
else if(f==370&&e>230&&e<560)			
f=f-140;
else if(g==300&&d>230&&d<560)
g=g-70;
else if(g==370&&d>230&&d<560)		
g=g-140;
else if(g1==300&&d1>230&&d1<560)
g1=g1-70;
else if(g1==370&&d1>230&&d1<560)			
g1=g1-140;

else if(f==410&&e>230&&e<560)
f=f+70;
else if(f==340&&e>230&&e<560)		
f=f+140;
else if(g==410&&d>230&&d<560)
g=g+70;
else if(g==340&&d1>230&&d<460)			
g=g+140;
else if(g1==410&&d1>230&&d1<560)
g1=g1+70;
else if(g1==340&&d1>230&&d1<560)		
g1=g1-140;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
if(lavel==1)
{

if((d>370&&d<460)&&g>0&&g<250&&g!=300&&g!=370)		//condition for down movement.	
g=g+70;
if((d>370&&d<450)&&g<=740&&g>450&&g!=410&&g!=340)		//condition for up movement.		
g=g-70;}
if(lavel>1)				//condition for right movement.
{if((g>350&&g<400)&&d<=770&&d>540&&d!=490&&d!=420)
d=d-70;
if((d>370&&d<450)&&g<=740&&g>450&&g!=410&&g!=340)		//condition for up movement.		
g=g-70;
if((d>370&&d<460)&&g>0&&g<250&&g!=300&&g!=370)		//condition for down movement.	
g=g+70;
if((g>350&&g<450)&&d>0&&d<260&&d!=300&&d!=370)
d=d+70;}
if(lavel==4)
{if((g1>350&&g1<400)&&d1>0&&d<260&&d1!=300&&d1!=370)
d1=d1+70;
if((d1>370&&d1<450)&&g1<=740&&g1>450&&g1!=410&&g1!=340)		//condition for up movement.		
g1=g1-70;
if((d1>370&&d<460)&&g1>0&&g1<250&&g1!=300&&g1!=370)		//condition for down movement.	
g1=g1+70;
if((g1>350&&g1<450)&&d1<=770&&d1>540&&d1!=490&&d1!=420)
d1=d1-70;}

if(e>370&&e<460)
f=f+70;
	
if(d1==-50)				// these conditions for opponant two for ristection to go outside the arena
d1=d1+70;

if(d1==-120)
d1=d1+140;
if(d1==910)
d1=d1-140;

if(d1==840)
d1=d1-70;
if(g1==760)
g1=g1-70;
if(g1==-50)
g1=g1+70;
if(g1==830)
g1=g1-140;
if(g1==-120)
g1=g1+140;

if(d==-50)			// these conditions for opponant one for ristection to go outside the arena
d=d+70;

if(d==-120)
d=d+140;
if(d1==910)
d=d-140;

if(d==840)
d=d-70;
if(g==760)
g=g-70;
if(g==-50)
g=g+70;
if(g==830)
g=g-140;
if(g==-120)
g=g+140;


if(e==-50)			// these conditions for player for ristection to go outside the arena
e=e+70;

if(e==-120)
e=e+140;
if(e==910)
e=e-140;

if(e==840)
e=e-70;
if(f==760)
f=f-70;
if(f==-50)
f=f+70;
if(f==830)
f=f-140;
if(f==-120)
f=f+140;	
	
//these conditions are used to restict the cars to go in the most inner part of arena

if(d==490&&g>230&&g<480)
d=d+70;
if(d==420&&g>230&&g<480)			
d=d+140;
if(e==490&&f>230&&f<480)
e=e+70;
if(e==420&&f>230&&f<480)	
e=e+140;
if(d1==490&&g1>230&&g1<480)
d1=d1+70;
if(d1==420&&g1>230&&g1<480)		
d1=d1+140;
		
if(d==300&&g>230&&g<480)
d=d-70;
if(d==370&&g>230&&g<480)		
d=d-140;
if(e==300&&f>230&&f<480)
e=e-70;
if(e==370&&f>230&&f<480)			
e=e-140;
if(d1==300&&g1>230&&g1<480)
d1=d1-70;
if(d1==370&&g1>230&&g1<480)			
d1=d1-140;

if(f==300&&e>230&&e<560)
f=f-70;
if(f==370&&e>230&&e<560)			
f=f-140;
if(g==300&&d>230&&d<560)
g=g-70;
if(g==300&&d>230&&d<560)		
g=g-140;
if(g1==300&&d1>230&&d1<560)
g1=g1-70;
if(g1==370&&d1>230&&d1<560)			
g1=g1-140;

if(f==410&&e>230&&e<560)
f=f+70;
if(f==340&&e>230&&e<560)		
f=f+140;
if(g==410&&d>230&&d<560)
g=g+70;
if(g==340&&d>230&&d<560)			
g=g+140;
if(g1==410&&d1>230&&d1<560)
g1=g1+70;
if(g1==340&&d1>230&&d1<560)		
g1=g1+140;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

if(lavel==1)
{
if((d>370&&d<460)&&g>0&&g<250)		//condition for down movement.	
g=g+70;
if((d>370&&d<450)&&g<=740&&g>450&&g!=410&&g!=340)		//condition for up movement.		
g=g-70;
}
if(lavel>1)				//condition for right movement.
{if((g>350&&g<400)&&d<=770&&d>540&&d!=420)
d=d-70;
if((d>370&&d<450)&&g<=740&&g>450&&g!=340)		//condition for up movement.		
g=g-70;
if((d>370&&d<460)&&g>0&&g<250&&g!=300)		//condition for down movement.	
g=g+70;
if((g>350&&g<450)&&d>0&&d<260&&d!=300)
d=d+70;}
if(lavel==4)
{if((g1>350&&g1<400)&&d1>0&&d1<260&&d1!=300)
d1=d1+70;
if((d1>370&&d1<450)&&g1<=740&&g1>450&&g1!=340)		//condition for up movement.		
g1=g1-70;
if((d1>370&&d<460)&&g1>0&&g1<250&&g1!=300)		//condition for down movement.	
g1=g1+70;
if((g1>350&&g1<450)&&d1<=770&&d1>540&&d1!=420)
d1=d1-70;}

if(e>370&&e<460)			
f=f-70;
	
if(d1==-50)				// these conditions for opponant two for ristection to go outside the arena
d1=d1+70;

if(d1==-120)
d1=d1+140;
if(d1==910)
d1=d1-140;

if(d1==840)
d1=d1-70;
if(g1==760)
g1=g1-70;
if(g1==-50)
g1=g1+70;
if(g1==830)
g1=g1-140;
if(g1==-120)
g1=g1+140;

if(d==-50)			// these conditions for opponant one for ristection to go outside the arena
d=d+70;

if(d==-120)
d=d+140;
if(d1==910)
d=d-140;

if(d==840)
d=d-70;
if(g==760)
g=g-70;
if(g==-50)
g=g+70;
if(g==830)
g=g-140;
if(g==-120)
g=g+140;


if(e==-50)			// these conditions for player for ristection to go outside the arena
e=e+70;

if(e==-120)
e=e+140;
if(e==910)
e=e-140;

if(e==840)
e=e-70;
if(f==760)
f=f-70;
if(f==-50)
f=f+70;
if(f==830)
f=f-140;
if(f==-120)
f=f+140;	
	
	
//these conditions are used to restict the cars to go in the most inner part of arena

if(d==490&&g>230&&g<480)
d=d+70;
if(d==420&&g>230&&g<480)			
d=d+140;
if(e==490&&f>230&&f<480)
e=e+70;
if(e==420&&f>230&&f<480)	
e=e+140;
if(d1==490&&g1>230&&g1<480)
d1=d1+70;
if(d1==420&&g1>230&&g1<480)		
d1=d1+140;
		
if(d==300&&g>230&&g<480)
d=d-70;
if(d==370&&g>230&&g<480)		
d=d-140;
if(e==300&&f>230&&f<480)
e=e-70;
if(e==370&&f>230&&f<480)			
e=e-140;
if(d1==300&&g1>230&&g1<480)
d1=d1-70;
if(d1==370&&g1>230&&g1<480)			
d1=d1-140;

if(f==300&&e>230&&e<560)
f=f-70;
if(f==370&&e>230&&e<560)			
f=f-140;
if(g==300&&d>230&&d<560)
g=g-70;
if(g==370&&d>230&&d<560)		
g=g-140;
if(g1==300&&d1>230&&d1<560)
g1=g1-70;
if(g1==370&&d1>230&&d1<560)			
g1=g1-140;

if(f==410&&e>230&&e<560)
f=f+70;
if(f==340&&e>230&&e<560)		
f=f+140;
if(g==410&&d>230&&d<560)
g=g+70;
if(g==340&&d>230&&d<560)			
g=g+140;
if(g1==410&&d1>230&&d1<560)
g1=g1+70;
if(g1==340&&d1>230&&d1<560)		
g1=g1+140;
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
}
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if (key ==' '/* Escape key ASCII*/) {	// exit the program when escape key is pressed.
	if(f==20&&e!=20)	// my movement car.in track 1
e=e-5;
else if(e==20&&f!=690)
f=f+5;
else if(f==690&&e!=770)
e=e+5;
else if(e==770&&f!=20)
f=f-5;

else if(f==90&&e!=90)	// my movement car in track 2.
//{if(sap==1){e=e-10;}else {e=e-5;}}
e=e-5;
else if(e==90&&f!=620)
f=f+5;
else if(f==620&&e!=700)
e=e+5;
else if(e==700&&f!=90)
f=f-5;

else if(f==160&&e!=160)	// my movement car in track 3
e=e-5;
else if(e==160&&f!=550)
f=f+5;
else if(f==550&&e!=630)
e=e+5;
else if(e==630&&f!=160)
f=f-5;

else if(f==230&&e!=230)	// my movement car in track 4.
e=e-5;
else if(e==230&&f!=480)
f=f+5;
else if(f==480&&e!=560)
e=e+5;
else if(e==560&&f!=230)
f=f-5;
sap=0;
	}

	if (key == 'p' || key == 'P')
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
paus++;
	}
	////if (key == 32)		
	//{e=e+10;
	//f=f+10;
	//}		/*q=e;
			/*w=f;
			o=d;
			p=g;
			e=0;
			f=0;
			d=0;
			g=0;*/
			//glutTimerFunc(100000000000.0, Timer, 0);
//glutTimerFunc(100000000000000.0, Timer1, 0);
			
		//do something if b is pressed
		//if(z==1)
//{pause();
		//z++;}
		//if(z==2)
	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
 
 void Timer1(int m) {
 if(paus%2!=0){d=d;}
 else{
 if(g==20&&d!=770)	// oponant movement car.in track 1
d=d+10;
else if(d==770&&g!=690)
g=g+10;
else if(g==690&&d!=20)
d=d-10;
else if(d==20&&g!=20)
g=g-10;
else if(g==90&&d!=700)	// oponant movement car. in track 2
d=d+10;
else if(d==700&&g!=620)
g=g+10;
else if(g==620&&d!=90)
d=d-10;
else if(d==90&&g!=90)
g=g-10;
else if(g==160&&d!=630)	// oponant movement car. in track 3
d=d+10;
else if(d==630&&g!=550)
g=g+10;
else if(g==550&&d!=160)
d=d-10;
else if(d==160&&g!=160)
g=g-10;

else if(g==230&&d!=560)	// oponant movement car. in track 4
d=d+10;
else if(d==560&&g!=480)
g=g+10;
else if(g==480&&d!=230)
d=d-10;
else if(d==230&&g!=230)
g=g-10;}glutPostRedisplay();
 if (key == 'p' || key == 'P')
	{if(x==1)
	{glutTimerFunc(10000000000000.0, Timer1, 0);x++;}
	if(x==2) 
	{glutTimerFunc(20.0, Timer1, 0);x=1;}
	}else
	{glutTimerFunc(40.0, Timer1, 0);}
	if(lavel==3)
	{if(paus%2!=0){d=d;}
 else{
 if(g==20&&d!=770)	// oponant movement car.in track 1
d=d+10;
else if(d==770&&g!=690)
g=g+10;
else if(g==690&&d!=20)
d=d-10;
else if(d==20&&g!=20)
g=g-10;
else if(g==90&&d!=700)	// oponant movement car. in track 2
d=d+10;
else if(d==700&&g!=620)
g=g+10;
else if(g==620&&d!=90)
d=d-10;
else if(d==90&&g!=90)
g=g-10;
else if(g==160&&d!=630)	// oponant movement car. in track 3
d=d+10;
else if(d==630&&g!=550)
g=g+10;
else if(g==550&&d!=160)
d=d-10;
else if(d==160&&g!=160)
g=g-10;

else if(g==230&&d!=560)	// oponant movement car. in track 4
d=d+10;
else if(d==560&&g!=480)
g=g+10;
else if(g==480&&d!=230)
d=d-10;
else if(d==230&&g!=230)
g=g-10;}}}
	
	
	
	 void Timer3(int m) {
 if(paus%2!=0){d1=d1;}
 else{
 if(g1==20&&d1!=770)	// second oponant movement car.in track 1
d1=d1+10;
else if(d1==770&&g1!=690)
g1=g1+10;
else if(g1==690&&d1!=20)
d1=d1-10;
else if(d1==20&&g1!=20)
g1=g1-10;
else if(g1==90&&d1!=700)	// second oponant movement car. in track 2
d1=d1+10;
else if(d1==700&&g1!=620)
g1=g1+10;
else if(g1==620&&d1!=90)
d1=d1-10;
else if(d1==90&&g1!=90)
g1=g1-10;
else if(g1==160&&d1!=630)	// second oponant movement car. in track 3
d1=d1+10;
else if(d1==630&&g1!=550)
g1=g1+10;
else if(g1==550&&d1!=160)
d1=d1-10;
else if(d1==160&&g1!=160)
g1=g1-10;

else if(g1==230&&d1!=560)	//second oponant movement car. in track 4
d1=d1+10;
else if(d1==560&&g1!=480)
g1=g1+10;
else if(g1==480&&d1!=230)
d1=d1-10;
else if(d1==230&&g1!=230)
g1=g1-10;}glutPostRedisplay();
 if (key == 'p' || key == 'P')
	{if(x==1)
	{glutTimerFunc(10000000000000.0, Timer1, 0);x++;}
	if(x==2) 
	{glutTimerFunc(20.0, Timer3, 0);x=1;}
	}else
	{glutTimerFunc(40.0, Timer3, 0);}}

/*void Timer3(int m) {
 if(paus%2!=0){d=d;}
 else{
 if(g1==690&&d1!=20)	// oponant movement car.in track 1
d1=d1-5;
else if(d1==20&&g1!=20)
g1=g1-5;
else if(g1==20&&d1!=770)
d1=d1+5;
else if(d1==770&&g1!=690)
g1=g1+5;
else if(g1==620&&d1!=90)	// oponant movement car. in track 2
d1=d1+5;
else if(d1==90&&g1!=90)
g1=g1+5;
else if(g1==90&&d1!=700)
d1=d1-5;
else if(d1==700&&g1!=620)
g1=g1-5;
else if(g1==550&&d1!=160)	// oponant movement car. in track 3
d1=d1+5;
else if(d1==160&&g1!=160)
g1=g1+5;
else if(g1==160&&d1!=630)
d1=d1-5;
else if(d1==630&&g1!=550)
g1=g1-5;

else if(g1==480&&d1!=230)	// oponant movement car. in track 4
d1=d1+5;
else if(d1==230&&g1!=230)
g1=g1+5;
else if(g1==230&&d1!=540)
d1=d1-5;
else if(d1==540&&g1!=480)
g1=g1-5;}



 glutPostRedisplay();
 if (key == 'p' || key == 'P')
	{if(x==1)
	{glutTimerFunc(10000000000000.0, Timer1, 0);x++;}
	if(x==2) 
	{glutTimerFunc(20.0, Timer3, 0);x=1;}
	}else
	{glutTimerFunc(40.0, Timer3, 0);}
	//glutTimerFunc(10.0, Timer1, 0);
}*/
void Timer(int m) {


if(paus%2!=0)
{e=e;}
else
{if(f==20&&e!=20&&e>330&&(lavel==2||lavel==4||lavel==3))
e=e-5;
if(f==20&&e!=20)
e=e-5;	// my movement car.in track 1
else if(e==20&&f!=690)
f=f+5;
else if(f==690&&e!=770)
e=e+5;
else if(e==770&&f!=20)
f=f-5;

else if(f==90&&e!=90)	// my movement car in track 2.
e=e-5;
else if(e==90&&f!=620)
f=f+5;
else if(f==620&&e!=700)
e=e+5;
else if(e==700&&f!=90)
f=f-5;

else if(f==160&&e!=160)	// my movement car in track 3
e=e-5;
else if(e==160&&f!=550)
f=f+5;
else if(f==550&&e!=630)
e=e+5;
else if(e==630&&f!=160)
f=f-5;

else if(f==230&&e!=230)	// my movement car in track 4.
e=e-5;
else if(e==230&&f!=480)
f=f+5;
else if(f==480&&e!=560)
e=e+5;
else if(e==560&&f!=230)
f=f-5;
sap=0;}
//glutTimerFunc(4.0, Timer, 0);}




	//glutTimerFunc(20.0, Timer, 0);

if(e==20&&f==20)   //conditions for removing cions.
{if(arry[0]==1)
{l++;
cout<<"\a";}
arry[0]=0;}
if(e==20&&f==90)
{if(arry[1]==1){
l++;
cout<<"\a";}
arry[1]=0;}
if(e==20&&f==160)
{if(arry[2]==1){
l++;
cout<<"\a";}
arry[2]=0;}
if(e==20&&f==230)
{if(arry[3]==1){
l++;
cout<<"\a";}
arry[3]=0;}
if(e==20&&f==310)
{if(arry[4]==1){
l++;
cout<<"\a";}
arry[4]=0;}
if(e==20&&f==400)
{if(arry[5]==1){
l++;
cout<<"\a";}
arry[5]=0;}
if(e==20&&f==470)
{if(arry[6]==1){
l++;
cout<<"\a";}
arry[6]=0;}
if(e==20&&f==550)
{if(arry[7]==1){
l++;
cout<<"\a";}
arry[7]=0;}
if(e==20&&f==620)
{if(arry[8]==1){
l++;
cout<<"\a";}
arry[8]=0;}
if(e==20&&f==690)
{if(arry[9]==1){
l++;
cout<<"\a";}
arry[9]=0;}
if(e==90&&f==20)
{if(arry[10]==1){
l++;
cout<<"\a";}
arry[10]=0;}
if(e==90&&f==90)
{if(arry[11]==1){
l++;
cout<<"\a";}
arry[11]=0;}
if(e==90&&f==160)
{if(arry[12]==1){
l++;
cout<<"\a";}
arry[12]=0;}
if(e==90&&f==230)
{if(arry[13]==1){
l++;
cout<<"\a";}
arry[13]=0;}
if(e==90&&f==310)
{if(arry[14]==1){
l++;
cout<<"\a";}
arry[14]=0;}
if(e==90&&f==400)
{
if(arry[15]==1){
l++;
cout<<"\a";}
arry[15]=0;}
if(e==90&&f==470)
{
if(arry[16]==1){
l++;
cout<<"\a";}
arry[16]=0;}
if(e==90&&f==550)
{
if(arry[17]==1){
l++;
cout<<"\a";}
arry[17]=0;}
if(e==90&&f==620)
{
if(arry[18]==1){
l++;
cout<<"\a";}
arry[18]=0;}
if(e==100&&f==690)
{
if(arry[19]==1){
l++;
cout<<"\a";}
arry[19]=0;}
if(e==160&&f==20)
{
if(arry[20]==1){
l++;
cout<<"\a";}
arry[20]=0;}
if(e==160&&f==90)
{
if(arry[21]==1){
l++;
cout<<"\a";}
arry[21]=0;}
if(e==160&&f==160)
{
if(arry[22]==1){
l++;
cout<<"\a";}
arry[22]=0;}

if(e==160&&f==230)
{
if(arry[23]==1){
l++;
cout<<"\a";}
arry[23]=0;}

if(e==160&&f==310)
{
if(arry[24]==1){
l++;
cout<<"\a";}
arry[24]=0;}

if(e==160&&f==400)
{
if(arry[25]==1){
l++;
cout<<"\a";}
arry[25]=0;}

if(e==160&&f==470)
{
if(arry[26]==1){
l++;
cout<<"\a";}
arry[26]=0;}

if(e==160&&f==550)
{
if(arry[27]==1){
l++;
cout<<"\a";}
arry[27]=0;}

if(e==160&&f==620)
{
if(arry[28]==1){
l++;
cout<<"\a";}
arry[28]=0;}


if(e==160&&f==690)
{
if(arry[29]==1){
l++;
cout<<"\a";}
arry[29]=0;}

if(e==230&&f==20)
{
if(arry[30]==1){
l++;
cout<<"\a";}
arry[30]=0;}
if(e==230&&f==90)
{
if(arry[31]==1){
l++;
cout<<"\a";}
arry[31]=0;}

if(e==230&&f==160)
{
if(arry[32]==1){
l++;
cout<<"\a";}
arry[32]=0;}

if(e==230&&f==230)
{
if(arry[33]==1){
l++;
cout<<"\a";}
arry[33]=0;}

if(e==230&&f==310)
{
if(arry[34]==1){
l++;
cout<<"\a";}
arry[34]=0;}

if(e==230&&f==400)
{
if(arry[35]==1){
l++;
cout<<"\a";}
arry[35]=0;}

if(e==230&&f==470)
{
if(arry[36]==1){
l++;
cout<<"\a";}
arry[36]=0;}

if(e==230&&f==550)
{
if(arry[37]==1){
l++;
cout<<"\a";}
arry[37]=0;}


if(e==230&&f==620)
{
if(arry[38]==1){
l++;
cout<<"\a";}
arry[38]=0;}
if(e==230&&f==690)
{
if(arry[39]==1){
l++;
cout<<"\a";}
arry[39]=0;}
if(e==340&&f==20)
{
if(arry[40]==1){
l++;
cout<<"\a";}
arry[40]=0;}

if(e==340&&f==90)
{
if(arry[41]==1){
l++;
cout<<"\a";}
arry[41]=0;}

if(e==340&&f==160)
{
if(arry[42]==1){
l++;
cout<<"\a";}
arry[42]=0;}

if(e==340&&f==230)
{
if(arry[43]==1){
l++;
cout<<"\a";}
arry[43]=0;}

if(e==340&&f==480)
{
if(arry[44]==1){
l++;
cout<<"\a";}
arry[44]=0;}

if(e==340&&f==550)
{
if(arry[45]==1){
l++;
cout<<"\a";}
arry[45]=0;}

if(e==340&&f==620)
{
if(arry[46]==1){
l++;
cout<<"\a";}
arry[46]=0;}


if(e==340&&f==690)
{
if(arry[47]==1){
l++;
cout<<"\a";}
arry[47]=0;}
if(e==450&&f==20)
{
if(arry[48]==1){
l++;
cout<<"\a";}
arry[48]=0;}
if(e==450&&f==90)
{
if(arry[49]==1){
l++;
cout<<"\a";}
arry[49]=0;}

if(e==450&&f==160)
{
if(arry[50]==1){
l++;
cout<<"\a";}
arry[50]=0;}

if(e==450&&f==230)
{
if(arry[51]==1){
l++;
cout<<"\a";}
arry[51]=0;}

if(e==450&&f==480)
{
if(arry[52]==1){
l++;
cout<<"\a";}
arry[52]=0;}

if(e==450&&f==550)
{
if(arry[53]==1){
l++;
cout<<"\a";}
arry[53]=0;}

if(e==450&&f==620)
{
if(arry[54]==1){
l++;
cout<<"\a";}
arry[54]=0;}

if(e==450&&f==690)
{
if(arry[55]==1){
l++;
cout<<"\a";}
arry[55]=0;}

if(e==560&&f==20)
{
if(arry[56]==1){
l++;
cout<<"\a";}
arry[56]=0;}


if(e==560&&f==90)
{
if(arry[57]==1){
l++;
cout<<"\a";}
arry[57]=0;}
if(e==560&&f==160)
{
if(arry[58]==1){
l++;
cout<<"\a";}
arry[58]=0;}
if(e==560&&f==230)
{
if(arry[59]==1){
l++;
cout<<"\a";}
arry[59]=0;}


if(e==560&&f==310)
{if(arry[60]==1)
{l++;
cout<<"\a";}
arry[60]=0;}
if(e==560&&f==400)
{if(arry[61]==1){
l++;
cout<<"\a";}
arry[61]=0;}
if(e==560&&f==480)
{if(arry[62]==1){
l++;
cout<<"\a";}
arry[62]=0;}
if(e==560&&f==550)
{if(arry[63]==1){
l++;
cout<<"\a";}
arry[63]=0;}
if(e==560&&f==620)
{if(arry[64]==1){
l++;
cout<<"\a";}
arry[64]=0;}
if(e==560&&f==690)
{if(arry[65]==1){
l++;
cout<<"\a";}
arry[65]=0;}
if(e==630&&f==20)
{if(arry[66]==1){
l++;
cout<<"\a";}
arry[66]=0;}
if(e==630&&f==90)
{if(arry[67]==1){
l++;
cout<<"\a";}
arry[67]=0;}
if(e==630&&f==160)
{if(arry[68]==1){
l++;
cout<<"\a";}
arry[68]=0;}
if(e==630&&f==230)
{if(arry[69]==1){
l++;
cout<<"\a";}
arry[69]=0;}


if(e==630&&f==310)
{
if(arry[70]==1){
l++;
cout<<"\a";}
arry[70]=0;}


if(e==630&&f==400)
{
if(arry[71]==1){
l++;
cout<<"\a";}
arry[71]=0;}
if(e==630&&f==470)
{
if(arry[72]==1){
l++;
cout<<"\a";}
arry[72]=0;}
if(e==630&&f==550)
{
if(arry[73]==1){
l++;
cout<<"\a";}
arry[73]=0;}


if(e==630&&f==620)
{if(arry[74]==1)
{l++;
cout<<"\a";}
arry[74]=0;}
if(e==630&&f==690)
{if(arry[75]==1){
l++;
cout<<"\a";}
arry[75]=0;}
if(e==700&&f==20)
{if(arry[76]==1){
l++;
cout<<"\a";}
arry[76]=0;}
if(e==700&&f==90)
{if(arry[77]==1){
l++;
cout<<"\a";}
arry[77]=0;}
if(e==700&&f==160)
{if(arry[78]==1){
l++;
cout<<"\a";}
arry[78]=0;}
if(e==700&&f==230)
{if(arry[79]==1){
l++;
cout<<"\a";}
arry[79]=0;}
if(e==700&&f==310)
{if(arry[80]==1){
l++;
cout<<"\a";}
arry[80]=0;}
if(e==700&&f==400)
{if(arry[81]==1){
l++;
cout<<"\a";}
arry[81]=0;}
if(e==700&&f==470)
{if(arry[82]==1){
l++;
cout<<"\a";}
arry[82]=0;}
if(e==700&&f==550)
{if(arry[83]==1){
l++;
cout<<"\a";}
arry[83]=0;}
if(e==700&&f==620)
{if(arry[84]==1){
l++;
cout<<"\a";}
arry[84]=0;}


if(e==700&&f==690)
{if(arry[85]==1){
l++;
cout<<"\a";}
arry[85]=0;}
if(e==770&&f==20)
{if(arry[86]==1){
l++;
cout<<"\a";}
arry[86]=0;}
if(e==770&&f==90)
{if(arry[87]==1){
l++;
cout<<"\a";}
arry[87]=0;}
if(e==770&&f==160)
{if(arry[88]==1){
l++;
cout<<"\a";}
arry[88]=0;}
if(e==770&&f==230)
{if(arry[89]==1){
l++;
cout<<"\a";}
arry[89]=0;}
if(e==770&&f==310)
{if(arry[90]==1){
l++;
cout<<"\a";}
arry[90]=0;}
if(e==770&&f==400)
{if(arry[91]==1){
l++;
cout<<"\a";}
arry[91]=0;}
if(e==770&&f==470)
{if(arry[92]==1){
l++;
cout<<"\a";}
arry[92]=0;}
if(e==770&&f==550)
{if(arry[93]==1){
l++;
cout<<"\a";}
arry[93]=0;}
if(e==770&&f==620)
{if(arry[94]==1){
l++;
cout<<"\a";}
arry[94]=0;}
if(e==770&&f==690)
{if(arry[95]==1){
l++;
cout<<"\a";}
arry[95]=0;}





glutPostRedisplay();

//cout<<" e "<<e<<" f "<<f<<"                            d"<<d<<" g "<<g<<endl;
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	//if(
	////if (key == 'p' || key == 'P')
	//{if(x==1)
	//{glutTimerFunc(10000000000000.0, Timer, 0);x++;}
	//if(x==2)
	//{glutTimerFunc(20.0, Timer, 0);x=1;}
	//}else
	if(lavel==3){glutTimerFunc(20.0, Timer, 0);
}
else glutTimerFunc(20.0, Timer, 0);
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		//cout << GLUT_DOWN << " " << GLUT_UP <<"    "<<x<<"    "<<y<< endl;
		if((x>197&&x<280)&&(y<32&&y>13))	//for starting game
		{glutDisplayFunc(GameDisplay);
e=350,f=20,g=20,d=450,g1=620,d1=380;
	}
	if((x>192&&x<343)&&(y<122&&y>92))		//for new game
		{
		e=350,f=20,g=20,d=450,g1=620,d1=380;
		s=1;l=0;lavel=1,o=3;
		glutDisplayFunc(GameDisplay);

	}
	
	if((x>187&&x<272)&&(y<293&&y>260))		//for displaying help.
		{
		glutDisplayFunc(help);

	}
	if((x>191&&x<404)&&(y<209&&y>175))		//for displaying high score.
		{
		s5=displying(h);					//calling the displying function that display score.
	
	glutDisplayFunc(high);

	}
	if((x>191&&x<265)&&(y<379&&y>348))		//for exit.
		{
		
		exit(1);
	}
	if((x>190&&x<400)&&(y<635&&y>614))		//for exit.
		{
		o=3;
		glutDisplayFunc(manu);
	}
	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{//cout << GLUT_DOWN << " " << GLUT_UP <<"    "<<x<<"    "<<y<< endl;
			//if((x>197&&x<280)&&(y<150&&y>10)
			//{glutDisplayFunc(GameDisplay);

	//}
	glutPostRedisplay();
}}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("MY PROJECT GAME"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
glutDisplayFunc(manu); 
	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(20.0, Timer, 0);
glutTimerFunc(20.0, Timer1, 0);
glutTimerFunc(20.0, Timer3, 0);
	glutMouseFunc(MouseClicked);
	cout<<MouseClicked<<endl;
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse





//int &a=h;
	
	

	
	//writing to a file
	//ifstream infile;
	//infile.open("high.txt"); //this function takes the name of the file that you are writing to
	
	
	//for (int i = 0; i < 10; i++){
	//	fout << high_Scores[i] << endl;
	//}
	/*fout<<a;	
	fout.close();
	
	//reading from a file
	string score;
	ifstream fin ("high score.txt"); //name of the file it is supposed to read
	if (fin.is_open())
	{
		while ( getline (fin, score) ) //this loop will run depending on the number of lines in the file
		{
		  cout << score << '\n';
		  
		  //HINT: use stoi() to convert string into Integer
		  
		}
		fin.close();
	}
	
	else 
		cout << "Unable to open file"; */

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
