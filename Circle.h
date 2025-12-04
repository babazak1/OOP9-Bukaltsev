#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle : public Shape {
private:
    double radius;  

public:
    Circle(double x = 0, double y = 0, double r = 1.0,
        double angle = 0, double scale = 1.0);

    void show() override;
    void hide() override;
    void rotate(double degrees) override;
    void move(double dx, double dy) override;

    void setRadius(double r);
    double getActualRadius() const;
    double getBaseRadius() const;
    double getArea() const;
    double getCircumference() const;

    void printInfo() const override;
    ~Circle();
};
#endif
