#pragma once

#include "animvalue.hh"
#include "menu.hh"
#include "screen.hh"
#include <boost/asio.hpp>

class Audio;
class ThemeIntro;
class SvgTxtTheme;
class MenuOption;

/// intro screen
class ScreenIntro : public Screen {
  public:
	/// constructor
	ScreenIntro(std::string const& name, Audio& audio);
	void enter();
	void exit();
	void reloadGL();
	void manageEvent(SDL_Event event);
	void manageEvent(input::NavEvent const& event);
	void draw();

  private:
	void draw_menu_options();
	void draw_webserverNotice();
	void populateMenu();
	std::string getIPaddr();
	SvgTxtTheme& getTextObject(std::string const& txt);

	Audio& m_audio;
	std::unique_ptr<ThemeIntro> theme;
	Menu m_menu;
	bool m_first;
	bool m_drawNotice = false;
	AnimValue m_selAnim;
	AnimValue m_submenuAnim;
	AnimValue m_webserverNoticeTimeout;
	int webserversetting = 0;
	std::string m_ipaddr = "";
};
