#include "prototype.h"

int mandelbrotSet(double x, double y) {
    double real = x;
    double imag = y;
    int iter = 0;

    while ((real * real + imag * imag) <= 4.0 && iter < ITERATIONS) {
        double real2 = (real * real) - (imag * imag);
        double imag2 = 2 * (real * imag);
        real = real2 + x;
        imag = imag2 + y;
        iter++;
    }

    return iter;
}

sf::Color getColor(int iter) {
    std::vector<sf::Color> palette = {
//            sf::Color(66, 30, 15),
            sf::Color(25, 7, 26),
            sf::Color(9, 1, 47),
            sf::Color(4, 4, 73),
            sf::Color(0, 7, 100),
            sf::Color(12, 44, 138),
            sf::Color(24, 82, 177),
            sf::Color(57, 125, 209),
            sf::Color(134, 181, 229),
            sf::Color(211, 236, 248),
            sf::Color(241, 233, 191),
            sf::Color(248, 201, 95),
            sf::Color(255, 170, 0),
            sf::Color(204, 128, 0),
            sf::Color(153, 87, 0),
            sf::Color(106, 52, 3)
    };

    // Return a color from the palette based on the iteration count
    if (iter == ITERATIONS) {
        return sf::Color::Black; // Set color to black for points inside the set
    } else {
        int index = iter % palette.size();
        return palette[index];
    }
}


void displaySet(sf::RenderWindow &window, double zoom, double offsetX, double offsetY) {
    sf::Image image;
    image.create(WIDTH, HEIGHT, sf::Color::Black);

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            double real = (j - WIDTH / 2.0) * 4.0 / (HEIGHT * zoom) + offsetX;
            double imag = (i - HEIGHT / 2.0) * 4.0 / (HEIGHT * zoom) + offsetY;
            int iter = mandelbrotSet(real, imag);
            sf::Color color = getColor(iter);
            image.setPixel(j, i, color);
        }
    }

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite(texture);

    window.draw(sprite);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mandelbrot Set");
    double zoom = 1.0;
    double offsetX = 0.0;
    double offsetY = 0.0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            switch (event.key.code) {
                case sf::Keyboard::Z:
                    zoom *= 1.2;
                    break;
                case sf::Keyboard::X:
                    zoom /= 1.2;
                    break;
                case sf::Keyboard::Space:
                    ITERATIONS += 10;
                    break;
                case sf::Keyboard::Left:
                    offsetX -= 0.1 / zoom;
                    break;
                case sf::Keyboard::Right:
                    offsetX += 0.1 / zoom;
                    break;
                case sf::Keyboard::Up:
                    offsetY -= 0.1 / zoom;
                    break;
                case sf::Keyboard::Down:
                    offsetY += 0.1 / zoom;
                    break;
                default:
                    break;
            }
        }

        window.clear();
        clock_t start = clock();
        displaySet(window, zoom, offsetX, offsetY);
        clock_t end = clock();

        std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
        std::cout << "Iterations: " << ITERATIONS << "\n";
        std::cout << "Zoom factor: " << zoom << "\n";

        window.display();
    }

    return 0;
}
