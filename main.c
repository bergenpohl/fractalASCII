#include <unistd.h>
#define iterations 64

const double	viewX = -2;
const double	viewY = -2;
const double	viewWidth = 4;
const double	viewHeight = 4;
const int	imageWidth = 200;
const int	imageHeight = 100;
const double	iterX = viewWidth / imageWidth;
const double	iterY = viewHeight / imageHeight;

int		mandelbrot(int y, int x) {
	double	a, bi;
	double	c, di;
	int	res;
	double	tmp;

	a = 0;
	bi = 0;
	c = viewX + (iterX * x);
	di = viewY + (iterY * y);
	res = 0;
	while (a < 2) {
		if (res >= iterations) return (1);
		tmp = a;
		a = a * a + bi * bi * -1 + c;
		bi = tmp * bi * 2 + di;
		++res;
	}
	return (0);
}

int		main(void) {
	char	grid[imageHeight][imageWidth + 1];
	int	x, y;

	y = 0;
	while (y < imageHeight) {
		x = 0;
		while (x < imageWidth) {
			if (mandelbrot(y, x)) grid[y][x] = '*';
			else grid[y][x] = ' ';
			++x;
		}
		grid[y][imageWidth] = '\n';
		++y;
	}
	y = 0;
	while (y < imageHeight) {
		write(1, grid[y], imageWidth + 1);
		++y;
	}
	return (0);
}
