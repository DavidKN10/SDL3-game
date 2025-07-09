export module GameLoop;

import <SDL3/SDL.h>;
import Initialization;
import std;

export auto game() -> void {
	// initialize the game, returning a string on error
	auto data = initialize();
	if (!data) {
		std::println("{}", data.error());
		return;
	}
	auto inputEvent = SDL_Event();

	auto quit = bool{ false };
	while (quit == false) {
		// input event system
		while (SDL_PollEvent(&inputEvent) > 0) {
			if (inputEvent.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
				quit = true;
			}
		}
		// update frame logic

		// rendering
		SDL_RenderClear(data->renderer.get());
		SDL_SetRenderDrawColor(data->renderer.get(), 0, 0, 0, 255);
		SDL_RenderPresent(data->renderer.get());
	}
}
