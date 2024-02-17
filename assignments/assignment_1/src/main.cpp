#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include <filesystem>
#include <math.h>
class WindowProps
{
public:
    int width = 0;
    int height = 0;
    WindowProps() {}
    WindowProps(int x, int y)
        : width(x), height(y)
    {
    }

    void printProperties()
    {
        std::cout << "width: " << width << std::endl;
        std::cout << "height: " << height << std::endl;
    }
};

class ShapeProperties
{
public:
    std ::string name;
    float posX = 0.0f;
    float posY = 0.0f;
    float speedX = 0.0f;
    float speedY = 0.0f;
    int colorR = 0;
    int colorG = 0;
    int colorB = 0;
    ShapeProperties(const std::string &shapeName, float initialPosX, float initialPosY, float initialSpeedX,
                    float initialSpeedY, int colorCodeR, int colorCodeG, int colorCodeB)
        : name(shapeName), posX(initialPosX), posY(initialPosY), speedX(initialSpeedX), speedY(initialSpeedY),
          colorR(colorCodeR), colorG(colorCodeG), colorB(colorCodeB)
    {
    }
};

class TextProperties
{
public:
    std::string fileName;
    int size = 0;
    int colorR = 0;
    int colorG = 0;
    int colorB = 0;
    TextProperties() {}
    TextProperties(std::string filePath, int textSize, int colorCodeR, int colorCodeG, int colorCodeB)
        : fileName(std::move(filePath)), size(textSize), colorR(colorCodeR), colorG(colorCodeG), colorB(colorCodeB)
    {
    }

    void printProperties()
    {
        std::cout << "filePath: " << fileName << std::endl;
        std::cout << "size: " << size << std::endl;
        std::cout << "colorR: " << colorR << std::endl;
        std::cout << "colorG: " << colorG << std::endl;
        std::cout << "colorB: " << colorB << std::endl;
    }
};

class RectangleProperties : public ShapeProperties
{
public:
    float width = 0;
    float height = 0;
    RectangleProperties(std::string name, float initialPosX, float initialPosY, float initialSpeedX,
                        float initialSpeedY, int colorCodeR, int colorCodeG, int colorCodeB, float rectWidth, float rectHeight)
        : ShapeProperties(std::move(name), initialPosX, initialPosY, initialSpeedX, initialSpeedY, colorCodeR, colorCodeG, colorCodeB),
          width(rectWidth), height(rectHeight)
    {
    }

    void printProperties()
    {
        std::cout << "name:" << ShapeProperties ::name << std::endl;
        std::cout << "initialPosX:" << ShapeProperties::posX << std::endl;
        std::cout << "initialPosY:" << ShapeProperties::posY << std::endl;
        std::cout << "initialSpeedX:" << ShapeProperties::speedX << std::endl;
        std::cout << "initialSpeedY:" << ShapeProperties ::speedY << std::endl;
        std::cout << "colorCodeR:" << ShapeProperties ::colorR << std::endl;
        std::cout << "colorCodeG:" << ShapeProperties ::colorG << std::endl;
        std::cout << "colorCodeB:" << ShapeProperties ::colorB << std::endl;
        std::cout << "width:" << width << std::endl;
        std::cout << "height:" << height << std::endl;
    }
};

class CircleProperties : public ShapeProperties
{
public:
    float radius = 0;

    CircleProperties(std::string name, float initialPosX, float initialPosY, float initialSpeedX,
                     float initialSpeedY, int colorCodeR, int colorCodeG, int colorCodeB, int circRadius)
        : ShapeProperties(std::move(name), initialPosX, initialPosY, initialSpeedX, initialSpeedY, colorCodeR, colorCodeG, colorCodeB),
          radius(circRadius)
    {
    }

    void printProperties()
    {
        std::cout << "name:" << ShapeProperties ::name << std::endl;
        std::cout << "initialPosX:" << ShapeProperties::posX << std::endl;
        std::cout << "initialPosY:" << ShapeProperties::posY << std::endl;
        std::cout << "initialSpeedX:" << ShapeProperties::speedX << std::endl;
        std::cout << "initialSpeedY:" << ShapeProperties ::speedY << std::endl;
        std::cout << "colorCodeR:" << ShapeProperties ::colorR << std::endl;
        std::cout << "colorCodeG:" << ShapeProperties ::colorG << std::endl;
        std::cout << "colorCodeB:" << ShapeProperties ::colorB << std::endl;
        std::cout << "radius:" << radius << std::endl;
    }
};

class GameProperties
{
private:
    static int propNameToCode(std::string propName)
    {
        std::transform(propName.begin(), propName.end(), propName.begin(), ::tolower);

        if (propName == "window")
        {
            return 0;
        }

        if (propName == "font")
        {
            return 1;
        }
        if (propName == "rectangle")
        {
            return 2;
        }
        if (propName == "circle")
        {
            return 3;
        }

        return -1;
    }

    static std::shared_ptr<WindowProps> readWindowProps(std::ifstream &fin)
    {
        int width, height;
        fin >> width >> height;
        return std::make_shared<WindowProps>(width, height);
    }

    static std::shared_ptr<TextProperties> readTextProps(std::ifstream &fin)
    {
        std::string fileName;
        int size, colorR, colorG, colorB;
        fin >> fileName >> size >> colorR >> colorG >> colorB;
        return std::make_shared<TextProperties>(std::move(fileName), size, colorR, colorG, colorB);
    }

    static std::shared_ptr<RectangleProperties> readRectangleProps(std::ifstream &fin)
    {
        std::string name;
        float initialPosX, initialPosY, initialSpeedX, initialSpeedY, rectWidth, rectHeight;
        int colorCodeR, colorCodeG, colorCodeB;
        fin >> name >> initialPosX >> initialPosY >> initialSpeedX >>
            initialSpeedY >> colorCodeR >> colorCodeG >> colorCodeB >> rectWidth >> rectHeight;
        return std::make_shared<RectangleProperties>(std::move(name), initialPosX, initialPosY, initialSpeedX, initialSpeedY, colorCodeR, colorCodeG, colorCodeB, rectWidth, rectHeight);
    }

    static std::shared_ptr<CircleProperties> readCircleProps(std::ifstream &fin)
    {
        std::string name;
        float initialPosX, initialPosY, initialSpeedX, initialSpeedY, radius;
        int colorCodeR, colorCodeG, colorCodeB;
        fin >> name >> initialPosX >> initialPosY >> initialSpeedX >>
            initialSpeedY >> colorCodeR >> colorCodeG >> colorCodeB >> radius;
        return std::make_shared<CircleProperties>(std::move(name), initialPosX, initialPosY, initialSpeedX, initialSpeedY, colorCodeR, colorCodeG, colorCodeB, radius);
    }

public:
    std::shared_ptr<WindowProps> windowProps = std::make_shared<WindowProps>();
    std::shared_ptr<TextProperties> textProps = std::make_shared<TextProperties>();
    std::vector<std::shared_ptr<RectangleProperties>> rectangleProps;
    std::vector<std::shared_ptr<CircleProperties>> circleProps;

    GameProperties() {}

    static std::shared_ptr<GameProperties> loadPropertiesFromConfigFile(const std::string &fileName)
    {
        std::cout << "reading config file" << fileName << std::endl;
        std::shared_ptr<GameProperties> props = std::make_shared<GameProperties>();
        std::ifstream fin(fileName);
        std::string propName;
        if (fin.is_open())
        {
            std::cout << "file stream is open" << std::endl;
        }
        else
        {
            std::cout << "file stream is close" << std::endl;
            return nullptr;
        }

        while (fin >> propName)
        {
            std::cout << "reading: " << propName << std::endl;
            switch (propNameToCode(propName))
            {
            case 0:
                props->windowProps = readWindowProps(fin);
                break;

            case 1:
                props->textProps = readTextProps(fin);
                break;

            case 2:
                props->rectangleProps.push_back(readRectangleProps(fin));
                break;

            case 3:
                props->circleProps.push_back(readCircleProps(fin));
                break;

            default:
                std::cout << "data not found" << std ::endl;
                break;
            }
        }

        fin.close();

        return props;
    }
};

class MovingShape
{
public:
    std::shared_ptr<sf::Shape> shape;
    float speedX = 0.0f;
    float speedY = 0.0f;
    std::shared_ptr<sf::Text> text;

    MovingShape(std::shared_ptr<sf::Shape> sfmlShape, float movingSpeedX, float movingSpeedY, std::shared_ptr<sf::Text> shapeText)
        : shape(sfmlShape), speedX(movingSpeedX), speedY(movingSpeedY), text(shapeText)
    {
        auto shapeBounds = shape->getLocalBounds();
        auto shapePos = shape->getPosition();
        auto textBounds = text->getLocalBounds();
        float textPosY = shapePos.y + (shapeBounds.height) / 2 - 0.55 * text->getCharacterSize();
        float textPosX = shapePos.x + (shapeBounds.width) / 2 - 0.55 * textBounds.width;
        std::cout << "textHeight:" << textPosY << " textWidth:" << textPosX << std::endl;
        text->setPosition(sf::Vector2f(textPosX, textPosY));
    }

    bool detectColisionWithBoundaryX(float minPosX, float maxPosX)
    {
        auto bounds = shape->getLocalBounds();
        auto currentPos = shape->getPosition();
        if (currentPos.x <= minPosX || currentPos.x + bounds.width >= maxPosX)
            return true;

        return false;
    }

    bool detectColisionWithBoundaryY(float minPosY, float maxPosY)
    {
        auto bounds = shape->getLocalBounds();
        auto currentPos = shape->getPosition();
        if (currentPos.y <= minPosY || currentPos.y + bounds.height >= maxPosY)
            return true;

        return false;
    }

    void reverseSpeedX()
    {
        speedX = -1 * speedX;
    }

    void reverseSpeedY()
    {
        speedY = -1 * speedY;
    }

    void moveShape()
    {
        auto currentPos = shape->getPosition();
        shape->move(speedX, speedY);
        text->move(speedX, speedY);
    }
};

int main()
{
    std::shared_ptr<GameProperties> gameProps = GameProperties::loadPropertiesFromConfigFile("config.txt");
    if (gameProps == nullptr)
    {
        std::cerr << "could not load game config. The config file may be corrupted" << std::endl;
        exit(-1);
    }
    sf::Font font;
    if (!font.loadFromFile(gameProps->textProps->fileName))
    {
        std::cerr << "could not load game fonts" << std::endl;
        exit(-1);
    }

    int wWidth = gameProps->windowProps->width;
    int wHeight = gameProps->windowProps->height;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Sfml test");
    window.setFramerateLimit(60);

    std::vector<std::shared_ptr<MovingShape>> movingShapes;
    for (std::shared_ptr<CircleProperties> circleProp : gameProps->circleProps)
    {
        std::cout << "pushing a circle" << std::endl;
        std::shared_ptr<sf::Shape> circle = std::make_shared<sf::CircleShape>(circleProp->radius);
        circle->setFillColor(sf::Color(circleProp->colorR, circleProp->colorG, circleProp->colorB));
        circle->setPosition(sf::Vector2f(circleProp->posX, circleProp->posY));

        std::shared_ptr<sf::Text> shapeText = std::make_shared<sf::Text>();
        shapeText->setCharacterSize(gameProps->textProps->size);
        shapeText->setString(circleProp->name);
        shapeText->setFillColor(sf::Color(gameProps->textProps->colorR, gameProps->textProps->colorG, gameProps->textProps->colorB));
        shapeText->setFont(font);

        std::shared_ptr<MovingShape>
            movingCircle = std::make_shared<MovingShape>(circle, circleProp->speedX, circleProp->speedY, shapeText);
        movingShapes.push_back(movingCircle);
    }

    for (std::shared_ptr<RectangleProperties> rectangleProp : gameProps->rectangleProps)
    {
        std::cout << "pushing a rectangle" << std::endl;
        std::shared_ptr<sf::Shape> rectangle = std::make_shared<sf::RectangleShape>(sf::Vector2f(rectangleProp->width, rectangleProp->height));
        rectangle->setFillColor(sf::Color(rectangleProp->colorR, rectangleProp->colorG, rectangleProp->colorB));
        rectangle->setPosition(sf::Vector2f(rectangleProp->posX, rectangleProp->posY));

        std::shared_ptr<sf::Text> shapeText = std::make_shared<sf::Text>();
        shapeText->setCharacterSize(gameProps->textProps->size);
        shapeText->setString(rectangleProp->name);
        shapeText->setFillColor(sf::Color(gameProps->textProps->colorR, gameProps->textProps->colorG, gameProps->textProps->colorB));
        shapeText->setFont(font);

        std::shared_ptr<MovingShape> movingRectangle = std::make_shared<MovingShape>(rectangle, rectangleProp->speedX, rectangleProp->speedY, shapeText);
        movingShapes.push_back(movingRectangle);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        for (auto movingShape : movingShapes)
        {
            if (movingShape->detectColisionWithBoundaryX(0, gameProps->windowProps->width))
            {
                movingShape->reverseSpeedX();
            }

            if (movingShape->detectColisionWithBoundaryY(0, gameProps->windowProps->height))
            {
                movingShape->reverseSpeedY();
            }

            movingShape->moveShape();
        }

        window.clear(sf::Color::Black);

        for (auto movingShape : movingShapes)
        {
            window.draw(*(movingShape->shape));
            window.draw(*(movingShape->text));
        }

        window.display();
    }
    return 0;
}
