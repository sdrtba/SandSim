#include <SFML/Graphics.hpp>
#include <vector>


const int WIDTH = 480;
const int HEIGHT = 640;
const int CELL_SIZE = 4;


class Cell {
private:
	sf::Color color;
	bool empty;
public:
	Cell(sf::Color color, bool empty) {
		this->color = color;
		this->empty = empty;
	}

	void update() {

	}
};

class Sand : Cell {
private:
	sf::Color color = sf::Color::Yellow;
public:
	Sand() : Cell(color, false) {
		
	}
};

class Empty : Cell {
private:
	sf::Color color = sf::Color::Black;
public:
	Empty() : Cell(color, true) {

	}
};

class Grid {
private:
	int width;
	int height;
	std::vector<int> vector;

	void updatePixel(int index) {
		int below = index + width;
		int belowLeft = below - 1;
		int belowRight = (below + 1) % vector.size();

		if (isEmpty(below)) {
			swap(index, below);
		}
		else if (index % width > belowLeft % width && isEmpty(belowLeft)) {
			swap(index, belowLeft);
		}
		else if (index % width < belowRight % width && isEmpty(belowRight)) {
			swap(index, belowRight);
		}
	}

public:
	void initialize(int width, int height) {
		this->width = width;
		this->height = height;
		vector = std::vector<int>(width * height, 0);
	}

	void clear() {
		std::fill(vector.begin(), vector.end(), 0);
	}

	void set(int x, int y, int color) {
		int index = y * width + x;
		if (index >= 0 && index < vector.size()) {
			vector[y * width + x] = color;
		}
	}

	int get(int x, int y) {
		int index = y * width + x;
		if (index >= 0 && index < vector.size()) {
			return vector[y * width + x];
		}
		return -1;
	}

	void swap(int a, int b) {
		int temp = vector[a];
		vector[a] = vector[b];
		vector[b] = temp;
	}

	bool isEmpty(int index) {
		return vector[index] == 0;
	}

	bool isEmpty(int x, int y) {
		return vector[y * width + x] == 0;
	}

	void update() {
		for (int i = vector.size() - width - 1; i > 0; i--) {
			updatePixel(i);
		}
	}
};

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sand");

	Grid grid = Grid();
	grid.initialize(WIDTH / CELL_SIZE, HEIGHT / CELL_SIZE);

	bool mousePressed = false;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == event.MouseButtonPressed) { mousePressed = true; }
			else if (event.type == event.MouseButtonReleased) { mousePressed = false; }
		}

		if (mousePressed) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			int x = mousePos.x;
			int y = mousePos.y;
			if (x > WIDTH - 1) { x = WIDTH - 1; }
			else if (x < 0) { x = 0; }
			grid.set(x / CELL_SIZE, y / CELL_SIZE, 1);
		}

		grid.update();

		window.clear();

		for (int y = 0; y < HEIGHT / CELL_SIZE; ++y) {
			for (int x = 0; x < WIDTH / CELL_SIZE; ++x) {
				if (!grid.isEmpty(x, y)) {
					sf::RectangleShape cellShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
					cellShape.setPosition(x * CELL_SIZE, y * CELL_SIZE);
					cellShape.setFillColor(sf::Color::Yellow);
					window.draw(cellShape);
				}
			}
		}

		window.display();
	}

	return 0;
}