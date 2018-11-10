#include "room.hpp"

using namespace All;

Room::Room( ) { }

Room::Room( sf::VideoMode* ptr_desktop, sf::Texture* ptr_texture )
{
  animatedSprite = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite.setPosition( sf::Vector2f( 0, 0 ) );
  animatedSprite.setScale( ptr_desktop->width / 1280.0, ptr_desktop->height / 720.0 );
  InitializeAnimations( ptr_texture );
}

void Room::Draw( sf::RenderWindow* ptr_renderWindow, sf::Time frameTime ) {
  animatedSprite.play( animation );
  animatedSprite.update( frameTime );
  ptr_renderWindow->draw( animatedSprite );
}

void Room::InitializeAnimations( sf::Texture* ptr_texture ) {
  animation.setSpriteSheet( *ptr_texture );
  animation.addFrame( sf::IntRect( 0, 0, 1280, 720 ) );
}