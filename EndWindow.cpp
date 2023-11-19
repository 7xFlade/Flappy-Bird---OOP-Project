#include "EndWindow.hpp"



void EndWindow::Initialize(SDL_Renderer* ren)
{
	endBackground.CreateTexture("image/endscreen.png", ren);
}

int EndWindow::EventHandling(SDL_Event& w)
{
	SDL_PollEvent(&w);
	if (w.type == SDL_QUIT)
	{
		return -1;
	}
	else if (w.type == SDL_MOUSEBUTTONDOWN && w.motion.x > 250 && w.motion.x < 550 && w.motion.y > 480 && w.motion.y < 560)
	{
		restart = true;
        
	}
	//
	// SDL_Init(SDL_INIT_VIDEO);
    // TTF_Init();
	// std::string fontpath = "C:\\Users\\A450L\\Downloads\\OOP-Project-Manal-Moiz-Naaseh-main\\OOP-Project-Manal-Moiz-Naaseh-main\\font3.ttf";
    // font = TTF_OpenFont(fontpath.c_str(), 45);
    // if (font==nullptr){std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;}
    // SDL_Init(SDL_INIT_VIDEO);
    // TTF_Init();

	// score += 1;

    //     if (prevScore != score) {
    //         prevScore = score;

    //         if (texture) {
    //             SDL_DestroyTexture(texture);
    //             texture = nullptr;
    //         }

    //         sprintf(buffer, "SCORE: %d",score);
    //         surface = TTF_RenderText_Solid(font, buffer, text_color);
    //         texture = SDL_CreateTextureFromSurface(renderer, surface);

    //         SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    //         SDL_FreeSurface(surface);
    //     }

    //     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set renderer color to black
    //     SDL_RenderClear(renderer);
    //     SDL_Rect dstrect = {400, 300, texW, texH};
    //     SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    //     SDL_RenderPresent(renderer);
    
	

	return 0;
}

void EndWindow::Render(SDL_Renderer* ren)
{
	endBackground.Render(ren);
}

bool EndWindow::getRestart()
{
	return restart;
}

EndWindow::~EndWindow()
{
	restart = false;
	
    // TTF_CloseFont(font);
    // TTF_Quit();
}