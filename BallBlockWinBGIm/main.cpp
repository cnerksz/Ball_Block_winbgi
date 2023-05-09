
#include <graphics.h>
#include <conio.h>
#define SCREEN_WIDTH 79
#define SCREEN_HEIGHT 25
int board[4][40];
int life=5;
int resume=1;
int ballx=600;
int rktx=525;
int rkty=600;
int score=0;
int rktx_size=150;
int boardx_size=70;
int boardy_size=30;
int ball_radius=10;
int move_rkt=10;
int move_ballx=0;
int move_bally=3;
int bally=250;
void init_board()
{


        for(int row=0; row<4; row++)
        {
            for(int col=0; col<10; col++)
            {


            board[row][col] =1;





            }

            }



    }

void draw_board(){
    rectangle(1,1,1060,700);
        int top=50;
    int right=50;

        for(int row=0; row<4; row++)
        {
            for(int col=0; col<10; col++)
            {


           if(board[row][col]==1){

setfillstyle(SOLID_FILL,BLACK);

                    rectangle(right, top, right + boardx_size,top+boardy_size);
                    floodfill(right+60,top+15,WHITE);

           }




 right+=100;
 }
 top+=50;
            right=50;
                }



}

void draw_ball(){
                    setfillstyle(SOLID_FILL,WHITE);
                    circle(ballx,bally,ball_radius);
                    floodfill(ballx,bally,WHITE);
}
void draw_rkt(){
                setfillstyle(SOLID_FILL,BLACK);

                    rectangle(rktx, rkty, rktx + 150, rkty + 30);
                    floodfill(rktx+140,rkty+15,WHITE);
}
void update_rkt(int new_rktx) {
    setfillstyle(SOLID_FILL, RED);
    rectangle(rktx, rkty, rktx + 150, rkty + 30);
    floodfill(rktx + 140, rkty + 15, RED);
    rktx = new_rktx;
    setfillstyle(SOLID_FILL, BLACK);
    rectangle(rktx, rkty, rktx + 150, rkty + 30);
    floodfill(rktx + 140, rkty + 15, WHITE);
}
void check_collision() {
    int top=50;
    int right=50;
    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 10; col ++) {
            if(board[row][col] == 1) {
        if ((bally + ball_radius >= top && bally + ball_radius <= top + boardy_size) || (bally - ball_radius >= top && bally - ball_radius <= top + boardy_size)) {
					if (ballx - ball_radius == right + boardx_size - 1 || ballx - ball_radius + 1 == right || ballx + ball_radius - 1 == right || ballx + ball_radius - 1 == right + boardx_size) {
						board[row][col] = 0;
score+=10;
						move_ballx = -move_ballx;

						break;
					}
					else {
						if (move_ballx >= 0) {
							if (ballx - ball_radius <= right + boardx_size && ballx - ball_radius >= right)
							{
								board[row][col] = 0;
score+=10;
								move_bally = move_bally * (-1);

								break;
							}
							else if (ballx + ball_radius >= right && ballx + ball_radius <= right + boardx_size) {
								board[row][col] = 0;
score+=10;
								move_bally = move_bally * (-1);

								break;
							}
						}
						if (move_ballx <= -1) {
							if (ballx - ball_radius >= right && ballx - ball_radius <= right + boardx_size) {
								board[row][col] = 0;
score+=10;
								move_bally = move_bally * (-1);

								break;
							}
							else if (ballx + ball_radius >= right && ballx + ball_radius <= right + boardx_size)
							{
								board[row][col] = 0;
score+=10;

								move_bally = move_bally * (-1);

								break;
							}
						}
					}
				}

    }
    right+=100;
  }
  top+=50;
  right=50;
 }
 char temp[10];
outtextxy(1100,330,"Score :");
sprintf(temp,"%d",score);
outtextxy(1200,330,temp);

}


void update_ball(){
char  temp [10];
outtextxy(1100,350,"Life :");
sprintf(temp,"%d",life);
outtextxy(1200,350,temp);
setfillstyle(SOLID_FILL,RED);
circle(ballx,bally,ball_radius);
floodfill(ballx,bally,RED);
 ballx+=move_ballx;
            bally+=move_bally;
draw_ball();
check_collision();
if ((bally + 11 >= rkty) && (ballx >= rktx) && (ballx <= rktx + 150)) {
    move_bally = -move_bally;
    if (ballx < rktx + 25) {
        move_ballx = -2;
    }
    else if(ballx<rktx+125&&ballx>=rktx+100){
        move_ballx=1;
    }
    else if (ballx >= rktx + 25&&ballx<rktx+50) {
        move_ballx = -1;
    }
    else if (ballx >= rktx + 50 && ballx < rktx + 100) {
        move_ballx = 0;

    }
    else if (ballx >= rktx + 125) {
        move_ballx = 2;

    }

    update_rkt(rktx);
}

if(ballx<=2)move_ballx=-move_ballx;
if(ballx>=1058)move_ballx=-move_ballx;
if(bally<=2)move_bally=-move_bally;
if(bally>=rkty+11){
        life--;
             setfillstyle(SOLID_FILL,RED);
circle(ballx,bally,ball_radius);
floodfill(ballx,bally,RED);
        ballx=600;
        move_ballx=0;
        move_bally=3;
        bally=250;
         setfillstyle(SOLID_FILL, RED);
    rectangle(rktx, rkty, rktx + 150, rkty + 30);
    floodfill(rktx + 140, rkty + 15, RED);
        rktx=525;
        draw_rkt();


         char temp[10];
outtextxy(1100,350,"Life :");
sprintf(temp,"%d",life);
outtextxy(1200,350,temp);
}

draw_board();
Sleep(1);
}


main(int argc, char *argv[])
{

	initwindow(600, 600);					// init window graphics
	setbkcolor(4);							// set background
   	cleardevice();


init_board();
draw_board();
	draw_ball();
	draw_rkt();
	char temp[10];


while(1){
            while(resume==1){
                    if(life==0){
                        cleardevice();
                          char temp[10];
outtextxy(550,350,"Uzgunuz Kaybettiniz ");
outtextxy(550,370,"Total Score :");
sprintf(temp,"%d",score);
outtextxy(700,370,temp);
                            resume=0;
                        continue;
                    }
                    if(score==400){
                            cleardevice();
                    char temp[10];
                    outtextxy(550,350,"TEBRIKLERR.. ");
                    outtextxy(550,370,"Total Score :");
                    sprintf(temp,"%d",score);
                    outtextxy(700,370,temp);
                     resume=0;
                        continue;
                    }
update_ball();



            if(kbhit()){
                char ch = getch();
                switch(ch){
                case 'a':
                case 'A':
                    if(rktx>=20){
                    rktx=rktx-move_rkt;
                    update_rkt(rktx);
                    }
                break;
                case 'd':
                case 'D':
                     if(rktx+rktx_size<=1050){
                    rktx=rktx+move_rkt;
                    update_rkt(rktx);
                    }
                }
            }
}
if(kbhit())
    getch();
}}
