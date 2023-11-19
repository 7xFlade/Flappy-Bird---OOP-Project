#include "GameLoop.hpp"

GameLoop::GameLoop() : window(nullptr), renderer(nullptr), GameState(false) {
    p.setSource(0,0,65, 55);
    p.setDest(250,Height/2,65,55);
    y.setSource(0,0,65, 55);
    y.setDest(250,Height/2,65,55);
    o.setSource(0,0,65, 55);
    o.setDest(250,Height/2,65,55);
    ground1.setSource(0, 0, 336, 112);
	ground1.setDest(0, 520, 336, 112);//805
    ground2.setSource(0, 0, 336, 112);//805
	ground2.setDest(0, 520, 336, 112);
    Pipe_Above1.setSource(0, 0, 52,320);
	Pipe_Above1.setDest(0, -200, 52,320);
	Pipe_Below1.setSource(0, 0, 52,320);
	Pipe_Below1.setDest(0, 350, 52,320);
	Pipe_Above2.setSource(0, 0, 52,320);
	Pipe_Above2.setDest(0, -200,52,320);
	Pipe_Below2.setSource(0, 0, 52,320);
	Pipe_Below2.setDest(0, 350, 52,320);
	Pipe_Above3.setSource(0, 0, 52,320);
	Pipe_Above3.setDest(0, -200, 52,320);
	Pipe_Below3.setSource(0, 0, 52,320);
	Pipe_Below3.setDest(0, 350, 52,320);
}

bool GameLoop::getGameState(){
    return GameState;
}

void GameLoop::Initialize() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_RESIZABLE);

    if (window) {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) { 
            //if Main menu start game clicked only then do the below so for that getsamestate func in main menu class
            cout << "Succeeded!" << endl;
            GameState= true;
            p.CreateTexture("image/Frame-1 (1).png", renderer); 
            p.createTexture1("image/Frame-2 (1).png", renderer); 
            p.createTexture2("image/Frame-3 (1).png", renderer);
            y.CreateTexture("image/frameY-1.png", renderer);
            y.createTexture1("image/frameY-2.png", renderer);
            o.CreateTexture("image/frameO-1.png", renderer);
            o.createTexture1("image/frameO-2.png", renderer);
            o.createTexture2("image/frameO-3.png", renderer);
            o.createTexture3("image/frameO-4.png", renderer);
            b.CreateTexture("image/bg.png", renderer);
            ground1.CreateTexture("image/base.png", renderer);
			ground2.CreateTexture("image/base.png", renderer);
            Pipe_Above1.CreateTexture("Image/brick_3 (1).png", renderer);
			Pipe_Below1.CreateTexture("Image/brick_3.png", renderer);
			Pipe_Above2.CreateTexture("Image/brick_3 (1).png", renderer);
			Pipe_Below2.CreateTexture("Image/brick_3.png", renderer);
			Pipe_Above3.CreateTexture("Image/brick_3 (1).png", renderer);
			Pipe_Below3.CreateTexture("Image/brick_3.png", renderer);
            
        } else {
            cout << "Renderer not created" << endl;
        }
    } else {
        cout << "Window not created" << endl;
    }
}

void GameLoop::MainMenu(){
    menu.Initialize(renderer);
    while (!menu.getClicked()){
        if (menu.EventHandling(event1)==-1){
            GameState=false;
            break;
        }
        SDL_RenderClear(renderer);
		menu.Render(renderer);
		SDL_RenderPresent(renderer);
    }
}

void GameLoop::SelectBird(){
    sb.Initialize(renderer);
    while (!sb.getChosenB()){
        if (sb.EventHandling(event1)==-1){
            GameState = false;
			break;
        }
        SDL_RenderClear(renderer);
		sb.Render(renderer);
		SDL_RenderPresent(renderer);
    }
}

void GameLoop::Endgame() {
    GameState = true;
    ew.Initialize(renderer);

    // Initialize TTF and font
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("C:\\Users\\A450L\\Desktop\\scoredisplay\\scoredisplay\\font3.ttf", 25);
    SDL_Color text_color = {0, 0, 0};
    SDL_Texture* scoreTexture = nullptr;
    SDL_Surface* scoreSurface = nullptr;

    while (!ew.getRestart()) {
        if (ew.EventHandling(event1) == -1) {
            GameState = false;
            break;
        }

        // Your existing rendering code for end window
        SDL_RenderClear(renderer);
        ew.Render(renderer);

        // Render and update the score
        score1=score.getScore()/50;
        char scoreText[50];
        sprintf(scoreText, " %d", score1);

        if (scoreTexture) {
            SDL_DestroyTexture(scoreTexture);
            scoreTexture = nullptr;
        }

        scoreSurface = TTF_RenderText_Solid(font, scoreText, text_color);
        scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

        int texW = 0, texH = 0;
        SDL_QueryTexture(scoreTexture, NULL, NULL, &texW, &texH);
        SDL_Rect scoreRect = {400, 270, texW, texH};
        SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

        SDL_FreeSurface(scoreSurface);

        SDL_RenderPresent(renderer);
    }

    if (scoreTexture) {
        SDL_DestroyTexture(scoreTexture);
    }

    TTF_CloseFont(font);
    TTF_Quit();
}


void GameLoop::Event(){
    SDL_PollEvent(&event1);
    if (event1.type==SDL_QUIT){
        GameState=false;
    }
    //Mouse Events
    // if (event1.type==SDL_MOUSEMOTION){
    //     cout<<event1.motion.x<<" "<<event1.motion.y<<endl;
    // }
    // if(event1.type==SDL_MOUSEBUTTONDOWN){
    //     cout<<"Pressed"<<endl;
    // }
    //Keyboard Events
    if (event1.type==SDL_KEYDOWN){
        if (event1.key.keysym.sym==SDLK_UP){//specific to space key
            cout<<"Pressed"<<endl;
            if(sb.getBird()==1){
                p.Gravity();
            }
            else if (sb.getBird()==2){
                y.Gravity();
            }
            else if (sb.getBird()==3){
                o.Gravity();
            }
        }
    }

}


void GameLoop::Update(){
    timer++;
    if (timer>100){
        if (sb.getBird()==1){
            neuralNetwork.Update(p.getYPos(), nextCheckPoint);
        }
        else if (sb.getBird()==2){
            neuralNetwork.Update(y.getYPos(), nextCheckPoint);
        }
        else if(sb.getBird()==3){
            neuralNetwork.Update(o.getYPos(), nextCheckPoint);
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
        else if (Pipe_Below3.getPipe3X() < Pipe_Below1.getPipe1X() && Pipe_Below3.getPipe3X() < Pipe_Below2.getPipe2X()){
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
    bool flag1 = false, flag2 = false;
	ground1.GroundUpdate1();
	ground2.GroundUpdate2();
    if (timer>100){
        flag1 = Pipe_Above1.Pipe_Above1Update(variance1, points);
        flag2 = Pipe_Below1.Pipe_Below1Update(variance1);
        if (flag1 && flag2)
        {
            srand(SDL_GetTicks());
            variance1 = rand() % 201 - 100;
            Pipe_Above1.Pipe_Above1Update(variance1, points);
            Pipe_Below1.Pipe_Below1Update(variance1);
        }
        flag1 = Pipe_Above2.Pipe_Above2Update(variance2, points);
        flag2 = Pipe_Below2.Pipe_Below2Update(variance2);
        if (flag1 && flag2)
        {
            srand(SDL_GetTicks());
            variance2 = rand() % 201 - 100;
            Pipe_Above2.Pipe_Above2Update(variance2, points);
            Pipe_Below2.Pipe_Below2Update(variance2);
        }
        flag1 = Pipe_Above3.Pipe_Above3Update(variance3, points);
        flag1 = Pipe_Below3.Pipe_Below3Update(variance3);
        if (flag1 && flag2)
        {
            srand(SDL_GetTicks());
            variance3 = rand() % 201 - 100;
            Pipe_Above3.Pipe_Above3Update(variance3, points);
            Pipe_Below3.Pipe_Below3Update(variance3);
        }

    }

    if (sb.getBird()==1){
        p.Update();
    }
    else if (sb.getBird()==2){
        y.Update();
    }
    else if (sb.getBird()==3){
        o.Update();
    }
    score.scoreInc();
    double a=score.getScore();
    score.setHighscore(a);

    CollisionDetection();
}

void GameLoop::CollisionDetection(){
    if (sb.getBird()==1){
        if (CollisionManager::checkCollision(&p.getDest(), &Pipe_Above1.getDest()) || CollisionManager::checkCollision(&p.getDest(), &Pipe_Below1.getDest()) || 
            CollisionManager::checkCollision(&p.getDest(), &Pipe_Above2.getDest()) || CollisionManager::checkCollision(&p.getDest(), &Pipe_Below2.getDest()) || 
            CollisionManager::checkCollision(&p.getDest(), &Pipe_Above3.getDest()) || CollisionManager::checkCollision(&p.getDest(), &Pipe_Below3.getDest())) {
                //SDL_Delay(500);
                GameState=false;
        }
        if (CollisionManager::checkCollision(&p.getDest(), &ground1.getDest())){
            //SDL_Delay(500);
            // Endgame();
            GameState=false;
        }

        if (CollisionManager::checkCollision(&p.getDest(), &ground2.getDest())){
            //SDL_Delay(500);
            // Endgame();
            GameState=false;
        }
    }
    else if (sb.getBird()==2){
        if (CollisionManager::checkCollision(&y.getDest(), &Pipe_Above1.getDest()) || CollisionManager::checkCollision(&y.getDest(), &Pipe_Below1.getDest()) || 
            CollisionManager::checkCollision(&y.getDest(), &Pipe_Above2.getDest()) || CollisionManager::checkCollision(&y.getDest(), &Pipe_Below2.getDest()) || 
            CollisionManager::checkCollision(&y.getDest(), &Pipe_Above3.getDest()) || CollisionManager::checkCollision(&y.getDest(), &Pipe_Below3.getDest())) {
                //SDL_Delay(500);
                //Endgame();
                GameState=false;
        }
        if (CollisionManager::checkCollision(&y.getDest(), &ground1.getDest())){
            //SDL_Delay(500);
            //Endgame();
            GameState=false;
        }

        if (CollisionManager::checkCollision(&y.getDest(), &ground2.getDest())){
            //SDL_Delay(500);
            //Endgame();
            GameState=false;
        }
    }
    else if (sb.getBird()==3){
        if (CollisionManager::checkCollision(&o.getDest(), &Pipe_Above1.getDest()) || CollisionManager::checkCollision(&o.getDest(), &Pipe_Below1.getDest()) || 
            CollisionManager::checkCollision(&o.getDest(), &Pipe_Above2.getDest()) || CollisionManager::checkCollision(&o.getDest(), &Pipe_Below2.getDest()) || 
            CollisionManager::checkCollision(&o.getDest(), &Pipe_Above3.getDest()) || CollisionManager::checkCollision(&o.getDest(), &Pipe_Below3.getDest())) {
                //SDL_Delay(500);
                //Endgame();
                GameState=false;
        }
        if (CollisionManager::checkCollision(&o.getDest(), &ground1.getDest())){
            //SDL_Delay(500);
            //Endgame();
            GameState=false;
        }

        if (CollisionManager::checkCollision(&o.getDest(), &ground2.getDest())){
            //SDL_Delay(500);
            //Endgame();
            GameState=false;
        }
    }
}

void GameLoop::Render() {
    t1++;
    
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
        p.Render(renderer);
    }
    else if (sb.getBird()==2){
        y.Render(renderer);
    }
    else if (sb.getBird()==3){
        o.Render(renderer);
    }
    
    SDL_RenderPresent(renderer);
}

void GameLoop::Clear() {
    cout<<score.getScore();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
