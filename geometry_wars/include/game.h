#ifndef gameh
#define gameh
#include <iostream>
#include <SFML/Graphics.hpp>
#include <utility>
#include <memory>
#include <fstream>
#include "imgui.h"
#include "imgui-SFML.h"

struct WindowConfig
{
    int width;
    int height;
    int framesPerSecond;
    int fullScreenMode;
};
struct FontConfig
{
    std::string filePath;
    int fontSize;
    int fontColorR;
    int fontColorG;
    int fontColorB;
};

struct PlayerConfig
{
    int shapeRadius;
    int collisionRadius;
    float speed;
    int fillColorR;
    int fillColorG;
    int fillColorB;
    int outlineColorR;
    int outlineColorG;
    int outlineColorB;
    int outlineThickness;
    int shapeVertices;
};

struct EnemyConfig
{
    int shapeRadius;
    int collisionRadius;
    float minSpeed;
    float maxSpeed;
    int outlineColorR;
    int outlineColorG;
    int outlineColorB;
    int outlineThickness;
    int minVertices;
    int maxVertices;
    int smallLifeSpan;
    int spawnInterval;
};

struct BulletConfig
{
    int shapeRadius;
    int collisionRadius;
    float speed;
    int fillColorR;
    int fillColorG;
    int fillColorB;
    int outlineColorR;
    int outlineColorG;
    int outlineColorB;
    int outlineThickness;
    int shapeVertices;
    int lifeSpan;
};
class Game
{
    sf::RenderWindow m_window;

    WindowConfig windowConfig;
    FontConfig fontConfig;
    PlayerConfig playerConfig;
    EnemyConfig enemyConfig;
    BulletConfig bulletConfig;

    void sMovement();
    // void sCollision();
    // void sUserInput();
    // void sRender();
    // void sEnemySpawner();

    int propNameToCode(const std::string &propName);
    WindowConfig readWindowProps(std::ifstream &fin);
    FontConfig readTextProps(std::ifstream &fin);
    PlayerConfig readPlayerProps(std::ifstream &fin);
    EnemyConfig readEnemyProps(std::ifstream &fin);
    BulletConfig readBulletProps(std::ifstream &fin);

public:
    void run();
    void init(const std::string &configFilePath);
};

#endif
