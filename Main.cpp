#include "circle.h"
#include <iostream>
#include <cmath>
#include <locale>
#include <windows.h>

using namespace std;

void setupWindowsConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    setlocale(LC_ALL, "Ukrainian");
}

Shape::Shape(double x, double y, double angle, double scale)
    : centerX(x), centerY(y), rotationAngle(angle),
    scaleFactor(scale), isVisible(false) {
}

void Shape::setPosition(double x, double y) {
    centerX = x;
    centerY = y;
}

void Shape::setScale(double scale) {
    if (scale > 0) {
        scaleFactor = scale;
    }
}

void Shape::printInfo() const {
    cout << "Центр: (" << centerX << ", " << centerY << ")" << endl;
    cout << "Кут повороту: " << rotationAngle << "°" << endl;
    cout << "Масштаб: " << scaleFactor << endl;
    cout << "Видимість: " << (isVisible ? "так" : "ні") << endl;
}

Shape::~Shape() {}

void Shape::setRotation(double angle) {
    rotationAngle = fmod(angle, 360.0);
    if (rotationAngle < 0) {
        rotationAngle += 360.0;
    }
}

void Shape::setVisibility(bool visible) {
    isVisible = visible;
}

double Shape::getCenterX() const { return centerX; }
double Shape::getCenterY() const { return centerY; }
double Shape::getRotation() const { return rotationAngle; }
double Shape::getScale() const { return scaleFactor; }
bool Shape::getVisibility() const { return isVisible; }

Circle::Circle(double x, double y, double r, double angle, double scale)
    : Shape(x, y, angle, scale), radius(r) {
    cout << "Створено коло з радіусом " << r << " у точці (" << x << ", " << y << ")" << endl;
}

void Circle::show() {
    if (!getVisibility()) {
        cout << "Показую коло:" << endl;
        cout << "  Центр: (" << getCenterX() << ", " << getCenterY() << ")" << endl;
        cout << "  Радіус: " << getActualRadius() << " (базовий: " << radius << ")" << endl;
        cout << "  Масштаб: " << getScale() << endl;
        cout << "  Кут повороту: " << getRotation() << "°" << endl;
        setVisibility(true);
    }
    else {
        cout << "Коло вже показано" << endl;
    }
}

void Circle::hide() {
    if (getVisibility()) {
        cout << "Ховаю коло з центра (" << getCenterX() << ", " << getCenterY() << ")" << endl;
        setVisibility(false);
    }
    else {
        cout << "Коло вже приховано" << endl;
    }
}

void Circle::rotate(double degrees) {
    cout << "Повертаю коло на " << degrees << "°" << endl;
    cout << "  Старий кут: " << getRotation() << "°" << endl;
    setRotation(getRotation() + degrees);
    cout << "  Новий кут: " << getRotation() << "°" << endl;

    if (getVisibility()) {
        cout << "Коло оновлено на екрані" << endl;
    }
}

void Circle::move(double dx, double dy) {
    cout << "Переміщую коло на вектор (" << dx << ", " << dy << ")" << endl;
    cout << "  Стара позиція: (" << getCenterX() << ", " << getCenterY() << ")" << endl;
    setPosition(getCenterX() + dx, getCenterY() + dy);
    cout << "  Нова позиція: (" << getCenterX() << ", " << getCenterY() << ")" << endl;

    if (getVisibility()) {
        cout << "Коло перемальовано у новій позиції" << endl;
    }
}

void Circle::setRadius(double r) {
    if (r > 0) {
        radius = r;
        cout << "Радіус кола змінено на " << r << endl;
        if (getVisibility()) {
            cout << "Коло перемальовано з новим радіусом" << endl;
        }
    }
}

double Circle::getActualRadius() const {
    return radius * getScale();
}

double Circle::getBaseRadius() const {
    return radius;
}

double Circle::getArea() const {
    double actualRadius = getActualRadius();
    return M_PI * actualRadius * actualRadius;
}

double Circle::getCircumference() const {
    return 2 * M_PI * getActualRadius();
}

void Circle::printInfo() const {
    Shape::printInfo();
    cout << "Базовий радіус: " << radius << endl;
    cout << "Фактичний радіус: " << getActualRadius() << endl;
    cout << "Площа: " << getArea() << endl;
    cout << "Довжина кола: " << getCircumference() << endl;
}

Circle::~Circle() {
    cout << "Коло знищено" << endl;
}

int main() {
    setupWindowsConsole();

    Circle circle(5, 5, 3.0);

    cout << endl << "1. Початковий стан:" << endl;
    circle.printInfo();

    cout << endl << "2. Показ кола:" << endl;
    circle.show();

    cout << endl << "3. Поворот кола на 45 градусів:" << endl;
    circle.rotate(45);

    cout << endl << "4. Переміщення кола:" << endl;
    circle.move(2, -1);

    cout << endl << "5. Зміна масштабу:" << endl;
    circle.setScale(1.5);
    circle.printInfo();

    cout << endl << "6. Зміна радіусу:" << endl;
    circle.setRadius(4.0);

    cout << endl << "7. Приховування кола:" << endl;
    circle.hide();

    cout << endl << "8. Повторний показ:" << endl;
    circle.show();

    cout << endl << "9. Робота через покажчик на базовий клас:" << endl;
    Shape* shapePtr = &circle;
    shapePtr->printInfo();

    cout << endl << "10. Переміщення через базовий клас:" << endl;
    shapePtr->move(-3, 2);

    return 0;
}
