export module Initialization;

import <SDL3/SDL.h>;
import std;

export struct appData {
	SDL_Rect resolution;
	std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>> window;
	std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>> renderer;
};

export auto initialize() -> std::expected<appData, std::string> {
	// initialize video
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) != true) {
		return std::unexpected("Failed to initialize SDL_INIT_VIDEO");
	}

	// find user's primary monitor resolution
	auto dm = SDL_DisplayMode{};
	if (SDL_GetCurrentDisplayMode(dm.displayID) != 0) {
		return std::unexpected("Failed to locate monitor");
	}

	auto lData = appData{};
	lData.resolution = { 0, 0, dm.w, dm.h };

	// create temporary window based on found resolution
	lData.window = std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>>{
		SDL_CreateWindow("Window", lData.resolution.w, lData.resolution.h, 0),
		SDL_DestroyWindow
	};
	
	if (!lData.window) {
		 return std::unexpected("Failed to load window");
	}

	lData.renderer = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>>{
		SDL_CreateRenderer(lData.window.get(), nullptr),
		SDL_DestroyRenderer
	};

	if (!lData.renderer) {
		return std::unexpected("Failed to load renderer");
	}

	// lData is a struct (appData) that holds game resoulution and renderer
	return lData;
}
