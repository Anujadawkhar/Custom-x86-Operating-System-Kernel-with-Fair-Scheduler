#include "print.h"

//volatile : directly mapped to hardware memory , changes cannot be done. 
volatile unsigned short* video =
    (volatile unsigned short*)0xB8000;  //VGA text meemory : 0xB8000

//initialize
int row = 0;
int col = 0;

void clear_screen()
{
    //rows (25): 0 to 24 , cols(80) : 0 to 79    
    for(int i=0;i<80*25;i++)
        video[i] = (0x0F << 8) | ' ';
                    //0x0F : white background to black screen 
                    //<< 8 : color to high byte 
                    //' ' : sets white background for entire screen
    row = 0;
    col = 0;
}

void print(const char* str)
{
    while(*str)
    {
        if(*str == '\n')
        {
            row++;
            col = 0;
        }
        else
        {         //screen position write str
            video[row * 80 + col] =
                (0x0F << 8) | *str;

            col++;

            if(col >= 80)
            {
                col = 0;
                row++;
            }
        }

        if(row >= 25)
        {
            row = 0;   // simple wrap
        }

        str++;
    }
}


