#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

namespace All {
  class NewPlayer {
    public:
      NewPlayer( );
      NewPlayer( sf::Texture* ptr_texture_arm, sf::Texture* ptr_texture_body, sf::Texture* ptr_texture_head, sf::Texture* ptr_texture_leg, sf::Vector2<float> location );
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
    private:
      sf::Vector2<float> speed;
      bool reverseAnimation;
      AnimatedSprite animatedSprite_arm1;
      AnimatedSprite animatedSprite_arm2;
      AnimatedSprite animatedSprite_body;
      AnimatedSprite animatedSprite_head;
      AnimatedSprite animatedSprite_leg1;
      AnimatedSprite animatedSprite_leg2;
      Animation armAnimation;
      Animation bodyAnimation;
      Animation headAnimation;
      Animation legAnimation;
      void AnimateMove( sf::Time frameTime );
      void AnimateStand( );
      void AnimateWalk( sf::Time frameTime );
      void InitializeAnimations( sf::Texture* ptr_texture_arm, sf::Texture* ptr_texture_body, sf::Texture* ptr_texture_head, sf::Texture* ptr_texture_leg );
  };
}