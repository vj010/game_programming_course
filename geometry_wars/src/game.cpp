#include <game.h>
#include <fstream>
#include <SFML/Graphics.hpp>

void Game::sMovement() {}
// void Game::sCollision() {}
// void Game::sUserInput() {}
// void Game::sRender() {}
// void Game::sEnemySpawner() {}

void Game::run()
{
    std::cout << "hello world" << std::endl;
    m_window.create(sf::VideoMode(windowConfig.width, windowConfig.height), "Geometry Wars", sf::Style::Fullscreen);
    m_window.setFramerateLimit(windowConfig.framesPerSecond);
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }
    }

    std::cin.get();
}

void Game::init(const std::string &configFilePath)
{
    std::ifstream fin(configFilePath);
    if (!fin)
    {
        std::cerr << "could'n open config file" << std::endl;
        exit(1);
    }

    std::string propName;

    while (fin >> propName)
    {
        std::cout << "reading: " << propName << std::endl;
        switch (propNameToCode(propName))
        {
        case 1:
            windowConfig = readWindowProps(fin);
            break;

        case 2:
            fontConfig = readTextProps(fin);
            break;

        case 3:
            playerConfig = readPlayerProps(fin);
            break;

        case 4:
            enemyConfig = readEnemyProps(fin);
            break;

        case 5:
            bulletConfig = readBulletProps(fin);
            break;

        default:
            std::cerr << "unknown property in game config" << std ::endl;
            exit(1);
            break;
        }
    }
}

int Game::propNameToCode(const std::string &propName)
{
    if (propName == "Window")
    {
        return 1;
    }

    if (propName == "Font")
    {
        return 2;
    }

    if (propName == "Player")
    {
        return 3;
    }

    if (propName == "Enemy")
    {
        return 4;
    }

    if (propName == "Bullet")
    {
        return 5;
    }
    return 0;
}

WindowConfig Game::readWindowProps(std::ifstream &fin)
{
    int width, height, framesPerSecond, fullScreenMode;
    fin >> width >> height >> framesPerSecond >> fullScreenMode;

    WindowConfig windowConfig = {
        width,
        height,
        framesPerSecond,
        fullScreenMode

    };

    return windowConfig;
}

FontConfig Game::readTextProps(std::ifstream &fin)
{
    std::string filePath;
    int fontSize, fontColorR, fontColorG, fontColorB;
    fin >> filePath >> fontSize >> fontColorR >> fontColorG >> fontColorB;

    FontConfig fontConfig = {
        filePath, fontSize, fontColorR, fontColorG, fontColorB

    };

    return fontConfig;
}

PlayerConfig Game::readPlayerProps(std::ifstream &fin)
{
    int shapeRadius, collisionRadius;
    float speed;
    int fillColorR, fillColorG, fillColorB, outlineColorR, outlineColorG, outlineColorB, outlineThickness, shapeVertices;
    fin >> shapeRadius >>
        collisionRadius >>
        speed >>
        fillColorR >>
        fillColorG >>
        fillColorB >>
        outlineColorR >>
        outlineColorG >>
        outlineColorB >>
        outlineThickness >>
        shapeVertices;

    PlayerConfig playerConfig = {
        shapeRadius,
        collisionRadius,
        speed,
        fillColorR,
        fillColorG,
        fillColorB,
        outlineColorR,
        outlineColorG,
        outlineColorB,
        outlineThickness,
        shapeVertices

    };
    return playerConfig;
}

EnemyConfig Game::readEnemyProps(std::ifstream &fin)
{
    int shapeRadius, collisionRadius;
    float minSpeed, maxSpeed;
    int outlineColorR, outlineColorG, outlineColorB, outlineThickness, minVertices, maxVertices, smallLifeSpan, spawnInterval;
    fin >> shapeRadius >> collisionRadius >> minSpeed >> maxSpeed >> outlineColorR >> outlineColorG >> outlineColorB >> outlineThickness >> minVertices >> maxVertices >> smallLifeSpan >> spawnInterval;

    EnemyConfig enemyConfig = {
        shapeRadius,
        collisionRadius,
        minSpeed,
        maxSpeed,
        outlineColorR,
        outlineColorG,
        outlineColorB,
        outlineThickness,
        minVertices,
        maxVertices,
        smallLifeSpan,
        spawnInterval

    };
    return enemyConfig;
}

BulletConfig Game::readBulletProps(std::ifstream &fin)
{
    int shapeRadius, collisionRadius;
    float speed;
    int fillColorR, fillColorG, fillColorB, outlineColorR, outlineColorG, outlineColorB, outlineThickness, shapeVertices, lifeSpan;

    fin >> shapeRadius >> collisionRadius >> speed >> fillColorR >> fillColorG >> fillColorB >> outlineColorR >> outlineColorG >> outlineColorB >> outlineThickness >> shapeVertices >> lifeSpan;

    BulletConfig bulletConfig = {
        shapeRadius,
        collisionRadius,
        speed,
        fillColorR,
        fillColorG,
        fillColorB,
        outlineColorR,
        outlineColorG,
        outlineColorB,
        outlineThickness,
        shapeVertices,
        lifeSpan

    };

    return bulletConfig;
}
