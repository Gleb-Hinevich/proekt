for (int i = 0; i < nTail; i++) {
	if (tail[i].x != 1000 && tail[i].y != 1000) {
		if (i == (nTail - 1) && (tail[i].y - tail[i - 1].y) == 1) {
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
	}
}
