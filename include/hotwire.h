#ifndef TM_H
#define TM_H
#define WS_W render_window.getSize().x
#define WS_H render_window.getSize().y
#define SFGUI_WS_W render_window.getSize().x 
#define SFGUI_WS_H render_window.getSize().y 
#define SFGUI_WS_BAR_W sfgui_window_bar->GetAllocation().width
#define SFGUI_WS_BAR_H render_window.getSize().y

//#include "texture_manager.h"
#include "elements.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <memory>

class Hotwire{
    public: 
        Hotwire();
        ~Hotwire();

        sf::RenderWindow render_window;
		sfg::SFGUI sfgui;

		sfg::Canvas::Ptr canvas = sfg::Canvas::Create();
		sfg::Desktop desktop;

		sf::Mouse mouse;

		sfg::ScrolledWindow::Ptr scrolledwindow = sfg::ScrolledWindow::Create();

		sfg::Box::Ptr boxIN = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
		sfg::Box::Ptr box = sfg::Box::Create();	

		sfg::Window::Ptr sfgui_window = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_menu = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_pause = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_bar = sfg::Window::Create();
		
		std::map<std::string, sfg::Image::Ptr> image_map;

		sfg::Fixed::Ptr fixed = sfg::Fixed::Create();
		void init_image(const std::string & name);

		std::map<int , Element* > element_map;	
		std::vector<std::pair<int, int> > vector_wires;
		sf::VertexArray wires;
		std::vector<sf::VertexArray *> vector_draw_wire;
		std::vector<sf::CircleShape *> vector_draw_circleshape;

		std::string buffer = "empty";
		int bufferFirstElement = -1;
		int bufferSecondElement = -1;


		bool render_bar = false;
        bool running = false;

		int amountImageX;
		int amountImagey;

		sf::Vector2i couting_amountImage(int ws_w, int ws_h, int img_s);

		int amountOfBatteries = 0;
		int wire_id = 0;
		int element_id = 0;

		int element_making(std::string name, sf::Vector2i pos, int amountOfBatteries, int &id);
		int wire_making(int b1, int b2);

        void init();
        void handle_events();
        void render();
        void update();
        void clear();
};
#endif
