#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#pragma comment(lib, "SDL3")

//C++ console entry -> iOS, Window, Linux
//int main(int argc, char* argv[])
//{
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	SDL_Window* MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);
	
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);
	
	SDL_Event MyEvent;
	
	bool bIsRunning = true;
	while(bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			if (MyEvent.type == SDL_EVENT_QUIT)
			{
				bIsRunning = false;
			}
		}
		else
		{
			//command queue
			SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
			SDL_RenderClear(MyRenderer);

			SDL_FRect MyRect = { 0.0f ,0.0f , 0.0f , 0.0f};
			for (int i = 0; i < 100; ++i)
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(256), SDL_rand(256), SDL_rand(256), 0);
				Sint32 RectX = SDL_rand(640);
				Sint32 RectY = SDL_rand(480);
				Sint32 RectW = SDL_rand((640 - RectX));
				Sint32 RectH = SDL_rand((480 - RectY));
				MyRect = { (float)RectX ,(float)RectY , (float)RectW , (float)RectH };
				
				SDL_RenderFillRect(MyRenderer, &MyRect);
			}
			//화면 업데이트, 사각형 100개를 랜덤으로 그려주세요.
			SDL_RenderPresent(MyRenderer);
		}
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);
	
	SDL_Quit();
	return 0;
}