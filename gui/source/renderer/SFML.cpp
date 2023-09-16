/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SFML
*/

#include "SFML.hpp"

zappy::TextureData::TextureData(sf::Texture &__texture, const std::string &__path)
{
    this->texture = __texture;
    this->path = __path;
}

zappy::TextureData::TextureData(const zappy::TextureData &__data)
{
    this->texture = __data.texture;
    this->path = __data.path;
}

zappy::SFML::SFML(int width, int height, std::string machine)
{
    this->width = width;
    this->height = height;

    this->scale = 1.0;

    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), machine);

    this->loadAllTextures();
}

void zappy::SFML::setScale(double __scale)
{
    this->scale = __scale;
}

void zappy::SFML::addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y, double __scale)
{
    sf::Texture texture = this->getTexture(__path_to_texture);
    this->textures.push_back(texture);

    sf::Sprite sprite;
    sprite.setTexture(*this->textures[this->textures.size() - 1]);
    sprite.setPosition(__pos_screen_x, __pos_screen_y);
    sprite.setScale(__scale, __scale);
    this->sprites.push_back(sprite);
}

void zappy::SFML::addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y, double __scaleX, double __scaleY)
{
    sf::Texture texture = this->getTexture(__path_to_texture);
    this->textures.push_back(texture);

    sf::Sprite sprite;
    sprite.setTexture(*this->textures[this->textures.size() - 1]);
    sprite.setPosition(__pos_screen_x, __pos_screen_y);
    sprite.setScale(__scaleX, __scaleY);
    this->sprites.push_back(sprite);
}

void zappy::SFML::addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y,
                            int __pos_sprite_x, int __pos_sprite_y, int __sprite_width, int __sprite_height,
                            double __scale)
{
    sf::Texture texture = this->getTexture(__path_to_texture);
    this->textures.push_back(texture);

    sf::Sprite sprite;
    sprite.setTexture(*this->textures[this->textures.size() - 1]);
    sprite.setPosition(__pos_screen_x, __pos_screen_y);

    sf::IntRect sourceRect(__pos_sprite_x, __pos_sprite_y, __sprite_width, __sprite_height);
    sprite.setTextureRect(sourceRect);
    sprite.setScale(__scale, __scale);

    this->sprites.push_back(sprite);
}

void zappy::SFML::addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y,
                            int __pos_sprite_x, int __pos_sprite_y, int __sprite_width, int __sprite_height,
                            double __scaleX, double __scaleY)
{
    sf::Texture texture = this->getTexture(__path_to_texture);
    this->textures.push_back(texture);

    sf::Sprite sprite;
    sprite.setTexture(*this->textures[this->textures.size() - 1]);
    sprite.setPosition(__pos_screen_x, __pos_screen_y);

    sf::IntRect sourceRect(__pos_sprite_x, __pos_sprite_y, __sprite_width, __sprite_height);
    sprite.setTextureRect(sourceRect);
    sprite.setScale(__scaleX, __scaleY);

    this->sprites.push_back(sprite);
}

void zappy::SFML::addSpriteWithOpacity(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y,
                                       int __pos_sprite_x, int __pos_sprite_y, int __sprite_width, int __sprite_height,
                                       double __scale, float __opacity)
{
    sf::Texture texture = this->getTexture(__path_to_texture);
    this->textures.push_back(texture);

    sf::Sprite sprite;
    sprite.setTexture(*this->textures[this->textures.size() - 1]);
    sprite.setPosition(__pos_screen_x, __pos_screen_y);

    sf::IntRect sourceRect(__pos_sprite_x, __pos_sprite_y, __sprite_width, __sprite_height);
    sprite.setTextureRect(sourceRect);
    sprite.setScale(__scale, __scale);

    sf::Color spriteColor = sprite.getColor();
    spriteColor.a = static_cast<sf::Uint8>(__opacity * 255);  // Convert opacity to alpha value
    sprite.setColor(spriteColor);

    this->sprites.push_back(sprite);
}

void zappy::SFML::drawSquare(int __x, int __y, int __size,
                             int __r,
                             int __g,
                             int __b,
                             int __a)
{
    sf::RectangleShape square;
    square.setPosition(__x, __y);
    square.setSize(sf::Vector2f(__size, __size));
    square.setFillColor(sf::Color(__r, __g, __b, __a));
    this->window->draw(square);
}

void zappy::SFML::drawSquare(int __x, int __y, int __width, int __height,
                             int __r,
                             int __g,
                             int __b,
                             int __a)
{
    sf::RectangleShape square;
    square.setPosition(__x, __y);
    square.setSize(sf::Vector2f(__width, __height));
    square.setFillColor(sf::Color(__r, __g, __b, __a));
    window->draw(square);
}

void zappy::SFML::drawBackground(int __background_color_r__, int __background_color_g__, int __background_color_b__, int __background_color_a__)
{
    this->window->clear(sf::Color(__background_color_r__, __background_color_g__, __background_color_b__, __background_color_a__));
}

void zappy::SFML::display()
{
    return (this->window->display());
}

std::vector<zappy::Events> zappy::SFML::events()
{
    sf::Event event;
    std::vector<zappy::Events> events;

    this->mouseClick = nullptr;

    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->window->close();
            return (events);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                this->mouseClick = std::pair<int, int>(mouseX, mouseY);
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        events.push_back(zappy::Events::MOVE_UP);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        events.push_back(zappy::Events::MOVE_DOWN);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        events.push_back(zappy::Events::MOVE_LEFT);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        events.push_back(zappy::Events::MOVE_RIGHT);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        events.push_back(zappy::Events::ZOOM_IN);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        events.push_back(zappy::Events::ZOOM_OUT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        events.push_back(zappy::Events::TIME_UP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        events.push_back(zappy::Events::TIME_DOWN);

    return (events);
}

my::nullable<std::pair<int, int>> zappy::SFML::getMouseClick()
{
    sf::Event event;
    std::vector<zappy::Events> events;

    return (this->mouseClick);
}

bool zappy::SFML::isOpen() const
{
    return (this->window->isOpen());
}

void zappy::SFML::loadAllTextures() 
{
}

sf::Texture zappy::SFML::getTexture(const std::string &__path) const
{
    for (auto &data : this->texturesData)
        if (data.path == __path)
            return (data.texture);
    return (this->texturesData[0].texture);
}

void zappy::SFML::drawText(int __x, int __y, const std::string& __text,
                           const std::string& __fontFile, int __fontSize,
                           int __r, int __g, int __b, int __a)
{
    sf::Text text;
    text.setPosition(__x, __y);
    text.setString(__text);

    // Load font
    sf::Font font;
    if (!font.loadFromFile(__fontFile)) {
        // Handle font loading error
    }

    text.setFont(font);
    text.setCharacterSize(__fontSize);
    text.setFillColor(sf::Color(__r, __g, __b, __a));
    window->draw(text);
}

void zappy::SFML::drawTextCentered(int __x, int __y, const std::string& __text,
                                   const std::string& __fontFile, int __fontSize,
                                   int __r, int __g, int __b, int __a)
{
    sf::Text text;
    text.setString(__text);

    // Load font
    sf::Font font;
    if (!font.loadFromFile(__fontFile)) {
        // Handle font loading error
    }

    text.setFont(font);
    text.setCharacterSize(__fontSize);
    text.setFillColor(sf::Color(__r, __g, __b, __a));

    // Get the width of the text
    sf::FloatRect bounds = text.getGlobalBounds();
    float textWidth = bounds.width;

    // Calculate the centered position
    float centeredX = __x - (textWidth / 2.f);
    float centeredY = __y;

    // Set the position of the text
    text.setPosition(centeredX, centeredY);

    // Draw the text
    window->draw(text);
}
