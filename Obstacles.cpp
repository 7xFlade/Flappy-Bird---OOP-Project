#include "Obstacles.hpp"

void Obstacles::Render(SDL_Renderer* ren){
    SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

//updating
bool Obstacles::Pipe_Above1Update(int incY, int &score)
{   if (score<=1500){
		this->incY1 = incY;
		if (pipeDistance1 <= -100)
		{
			pipeDistance1 += 900;
			//score++;
			return true;
		}
		else
		{
			pipeDistance1-=3;
			setSource(0, 0, 52,320);
			setDest(pipeDistance1, -200 + this->incY1, 52,320);
			return false;
		}
	}
	else if(score>1500 && score<=3000){
		this->incY1 = incY;
		if (pipeDistance1 <= -100)
		{
			pipeDistance1 += 900;
			//score++;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance1-=4;
			setSource(0, 0, 52,320);
			setDest(pipeDistance1, -200 + this->incY1, 52,320);
			return false;
		}
	}
	else{
		this->incY1 = incY;
		if (pipeDistance1 <= -100)
		{
			pipeDistance1 += 900;
			//score++;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance1-=5;
			setSource(0, 0, 52,320);
			setDest(pipeDistance1, -200 + this->incY1, 52,320);
			return false;
		}
	}
}

bool Obstacles::Pipe_Below1Update(int incY, int &score)
{	if (score<=1500){
		this->incY1 = incY;
		if (pipeDistance1 <= -100)
		{
			pipeDistance1 += 900;
			return true;
		}
		else
		{
			pipeDistance1-=3;
			setSource(0, 0, 52,320);
			setDest(pipeDistance1, 350 + this->incY1,52,320);
			return false;
		}
	}
	else if(score>1500 && score<=3000){
		this->incY1 = incY;
		if (pipeDistance1 <= -100)
		{
			pipeDistance1 += 900;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance1-=4;
			setSource(0, 0, 52,320);
			setDest(pipeDistance1, 350 + this->incY1,52,320);
			return false;
		}
	}
	else{
		this->incY1 = incY;
		if (pipeDistance1 <= -100)
		{
			pipeDistance1 += 900;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance1-=5;
			setSource(0, 0, 52,320);
			setDest(pipeDistance1, 350 + this->incY1,52,320);
			return false;
		}
	}
}



bool Obstacles::Pipe_Above2Update(int incY, int &score)
{
	if (score<=1500){
		this->incY1 = incY;
		if (pipeDistance2 <= -100)
		{
			pipeDistance2 += 900;
			//score++;
			return true;
		}
		else
		{
			pipeDistance2-=3;
			setSource(0, 0, 52,320);
			setDest(pipeDistance2, -200 + this->incY1, 52,320);
			return false;
		}
	}
	else if(score>1500 && score<=3000){
		this->incY1 = incY;
		if (pipeDistance2 <= -100)
		{
			pipeDistance2 += 900;
			//score++;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance2-=4;
			setSource(0, 0, 52,320);
			setDest(pipeDistance2, -200 + this->incY1, 52,320);
			return false;
		}
	}
	else{
		this->incY1 = incY;
		if (pipeDistance2 <= -100)
		{
			pipeDistance2 += 900;
			//score++;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance2-=5;
			setSource(0, 0, 52,320);
			setDest(pipeDistance2, -200 + this->incY1, 52,320);
			return false;
		}
	}
}

bool Obstacles::Pipe_Below2Update(int incY, int &score)
{
	if (score<=1500){
		this->incY1 = incY;
		if (pipeDistance2 <= -100)
		{
			pipeDistance2 += 900;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance2-=3;
			setSource(0, 0, 52,320);
			setDest(pipeDistance2, 350 + this->incY1,52,320);
			return false;
		}
	}
	else if(score>1500 && score<=3000){
		this->incY1 = incY;
		if (pipeDistance2 <= -100)
		{
			pipeDistance2 += 900;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance2-=4;
			setSource(0, 0, 52,320);
			setDest(pipeDistance2, 350 + this->incY1,52,320);
			return false;
		}
	}
	else{
		this->incY1 = incY;
		if (pipeDistance2 <= -100)
		{
			pipeDistance2 += 900;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance2-=5;
			setSource(0, 0, 52,320);
			setDest(pipeDistance2, 350 + this->incY1,52,320);
			return false;
		}
	}
}

bool Obstacles::Pipe_Above3Update(int incY, int &score)
{
	if (score<=1500){
		this->incY1 = incY;
		if (pipeDistance3 <= -100)
		{
			pipeDistance3 += 900;
			//score++;
			return true;
		}
		else
		{
			pipeDistance3-=3;
			setSource(0, 0, 52,320);
			setDest(pipeDistance3, -200 + this->incY1, 52,320);
			return false;
		}
	}
	else if(score>1500 && score<=3000){
		this->incY1 = incY;
		if (pipeDistance3 <= -100)
		{
			pipeDistance3 += 900;
			//score++;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance3-=4;
			setSource(0, 0, 52,320);
			setDest(pipeDistance3, -200 + this->incY1, 52,320);
			return false;
		}
	}
	else{
		this->incY1 = incY;
		if (pipeDistance3 <= -100)
		{
			pipeDistance3 += 900;
			//score++;
			return true;
		}
		else
		{	//cout<<sc.getScore();
			pipeDistance3-=5;
			setSource(0, 0, 52,320);
			setDest(pipeDistance3, -200 + this->incY1, 52,320);
			return false;
		}
	}
}

bool Obstacles::Pipe_Below3Update(int incY, int &score)
{
	if (score<=1500){
		this->incY1 = incY;
		if (pipeDistance3 <= -100)
		{
			pipeDistance3 += 900;
			return true;
		}
		else
		{
			pipeDistance3-=3;
			setSource(0, 0, 52,320);
			setDest(pipeDistance3, 350 + this->incY1,52,320);
			return false;
		}
	}
	else if(score>1500 && score<=3000){
		//cout<<sc.getScore();
		this->incY1 = incY;
		if (pipeDistance3 <= -100)
		{
			pipeDistance3 += 900;
			return true;
		}
		else
		{
			pipeDistance3-=4;
			setSource(0, 0, 52,320);
			setDest(pipeDistance3, 350 + this->incY1,52,320);
			return false;
		}
	}
	else{
		//cout<<sc.getScore();
		this->incY1 = incY;
		if (pipeDistance3 <= -100)
		{
			pipeDistance3 += 900;
			return true;
		}
		else
		{
			pipeDistance3-=5;
			setSource(0, 0, 52,320);
			setDest(pipeDistance3, 350 + this->incY1,52,320);
			return false;
		}
	}
}

int Obstacles::getPipe1Y() const
{
	return 300 + this->incY1;
}

int Obstacles::getPipe1X() const
{
	return pipeDistance1;
}

int Obstacles::getPipe2Y() const
{
	return 300 + this->incY2;
}

int Obstacles::getPipe2X() const
{
	return pipeDistance2;
}

int Obstacles::getPipe3Y() const
{
	return 300 + this->incY3;
}

int Obstacles::getPipe3X() const
{
	return pipeDistance3;
}

void Obstacles::Reset()
{
	pipeDistance1 = 700;
	pipeDistance2 = 900;
	pipeDistance3 = 1100;
	incY1 = 0;
	incY2 = 0;
	incY3 = 0;
}
