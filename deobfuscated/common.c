/* common.c -- common functions for kernel and user-space programs */

#include "common.h"

void draw_rectangle(char *dest, int top, int left, int height, int width, char color){
	for(int i = top; i != top + height; ++i){
		for(int j = left; j != left + width; ++j){
			dest[i * SCREEN_WIDTH + j] = color;
		}
	}
}

void draw_symbol(char *dest, char symbol, char color){
	for(int i = 0; i != SYMBOL_HEIGHT; ++i){
		for(int j = 0; j != SYMBOL_WIDTH; ++j){
			/*
			 * (const char *const *)(START + 36) is pointer to array of representing of all symbols.
			 * Information about every symbol has size 16 bytes (16 is symbol height).
			 * Every byte contents 8 bits (8 is symbol width).
			 * Every bit content one pixel of symbol.
			 */
			if((*(const char *const *)(START + 36))[symbol * SYMBOL_HEIGHT + i] & (128 >> j)){
				dest[i * SCREEN_WIDTH + j] = color;
			}
		}
	}
}
