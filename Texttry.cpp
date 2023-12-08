TTF_Init();
    TTF_Font *font = TTF_OpenFont("C:\\Users\\A450L\\Downloads\\OOP-Project-Manal-Moiz-Naaseh-main\\OOP-Project-Manal-Moiz-Naaseh-main\\font3.ttf", 25);
    SDL_Color text_color = {0, 0, 0};
    SDL_Texture *scoreTexture = nullptr;
    SDL_Surface *scoreSurface = nullptr;
    SDL_Texture *highscoreTexture = nullptr;
    SDL_Surface *highscoreSurface = nullptr;

    while (!ew.getRestart())
    {
        if (ew.EventHandling(event1) == -1)
        {
            GameState = false;
            // sound.closeSDL();
            break;
        }
        // Your existing rendering code for end window
        SDL_RenderClear(renderer);
        ew.Render(renderer);
        //SDL_RenderPresent(renderer);


        // Render and update the score
        //score1 = score.getScore() / 50;
        score1 = s / 50;
        score.setHighscore(score1); ////

        int score2 = score.getHighschore();
        char scoreText[50];
        char highscoreText[50];
        sprintf(scoreText, " %d", score1);
        sprintf(highscoreText, " %d", score2);
        if (scoreTexture)
        {
            SDL_DestroyTexture(scoreTexture);
            scoreTexture = nullptr;
        }
        if (highscoreTexture)
        {
            SDL_DestroyTexture(highscoreTexture);
            highscoreTexture = nullptr;
        }

        scoreSurface = TTF_RenderText_Solid(font, scoreText, text_color);
        scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

        highscoreSurface = TTF_RenderText_Solid(font, highscoreText, text_color);
        highscoreTexture = SDL_CreateTextureFromSurface(renderer, highscoreSurface);

        int texW = 0, texH = 0;
        SDL_QueryTexture(scoreTexture, NULL, NULL, &texW, &texH);
        SDL_Rect scoreRect = {400, 280, texW, texH};
        SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

        SDL_QueryTexture(highscoreTexture, NULL, NULL, &texW, &texH);
        SDL_Rect highscoreRect = {400, 370, texW, texH};
        SDL_RenderCopy(renderer, highscoreTexture, NULL, &highscoreRect);

        SDL_FreeSurface(scoreSurface);
        SDL_FreeSurface(highscoreSurface);

        SDL_RenderPresent(renderer);
    }

// if restart clicked
    if (ew.getRestart())
    {
        GameState = true;
        startState = true;
        //score.setscore(0);
        s=0;
        ew.setRestart(false);
        Reset();
    }

    if (scoreTexture)
    {
        SDL_DestroyTexture(scoreTexture);
    }
    if (highscoreTexture)
    {
        SDL_DestroyTexture(highscoreTexture);
    }

    TTF_CloseFont(font);
    TTF_Quit();
