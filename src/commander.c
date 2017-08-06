/* -*- mode: c; c-file-style: "openbsd" -*- */
/*
 * Copyright (c) 2017, Alexander Memer <mkoaleksedos@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define BOT_PREFIX "~>"

#include "../include/crow.h"
#include "../include/commander.h"

#include <string.h>

void 
on_discord_message(message_t msg) {
	if (strcmp(msg.author.id, bot.id)) {
		if (startsWith(msg.content, BOT_PREFIX)) {
			msg.content = msg.content + strlen(BOT_PREFIX);

			if (!strcmp("ping", msg.content)) {
				send_message(msg.channel_id, "Pong!");
			}
			if (!strcmp("ok", msg.content)) {
				add_reaction(msg.channel_id, msg.id, "trumpLUL:237288619088412683");
			}
			if (!strcmp("debug_channel", msg.content)) {
				guild_channel_t channel = get_channel(msg.channel_id);

				char to_send[1024];

				snprintf(to_send, sizeof(to_send), "This channel: \nID: %s\nGuildID: %s\nType: %d\nTopic: %s ", channel.id, channel.guild_id, channel.type, channel.topic);

				send_message(msg.channel_id, to_send);
			}
			if (startsWith(msg.content, "echo")) {
				send_message(msg.channel_id, msg.content);
			}
			if (!strcmp("hi", msg.content)) {
				char to_send[1024];

				snprintf(to_send, sizeof(to_send), "Hi, %s!", msg.author.username);

				send_message(msg.channel_id, to_send);
			}
		}
	}
}

void 
on_presence_update(presence_update_t upd) {

}