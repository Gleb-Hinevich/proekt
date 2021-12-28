#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;



struct Coords {
	float x, y;
}fruit, head, tail[100];


int main()
{
	const int WIDTH = 19;
	const int HEIGHT = 19;
	int dx = 0, dy = 0;
	bool gameOver = false;
	bool first = true;
	int fiedl[HEIGHT][WIDTH] = { 0 };
	Clock clock;
	double timer = 0, delay = 0.11;
	int nTail = 4;
	int prev2X, prev2Y;
	//1-left 2-right 3-up 4-down
	int key = 5;

	srand(time(0));
	head.x = (WIDTH - 1) / 2;
	head.y = (HEIGHT - 1) / 2;
	fruit.x = rand() % WIDTH;
	fruit.y = rand() % HEIGHT;

	RenderWindow window(VideoMode(342, 342), "Snake SFML");
	Image snake;
	snake.loadFromFile("D:\\games\\snake_SFML\\snake_SFML\\images\\snhxZ.png");
	snake.createMaskFromColor(Color(255, 255, 255));

	Texture texsture;
	texsture.loadFromImage(snake);
	
	Image fruitImage;
	fruitImage.loadFromFile("D:\\games\\snake_SFML\\snake_SFML\\images\\apple.jpg");
	fruitImage.createMaskFromColor(Color(255, 255, 255));

	Texture apple;
	apple.loadFromImage(fruitImage);

	Sprite sprite(texsture);
	sprite.setTextureRect(IntRect(54, 0, 18, 18));

	Sprite spriteFruit(apple);
	spriteFruit.setTextureRect(IntRect(0, 0, 18, 18));

	Sprite spriteTail(texsture);
	spriteTail.setTextureRect(IntRect(36, 18, 18, 18));

	while (window.isOpen() && !gameOver)
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		
		Event event;
		//1
		//2
		for (int i = 0; i < nTail; i++) {
			if (tail[i].x == head.x && tail[i].y == head.y) {
				for (int j = i; j < nTail; j++) {
					tail[j].x = 1000;
					tail[j].y = 1000;
				}
				nTail = i;
			}
		}

		window.clear(Color::White);

		if (first) {
			sprite.setPosition((WIDTH - 1)/2 * 18, (HEIGHT - 1) / 2 * 18);
			window.draw(sprite);
			first = false;
		}
		
		//3
		spriteFruit.setPosition(fruit.x * 18, fruit.y * 18);
		window.draw(spriteFruit);

		if (dy == -1)
			sprite.setTextureRect(IntRect(54, 0, 18, 18));
		else if (dy == 1)
			sprite.setTextureRect(IntRect(72, 18, 18, 18));
		else if (dx ==-1)
			sprite.setTextureRect(IntRect(54, 18, 18, 18));
		else if (dx == 1)
			sprite.setTextureRect(IntRect(72, 0, 18, 18));



			
			sprite.setPosition(head.x * 18, head.y * 18);
			window.draw(sprite);
			window.display();
	}

	return 0;
}
