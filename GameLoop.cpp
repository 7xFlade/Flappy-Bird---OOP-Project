#include "GameLoop.hpp"

//constructor --Player class pointers assigned to base class birds
GameLoop::GameLoop() : window(nullptr), renderer(nullptr), GameState(false), PauseState(false), startState(false), p(new BirdB()), y(new BirdY()), o(new BirdO())
{   //want birds to start from middle of y axis of screen and a fixed x axis
    p->setSource(0, 0, 65, 55);
    p->setDest(250, Height / 2, 65, 55);
    y->setSource(0, 0, 65, 55);
    y->setDest(250, Height / 2, 65, 55);
    o->setSource(0, 0, 65, 55);
    o->setDest(250, Height / 2, 65, 55);
    //the base ground
    ground1.setSource(0, 0, 336, 112);
    ground1.setDest(0, 520, 336, 112);
    ground2.setSource(0, 0, 336, 112);
    ground2.setDest(0, 520, 336, 112);
    //obstacles that will be appearing from above and below
    Pipe_Above1.setSource(0, 0, 52, 320);
    Pipe_Above1.setDest(0, -200, 52, 320);
    Pipe_Below1.setSource(0, 0, 52, 320);
    Pipe_Below1.setDest(0, 350, 52, 320);
    Pipe_Above2.setSource(0, 0, 52, 320);
    Pipe_Above2.setDest(0, -200, 52, 320);
    Pipe_Below2.setSource(0, 0, 52, 290);
    Pipe_Below2.setDest(0, 350, 52, 290);
    Pipe_Above3.setSource(0, 0, 52, 320);
    Pipe_Above3.setDest(0, -200, 52, 320);
    Pipe_Below3.setSource(0, 0, 52, 320);
    Pipe_Below3.setDest(0, 350, 52, 320);
}

//mutator of startstate to change it in between our main gameloop
void GameLoop::setStartState(const bool x)
{
    startState = x;
}


//following are accessors of gamestate, pausestate, and start state
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

//Initializing sdl and making window, also creating textures of the objects(only once in the beginning)
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
            Pipe_Above1.CreateTexture("Image/spike 1.png", renderer);
            Pipe_Below1.CreateTexture("Image/brick_3.png", renderer);
            Pipe_Above2.CreateTexture("Image/brick_3 (1).png", renderer);
            Pipe_Below2.CreateTexture("Image/spike 2 (1).png", renderer);
            Pipe_Above3.CreateTexture("Image/brick_3 (1).png", renderer);
            Pipe_Below3.CreateTexture("Image/spike B.png", renderer);
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
{   //referring to methods of soundManager
    sound.initializeSDL(); 
    sound.loadMedia();
}
// Main menu
void GameLoop::MainMenu()
{   //referring to methods of Mainmenu class
    menu.Initialize(renderer);
    while (!menu.getClicked())//if start game is not clicked keep on rendering until user quits
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
{   //referring to methods of Instructions class
    ins.Initialize(renderer);
    while (!ins.getNext())//if arrow is not clicked keep on rendering until user quits
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
{   //referring to methods of SelectBird class
    sb.Initialize(renderer);
    while (!sb.getChosenB())//if any bird is not chosen keep on rendering until user quits
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
{   //referring to methods of PauseScreen class
    PScreen.Initialize(renderer);
    SDL_RenderClear(renderer);
    PScreen.Render(renderer);
    SDL_RenderPresent(renderer);
}
// End game with score display
void GameLoop::Endgame()
{
    ew.Initialize(renderer);
    //displaying score at the end screen
   //Initialize TTF and font
    TTF_Init();
    //path will be changed accordingly
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
        //rendering code for end window
        SDL_RenderClear(renderer);
        ew.Render(renderer);


        // Render and update the score
        score1 = score.getScore() / 50;
        score1 = s / 50;
        //score.setHighscore(score1); ////
        score=score1;
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
        s=0;
        ew.setRestart(false);
        Reset();//reset every thing to initial condition-Reset() defined below
    }

    if (scoreTexture)
    {
        SDL_DestroyTexture(scoreTexture);
    }
    if (highscoreTexture)
    {
        SDL_DestroyTexture(highscoreTexture);
    }
    //closing sdl font display
    TTF_CloseFont(font);
    TTF_Quit();
}
    
//will be used before user starts the game
void GameLoop::SetHighscore()
{
    //score.setHighscore(0);
    score=0;
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
{ 
    timer++;
    bool flag1 = false, flag2 = false;
    ground1.GroundUpdate1();
    ground2.GroundUpdate2();
    //the pipes that exit the screen are being updated to reappear from right side of screen but with different orientation(height)
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
    //updating the movement of birds to give them the flapping effect and apply gravity to them
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
    //operator overloading
    s+=score++;
    std::cout<<s<<std::endl;
    //to check for collision throughout the runtime of game
    CollisionDetection();
}

// Collison check either with the obsracles or the ground
void GameLoop::CollisionDetection()
{
    if (sb.getBird() == 1)
    {   //checks for collison of blue bird bird with obstacles
        if (CollisionManager::checkCollision(&p->getDest(), &Pipe_Above1.getDest()) || CollisionManager::checkCollision(&p->getDest(), &Pipe_Below1.getDest()) ||
            CollisionManager::checkCollision(&p->getDest(), &Pipe_Above2.getDest()) || CollisionManager::checkCollision(&p->getDest(), &Pipe_Below2.getDest()) ||
            CollisionManager::checkCollision(&p->getDest(), &Pipe_Above3.getDest()) || CollisionManager::checkCollision(&p->getDest(), &Pipe_Below3.getDest()))
        {
            sound.loadMedia1(); // collision sound
            Reset();//reset every value to initial state
            GameState = false;//through this the game will exit the main loop
        }
        //checks for collison of blue bird bird with ground
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
    //for yellow bird
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

    //for the owl
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
    //clear any rendering before this
    SDL_RenderClear(renderer);
    //background render
    b.Render(renderer); 
    if (t1>100){
        //rendering of objects
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
    
    //displaying the current score during game
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("C:\\Users\\A450L\\Downloads\\OOP-Project-Manal-Moiz-Naaseh-main\\OOP-Project-Manal-Moiz-Naaseh-main\\font3.ttf", 55);
    SDL_Color text_color = {0, 0, 0};
    SDL_Texture *scoreTexture = nullptr;
    SDL_Surface *scoreSurface = nullptr;

    
    score1 = s / 50;
    //score.setHighscore(score1);////
    score=score1;
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
//Rule of 3
//copy constructor
GameLoop::GameLoop(const GameLoop& other) : window(other.window), renderer(other.renderer),
                                       GameState(other.GameState), PauseState(other.PauseState),
                                       startState(other.startState), p(new BirdB()),
                                       y(new BirdY()), o(new BirdO()),
                                       ground1(other.ground1), ground2(other.ground2),
                                       Pipe_Above1(other.Pipe_Above1), Pipe_Below1(other.Pipe_Below1),
                                       Pipe_Above2(other.Pipe_Above2), Pipe_Below2(other.Pipe_Below2),
                                       Pipe_Above3(other.Pipe_Above3), Pipe_Below3(other.Pipe_Below3) {}

//assignment operator overloading
GameLoop &GameLoop::operator=(const GameLoop &other) {
    if (this != &other) {
        // Copy data from the source object
        window = other.window;
        renderer = other.renderer;
        GameState = other.GameState;
        PauseState = other.PauseState;
        startState = other.startState;

        // Delete existing objects
        delete p;
        delete y;
        delete o;

        // Create new objects and copy data
        p = new BirdB();
        y = new BirdY();
        o = new BirdO();

        ground1 = other.ground1;
        ground2 = other.ground2;
        Pipe_Above1 = other.Pipe_Above1;
        Pipe_Below1 = other.Pipe_Below1;
        Pipe_Above2 = other.Pipe_Above2;
        Pipe_Below2 = other.Pipe_Below2;
        Pipe_Above3 = other.Pipe_Above3;
        Pipe_Below3 = other.Pipe_Below3;
    }
    return *this;
}

void GameLoop::operator=(const bool x){
    startState=x;
}