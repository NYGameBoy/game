#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

namespace All {
  class Player {
    public:
      Player( );
      Player( sf::Texture* ptr_texture, sf::Vector2<float> location );
      void Draw( sf::RenderWindow* ptr_renderWindow, sf::Time frameTime );
      void StopDown( );
      void StopLeft( );
      void StopRight( );
      void StopUp( );
      void StopPunch( );
      void WalkDown( );
      void WalkLeft( );
      void WalkRight( );
      void WalkUp( );
      void Punch( );
    private:
      sf::Vector2<float> speed;
      AnimatedSprite animatedSprite;
      Animation currentAnimation;
      Animation standingAnimation;
      Animation walkingAnimation;
      Animation punchingAnimation;
      bool punching;
      void Flip( bool flipped );
      void InitializeAnimations( sf::Texture* ptr_texture );
  };
}