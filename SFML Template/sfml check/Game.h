#pragma once
class Game
{
public:
	Game();   //constructor
	~Game();  //destructor

	void Update();

	//structuur van de functie:
	//return type, functie naam, ( argumenten );
	bool GetIsRunning();

private:
	bool isRunning = true;
protected:

};

