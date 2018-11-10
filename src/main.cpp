#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "newplayer.hpp"
#include "room.hpp"
#include "textures.hpp"

using namespace All;

void InitializeGame( );
void InputHandler( sf::Event event );
void LoadPlayer( );
void LoadRoom( );
void RunGame( );
void UpdateUI( sf::Time frameTime );

sf::VideoMode desktop;
sf::RenderWindow* ptr_renderWindow;
Textures textures;
Room room;
Player player_1;
NewPlayer player_2;

int main( int argc, char** argv ) {
  InitializeGame( );
}

void InitializeGame( ) {
  //desktop = sf::VideoMode( ).getDesktopMode( );
  //sf::RenderWindow renderWindow( desktop, "Game", sf::Style::None );
  desktop = sf::VideoMode( 1280, 720 );
  sf::RenderWindow renderWindow( desktop, "Game" );
  renderWindow.setFramerateLimit( 60 );
  renderWindow.setKeyRepeatEnabled( false );
  ptr_renderWindow = &renderWindow;
  LoadRoom( );
  LoadPlayer( );
  RunGame( );
}

void InputHandler( sf::Event event ) {
  while( ptr_renderWindow->pollEvent( event ) ) {
    switch( event.type ) {
      case sf::Event::Closed:
        ptr_renderWindow->close( );
        break;
      case sf::Event::KeyPressed:
        switch( event.key.code ) {
          case sf::Keyboard::Escape:
            exit(0);
            break;
          case sf::Keyboard::S:
            player_1.WalkDown( );
            break;
          case sf::Keyboard::A:
            player_1.WalkLeft( );
            break;
          case sf::Keyboard::D:
            player_1.WalkRight( );
            break;
          case sf::Keyboard::W:
            player_1.WalkUp( );
            break;
          case sf::Keyboard::P:
            player_1.Punch( );
            break;            
          case sf::Keyboard::Down:
            player_2.WalkDown( );
            break;
          case sf::Keyboard::Left:
            player_2.WalkLeft( );
            break;
          case sf::Keyboard::Right:
            player_2.WalkRight( );
            break;
          case sf::Keyboard::Up:
            player_2.WalkUp( );
            break;          
          default:
            break;
        }
        break;
      case sf::Event::KeyReleased:
        switch( event.key.code ) {
          case sf::Keyboard::S:
            player_1.StopDown( );
            break;
          case sf::Keyboard::A:
            player_1.StopLeft( );
            break;
          case sf::Keyboard::D:
            player_1.StopRight( );
            break;
          case sf::Keyboard::W:
            player_1.StopUp( );
            break;
          case sf::Keyboard::P:
            player_1.StopPunch( );
            break;            
          case sf::Keyboard::Down:
            player_2.StopDown( );
            break;
          case sf::Keyboard::Left:
            player_2.StopLeft( );
            break;
          case sf::Keyboard::Right:
            player_2.StopRight( );
            break;
          case sf::Keyboard::Up:
            player_2.StopUp( );
            break;            
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
}

void LoadPlayer( ) {
  player_1 = Player( &textures.Player_Skeleton_1, sf::Vector2<float>( 96, ( desktop.height / 2 ) + 96 ) );
  player_2 = NewPlayer( &textures.Player_Armsheet, &textures.Player_Bodysheet, &textures.Player_Headsheet, &textures.Player_Legsheet, sf::Vector2<float>( 64, ( desktop.height / 2 ) - 96 ) );
}

void LoadRoom( ) {
  room = Room( &desktop, &textures.Background_Castle_1 );
}

void RunGame( ) {
  sf::Event event;
  sf::Clock frameClock;
  while( ptr_renderWindow->isOpen( ) ) {
    InputHandler( event );
    UpdateUI( frameClock.restart( ) );
  }
}

void UpdateUI( sf::Time frameTime ) {
  ptr_renderWindow->clear( );
  room.Draw( ptr_renderWindow, frameTime );
  player_2.Draw( ptr_renderWindow, frameTime );
  player_1.Draw( ptr_renderWindow, frameTime );
  ptr_renderWindow->display( );
}