/*
Copyright (C) 2015-2018 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "common.h"

static SDL_Texture *pete[2];

void initPlayer(void)
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;

	player2 = malloc(sizeof(Entity));
	memset(player2, 0, sizeof(Entity));
	stage.entityTail->next = player2;
	stage.entityTail = player2;

	player->health = 1;
	player2->health = 1;

	pete[0] = loadTexture("gfx/pete01.png");
	pete[1] = loadTexture("gfx/pete02.png");
	pete[2] = loadTexture("gfx/pete03.png");

	player->texture = pete[0];

	player2->texture = pete[2];

	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
	SDL_QueryTexture(player2->texture, NULL, NULL, &player2->w, &player2->h);
}

void doPlayer(void)
{
	
	player->dx = 0;

	player2->dx = 0;

	if (app.keyboard[SDL_SCANCODE_A])
	{
		player->dx = -PLAYER_MOVE_SPEED;

		player->texture = pete[1];
	}

	if (app.keyboard[SDL_SCANCODE_D])
	{
		player->dx = PLAYER_MOVE_SPEED;

		player->texture = pete[0];

	}

	if (app.keyboard[SDL_SCANCODE_SPACE] && player->isOnGround)
	{
		player->riding = NULL;

		player->dy = -20;

		playSound(SND_JUMP, CH_PLAYER);
	}


	if (app.keyboard[SDL_SCANCODE_J])
	{
		player2->dx = -PLAYER_MOVE_SPEED;

		player2->texture = pete[1];
	}

	if (app.keyboard[SDL_SCANCODE_L])
	{
		player2->dx = PLAYER_MOVE_SPEED;

		player2->texture = pete[0];

	}

	if (app.keyboard[SDL_SCANCODE_K] && player2->isOnGround)
	{
		player2->riding = NULL;

		player2->dy = -20;

		playSound(SND_JUMP, CH_PLAYER);
	}

	if (app.keyboard[SDL_SCANCODE_Y])
	{
		player->x = player->y = 0;

		app.keyboard[SDL_SCANCODE_SPACE] = 0;
	}

	if (app.keyboard[SDL_SCANCODE_T])
	{
		player2->x = player2->y = 0;

		app.keyboard[SDL_SCANCODE_SPACE] = 0;
	}
}
