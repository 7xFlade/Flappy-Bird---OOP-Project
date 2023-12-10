#include "GameLoop.hpp"

GameLoop::GameLoop() : window(nullptr), renderer(nullptr), GameState(false), PauseState(false), startState(false), p(new BirdB()), y(new BirdY()), o(new BirdO())
{
    p->setSource(0, 0, 65, 55);
    p->setDest(250, Height / 2, 65, 55);
    y->setSource(0, 0, 65, 55);
    y->setDest(250, Height / 2, 65, 55);
    o->setSource(0, 0, 65, 55);
    o->setDest(250, Height / 2, 65, 55);
    ground1.setSource(0, 0, 336, 112);
    ground1.setDest(0, 520, 336, 112);
    ground2.setSource(0, 0, 336, 112);
    ground2.setDest(0, 520, 336, 112);
    Pipe_Above1.setSource(0, 0, 52, 320);
    Pipe_Above1.setDest(0, -200, 52, 320);
    Pipe_Below1.setSource(0, 0, 52, 320);
    Pipe_Below1.setDest(0, 350, 52, 320);
    Pipe_Above2.setSource(0, 0, 52, 320);
    Pipe_Above2.setDest(0, -200, 52, 320);
    Pipe_Below2.setSource(0, 0, 52, 320);
    Pipe_Below2.setDest(0, 350, 52, 320);
    Pipe_Above3.setSource(0, 0, 52, 320);
    Pipe_Above3.setDest(0, -200, 52, 320);
    Pipe_Below3.setSource(0, 0, 52, 320);
    Pipe_Below3.setDest(0, 350, 52, 320);
}

void GameLoop::setStartState(const bool x)
{
    startState = x;
}

bool GameLoop::getGameState() const
{
    return GameState;
}

bool GameLoop::getPauseState() const
{
    return PauseState;
}

bool GameLoop::getStartState() const
{
    return startState;
}

void GameLoop::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_RESIZABLE);

    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            // if Main menu start game clicked only then do the below so for that getsamestate func in main menu class
            cout << "Succeeded!" << endl;
            GameState = true;
            p->CreateTexture("image/Frame-1 (1).png", renderer);
            p->createTexture1("image/Frame-2 (1).png", renderer);
            p->createTexture2("image/Frame-3 (1).png", renderer);
            y->CreateTexture("image/frameY-1.png", renderer);
            y->createTexture1("image/frameY-2.png", renderer);
            o->CreateTexture("image/frameO-1.png", renderer);
            o->createTexture1("image/frameO-2.png", renderer);
            o->createTexture2("image/frameO-3.png", renderer);
            o->createTexture3("image/frameO-4.png", renderer);
            b.CreateTexture("image/bg1.png", renderer);
            ground1.CreateTexture("image/Tile (1).png", renderer);
            ground2.CreateTexture("image/Tile (1).png", renderer);
            Pipe_Above1.CreateTexture("Image/brick_3 (1).png", renderer);
            Pipe_Below1.CreateTexture("Image/brick_3.png", renderer);
            Pipe_Above2.CreateTexture("Image/brick_3 (1).png", renderer);
            Pipe_Below2.CreateTexture("Image/spike B.png", renderer);
            Pipe_Above3.CreateTexture("Image/brick_3 (1).png", renderer);
            Pipe_Below3.CreateTexture("Image/brick_3.png", renderer);
        }
        else
        {
            cout << "Renderer not created" << endl;
        }
    }
    else
    {
        cout << "Window not created" << endl;
    }
}
// background music
void GameLoop::bgMusic()
{
    sound.initializeSDL(); // background music
    sound.loadMedia();
}
// Main menu
void GameLoop::MainMenu()
{
    menu.Initialize(renderer);
    while (!menu.getClicked())
    {
        if (menu.EventHandling(event1) == -1)
        {
            GameState = false;
            break;
        }
        SDL_RenderClear(renderer);
        menu.Render(renderer);
        SDL_RenderPresent(renderer);
    }
}
// Instructions
void GameLoop::Instructions()
{
    ins.Initialize(renderer);
    while (!ins.getNext())
    {
        if (ins.EventHandling(event1) == -1)
        {
            GameState = false;
            break;
        }
        SDL_RenderClear(renderer);
        ins.Render(renderer);
        SDL_RenderPresent(renderer);
    }
}
// selct your bird page
void GameLoop::SelectBird()
{
    sb.Initialize(renderer);
    while (!sb.getChosenB())
    {
        if (sb.EventHandling(event1) == -1)
        {
            GameState = false;
            break;
        }
        SDL_RenderClear(renderer);
        sb.Render(renderer);
        SDL_RenderPresent(renderer);
    }
}
// pause functionality
void GameLoop::Paused()
{
    PScreen.Initialize(renderer);
    SDL_RenderClear(renderer);
    PScreen.Render(renderer);
    SDL_RenderPresent(renderer);
}
// End game with score display
void GameLoop::Endgame()
{
    ew.Initialize(renderer);



    //Initialize TTF and font
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
        SDL_Rect highscoreRect = {400, 350, texW, texH};
        SDL_RenderCopy(renderer, highscoreTexture, NULL, &highscoreRect);

        SDL_FreeSurface(scoreSurface);
        SDL_FreeSurface(highscoreSurface);

        SDL_RenderPresent(renderer);





    }
    // // if restart clicked
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
}
    

void GameLoop::SetHighscore()
{
    score.setHighscore(0);
}

// keyboard connectivity
void GameLoop::Event()
{
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT)
    {
        GameState = false;
    }
    if (event1.type == SDL_KEYDOWN)
    {
        if (event1.key.keysym.sym == SDLK_UP) // when up pressed
        {
            cout << "Pressed" << endl;
            if (sb.getBird() == 1)
            {
                p->Gravity();
            }
            else if (sb.getBird() == 2)
            {
                y->Gravity();
            }
            else if (sb.getBird() == 3)
            {
                o->Gravity();
            }
        }
        else if (event1.key.keysym.sym == SDLK_SPACE) // when space bar pressed
        {
            PauseState = !PauseState;
        }
    }
}

// updating x/y axis values of objects
void GameLoop::Update()
{ // score display during game

    ///////////////
    timer++;
    if (timer > 100)
    {
        if (sb.getBird() == 1)
        {
            neuralNetwork.Update(p->getYPos(), nextCheckPoint);
        }
        else if (sb.getBird() == 2)
        {
            neuralNetwork.Update(y->getYPos(), nextCheckPoint);
        }
        else if (sb.getBird() == 3)
        {
            neuralNetwork.Update(o->getYPos(), nextCheckPoint);
        }

        // Finding closest Checkpoint !
        if (Pipe_Below1.getPipe1X() < Pipe_Below2.getPipe2X() && Pipe_Below1.getPipe1X() < Pipe_Below3.getPipe3X())
        {
            if (Pipe_Below1.getPipe1X() < -5)
            {
                nextCheckPoint = Pipe_Below2.getPipe2Y();
            }
            else
            {
                nextCheckPoint = Pipe_Below1.getPipe1Y();
            }
        }
        else if (Pipe_Below2.getPipe2X() < Pipe_Below1.getPipe1X() && Pipe_Below2.getPipe2X() < Pipe_Below3.getPipe3X())
        {
            if (Pipe_Below2.getPipe2X() < -5)
            {
                nextCheckPoint = Pipe_Below3.getPipe3Y();
            }
            else
            {
                nextCheckPoint = Pipe_Below2.getPipe2Y();
            }
        }
        else if (Pipe_Below3.getPipe3X() < Pipe_Below1.getPipe1X() && Pipe_Below3.getPipe3X() < Pipe_Below2.getPipe2X())
        {
            if (Pipe_Below3.getPipe3X() < -5)
            {
                nextCheckPoint = Pipe_Below1.getPipe1Y();
            }
            else
            {
                nextCheckPoint = Pipe_Below3.getPipe3Y();
            }
        }
    }
    //points = score.getScore();
    
    bool flag1 = false, flag2 = false;
    ground1.GroundUpdate1();
    ground2.GroundUpdate2();
    if (timer > 100)
    {
        flag1 = Pipe_Above1.Pipe_Above1Update(variance1, s);
        flag2 = Pipe_Below1.Pipe_Below1Update(variance1, s);
        if (flag1 && flag2)
        {
            srand(SDL_GetTicks());
            variance1 = rand() % 201 - 100;
            Pipe_Above1.Pipe_Above1Update(variance1, s);
            Pipe_Below1.Pipe_Below1Update(variance1, s);
        }
        flag1 = Pipe_Above2.Pipe_Above2Update(variance2, s);
        flag2 = Pipe_Below2.Pipe_Below2Update(variance2, s);
        if (flag1 && flag2)
        {
            srand(SDL_GetTicks());
            variance2 = rand() % 201 - 100;
            Pipe_Above2.Pipe_Above2Update(variance2, s);
            Pipe_Below2.Pipe_Below2Update(variance2, s);
        }
        flag1 = Pipe_Above3.Pipe_Above3Update(variance3, s);
        flag1 = Pipe_Below3.Pipe_Below3Update(variance3, s);
        if (flag1 && flag2)
        {
            srand(SDL_GetTicks());
            variance3 = rand() % 201 - 100;
            Pipe_Above3.Pipe_Above3Update(variance3, s);
            Pipe_Below3.Pipe_Below3Update(variance3, s);
        }
    }

    if (sb.getBird() == 1)
    {
        p->Update();
    }
    else if (sb.getBird() == 2)
    {
        y->Update();
    }
    else if (sb.getBird() == 3)
    {
        o->Update();
    }
    //score.scoreInc();
    //operator overloading
    s+=score++;
    std::cout<<s<<std::endl;
    //double a = score.getScore();
    CollisionDetection();
}

// Collison check either with the obsracles or the ground
void GameLoop::CollisionDetection()
{
    if (sb.getBird() == 1)
    {
        if (CollisionManager::checkCollision(&p->getDest(), &Pipe_Above1.getDest()) || CollisionManager::checkCollision(&p->getDest(), &Pipe_Below1.getDest()) ||
            CollisionManager::checkCollision(&p->getDest(), &Pipe_Above2.getDest()) || CollisionManager::checkCollision(&p->getDest(), &Pipe_Below2.getDest()) ||
            CollisionManager::checkCollision(&p->getDest(), &Pipe_Above3.getDest()) || CollisionManager::checkCollision(&p->getDest(), &Pipe_Below3.getDest()))
        {
            sound.loadMedia1(); // collision sound
            Reset();
            GameState = false;
        }
        if (CollisionManager::checkCollision(&p->getDest(), &ground1.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }

        if (CollisionManager::checkCollision(&p->getDest(), &ground2.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }
    }
    else if (sb.getBird() == 2)
    {
        if (CollisionManager::checkCollision(&y->getDest(), &Pipe_Above1.getDest()) || CollisionManager::checkCollision(&y->getDest(), &Pipe_Below1.getDest()) ||
            CollisionManager::checkCollision(&y->getDest(), &Pipe_Above2.getDest()) || CollisionManager::checkCollision(&y->getDest(), &Pipe_Below2.getDest()) ||
            CollisionManager::checkCollision(&y->getDest(), &Pipe_Above3.getDest()) || CollisionManager::checkCollision(&y->getDest(), &Pipe_Below3.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }
        if (CollisionManager::checkCollision(&y->getDest(), &ground1.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }

        if (CollisionManager::checkCollision(&y->getDest(), &ground2.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }
    }
    else if (sb.getBird() == 3)
    {
        if (CollisionManager::checkCollision(&o->getDest(), &Pipe_Above1.getDest()) || CollisionManager::checkCollision(&o->getDest(), &Pipe_Below1.getDest()) ||
            CollisionManager::checkCollision(&o->getDest(), &Pipe_Above2.getDest()) || CollisionManager::checkCollision(&o->getDest(), &Pipe_Below2.getDest()) ||
            CollisionManager::checkCollision(&o->getDest(), &Pipe_Above3.getDest()) || CollisionManager::checkCollision(&o->getDest(), &Pipe_Below3.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }
        if (CollisionManager::checkCollision(&o->getDest(), &ground1.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }

        if (CollisionManager::checkCollision(&o->getDest(), &ground2.getDest()))
        {
            sound.loadMedia1();
            Reset();
            GameState = false;
        }
    }
}

// reseting all the values, when game restarted
void GameLoop::Reset()
{
    points = 0;
    variance1 = rand() % 201 - 100;
    variance2 = rand() % 201 - 100;
    variance3 = rand() % 201 - 100;
    p->Reset();
    o->Reset();
    y->Reset();
    Pipe_Above1.Reset();
    Pipe_Above2.Reset();
    Pipe_Above3.Reset();
    Pipe_Below1.Reset();
    Pipe_Below2.Reset();
    Pipe_Below3.Reset();
}


void GameLoop::Render() {
    t1++;
    ///we can mpre font saying 123 fly
    SDL_RenderClear(renderer);

    b.Render(renderer); 
    if (t1>100){
        Pipe_Above1.Render(renderer);
        Pipe_Below1.Render(renderer);
        Pipe_Above2.Render(renderer);
        Pipe_Below2.Render(renderer);
        Pipe_Above3.Render(renderer);
        Pipe_Below3.Render(renderer);
        ground1.GroundRender(renderer);
        ground2.GroundRender(renderer);
    }
    if (sb.getBird()==1){
        p->Render(renderer);
    }
    else if (sb.getBird()==2){
        y->Render(renderer);
    }
    else if (sb.getBird()==3){
        o->Render(renderer);
    }
    
    //SDL_RenderPresent(renderer);
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("C:\\Users\\A450L\\Downloads\\OOP-Project-Manal-Moiz-Naaseh-main\\OOP-Project-Manal-Moiz-Naaseh-main\\font3.ttf", 55);
    SDL_Color text_color = {0, 0, 0};
    SDL_Texture *scoreTexture = nullptr;
    SDL_Surface *scoreSurface = nullptr;

    
    score1 = s / 50;
    score.setHighscore(score1);////
    char scoreText[50];
    sprintf(scoreText, " %d", score1);
    if (scoreTexture)
    {
        SDL_DestroyTexture(scoreTexture);
        scoreTexture = nullptr;
    }

    scoreSurface = TTF_RenderText_Solid(font, scoreText, text_color);
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

    int texW = 0, texH = 0;
    SDL_QueryTexture(scoreTexture, NULL, NULL, &texW, &texH);
    SDL_Rect scoreRect = {350, 180, texW, texH};
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

    SDL_FreeSurface(scoreSurface);
    SDL_DestroyTexture(scoreTexture);
    TTF_CloseFont(font);

    SDL_RenderPresent(renderer);
}

// Exiting the window
void GameLoop::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

// destructor for dealocating dynamic memeory of player type objects
GameLoop::~GameLoop()
{
    sound.closeSDL();
    delete p;
    delete y;
    delete o;
    p = nullptr;
    y = nullptr;
    o = nullptr;
}