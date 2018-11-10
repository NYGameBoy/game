#include "player.hpp"

using namespace All;

Player::Player( ) { }

Player::Player( sf::Texture* ptr_texture, sf::Vector2<float> location )
:
punching( false )
{
  animatedSprite = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite.setOrigin( sf::Vector2f( 16, 32 ) );
  animatedSprite.setPosition( location );
  animatedSprite.setScale( 4, 4 );
  InitializeAnimations( ptr_texture );
}

void Player::Draw( sf::RenderWindow* ptr_renderWindow, sf::Time frameTime ) {
  if( punching )
    currentAnimation = punchingAnimation;
  else if( speed.x == 0 && speed.y == 0 )
    currentAnimation = standingAnimation;
  else {
    currentAnimation = walkingAnimation;
  }
  if( speed.x != 0 )
    Flip( speed.x < 0 );
  animatedSprite.play( currentAnimation );
  animatedSprite.move( speed * frameTime.asSeconds( ) );
  animatedSprite.update( frameTime );
  ptr_renderWindow->draw( animatedSprite );
}

void Player::Flip( bool flipped ) {
  animatedSprite.setScale( ( flipped ? -1 : 1 ) * 4, 4 );
}

void Player::InitializeAnimations( sf::Texture* ptr_texture ) {
  standingAnimation.setSpriteSheet( *ptr_texture );
  standingAnimation.addFrame( sf::IntRect( 0, 0, 32, 64 ) );
  walkingAnimation.setSpriteSheet( *ptr_texture );
  walkingAnimation.addFrame( sf::IntRect( 32, 0, 32, 64 ) );
  walkingAnimation.addFrame( sf::IntRect( 64, 0, 32, 64 ) );
  walkingAnimation.addFrame( sf::IntRect( 96, 0, 32, 64 ) );
  walkingAnimation.addFrame( sf::IntRect( 128, 0, 32, 64 ) );
  walkingAnimation.addFrame( sf::IntRect( 160, 0, 32, 64 ) );
  punchingAnimation.setSpriteSheet( *ptr_texture );
  punchingAnimation.addFrame( sf::IntRect( 128, 128, 32, 64 ) );
  punchingAnimation.addFrame( sf::IntRect( 160, 128, 32, 64 ) );
  punchingAnimation.addFrame( sf::IntRect( 192, 128, 32, 64 ) );
  punchingAnimation.addFrame( sf::IntRect( 224, 128, 32, 64 ) );
  punchingAnimation.addFrame( sf::IntRect( 256, 128, 32, 64 ) );
  punchingAnimation.addFrame( sf::IntRect( 288, 128, 32, 64 ) );
  currentAnimation = standingAnimation;
}

void Player::StopDown( ) {
  speed.y -= 200;
}

void Player::StopLeft( ) {
  speed.x += 200;
}

void Player::StopRight( ) {
  speed.x -= 200;
}

void Player::StopUp( ) {
  speed.y += 200;
}

void Player::WalkDown( ) {
  speed.y += 200;
}

void Player::WalkLeft( ) {
  speed.x -= 200;
}

void Player::WalkRight( ) {
  speed.x += 200;
}

void Player::WalkUp( ) {
  speed.y -= 200;
}

void Player::Punch( ) {
  punching = true;
}

void Player::StopPunch( ) {
  punching = false;
}