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

		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Up && key!= 4 || event.key.code == Keyboard::W) { dy = -1; dx = 0; key = 3; }
				else if (event.key.code == Keyboard::Down && key != 3 || event.key.code == Keyboard::S) { dy = 1; dx = 0; key = 4; }
				else if (event.key.code == Keyboard::Left && key != 2 || event.key.code == Keyboard::A) { dx = -1; dy = 0; key = 1; }
				else if (event.key.code == Keyboard::Right && key != 1 || event.key.code == Keyboard::D) { dx = 1; dy = 0; key = 2; }
				else if (event.key.code == Keyboard::X) gameOver = true;
			}
		}

		if (head.x == fruit.x && head.y == fruit.y) {
			nTail++;
			fruit.x = rand() % WIDTH;
			fruit.y = rand() % HEIGHT;
		}
		if (timer > delay) {

			int prevX = tail[0].x, prevY = tail[0].y;
			tail[0].x = head.x;
			tail[0].y = head.y;

			for (int i = 1; i <= nTail; i++) {
				prev2X = tail[i].x;
				prev2Y = tail[i].y;
				tail[i].x = prevX;
				tail[i].y = prevY;
				prevX = prev2X;
				prevY = prev2Y;
			}

			head.x += dx;
			head.y += dy;

			timer = 0;
		}
		if (head.x < 0)
			head.x = WIDTH-1;
		if (head.x > WIDTH-1)
			head.x = 0;
		if (head.y < 0)
			head.y = HEIGHT-1;
		if (head.y > HEIGHT-1)
			head.y = 0;

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
		
		for (int i = 0; i < nTail; i++) {
			if (tail[i].x != 1000 && tail[i].y != 1000) {
				if (i==(nTail-1) && (tail[i].y-tail[i-1].y)==1) {
					spriteTail.setTextureRect(IntRect(54, 36, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if (i == (nTail - 1) && (tail[i].y - tail[i - 1].y) == -1) {
					spriteTail.setTextureRect(IntRect(72, 54, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if (i == (nTail - 1) && (tail[i].x - tail[i - 1].x) == -1) {
					spriteTail.setTextureRect(IntRect(72, 36, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if (i == (nTail - 1) && (tail[i].x - tail[i - 1].x) == 1) {
					spriteTail.setTextureRect(IntRect(54, 54, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i + 1].x) == -1 && (tail[i].y - tail[i - 1].y) == 1) {
					spriteTail.setTextureRect(IntRect(0, 18, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i - 1].x) == -1 && (tail[i].y - tail[i + 1].y) == 1) {
					spriteTail.setTextureRect(IntRect(0, 18, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i - 1].x) == -1 && (tail[i].y - tail[i + 1].y) == -1) {
					spriteTail.setTextureRect(IntRect(0, 0, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i + 1].x) == -1 && (tail[i].y - tail[i - 1].y) == -1) {
					spriteTail.setTextureRect(IntRect(0, 0, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i + 1].x) == 1 && (tail[i].y - tail[i - 1].y) == -1) {
					spriteTail.setTextureRect(IntRect(36, 0, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i - 1].x) == 1 && (tail[i].y - tail[i + 1].y) == -1) {
					spriteTail.setTextureRect(IntRect(36, 0, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i - 1].x) == 1 && (tail[i].y - tail[i + 1].y) == 1) {
					spriteTail.setTextureRect(IntRect(36, 36, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if ((tail[i].x - tail[i + 1].x) == 1 && (tail[i].y - tail[i - 1].y) == 1) {
					spriteTail.setTextureRect(IntRect(36, 36, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if (tail[i].x > tail[i + 1].x || tail[i].x < tail[i + 1].x && tail[i].y == tail[i + 1].y) {
					spriteTail.setTextureRect(IntRect(18, 0, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				else if (tail[i].y > tail[i + 1].y || tail[i].y < tail[i + 1].y && tail[i].x == tail[i + 1].x) {
					spriteTail.setTextureRect(IntRect(36, 18, 18, 18));
					spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
					window.draw(spriteTail);
				}
				
				//else if (i > 0 && (tail[i + 1].x - tail[i].x) == 1 && (tail[i].y > tail[i - 1].y) == 1) {
				//	spriteTail.setTextureRect(IntRect(0, 18, 18, 18));
				//	spriteTail.setPosition(tail[i].x * 18, tail[i].y * 18);
				//	window.draw(spriteTail);
				//}



			}
		}
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