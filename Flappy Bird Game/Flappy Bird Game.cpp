#include <iostream>
#include <string>
#include<list>
using namespace std;
#include "olcConsoleGameEngine.h"
class FlappyBird : public olcConsoleGameEngine {

private:
	//bird components
	float acceleration;
	float velocity;
	float position;
	float gravity;

	//game logic components
	float obstaclewidth;
	list<int> obstacle;
	float levelposition;
	bool collision;
	int attemptcount;
	int score;
	int highscore;
	bool reset;
public:
	FlappyBird() {
		 acceleration = 0.0f;
		 velocity = 0.0f;
		 position = 0.0f;
		 gravity = 100.0f;
		 levelposition = 0.0f;
		 collision = false;
		 attemptcount = 0;
		 score = 0;
		 highscore = 0;
		 reset = false;
	}
protected:
	bool OnUserCreate() {
		obstacle = { 0,0,0,0 };
		obstaclewidth = (float)ScreenWidth() / (float)obstacle.size() - 1;
		reset = true;
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) {
		//Game Logic
		if (reset) {
			score = 0;
			obstacle = { 0,0,0,0 };
			reset = false;
			collision = false;
			acceleration = 0.0f;
			position = ScreenHeight() / 2.0f;
			velocity = 0.0f;
			attemptcount++;
		}
		if (collision) {
			DrawString(ScreenWidth() / 2.5, ScreenHeight() / 2.5, L"TRY AGAIN");
			if (m_keys[VK_SPACE].bReleased) {
				reset = true;
				Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

			}
		}
		else {

			if (m_keys[VK_SPACE].bPressed) {
				acceleration = 0.0f;
				velocity = -gravity / 5.0f;//minus sign is to move up beacuse in graph subtracting in y axis will make line move up and since this console is in x y plane we implement this graph logic
				score++;
				if (score > highscore) {
					highscore = score;
				}
			}
			else {
				acceleration += gravity * fElapsedTime;//from law of motion :a=gt
				if (acceleration > gravity) {
					acceleration = gravity;
				}
				velocity += acceleration * fElapsedTime;//from law of motion :v=at;
			}
			position += velocity * fElapsedTime;//from law of motion :p=vt
			levelposition += 16.0f * fElapsedTime;//this determines how fast game moves
			if (levelposition > obstaclewidth) {//obstacle width if screen width is 160 then it 53.33 which means after every two section it will do this
				levelposition -= obstaclewidth;//this will move back to it starting position
				obstacle.pop_front();
				int i = rand() % (ScreenHeight() - 35) + 20;//we can change this to change gap of obstacle
				if (i <= 10) { i = 0; }
				obstacle.push_back(i);
			}
			Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');//this is to clear screen per frame or on buffer
			int nobstacles = 0;
			for (list<int>::iterator it = obstacle.begin(); it != obstacle.end(); ++it) {
				int k = *it;
				if (k != 0) {
					Fill(nobstacles * obstaclewidth + 10 - levelposition, ScreenHeight() - k, nobstacles * obstaclewidth + 20 - levelposition, ScreenHeight(), PIXEL_SOLID, FG_GREEN);
					Fill(nobstacles * obstaclewidth + 10 - levelposition, 0, nobstacles * obstaclewidth + 20 - levelposition, ScreenHeight() - k - 15, PIXEL_SOLID, FG_GREEN);
				}
				nobstacles++;
			}
			int bird_on_X = (int)(ScreenWidth() / 3.0f);
			// Collision Detection
			collision = position < 2 || position > ScreenHeight() - 2 ||
				m_bufScreen[(int)(position + 0) * ScreenWidth() + bird_on_X].Char.UnicodeChar != L' ' ||
				m_bufScreen[(int)(position + 1) * ScreenWidth() + bird_on_X].Char.UnicodeChar != L' ' ||
				m_bufScreen[(int)(position + 0) * ScreenWidth() + bird_on_X + 6].Char.UnicodeChar != L' ' ||//this is to check the face if only face is collided when moving down
				m_bufScreen[(int)(position + 1) * ScreenWidth() + bird_on_X + 6].Char.UnicodeChar != L' ';//this is to check the face if only face is collided when moving up
			//bird
			if (velocity > 0) {
				DrawString(bird_on_X, position + 0, L"////");
				DrawString(bird_on_X, position + 1, L"<//////O>");
			}
			else {
				DrawString(bird_on_X, position + 0, L"<//////O>");
				DrawString(bird_on_X, position + 1, L"////");
			}
			DrawString(1, 1, L"Attempt: " + to_wstring(attemptcount) + L" Score: " + to_wstring(score) + L" High Score: " + to_wstring(highscore));
		}
		return true;
	}
};
int main() {
	FlappyBird game;
	game.ConstructConsole(160, 48, 16, 16);//(120,60,11,11)
	game.Start();
}