#include "newplayer.hpp"

using namespace All;

NewPlayer::NewPlayer( ) { }

NewPlayer::NewPlayer( sf::Texture* ptr_texture_arm, sf::Texture* ptr_texture_body, sf::Texture* ptr_texture_head, sf::Texture* ptr_texture_leg, sf::Vector2<float> location )
:
reverseAnimation( false )
{
  animatedSprite_leg1 = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite_leg1.setPosition( sf::Vector2f( location.x - 4, location.y + 20 ) );
  animatedSprite_leg2 = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite_leg2.setPosition( sf::Vector2f( location.x - 8, location.y + 24 ) );
  animatedSprite_body = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite_body.setPosition( sf::Vector2f( location.x - 16, location.y - 32 ) );
  animatedSprite_head = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite_head.setPosition( sf::Vector2f( location.x - 16, location.y - 48 ) );
  animatedSprite_arm1 = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite_arm1.setPosition( sf::Vector2f( location.x + 4, location.y - 20 ) );
  animatedSprite_arm2 = AnimatedSprite( sf::seconds( 0.2 ), true, true );
  animatedSprite_arm2.setScale( -1, 1 );
  animatedSprite_arm2.setPosition( sf::Vector2f( location.x, location.y - 16 ) );
  InitializeAnimations( ptr_texture_arm, ptr_texture_body, ptr_texture_head, ptr_texture_leg );
}

void NewPlayer::AnimateMove( sf::Time frameTime ) {
  animatedSprite_leg1.move( speed * frameTime.asSeconds( ) );
  animatedSprite_leg2.move( speed * frameTime.asSeconds( ) );
  animatedSprite_body.move( speed * frameTime.asSeconds( ) );
  animatedSprite_head.move( speed * frameTime.asSeconds( ) );
  animatedSprite_arm1.move( speed * frameTime.asSeconds( ) );
  animatedSprite_arm2.move( speed * frameTime.asSeconds( ) );
}

void NewPlayer::AnimateStand( ) {
  animatedSprite_leg1.setRotation( 0 );
  animatedSprite_leg2.setRotation( 30 );
  animatedSprite_arm1.setRotation( -15 );
  animatedSprite_arm2.setRotation( 15 );
}

void NewPlayer::AnimateWalk( sf::Time frameTime ) {
  if( animatedSprite_leg1.getRotation( ) > 45 && animatedSprite_leg1.getRotation( ) < 280 )
    reverseAnimation = true;
  if( animatedSprite_leg1.getRotation( ) > 280 && animatedSprite_leg1.getRotation( ) < 315 )
    reverseAnimation = false;
  animatedSprite_leg1.rotate( ( reverseAnimation ? -1 : 1 ) * 90 * frameTime.asSeconds( ) );
  animatedSprite_leg2.rotate( ( reverseAnimation ? -1 : 1 ) * -90 * frameTime.asSeconds( ) );
  animatedSprite_arm1.rotate( ( reverseAnimation ? -1 : 1 ) * -90 * frameTime.asSeconds( ) );
  animatedSprite_arm2.rotate( ( reverseAnimation ? -1 : 1 ) * 90 * frameTime.asSeconds( ) );
}

void NewPlayer::Draw( sf::RenderWindow* ptr_renderWindow, sf::Time frameTime ) {
  if( speed.x == 0 && speed.y == 0 )
    AnimateStand( );
  else
    AnimateWalk( frameTime );
  AnimateMove( frameTime );
  ptr_renderWindow->draw( animatedSprite_arm1 );
  ptr_renderWindow->draw( animatedSprite_leg1 );
  ptr_renderWindow->draw( animatedSprite_body );
  ptr_renderWindow->draw( animatedSprite_head );
  ptr_renderWindow->draw( animatedSprite_leg2 );
  ptr_renderWindow->draw( animatedSprite_arm2 );
}

void NewPlayer::InitializeAnimations( sf::Texture* ptr_texture_arm, sf::Texture* ptr_texture_body, sf::Texture* ptr_texture_head, sf::Texture* ptr_texture_leg ) {
  armAnimation.setSpriteSheet( *ptr_texture_arm );
  armAnimation.addFrame( sf::IntRect( 0, 0, 32, 64 ) );
  bodyAnimation.setSpriteSheet( *ptr_texture_body );
  bodyAnimation.addFrame( sf::IntRect( 0, 0, 32, 64 ) );
  headAnimation.setSpriteSheet( *ptr_texture_head );
  headAnimation.addFrame( sf::IntRect( 0, 0, 32, 32 ) );
  legAnimation.setSpriteSheet( *ptr_texture_leg );
  legAnimation.addFrame( sf::IntRect( 0, 0, 32, 64 ) );
  animatedSprite_leg1.play( legAnimation );
  animatedSprite_leg2.play( legAnimation );
  animatedSprite_body.play( bodyAnimation );
  animatedSprite_head.play( headAnimation );
  animatedSprite_arm1.play( armAnimation );
  animatedSprite_arm2.play( armAnimation );
}

void NewPlayer::StopDown( ) {
  speed.y -= 200;
}

void NewPlayer::StopLeft( ) {
  speed.x += 200;
}

void NewPlayer::StopRight( ) {
  speed.x -= 200;
}

void NewPlayer::StopUp( ) {
  speed.y += 200;
}

void NewPlayer::WalkDown( ) {
  speed.y += 200;
}

void NewPlayer::WalkLeft( ) {
  speed.x -= 200;
}

void NewPlayer::WalkRight( ) {
  speed.x += 200;
}

void NewPlayer::WalkUp( ) {
  speed.y -= 200;
}