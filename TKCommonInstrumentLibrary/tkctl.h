/**
@file
@brief A Documented file.

Details.
*/

#ifndef __TKCIL__
#define __TKCIL__
#include <iostream>
#include <string>
#include <limits>
#include <map>
#include <vector>
using namespace std::literals::string_literals;

class SESSION
{
protected:
public:
	SESSION() {};
	std::string stream(std::string)
	{
		return "";
	}
};

/*
class Average : virtual public SESSION
{
private:
	const std::string keyname = ":ACQuire:AVERage"s;
protected:
public:
	std::string operator()(void) { return stream(keyname + "?"); }
	std::string Count(void) { return stream(keyname + "?"); }
	std::string Count(int nrf)
	{
		if (nrf != std::numeric_limits<int>::max())
			return stream(keyname + ":COUNt " + std::to_string(nrf));
		else
			return stream(keyname + ":COUNt " + "INFINITY");
	}
	std::string ExponentWeight(void) { return stream(keyname + "?"); }
	std::string ExponentWeight(int nrf)
	{
		return stream(keyname + ":EWEight " + std::to_string(nrf));
	}
};
class Acquire : virtual public SESSION, public Average
{
private:
	const std::string keyname = ":ACQuire"s;
protected:
public:
	std::string operator()(void) { return stream(keyname + "?"); }
	std::string Clock(void) { return stream(keyname + "?"); }
	enum CLOCKSOURCE
	{
		INTERNAL, EXTERNAL
	};
	std::string Clock(CLOCKSOURCE source)
	{
		switch (source) {
		case CLOCKSOURCE::INTERNAL:
			return stream(keyname + ":CLOCk INTernal");
		case CLOCKSOURCE::EXTERNAL:
			return stream(keyname + ":CLOCk EXTernal");
		}
	}
};
*/

class TKCTL : virtual public SESSION
{
public:
	class CHANNEL : virtual public SESSION
	{
	public:
		enum ADCMODULE
		{
			NOMODULE,
			M701251,
			M701255,
			M720210,
			M720211,
			M720250,
		};
	protected:
		int channel_number;
		std::map<std::string, ADCMODULE> module_map = {
			{ "NOMODULE"s, ADCMODULE::NOMODULE },
			{ "M701251"s, ADCMODULE::M701251 },
			{ "M701255"s, ADCMODULE::M701255 },
			{ "M720210"s, ADCMODULE::M720210 },
			{ "M720211"s, ADCMODULE::M720211 },
			{ "M720250"s, ADCMODULE::M720250 }
		};
		template <class T> ADCMODULE to_adcmodule(T str) { return module_map[std::transform(str.cbegin(), str.cend(), str.begin(), ::toupper); ]; }
	protected:
	public:
		CHANNEL() {};
		CHANNEL(int channel_number) : channel_number(channel_number) {};
		ADCMODULE GetModule()
		{
			std::string buf;
			buf = stream(":channel"s + std::to_string(channel_number) + ":module?");

			std::cout << "c" << channel_number << std::endl;
			return ADCMODULE::M701251;
		}

	};

	TKCTL()
	{
	}
	~TKCTL()
	{

	}

	CHANNEL operator[](int channel_index)
	{
		return CHANNEL(channel_index + 1);
	}

	class CONNECTION
	{
	public:
		CONNECTION();
		void StartSession();
	};

private:

};



#endif
