#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
protected:
    double centerX, centerY;  
    double rotationAngle;      
    double scaleFactor;        
    bool isVisible;            

public:
    Shape(double x = 0, double y = 0, double angle = 0, double scale = 1.0);

    virtual void show() = 0;                     
    virtual void hide() = 0;                     
    virtual void rotate(double degrees) = 0;     
    virtual void move(double dx, double dy) = 0;

    virtual void setPosition(double x, double y);
    virtual void setScale(double scale);
    virtual void printInfo() const;

    virtual ~Shape();

protected:
    void setRotation(double angle);
    void setVisibility(bool visible);
    double getCenterX() const;
    double getCenterY() const;
    double getRotation() const;
    double getScale() const;
    bool getVisibility() const;
};
#endif
