#include "library.h"
#include <iostream>
#include <cmath>

using namespace std;

int window_width = 400;
int window_height = 400;

const int divide_sign = L'÷';
const int up_arrow = L'↑';
const int multi_sign = L'×';
const int sub_sign = L'̶ ';

void draw_button(string num, int x, int y)
{
	set_pen_color(color::black);
	move_to(window_width - x, window_height - y);
	fill_rectangle(window_width - x - 2, window_height - y - 2, window_width-(window_width-84), window_height-(window_height-84));
	set_pen_color(color::light_grey);
	fill_rectangle(window_width - x, window_height - y, window_width-(window_width-80), window_height-(window_height-80));
	set_pen_color(color::black);
	move_to(window_width - x + ((window_width-(window_width-80))/2), window_height - y + (window_height-(window_height-80))/2);
	set_font_size((window_width-(window_width-84))/1.5);
	write_string(num, direction::center);
}

void draw_button_char(int num, int x, int y)
{
	set_pen_color(color::black);
	move_to(window_width - x, window_height - y);
	fill_rectangle(window_width - x - 2, window_height - y - 2, window_width-(window_width-84), window_height-(window_height-84));
	set_pen_color(color::light_grey);
	fill_rectangle(window_width - x, window_height - y, window_width-(window_width-80), window_height-(window_height-80));
	set_pen_color(color::black);
	move_to(window_width - x + ((window_width-(window_width-80))/2), window_height - y + (window_height-(window_height-80))/2);
	set_font_size((window_width-(window_width-84))/1.5);
	write_char(num, direction::center);
}

void get_power_of_number(int n, int x, int y)
{
	wait_for_mouse_click();
	int x_power = get_click_x();
	int	y_power = get_click_y();
	if (x_power > window_width - x - 2 && x_power < window_width - x + 82)
	{
		if (y_power > window_width - y - 2 && y_power < window_height - y + 82)
			n = 7;
		else if (y_power > window_width - y - 2 + 100 && y_power < window_height - y + 82 + 100)
			n = 4;
		else if (y_power > window_width - y - 2 + 200 && y_power < window_height - y + 82 + 200)
			n = 1;
		else if (y_power > window_width - y - 2 + 300 && y_power < window_height - y + 82 + 300)
			clear;
	}
	if (x_power > window_width - x - 2 + 100 && x_power < window_width - x + 82 + 100)
	{
		if (y_power > window_width - y - 2 && y_power < window_height - y + 82)
			n = 8;
		else if (y_power > window_width - y - 2 + 100 && y_power < window_height - y + 82 + 100)
			n = 5;
		else if (y_power > window_width - y - 2 + 200 && y_power < window_height - y + 82 + 200)
			n = 2;
		else if (y_power > window_width - y - 2 + 300 && y_power < window_height - y + 82 + 300)
			n = 0;
	}
	if (x_power > window_width - x - 2 + 200 && x_power < window_width - x + 82 + 200)
	{
		if (y_power > window_width - y - 2 && y_power < window_height - y + 82)
			n = 9;
		else if (y_power > window_width - y - 2 + 100 && y_power < window_height - y + 82 + 100)
			n = 6;
		else if (y_power > window_width - y - 2 + 200 && y_power < window_height - y + 82 + 200)
			n = 3;
	}
}

int get_Result(char operation, float x, float y)
{
	if (operation == '+') 
	{
		return x+y;
	}
	else if (operation == '-') 
	{
		return x-y;
	}
	else if (operation == '*') 
	{
		return x*y;
	}
	else if (operation == '/')
	{
		return x/y;
	}
	else 
	{
		return 0;
	}
}

void draw_calc(int x, int y)
{
	draw_button("7", x, y);
	draw_button("8", x-100, y);
	draw_button("9", x-200, y);
	draw_button("+", x-300, y);
	draw_button("x", x-400, y);
	move_to(window_width - x + ((window_width-(window_width-80))/2) + 5 + 410, window_height - y + ((window_height-(window_height-80))/2) - 5);
	set_font_size((window_width-(window_width-84))/2);
	write_string("2");
	draw_button("4", x, y-100);
	draw_button("5", x-100, y-100);
	draw_button("6", x-200, y-100);
	draw_button_char(sub_sign, x-300, y-100);
	draw_button("+/-", x-400, y-100);
	draw_button("1", x, y-200);
	draw_button("2", x-100, y-200);
	draw_button("3", x-200, y-200);
	draw_button_char(multi_sign, x-300, y-200);
	draw_button("rnd", x-400, y-200);
	draw_button("c", x, y-300);
	draw_button("0", x-100, y-300);
	draw_button("=", x-200, y-300);
	draw_button_char(divide_sign, x-300, y-300);
	draw_button_char(up_arrow, x-400, y-300);
	fill_rectangle(window_width - x - 50, window_height - y - 75, 500, 65, color::white);
	
	int result = 0;
	int input_number = 0;
	int first_input = 0;
	int second_input = 0;
	float n = 0;
	int counter = 0;
	int before_number = 0;
	char first_operation = ' ';
	char second_operation = ' ';
	bool didFirstOperation = false;

	while(true)
	{
	wait_for_mouse_click();
	int x_clicked = get_click_x();
	int	y_clicked = get_click_y();
	if (x_clicked > window_width - x - 2 && x_clicked < window_width - x + 82)
	{
		if (y_clicked > window_width - y - 2 && y_clicked < window_height - y + 82)
		{
			before_number = input_number*10 + 7 - (input_number*10);
			input_number = input_number*10 + 7;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_height - y - 2 + 100 && y_clicked < window_height - y + 82 + 100)
		{
			before_number = input_number*10 + 4 - (input_number*10);
			input_number = input_number*10 + 4;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_height - y - 2 + 200 && y_clicked < window_height - y + 82 + 200)
		{
			before_number = input_number*10 + 1 - (input_number*10);
			input_number = input_number*10 + 1;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_height - y - 2 + 300 && y_clicked < window_height - y + 82 + 300)
		{
			before_number = input_number*0;
			input_number = input_number*0;
			move_to(window_width - x - 2, window_height - y - 15);
			counter = 0;
			fill_rectangle(window_width - x - 50, window_height - y - 50, 500, 40, color::white);
		}
	}
	if (x_clicked > window_width - x - 2 + 100 && x_clicked < window_width - x + 82 + 100)
	{
		if (y_clicked > window_width - y - 2 && y_clicked < window_height - y + 82)
		{
			before_number = input_number*10 + 8 - (input_number*10);
			input_number = input_number*10 + 8;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_width - y - 2 + 100 && y_clicked < window_height - y + 82 + 100)
		{
			before_number = input_number*10 + 5 - (input_number*10);
			input_number = input_number*10 + 5;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_width - y - 2 + 200 && y_clicked < window_height - y + 82 + 200)
		{
			before_number = input_number*10 + 2 - (input_number*10);
			input_number = input_number*10 + 2;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_width - y - 2 + 300 && y_clicked < window_height - y + 82 + 300)
		{
			before_number = input_number*10 + 0 - (input_number*10);
			input_number = input_number*10 + 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
	}
	if (x_clicked > window_width - x - 2 + 200 && x_clicked < window_width - x + 82 + 200)
	{
		if (y_clicked > window_width - y - 2 && y_clicked < window_height - y + 82)
		{
			before_number = input_number*10 + 9 - (input_number*10);
			input_number = input_number*10 + 9;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_width - y - 2 + 100 && y_clicked < window_height - y + 82 + 100)
		{
			before_number = input_number*10 + 6 - (input_number*10);
			input_number = input_number*10 + 6;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_width - y - 2 + 200 && y_clicked < window_height - y + 82 + 200)
		{
			before_number = input_number*10 + 3 - (input_number*10);
			input_number = input_number*10 + 3;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_width - y - 2 + 300 && y_clicked < window_height - y + 82 + 300) //=
		{
			cout<<first_operation<<endl<<second_operation;
			if (second_operation == '*' || second_operation == '/')
			{
				result = get_Result(second_operation, second_input, input_number);
				result = get_Result(first_operation, first_input, result);
			}
			else
			{
				if (first_operation == ' ')
				{
					cout<<input_number;
					result = input_number;
				}
				else if (second_operation == ' ')
				{ 
					result = get_Result(first_operation, first_input, input_number);
				}
				else if (second_operation == '+' || second_operation == '-')
				{
					result = get_Result(first_operation, first_input, second_input);
					result = get_Result(second_operation, result, input_number);
				}
			}	
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string("=");
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(result);

		}
	}
	if (x_clicked > window_width - x - 2 + 300 && x_clicked < window_width - x + 82 + 300)
	{
		if (y_clicked > window_width - y - 2 && y_clicked < window_height - y + 82)
		{	
			if (!didFirstOperation)
			{
			first_input = input_number;
			first_operation = '+';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string("+");
			didFirstOperation = true;
			}
			else 
			{
			second_input = input_number;
			second_operation = '+';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string("+");
			}
		}
		else if (y_clicked > window_width - y - 2 + 100 && y_clicked < window_height - y + 82 + 100)
		{
			if (!didFirstOperation)
			{
			first_input = input_number;
			first_operation = '-';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_char(sub_sign);
			didFirstOperation = true;
			}
			else
			{
			second_input = input_number;
			second_operation = '-';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_char(sub_sign);
			}
		}
		else if (y_clicked > window_width - y - 2 + 200 && y_clicked < window_height - y + 82 + 200)
		{
			if (!didFirstOperation)
			{
			first_input = input_number;
			first_operation = '*';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_char(multi_sign);
			didFirstOperation = true;
			}
			else
			{
			second_input = input_number;
			second_operation = '*';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_char(multi_sign);
			}
		}
		else if (y_clicked > window_width - y - 2 + 300 && y_clicked < window_height - y + 82 + 300)
		{
			if (!didFirstOperation)
			{
			first_input = input_number;
			first_operation = '/';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_char(divide_sign);
			didFirstOperation = true;
			}
			else
			{
			second_input = input_number;
			second_operation = '/';
			input_number = 0;
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_char(divide_sign);
			}
		}
	}
	if (x_clicked > window_width - x - 2 + 400 && x_clicked < window_width - x + 82 + 400)
	{
		if (y_clicked > window_width - y - 2 && y_clicked < window_height - y + 82)
		{// j print 2 on top of number and then keep track that its squared
			before_number = input_number*input_number;
			input_number = input_number*input_number;
			move_to(window_width - x - 2 + ((counter*25)), window_height - y - 50);
			counter++;
			write_string("2");
		}
		else if (y_clicked > window_width - y - 2 + 100 && y_clicked < window_height - y + 82 + 100)
		{ // blank it out and then rewrite string
			before_number = input_number;
			input_number = input_number*(-1);
			fill_rectangle(window_width - x - 2 + (counter*25) -25, window_height - y - 50, 25, 35, color::white);
			move_to(window_width - x - 2 + (counter*25) - 25, window_height - y - 15);
			write_char(sub_sign);
			fill_rectangle(window_width - x - 2 + (counter*25), window_height - y - 50, 500, 40, color::white);
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			write_string(before_number);
		}
		else if (y_clicked > window_width - y - 2 + 200 && y_clicked < window_height - y + 82 + 200)
		{
			move_to(window_width - x - 2 + (counter*25), window_height - y - 15);
			counter++;
			input_number = random()%10;
			write_string(input_number);
		}
		else if (y_clicked > window_width - y - 2 + 300 && y_clicked < window_height - y + 82 + 300)
		{
			wait_for_mouse_click();
			int x_power = get_click_x();
			int	y_power = get_click_y();
			if (x_power > window_width - x - 2 && x_power < window_width - x + 82)
			{
				if (y_power > window_width - y - 2 && y_power < window_height - y + 82)
					n = 7;
				else if (y_power > window_width - y - 2 + 100 && y_power < window_height - y + 82 + 100)
					n = 4;
				else if (y_power > window_width - y - 2 + 200 && y_power < window_height - y + 82 + 200)
					n = 1;
				else if (y_power > window_width - y - 2 + 300 && y_power < window_height - y + 82 + 300)
					clear;
			}
			if (x_power > window_width - x - 2 + 100 && x_power < window_width - x + 82 + 100)
			{
				if (y_power > window_width - y - 2 && y_power < window_height - y + 82)
					n = 8;
				else if (y_power > window_width - y - 2 + 100 && y_power < window_height - y + 82 + 100)
					n = 5;
				else if (y_power > window_width - y - 2 + 200 && y_power < window_height - y + 82 + 200)
					n = 2;
				else if (y_power > window_width - y - 2 + 300 && y_power < window_height - y + 82 + 300)
					n = 0;
			}
			if (x_power > window_width - x - 2 + 200 && x_power < window_width - x + 82 + 200)
			{
				if (y_power > window_width - y - 2 && y_power < window_height - y + 82)
					n = 9;
				else if (y_power > window_width - y - 2 + 100 && y_power < window_height - y + 82 + 100)
					n = 6;
				else if (y_power > window_width - y - 2 + 200 && y_power < window_height - y + 82 + 200)
					n = 3;
	}
			before_number = pow(input_number, n);
			input_number = pow(input_number, n);
			move_to(window_width - x - 2 + ((counter*25)), window_height - y - 50);
			counter++;
			write_string(n);
		}
	}
	}
}


void main()
{
	make_window(window_width, window_height);
	draw_calc(300, 300);
}