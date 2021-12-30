delay = 0.33;
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
	head.x = WIDTH - 1;
if (head.x > WIDTH - 1)
head.x = 0;
if (head.y < 0)
	head.y = HEIGHT - 1;
if (head.y > HEIGHT - 1)
head.y = 0;
