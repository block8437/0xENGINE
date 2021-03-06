/*

Level File Format (.lvl):

MUSIC FILENAME\n
BACKGROUND FILENAME\n

for every spritesheet
	SPRITE SPRITESHEET_IMAGE, SPRITESHEET_FILE

for every object
	OBJECT SPRITESHEET, POSITION, FRAMES, SEQUENCE \n

*/

#ifndef LEVEL
#define LEVEL
#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <SDL.h>
#include "object.h"
#include "sound.h"
#include <map>
#include <vector>
#include "template.h"
class Level
{
		SDL_Renderer* renderer;
		std::string filename;

	public:
		std::map<std::string, spriteSheet> sprites;
		std::string music_file;
		background back;
		std::vector<Object> objlist;
		std::vector<std::string> vec;
		Level::Level(){};
		Level::Level(SDL_Renderer*, std::string filename);

		bool Load();
		bool Save();

		void clean();
		
		void addObject(Object obj);
};
#endif