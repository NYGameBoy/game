#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

namespace All {
  class Room {
    public:
      Room( );
      Room( sf::VideoMode* ptr_desktop, sf::Texture* ptr_texture );
      void Draw( sf::RenderWindow* ptr_renderWindow, sf::Time frameTime );
    private:
      AnimatedSprite animatedSprite;
      Animation animation;
      void InitializeAnimations( sf::Texture* ptr_texture );
  };
}