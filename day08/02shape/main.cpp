#include <iostream>
using namespace std;

class Shape {
public:
    Shape(int x, int y) : m_x(x), m_y(y) {}
    virtual void draw() {
        cout << "draw shape(" << m_x << ',' << m_y <<')' << endl;
    }
protected:
    int m_x;
    int m_y;
};

class Rect : public Shape {
public:
    Rect(int x, int y, int width, int height) : Shape(x, y), m_width(width), m_height(height) {}
    void draw() override {
        cout << "draw Rect(" << m_x <<',' << m_y <<',' << m_width << ',' << m_height << ')' << endl;
    }
private:
    int m_width;
    int m_height;
};

class Circle : public Shape {
public:
    Circle(int x, int y, int radius) : Shape(x, y), m_radius(radius) {}
    void draw() override {
        cout << "draw Circle(" << m_x <<',' << m_y << ',' << m_radius << ')' << endl;
    }
private:
    int m_radius;
};

void render(Shape* shapes[]) {
    for (size_t i = 0; shapes[i]; ++i) {
        shapes[i]->draw();
    }
}

int main() {
    Shape* shapes[1024];
    shapes[0] = new Rect(1, 2, 3, 4);
    shapes[1] = new Circle( 5, 6, 7);
    shapes[2] = new Circle( 8, 9, 10);
    shapes[3] = new Rect( 11, 12, 13, 14);
    shapes[4] = new Rect( 15, 16, 17, 18);
    shapes[5] = nullptr;

    render(shapes);
    return 0;
}
