#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termbox.h>

struct key {
	unsigned char x;
	unsigned char y;
	uint32_t ch;
};

#define STOP {0,0,0}
struct key K_ESC[] = {{1,1,'E'},{2,1,'S'},{3,1,'C'},STOP};

void draw_key(struct key *k, uint16_t fg, uint16_t bg)
{
	while (k->x)
	{
		tb_change_cell(k->x+2, k->y+4, k->ch, fg, bg);
		k++;
	}
}

int main()
{
	printf("Hello world\n");

	tb_init();
	tb_select_input_mode(TB_INPUT_ESC | TB_INPUT_MOUSE);
	tb_select_output_mode(TB_OUTPUT_256);
	tb_clear();

	const char* myName = "steel";
	int length = strlen(myName);
	for (int i = 0; i < length; i++)
	{
		tb_change_cell(i, 0, myName[i], 32+i, 231);
	}

	tb_change_cell(0, 10, 'y', TB_WHITE, TB_BLUE); 
	tb_change_cell(1, 10, 'o', TB_WHITE, TB_BLUE); 
	tb_change_cell(2, 10, ' ', TB_GREEN, TB_BLUE); 
	tb_change_cell(3, 10, 'y', TB_BLACK, TB_BLUE); 
	tb_change_cell(4, 10, 'o', TB_BLACK, TB_BLUE); 

	draw_key(K_ESC, TB_WHITE, TB_BLUE);
	tb_present();

	for (;;)
	{
		struct tb_event ev;
		int t = tb_poll_event(&ev);
		if (t == -1)
		{
			tb_shutdown();
			printf("termbox failed to poll an event\n");
			exit(-1);
		}

		switch (t) {
			case TB_EVENT_KEY:
				if (ev.key == TB_KEY_ESC)
				{
					tb_shutdown();
					exit(0);
				}
				break;
			default:
				break;
		}

		
	}
}
