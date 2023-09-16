/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../events/events.hpp"
#include "../tools/nullable.hpp"
#include "../routes/SpriteRouteConstants.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include <iostream>

namespace zappy
{
    struct TextureData {
        TextureData(sf::Texture &__texture, const std::string &__path);
        TextureData(const zappy::TextureData &__data);

        sf::Texture texture;
        std::string path;
    };

    class SFML {
        public:
            SFML(int width, int height, std::string machine);
            ~SFML() = default;

            void setScale(double __scale);

            /**
             ** @brief remove the background image if it exists
            **/
            void clearBackground();

            /**
            ** @brief add a sprite to the vector of sprites to draw
            ** @param __path_to_texture The path to the sprite
            ** @param __pos_screen_x The x position of the sprite on the screen
            ** @param __pos_screen_y The y position of the sprite on the screen
            ** @param __scale The scale of the sprite, 1 by default
            */
            void addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y, double __scale = 1.0);

            /**
            ** @brief add a sprite to the vector of sprites to draw
            ** @param __path_to_texture The path to the sprite
            ** @param __pos_screen_x The x position of the sprite on the screen
            ** @param __pos_screen_y The y position of the sprite on the screen
            ** @param __scaleX The scale x of the sprite
            ** @param __scaleY The scale y of the sprite
            */
            void addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y, double __scaleX, double __scaleY);

            /**
            ** @brief add a sprite to the vector of sprites to draw
            ** @param __path_to_texture The path to the sprite
            ** @param __pos_screen_x The x position of the sprite on the screen
            ** @param __pos_screen_y The y position of the sprite on the screen
            ** @param __pos_sprite_x The x position in the image of the sprite
            ** @param __pos_sprite_y The y position in the image of the sprite
            ** @param __sprite_width The width of the sprite
            ** @param __sprite_heigth The Height if the sprite
            ** @param __scaleX The scale x of the sprite
            ** @param __scaleY The scale y of the sprite
            */
            void addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y,
                           int __pos_sprite_x, int __pos_sprite_y, int __sprite_width, int __sprite_heigth,
                           double __scaleX, double __scaleY);

            /**
            ** @brief add a sprite to the vector of sprites to draw
            ** @param __path_to_texture The path to the sprite
            ** @param __pos_screen_x The x position of the sprite on the screen
            ** @param __pos_screen_y The y position of the sprite on the screen
            ** @param __pos_sprite_x The x position in the image of the sprite
            ** @param __pos_sprite_y The y position in the image of the sprite
            ** @param __sprite_width The width of the sprite
            ** @param __sprite_heigth The Height if the sprite
            ** @param __scale The scale of the sprite, 1 by default
            */
            void addSprite(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y,
                           int __pos_sprite_x, int __pos_sprite_y, int __sprite_width, int __sprite_heigth,
                           double __scale = 1.0);

            /**
            ** @brief add a sprite to the vector of sprites to draw
            ** @param __path_to_texture The path to the sprite
            ** @param __pos_screen_x The x position of the sprite on the screen
            ** @param __pos_screen_y The y position of the sprite on the screen
            ** @param __pos_sprite_x The x position in the image of the sprite
            ** @param __pos_sprite_y The y position in the image of the sprite
            ** @param __sprite_width The width of the sprite
            ** @param __sprite_height The Height if the sprite
            ** @param __scale The scale of the sprite
            ** @param __opacity The opacity of the sprite
            */
            void addSpriteWithOpacity(const std::string &__path_to_texture, int __pos_screen_x, int __pos_screen_y,
                        int __pos_sprite_x, int __pos_sprite_y, int __sprite_width, int __sprite_heigth,
                        double __scale, float __opacity);

            /**
             ** @brief draw a Square
             ** @param __x The x position of the square
             ** @param __y The y position of the square
             ** @param __size The size of the square
            */
            void drawSquare(int __x, int __y, int __size,
                            int __r = 255,
                            int __g = 255,
                            int __b = 255,
                            int __a = 255);

            /**
             ** @brief draw a Square
             ** @param __x The x position of the square
             ** @param __y The y position of the square
             ** @param __width The width of the square
             ** @param __height The height of the square
            */
            void drawSquare(int __x, int __y, int __width, int __height,
                            int __r,
                            int __g,
                            int __b,
                            int __a);

            /**
            ** @brief draw every sprites
            ** @param __background_color__ color of the background
            **/
            void drawBackground(int __background_color_r__, int __background_color_g__, int __background_color_b__, int __background_color_a__ = 255);

            /**
            ** @brief call the display méthod of the sfml window
            */
            void display();

            /**
            ** @brief get all the events from the keyboard, there can be multiple events
            */
            std::vector<zappy::Events> events();

            /**
            ** @brief get the mouse click
            */
            my::nullable<std::pair<int, int>> getMouseClick();

            // Methods for Texts
            void drawText(int __x, int __y, const std::string& __text,
                                       const std::string& __fontFile, int __fontSize,
                                       int __r, int __g, int __b, int __a);

            void drawTextCentered(int __x, int __y, const std::string& __text,
                                  const std::string& __fontFile, int __fontSize,
                                  int __r, int __g, int __b, int __a);

            /**
            ** @brief return true if the window is open, else it returns false
            */
            bool isOpen() const;

        protected:
        private:
            int width;
            int height;
            double scale;
            std::shared_ptr<sf::RenderWindow> window;
            my::nullable<std::pair<int, int>> mouseClick;

            /* we need to store the textures otherwise it will be destroyed and we will have white sprites */
            std::vector<my::nullable<sf::Texture>> textures;
            std::vector<zappy::TextureData> texturesData;
            std::vector<my::nullable<sf::Sprite>> sprites;
            std::vector<my::nullable<sf::Text>> texts;

            /**
             * @brief for optimisation purposes, load all the textures only once
            */
            void loadAllTextures();

            /**
             * @brief return the texture in the vector of TextureData
            */
            sf::Texture getTexture(const std::string &__path) const;
    };
}

#endif /* !SFML_HPP_ */
